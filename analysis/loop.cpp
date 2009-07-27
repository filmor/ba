#include "analysis.hpp"

#ifndef NO_PROGRESS_BAR
#include "boost/progress.hpp"
#endif

#include <algorithm>
#include <limits>
#include <cmath>
#include <string>

#include <TH1D.h>

namespace ba
{
    const double Z_MASS = 91.1876e3; // in MeV, delta 0.0021e3

    namespace
    {
        const char* make_name(std::string const& prefix,
                              const char* name)
        {
            static std::string val;
            if (prefix != "")
                val = "[" + prefix + "] " + name;
            else
                val = name;
            return val.c_str();
        }
        
        class histogram : TH1D
        {
        public:
            histogram (std::string const& prefix, const char* name,
                       unsigned count, int start, int end)
                : th1d_(make_name(prefix, name), name, count,
                        start, end)
            {}
            ~histogram () { th1d_.Write(); }

            void fill_mev (double value) { th1d_.Fill(value / 1000.); }
            void fill (double value) { th1d_.Fill(value); }

        private:
            TH1D th1d_;
        };
    }

    void analysis::loop(std::string const& prefix,
                        Long64_t begin, Long64_t end)
    {
        if (end < 0)
            end = tree_.GetEntriesFast ();
        else
            end = std::min (end, tree_.GetEntriesFast ());

        if (begin >= end) return;
        
        // Histogramme initialisieren
        histogram
            z_mass (prefix, "Z mass", 100, 50, 150),
            z_pt (prefix, "Z p_t", 300, 0, 200),
            l_pt (prefix, "lepton p_t", 300, 0, 200),
            m_t (prefix, "transverse mass", 300, 0, 200),
            delta_phi (prefix, "delta phi_WZ", 100, -4, 4),
            w_pt (prefix, "W p_t", 300, 0, 200)
            ;

#ifndef NO_PROGRESS_BAR
        boost::progress_display show_progress(end - begin);
        boost::progress_timer timer;
#endif

        for (Long64_t entry = begin; entry < end; ++entry)
        {
#ifndef NO_PROGESS_BAR
            ++show_progress;
#endif
            get_entry(tree_.LoadTree(entry));

            // Wir benötigen genau drei Leptonen
            if (leptons_.size() != 3) continue;

            particle_vector::const_iterator first = leptons_.end()
                                          , second = leptons_.end();

            // Massendifferenz zum echten Z⁰
            double delta_m = std::numeric_limits<double>::max();

            // Gehen über alle Kombinationen von (bereits gefilterten
            // Leptonen)
            for (particle_vector::const_iterator i = leptons_.begin();
                 i != leptons_.end();
                 ++i)
            {
                for (particle_vector::const_iterator j = i + 1;
                     j != leptons_.end();
                     ++j)
                {
                    // Die Leptonen, die das Z ausmachen müssen gleiches
                    // Flavour haben ...
                    if (i->kind != j->kind)
                        continue;
                    // ... aber entgegengesetzte Ladung
                    if (std::fabs(i->charge + j->charge) >
                            std::numeric_limits<double>::epsilon())
                        continue;

                        
                    const double d =
                        std::fabs((i->momentum + j->momentum).M()
                                  - Z_MASS)
                        ;
                    
                    // Wähle die Kombination mit der kleinsten Entfernung
                    // zur echten Z⁰-Masse.
                    if (d < delta_m)
                    {
                        first = i;
                        second = j;
                        delta_m = d;
                    }
                }
            }

            // Keine anständigen Leptonen gefunden
            // (Schnitt an delta_m wird nicht benötigt)
            if (first == leptons_.end())
                continue;

            // Z⁰
            const particle Z (particle::Z_BOSON,
                              first->momentum + second->momentum);

            // Pseudopartikel, das der transversal fehlenden Energie
            // zugeordnet und als Neutrino angenommen wird
            const particle met (particle::UNDEFINED,
                                MET_RefFinal_ex, MET_RefFinal_ey,
                                0.0, MET_RefFinal_et);

            // Drittes Lepton wählen
            // (f(x,y) = 3-x-y = z liefert immer das fehlende aus
            //  {0, 1, 2}, z.B. f(0,1) = 2)
            const charged_particle& l
                = leptons_[
                            3
                            - (first - leptons_.begin())
                            - (second - leptons_.begin())
                            ]
                ;
            
            // W-Boson als Summe aus dem Z⁰ und der Fehlenergie
            const charged_particle W (
                    particle::W_BOSON, l.charge,
                    l.momentum + met.momentum
                    );

            // Z⁰ Masse
            z_mass.fill_mev (Z.momentum.M());

            // Transversale Impulse
            w_pt.fill_mev (W.momentum.Pt());
            z_pt.fill_mev (Z.momentum.Pt());
            l_pt.fill_mev (l.momentum.Pt());
            
            // Transversale Masse
            m_t.fill_mev (
                std::sqrt(
                    2 * met.momentum.Pt() * l.momentum.Pt()
                      * (1 - std::cos(met.momentum.DeltaPhi(l.momentum))
                    ))
                );


            // Winkel zwischen W* und Z⁰
            delta_phi.fill (Z.momentum.DeltaPhi(W.momentum));
        }
    }
}
