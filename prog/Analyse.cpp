#define Analyse_cpp
#include "Analyse.hpp"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>

#include <iostream>

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
        // if (Cut(ientry) < 0) continue;
        //      std::cout << El_N << "\n";
        if (El_N == 2)
        {
            TLorentzVector v1, v2, v3;
            v1.SetPxPyPzE ((*El_px)[0], (*El_py)[0],
                           (*El_pz)[0], (*El_E)[0]);
            v2.SetPxPyPzE ((*El_px)[1], (*El_py)[1],
                           (*El_pz)[1], (*El_E)[1]);

            v3 = v1 + v2;
            z_mass->Fill(v3.M() / 1000);
        }

    }

    TFile f ("histogramm.root", "new");
    f.cd();
    z_mass->Write();
}
