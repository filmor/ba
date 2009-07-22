#include "Analyse.hpp"

#include <TH1D.h>
#include <algorithm>

namespace ba
{
    const double Z_MASS = 91.1876; // GeV, delta 0.0021

    namespace
    {
        const char* make_name(std::string const& prefix,
                              std::string const& name)
        {
            return ("[" + prefix + "] " + name).c_str();
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

        TH1D z_mass (make_name(prefix, "ll_mass"), "m_ll", 100, 50, 150);
        TH1D p_t (make_name(prefix, "W_mass"), "m_W", 100, 50, 150);

        for (Long64_t entry = begin; entry < end; ++entry)
        {
            get_entry(tree_.LoadTree(entry));

            // We need at least 3 leptons
            if (leptons_.size() < 3) continue;

            particle_vector::const_iterator first, second;

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
                    if (i->charge + j->charge < 0.1)
                    {
                        // Zuerst nehmen wir einfach den ersten
                        // gefundenen mit z.M() irgendwo in der Nähe
                        // von z
                        first = i;
                        second = j;

                        break;
                    }
                }
            }

            particle z (particle::Z_BOSON,
                        first->momentum + second->momentum);

            // [z.M()] = MeV
            z_mass.Fill(z.momentum.M() / 1000);

            // Drittes Lepton wählen
            // MET dazunehmen (transversale Masse)

        }

        TFile f ("output.root", "UPDATE");
        f.cd();
        z_mass.Write();
        p_t.Write();
    }

}
