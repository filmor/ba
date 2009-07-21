#ifndef ANALYSE_HPP
#define ANALYSE_HPP

#include <root/TROOT.h>
#include <root/TChain.h>
#include <root/TFile.h>
#include <root/TLorentzVector.h>
#include <vector>
#include <set>

#include "particle.hpp"

namespace ba
{
    using std::vector;

    class Analyse
    {
    private:
        TTree          *fChain;   //!pointer to the analyzed TTree or TChain
        Int_t           fCurrent; //!current Tree number in a TChain

        // Declaration of leave types
        Double_t        MET_RefFinal_ex;
        Double_t        MET_RefFinal_ey;
        Double_t        MET_RefFinal_et;
        Double_t        MET_RefFinal_sumet;
        Double_t        MET_RefEle_ex;
        Double_t        MET_RefEle_ey;
        Double_t        MET_RefEle_et;
        Double_t        MET_RefEle_sumet;
        Double_t        MET_RefMuon_ex;
        Double_t        MET_RefMuon_ey;
        Double_t        MET_RefMuon_et;
        Double_t        MET_RefMuon_sumet;
        Double_t        MET_RefJet_ex;
        Double_t        MET_RefJet_ey;
        Double_t        MET_RefJet_et;
        Double_t        MET_RefJet_sumet;
        Double_t        MET_RefGamma_ex;
        Double_t        MET_RefGamma_ey;
        Double_t        MET_RefGamma_et;
        Double_t        MET_RefGamma_sumet;
        Double_t        MET_CellOut_ex;
        Double_t        MET_CellOut_ey;
        Double_t        MET_CellOut_et;
        Double_t        MET_CellOut_sumet;
        Double_t        MET_MuonBoy_ex;
        Double_t        MET_MuonBoy_ey;
        Double_t        MET_MuonBoy_et;
        Double_t        MET_MuonBoy_sumet;
        Double_t        MET_CryoCone_ex;
        Double_t        MET_CryoCone_ey;
        Double_t        MET_CryoCone_et;
        Double_t        MET_CryoCone_sumet;
        Double_t        MET_LocHadTopoObj_ex;
        Double_t        MET_LocHadTopoObj_ey;
        Double_t        MET_LocHadTopoObj_et;
        Double_t        MET_LocHadTopoObj_sumet;
        Double_t        MET_LocHadTopo_ex;
        Double_t        MET_LocHadTopo_ey;
        Double_t        MET_LocHadTopo_et;
        Double_t        MET_LocHadTopo_sumet;
        Double_t        MET_Truth_Int_ex;
        Double_t        MET_Truth_Int_ey;
        Double_t        MET_Truth_Int_et;
        Double_t        MET_Truth_Int_sumet;
        Double_t        MET_Truth_NonInt_ex;
        Double_t        MET_Truth_NonInt_ey;
        Double_t        MET_Truth_NonInt_et;
        Double_t        MET_Truth_NonInt_sumet;
        Double_t        MET_Truth_IntCentral_ex;
        Double_t        MET_Truth_IntCentral_ey;
        Double_t        MET_Truth_IntCentral_et;
        Double_t        MET_Truth_IntCentral_sumet;
        Double_t        MET_Truth_IntFwd_ex;
        Double_t        MET_Truth_IntFwd_ey;
        Double_t        MET_Truth_IntFwd_et;
        Double_t        MET_Truth_IntFwd_sumet;
        Double_t        MET_Truth_IntOutCover_ex;
        Double_t        MET_Truth_IntOutCover_ey;
        Double_t        MET_Truth_IntOutCover_et;
        Double_t        MET_Truth_IntOutCover_sumet;
        Double_t        MET_Truth_Muons_ex;
        Double_t        MET_Truth_Muons_ey;
        Double_t        MET_Truth_Muons_et;
        Double_t        MET_Truth_Muons_sumet;
        Double_t        MET_Truth_PileUp_Int_ex;
        Double_t        MET_Truth_PileUp_Int_ey;
        Double_t        MET_Truth_PileUp_Int_et;
        Double_t        MET_Truth_PileUp_Int_sumet;
        Double_t        MET_Truth_PileUp_NonInt_ex;
        Double_t        MET_Truth_PileUp_NonInt_ey;
        Double_t        MET_Truth_PileUp_NonInt_et;
        Double_t        MET_Truth_PileUp_NonInt_sumet;
        Double_t        MET_Truth_PileUp_IntCentral_ex;
        Double_t        MET_Truth_PileUp_IntCentral_ey;
        Double_t        MET_Truth_PileUp_IntCentral_et;
        Double_t        MET_Truth_PileUp_IntCentral_sumet;
        Double_t        MET_Truth_PileUp_IntFwd_ex;
        Double_t        MET_Truth_PileUp_IntFwd_ey;
        Double_t        MET_Truth_PileUp_IntFwd_et;
        Double_t        MET_Truth_PileUp_IntFwd_sumet;
        Double_t        MET_Truth_PileUp_IntOutCover_ex;
        Double_t        MET_Truth_PileUp_IntOutCover_ey;
        Double_t        MET_Truth_PileUp_IntOutCover_et;
        Double_t        MET_Truth_PileUp_IntOutCover_sumet;
        Double_t        MET_Truth_PileUp_Muons_ex;
        Double_t        MET_Truth_PileUp_Muons_ey;
        Double_t        MET_Truth_PileUp_Muons_et;
        Double_t        MET_Truth_PileUp_Muons_sumet;
        Int_t           El_N;
        Int_t           Mu_N;
        Int_t           JetC4T_N;
        Int_t           Trk_N;
        Int_t           T_Mu_N;
        Int_t           T_El_N;
        Int_t           T_JetC4_N;
        vector<double>  *El_E;
        vector<double>  *El_p_T;
        vector<double>  *El_phi;
        vector<double>  *El_eta;
        vector<double>  *El_px;
        vector<double>  *El_py;
        vector<double>  *El_pz;
        vector<double>  *El_m;
        vector<double>  *El_charge;
        vector<double>  *El_pdgId;
        vector<double>  *El_EtaCorrMag;
        vector<double>  *El_EoverP;
        vector<double>  *El_deltaEta1;
        vector<double>  *El_deltaEta2;
        vector<double>  *El_deltaPhi2;
        vector<double>  *El_etcone20;
        vector<double>  *El_T_El_DeltaR;
        vector<double>  *Mu_E;
        vector<double>  *Mu_p_T;
        vector<double>  *Mu_phi;
        vector<double>  *Mu_eta;
        vector<double>  *Mu_px;
        vector<double>  *Mu_py;
        vector<double>  *Mu_pz;
        vector<double>  *Mu_m;
        vector<double>  *Mu_charge;
        vector<double>  *Mu_pdgId;
        vector<double>  *Mu_etcone40;
        vector<double>  *Mu_nucone40;
        vector<double>  *Mu_etcone20;
        vector<double>  *Mu_matchChi2;
        vector<double>  *Mu_matchChi2OverDoF;
        vector<double>  *Mu_SumTrkPtInCone;
        vector<double>  *Mu_T_Mu_DeltaR;
        vector<double>  *JetC4T_E;
        vector<double>  *JetC4T_p_T;
        vector<double>  *JetC4T_phi;
        vector<double>  *JetC4T_eta;
        vector<double>  *JetC4T_px;
        vector<double>  *JetC4T_py;
        vector<double>  *JetC4T_pz;
        vector<double>  *JetC4T_m;
        vector<double>  *JetC4T_charge;
        vector<double>  *JetC4T_pdgId;
        vector<double>  *JetC4T_weight;
        vector<double>  *JetC4T_SoftMuonWeight;
        vector<double>  *JetC4T_SoftElectronWeight;
        vector<double>  *JetC4T_IP1D;
        vector<double>  *JetC4T_IP2D;
        vector<double>  *JetC4T_IP3D;
        vector<double>  *JetC4T_SV1;
        vector<double>  *JetC4T_SecVtxTagBU;
        vector<double>  *JetC4T_SV2;
        vector<double>  *JetC4T_T_Jet_DeltaR;
        vector<double>  *JetC4T_T_El_DeltaR;
        vector<double>  *JetC4T_T_Ph_DeltaR;
        vector<double>  *Trk_E;
        vector<double>  *Trk_p_T;
        vector<double>  *Trk_phi;
        vector<double>  *Trk_eta;
        vector<double>  *Trk_px;
        vector<double>  *Trk_py;
        vector<double>  *Trk_pz;
        vector<double>  *Trk_m;
        vector<double>  *Trk_charge;
        vector<double>  *Trk_pdgId;
        vector<double>  *T_Mu_E;
        vector<double>  *T_Mu_p_T;
        vector<double>  *T_Mu_phi;
        vector<double>  *T_Mu_eta;
        vector<double>  *T_Mu_px;
        vector<double>  *T_Mu_py;
        vector<double>  *T_Mu_pz;
        vector<double>  *T_Mu_m;
        vector<double>  *T_Mu_charge;
        vector<double>  *T_Mu_pdgId;
        vector<double>  *T_El_E;
        vector<double>  *T_El_p_T;
        vector<double>  *T_El_phi;
        vector<double>  *T_El_eta;
        vector<double>  *T_El_px;
        vector<double>  *T_El_py;
        vector<double>  *T_El_pz;
        vector<double>  *T_El_m;
        vector<double>  *T_El_charge;
        vector<double>  *T_El_pdgId;
        vector<double>  *T_JetC4_E;
        vector<double>  *T_JetC4_p_T;
        vector<double>  *T_JetC4_phi;
        vector<double>  *T_JetC4_eta;
        vector<double>  *T_JetC4_px;
        vector<double>  *T_JetC4_py;
        vector<double>  *T_JetC4_pz;
        vector<double>  *T_JetC4_m;
        vector<double>  *T_JetC4_charge;
        vector<double>  *T_JetC4_pdgId;
        vector<double>  *T_JetC4_T_El_DeltaR;
        vector<double>  *T_JetC4_T_Mu_DeltaR;
        vector<double>  *T_JetC4_T_Ph_DeltaR;
        vector<double>  *T_JetC4_T_Jet_DeltaR;
        vector<int>     *El_IsEM;
        vector<int>     *El_author;
        vector<int>     *El_T_El_Matched;
        vector<int>     *Mu_author;
        vector<int>     *Mu_hasCluster;
        vector<int>     *Mu_hasCombinedMuon;
        vector<int>     *Mu_nTrkInCone;
        vector<int>     *Mu_T_Mu_Matched;
        vector<int>     *JetC4T_SoftMuonNumTrack;
        vector<int>     *JetC4T_SoftElectronNumTrack;
        vector<int>     *JetC4T_T_Jet_Matched;
        vector<int>     *JetC4T_T_El_Matched;
        vector<int>     *JetC4T_T_Ph_Matched;
        vector<int>     *T_Mu_nParents;
        vector<int>     *T_Mu_nDecay;
        vector<int>     *T_El_nParents;
        vector<int>     *T_El_nDecay;
        vector<int>     *T_JetC4_T_El_Matched;
        vector<int>     *T_JetC4_T_Mu_Matched;
        vector<int>     *T_JetC4_T_Ph_Matched;
        vector<int>     *T_JetC4_T_Jet_Matched;
        vector<vector<int> > *T_El_ParentIDs;
        vector<vector<double> > *T_Mu_ParentIDs;
        vector<vector<double> > *T_Mu_ParentBarcodes;
        vector<vector<double> > *T_Mu_ParentStatus;
        vector<vector<double> > *T_Mu_ParentPt;
        vector<vector<double> > *T_Mu_ParentEta;
        vector<vector<double> > *T_Mu_DecayIDs;
        vector<vector<double> > *T_Mu_DecayBarcodes;
        vector<vector<double> > *T_Mu_DecayStatus;
        vector<vector<double> > *T_Mu_DecayPt;
        vector<vector<double> > *T_Mu_DecayEta;
        vector<vector<double> > *T_El_DecayIDs;
        vector<vector<double> > *T_El_ParentBarcodes;
        vector<vector<double> > *T_El_DecayBarcodes;
        vector<vector<double> > *T_El_ParentStatus;
        vector<vector<double> > *T_El_DecayStatus;
        vector<vector<double> > *T_El_DecayPt;
        vector<vector<double> > *T_El_DecayEta;
        vector<vector<double> > *T_El_ParentPt;
        vector<vector<double> > *T_El_ParentEta;

    public:
        Analyse(TTree* tree);
        ~Analyse();
        Int_t    Cut(Long64_t entry);
        std::size_t get_entry(std::size_t entry);
        Long64_t LoadTree(Long64_t entry);

        void     loop();

    private:
        bool good_lepton(charged_particle const&);

        typedef std::vector<charged_particle> particle_vector;

        particle_vector jets_, leptons_;

        TLorentzVector met_;
    };
}

#endif
