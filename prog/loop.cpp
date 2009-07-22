#include "Analyse.hpp"

#include <TH1D.h>
#include <algorithm>
#include <limits>
#include <cmath>

namespace ba
{
    const double Z_MASS = 91.1876; // in GeV, delta 0.0021

    const double EPS_CHARGE = 0.3; // in e
    const double EPS_Z_MASS = std::numeric_limits<double>::max(); // MeV

    namespace
    {
        const char* make_name(std::string const& prefix,
                              std::string const& name)
        {
            static std::string val;
            if (prefix != "")
                val = "[" + prefix + "] " + name;
            else
                val = name;
            return val.c_str();
        }
    }

    void Analyse::loop(std::string const& prefix,
                       Long64_t begin, Long64_t end)
    {
        if (end < 0)
            end = tree_.GetEntriesFast ();
        else
            end = std::min (end, tree_.GetEntriesFast ());

        if (begin >= end) return;

        TH1D z_mass (make_name(prefix, "Z mass"), "m_ll", 100, 50, 150);
        TH1D p_t (make_name(prefix, "W mass"), "m_W", 100, 50, 150);

        for (Long64_t entry = begin; entry < end; ++entry)
        {
            get_entry(tree_.LoadTree(entry));

            // We need at least 3 leptons
            if (leptons_.size() < 3) continue;

            particle_vector::const_iterator first = leptons_.end()
                                          , second = leptons_.end();

            // Massendifferenz zum echten Z⁰
            double delta_m = std::numeric_limits<double>::max();

            for (particle_vector::const_iterator i = leptons_.begin();
                 i != leptons_.end();
                 ++i)
            {
                for (particle_vector::const_iterator j = i + 1;
                     j != leptons_.end();
                     ++j)
                {
                    // Same flavour
                    if (i->kind != j->kind)
                        continue;
                    // Opposite charge
                    if (i->charge + j->charge < EPS_CHARGE)
                    {
                        
                        const double d =
                            std::fabs((i->momentum + j->momentum).M()
                                      - Z_MASS)
                            ;

                        if (d < delta_m)
                        {
                            first = i;
                            second = j;
                            delta_m = d;
                        }
                    }
                }
            }

            // Keine anständigen Leptonen gefunden
            if (first == leptons_.end() || delta_m > EPS_Z_MASS)
                continue;

            const particle z (particle::Z_BOSON,
                              first->momentum + second->momentum);

            // [z.M()] = MeV

            z_mass.Fill(z.momentum.M() / 1000);

            // Drittes Lepton wählen
            // MET dazunehmen (transversale Masse) und m_W bestimmen

        }

        TFile f ("output.root", "UPDATE");
        f.cd();
        z_mass.Write();
        p_t.Write();
    }

}
