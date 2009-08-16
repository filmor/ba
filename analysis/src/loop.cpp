#include "analysis.hpp"

#ifndef NO_PROGRESS_BAR
#include "boost/progress.hpp"
#endif

#include <algorithm>
#include <limits>
#include <cmath>
#include <string>

#include <TH1D.h>
#include <TH2I.h>

namespace ba
{
    const double Z_MASS = 91.1876e3; // in MeV, delta 0.0021e3

    namespace
    {
        class histogram : TH1D
        {
        public:
            histogram (const char* name, unsigned count,
                       int start, int end)
                : th1d_(name, name, count, start, end)
            {}

            ~histogram () { th1d_.Write(); }

            void fill_mev (double value, double weight = 1.)
            {
                fill (value / 1000., weight);
            }
            void fill (double value, double weight = 1.)
            {
                th1d_.Fill(value, weight);
            }

        private:
            TH1D th1d_;
        };
    }

    void analysis::loop()
    {
        Long64_t begin = 0;
        Long64_t end = tree_.GetEntries();

        // Weil's nicht anders anständig geht wird die Anzahl der
        // verarbeiteten Ereignisse (wie auf der ROOT-Mailing-Liste
        // empfohlen) in der UniqueID eines TObject gespeichert
        TObject count;
        count.SetUniqueID (end - begin);
        count.Write ("count");

        // Histogramme initialisieren
        histogram
            z_mass ("Z mass", 100, 50, 150),
            z_pt ("Z p_t", 300, 0, 200),
            l_pt ("lepton p_t", 300, 0, 200),
            m_t ("m_t", 300, 0, 200),
            delta_phi ("delta phi_WZ", 100, -4, 4),
            w_pt ("W p_t", 300, 0, 200),
            met_pt ("MET p_t", 300, 0, 200)
            ;

        TH2I el_mu_count ("El Mu N", "Count;El;Mu", 5, 0, 5, 5, 0, 5);

#ifndef NO_PROGRESS_BAR
        boost::progress_display show_progress(end - begin);
        boost::progress_timer timer;
#endif

        for (Long64_t entry = begin; entry < end; ++entry)
        {
#ifndef NO_PROGRESS_BAR
            ++show_progress;
#endif
            get_entry(entry); // (tree_.LoadTree(entry));

            el_mu_count.Fill (El_N, Mu_N, eventWeight);

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
            if (first == leptons_.end())
                continue;
            
            // Schnitt an der Z Masse (gegen ttbar)
            if (flags_ & flags::Z_MASS)
                if (delta_m > 10e3)
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


            // Schnitt am pt des Leptons (gegen Zll+X)
            if (flags_ & flags::L_PT)
                if (l.momentum.Pt() < 20e3)
                    continue;
            
            // W-Boson als Summe aus dem übrigen Lepton und der Fehlenergie
            const charged_particle W (
                    particle::W_BOSON, l.charge,
                    l.momentum + met.momentum
                    );

            // Z⁰ Masse
            z_mass.fill_mev (Z.momentum.M(), eventWeight);

            // Transversale Impulse
            w_pt.fill_mev (W.momentum.Pt(), eventWeight);
            z_pt.fill_mev (Z.momentum.Pt(), eventWeight);
            l_pt.fill_mev (l.momentum.Pt(), eventWeight);
            met_pt.fill_mev (met.momentum.Pt(), eventWeight);
            
            // Transversale Masse
            m_t.fill_mev (
                std::sqrt(
                    2 * met.momentum.Pt() * l.momentum.Pt()
                      * (1 - std::cos(met.momentum.DeltaPhi(l.momentum))
                    )),
                eventWeight
                );

            // Winkel zwischen W* und Z⁰
            delta_phi.fill (Z.momentum.DeltaPhi(W.momentum),
                            eventWeight);
        }

        el_mu_count.Write();
    }
}
