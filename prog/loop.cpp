#include "Analyse.hpp"

#include <TH1D.h>

namespace ba
{
    const double Z_MASS = 91.1876; // GeV, delta 0.0021

    void Analyse::loop()
    {
        if (fChain == 0) return;

        Long64_t nentries = fChain->GetEntriesFast();
        TH1D* z_mass = new TH1D("z_mass", "Z Masse", 100, 50, 150);

        Long64_t nbytes = 0, nb = 0;
        for (Long64_t jentry=0; jentry<nentries;jentry++)
        {
            Long64_t ientry = LoadTree(jentry);
            if (ientry < 0) break;
            nb = get_entry(jentry);
            nbytes += nb;

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
            z_mass->Fill(z.momentum.M() / 1000);

            // Drittes Lepton wählen
            // MET dazunehmen (transversale Masse)

        }

        TFile f ("histogramm.root", "RECREATE");
        f.cd();
        z_mass->Write();
    }

}
