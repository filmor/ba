#include "Analyse.hpp"

#include <TH1D.h>

namespace ba
{

    void Analyse::Loop()
    {
        if (fChain == 0) return;

        Long64_t nentries = 100; // fChain->GetEntriesFast();
        TH1D* z_mass = new TH1D("z_mass", "Z Masse", 100, 50, 150);

        Long64_t nbytes = 0, nb = 0;
        for (Long64_t jentry=0; jentry<nentries;jentry++)
        {
            Long64_t ientry = LoadTree(jentry);
            if (ientry < 0) break;
            nb = fChain->GetEntry(jentry);
            nbytes += nb;

            // Filter Electrons
            // Filter Muons
            
            // Case: e⁺e⁻l

            TLorentzVector z;

            // We need at least 3 leptons
            if (Mu_N + El_N < 3) continue;

            if (El_N >= 2)
            {
                // Findet ein e⁺e⁻-Paar mit e⁺ + e⁻ <- Z
                int i, j;
                for (i = 0; i < El_N; ++i)
                {
                    for (j = i + 1; j < El_N; ++j)
                    {
                        if ((*El_charge)[j] + (*El_charge)[i] < 0.2)
                        {
                            z = get_electron_vector(i)
                              + get_electron_vector(j);

                            // Kandidaten speichern
                            // Zuerst nehmen wir einfach den ersten
                            // gefundenen it z.M() irgendwo in der Nähe
                            // von z
                            z_mass->Fill(z.M() / 1000);
                        }
                    }
                }
            }
            else if (Mu_N >= 2)
            {
                // Findet ein µ⁺µ⁻-Paar mit µ⁺ + µ⁻ <- Z
                int i, j;
                for (i = 0; i < Mu_N; ++i)
                {
                    for (j = i + 1; j < Mu_N; ++j)
                    {
                        if ((*Mu_charge)[j] + (*Mu_charge)[i] < 0.2)
                        {
                            z = get_muon_vector(i)
                              + get_muon_vector(j);

                            // Kandidaten speichern
                            // Zuerst nehmen wir einfach den ersten
                            // gefundenen it z.M() irgendwo in der Nähe
                            // von z
                            z_mass->Fill(z.M() / 1000);
                        }
                    }
                }
            }

            // Drittes Lepton wählen
            // MET dazunehmen (transversale Masse)

        }

        TFile f ("histogramm.root", "RECREATE");
        f.cd();
        z_mass->Write();
    }

}
