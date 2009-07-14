#include "Analyse.hpp"

#include <TH1D.h>

namespace ba
{

    void Analyse::Loop()
    {
        if (fChain == 0) return;

        Long64_t nentries = fChain->GetEntriesFast();
        TH1D* z_mass = new TH1D("bla", "blubb", 100, 50, 150);

        Long64_t nbytes = 0, nb = 0;
        for (Long64_t jentry=0; jentry<nentries;jentry++) {
            Long64_t ientry = LoadTree(jentry);
            if (ientry < 0) break;
            nb = fChain->GetEntry(jentry);
            nbytes += nb;

            if (El_N == 2 && Mu_N == 0)
            {
                TLorentzVector v = get_electron_vector(0) + get_electron_vector(1);
                z_mass->Fill(v.M() / 1000);
            }

            if (Mu_N == 2 && El_N == 0)
            {
                TLorentzVector v = get_muon_vector(0) + get_muon_vector(1);
                z_mass->Fill(v.M() / 1000);
            }

            if (Mu_N == 2 && El_N == 1)
            {
            }

            if (El_N == 2 && Mu_N == 1)
            {
            }

        }

        TFile f ("histogramm.root", "RECREATE");
        f.cd();
        z_mass->Write();
    }

}
