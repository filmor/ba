#include "Analyse.hpp"

namespace ba
{
    Analyse::~Analyse()
    {
    }

    Long64_t Analyse::LoadTree(Long64_t entry)
    {
        // Set the environment to read one entry
        if (!fChain) return -5;
        Long64_t centry = fChain->LoadTree(entry);
        if (centry < 0) return centry;
        if (!fChain->InheritsFrom(TChain::Class()))  return centry;
        TChain *chain = (TChain*)fChain;
        if (chain->GetTreeNumber() != fCurrent) {
            fCurrent = chain->GetTreeNumber();
        }
        return centry;
    }

    Analyse::Analyse(TTree *tree)
    {
        // Set object pointer
        El_E = 0;
        El_p_T = 0;
        El_phi = 0;
        El_eta = 0;
        El_px = 0;
        El_py = 0;
        El_pz = 0;
        El_m = 0;
        El_charge = 0;
        El_pdgId = 0;
        El_EtaCorrMag = 0;
        El_EoverP = 0;
        El_deltaEta1 = 0;
        El_deltaEta2 = 0;
        El_deltaPhi2 = 0;
        El_etcone20 = 0;
        El_T_El_DeltaR = 0;
        Mu_E = 0;
        Mu_p_T = 0;
        Mu_phi = 0;
        Mu_eta = 0;
        Mu_px = 0;
        Mu_py = 0;
        Mu_pz = 0;
        Mu_m = 0;
        Mu_charge = 0;
        Mu_pdgId = 0;
        Mu_etcone40 = 0;
        Mu_nucone40 = 0;
        Mu_etcone20 = 0;
        Mu_matchChi2 = 0;
        Mu_matchChi2OverDoF = 0;
        Mu_SumTrkPtInCone = 0;
        Mu_T_Mu_DeltaR = 0;
        JetC4T_E = 0;
        JetC4T_p_T = 0;
        JetC4T_phi = 0;
        JetC4T_eta = 0;
        JetC4T_px = 0;
        JetC4T_py = 0;
        JetC4T_pz = 0;
        JetC4T_m = 0;
        JetC4T_charge = 0;
        JetC4T_pdgId = 0;
        JetC4T_weight = 0;
        JetC4T_SoftMuonWeight = 0;
        JetC4T_SoftElectronWeight = 0;
        JetC4T_IP1D = 0;
        JetC4T_IP2D = 0;
        JetC4T_IP3D = 0;
        JetC4T_SV1 = 0;
        JetC4T_SecVtxTagBU = 0;
        JetC4T_SV2 = 0;
        JetC4T_T_Jet_DeltaR = 0;
        JetC4T_T_El_DeltaR = 0;
        JetC4T_T_Ph_DeltaR = 0;
        Trk_E = 0;
        Trk_p_T = 0;
        Trk_phi = 0;
        Trk_eta = 0;
        Trk_px = 0;
        Trk_py = 0;
        Trk_pz = 0;
        Trk_m = 0;
        Trk_charge = 0;
        Trk_pdgId = 0;
        T_Mu_E = 0;
        T_Mu_p_T = 0;
        T_Mu_phi = 0;
        T_Mu_eta = 0;
        T_Mu_px = 0;
        T_Mu_py = 0;
        T_Mu_pz = 0;
        T_Mu_m = 0;
        T_Mu_charge = 0;
        T_Mu_pdgId = 0;
        T_El_E = 0;
        T_El_p_T = 0;
        T_El_phi = 0;
        T_El_eta = 0;
        T_El_px = 0;
        T_El_py = 0;
        T_El_pz = 0;
        T_El_m = 0;
        T_El_charge = 0;
        T_El_pdgId = 0;
        T_JetC4_E = 0;
        T_JetC4_p_T = 0;
        T_JetC4_phi = 0;
        T_JetC4_eta = 0;
        T_JetC4_px = 0;
        T_JetC4_py = 0;
        T_JetC4_pz = 0;
        T_JetC4_m = 0;
        T_JetC4_charge = 0;
        T_JetC4_pdgId = 0;
        T_JetC4_T_El_DeltaR = 0;
        T_JetC4_T_Mu_DeltaR = 0;
        T_JetC4_T_Ph_DeltaR = 0;
        T_JetC4_T_Jet_DeltaR = 0;
        El_IsEM = 0;
        El_author = 0;
        El_T_El_Matched = 0;
        Mu_author = 0;
        Mu_hasCluster = 0;
        Mu_hasCombinedMuon = 0;
        Mu_nTrkInCone = 0;
        Mu_T_Mu_Matched = 0;
        JetC4T_SoftMuonNumTrack = 0;
        JetC4T_SoftElectronNumTrack = 0;
        JetC4T_T_Jet_Matched = 0;
        JetC4T_T_El_Matched = 0;
        JetC4T_T_Ph_Matched = 0;
        T_Mu_nParents = 0;
        T_Mu_nDecay = 0;
        T_El_nParents = 0;
        T_El_nDecay = 0;
        T_JetC4_T_El_Matched = 0;
        T_JetC4_T_Mu_Matched = 0;
        T_JetC4_T_Ph_Matched = 0;
        T_JetC4_T_Jet_Matched = 0;
        T_El_ParentIDs = 0;
        T_Mu_ParentIDs = 0;
        T_Mu_ParentBarcodes = 0;
        T_Mu_ParentStatus = 0;
        T_Mu_ParentPt = 0;
        T_Mu_ParentEta = 0;
        T_Mu_DecayIDs = 0;
        T_Mu_DecayBarcodes = 0;
        T_Mu_DecayStatus = 0;
        T_Mu_DecayPt = 0;
        T_Mu_DecayEta = 0;
        T_El_DecayIDs = 0;
        T_El_ParentBarcodes = 0;
        T_El_DecayBarcodes = 0;
        T_El_ParentStatus = 0;
        T_El_DecayStatus = 0;
        T_El_DecayPt = 0;
        T_El_DecayEta = 0;
        T_El_ParentPt = 0;
        T_El_ParentEta = 0;
        // Set branch addresses and branch pointers
        fChain = tree;
        fCurrent = -1;

        fChain->SetBranchAddress("MET_RefFinal_ex", &MET_RefFinal_ex);
        fChain->SetBranchAddress("MET_RefFinal_ey", &MET_RefFinal_ey);
        fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et);
        fChain->SetBranchAddress("MET_RefFinal_sumet", &MET_RefFinal_sumet);
        fChain->SetBranchAddress("MET_RefEle_ex", &MET_RefEle_ex);
        fChain->SetBranchAddress("MET_RefEle_ey", &MET_RefEle_ey);
        fChain->SetBranchAddress("MET_RefEle_et", &MET_RefEle_et);
        fChain->SetBranchAddress("MET_RefEle_sumet", &MET_RefEle_sumet);
        fChain->SetBranchAddress("MET_RefMuon_ex", &MET_RefMuon_ex);
        fChain->SetBranchAddress("MET_RefMuon_ey", &MET_RefMuon_ey);
        fChain->SetBranchAddress("MET_RefMuon_et", &MET_RefMuon_et);
        fChain->SetBranchAddress("MET_RefMuon_sumet", &MET_RefMuon_sumet);
        fChain->SetBranchAddress("MET_RefJet_ex", &MET_RefJet_ex);
        fChain->SetBranchAddress("MET_RefJet_ey", &MET_RefJet_ey);
        fChain->SetBranchAddress("MET_RefJet_et", &MET_RefJet_et);
        fChain->SetBranchAddress("MET_RefJet_sumet", &MET_RefJet_sumet);
        fChain->SetBranchAddress("MET_RefGamma_ex", &MET_RefGamma_ex);
        fChain->SetBranchAddress("MET_RefGamma_ey", &MET_RefGamma_ey);
        fChain->SetBranchAddress("MET_RefGamma_et", &MET_RefGamma_et);
        fChain->SetBranchAddress("MET_RefGamma_sumet", &MET_RefGamma_sumet);
        fChain->SetBranchAddress("MET_CellOut_ex", &MET_CellOut_ex);
        fChain->SetBranchAddress("MET_CellOut_ey", &MET_CellOut_ey);
        fChain->SetBranchAddress("MET_CellOut_et", &MET_CellOut_et);
        fChain->SetBranchAddress("MET_CellOut_sumet", &MET_CellOut_sumet);
        fChain->SetBranchAddress("MET_MuonBoy_ex", &MET_MuonBoy_ex);
        fChain->SetBranchAddress("MET_MuonBoy_ey", &MET_MuonBoy_ey);
        fChain->SetBranchAddress("MET_MuonBoy_et", &MET_MuonBoy_et);
        fChain->SetBranchAddress("MET_MuonBoy_sumet", &MET_MuonBoy_sumet);
        fChain->SetBranchAddress("MET_CryoCone_ex", &MET_CryoCone_ex);
        fChain->SetBranchAddress("MET_CryoCone_ey", &MET_CryoCone_ey);
        fChain->SetBranchAddress("MET_CryoCone_et", &MET_CryoCone_et);
        fChain->SetBranchAddress("MET_CryoCone_sumet", &MET_CryoCone_sumet);
        fChain->SetBranchAddress("MET_LocHadTopoObj_ex", &MET_LocHadTopoObj_ex);
        fChain->SetBranchAddress("MET_LocHadTopoObj_ey", &MET_LocHadTopoObj_ey);
        fChain->SetBranchAddress("MET_LocHadTopoObj_et", &MET_LocHadTopoObj_et);
        fChain->SetBranchAddress("MET_LocHadTopoObj_sumet", &MET_LocHadTopoObj_sumet);
        fChain->SetBranchAddress("MET_LocHadTopo_ex", &MET_LocHadTopo_ex);
        fChain->SetBranchAddress("MET_LocHadTopo_ey", &MET_LocHadTopo_ey);
        fChain->SetBranchAddress("MET_LocHadTopo_et", &MET_LocHadTopo_et);
        fChain->SetBranchAddress("MET_LocHadTopo_sumet", &MET_LocHadTopo_sumet);
        fChain->SetBranchAddress("MET_Truth_Int_ex", &MET_Truth_Int_ex);
        fChain->SetBranchAddress("MET_Truth_Int_ey", &MET_Truth_Int_ey);
        fChain->SetBranchAddress("MET_Truth_Int_et", &MET_Truth_Int_et);
        fChain->SetBranchAddress("MET_Truth_Int_sumet", &MET_Truth_Int_sumet);
        fChain->SetBranchAddress("MET_Truth_NonInt_ex", &MET_Truth_NonInt_ex);
        fChain->SetBranchAddress("MET_Truth_NonInt_ey", &MET_Truth_NonInt_ey);
        fChain->SetBranchAddress("MET_Truth_NonInt_et", &MET_Truth_NonInt_et);
        fChain->SetBranchAddress("MET_Truth_NonInt_sumet", &MET_Truth_NonInt_sumet);
        fChain->SetBranchAddress("MET_Truth_IntCentral_ex", &MET_Truth_IntCentral_ex);
        fChain->SetBranchAddress("MET_Truth_IntCentral_ey", &MET_Truth_IntCentral_ey);
        fChain->SetBranchAddress("MET_Truth_IntCentral_et", &MET_Truth_IntCentral_et);
        fChain->SetBranchAddress("MET_Truth_IntCentral_sumet", &MET_Truth_IntCentral_sumet);
        fChain->SetBranchAddress("MET_Truth_IntFwd_ex", &MET_Truth_IntFwd_ex);
        fChain->SetBranchAddress("MET_Truth_IntFwd_ey", &MET_Truth_IntFwd_ey);
        fChain->SetBranchAddress("MET_Truth_IntFwd_et", &MET_Truth_IntFwd_et);
        fChain->SetBranchAddress("MET_Truth_IntFwd_sumet", &MET_Truth_IntFwd_sumet);
        fChain->SetBranchAddress("MET_Truth_IntOutCover_ex", &MET_Truth_IntOutCover_ex);
        fChain->SetBranchAddress("MET_Truth_IntOutCover_ey", &MET_Truth_IntOutCover_ey);
        fChain->SetBranchAddress("MET_Truth_IntOutCover_et", &MET_Truth_IntOutCover_et);
        fChain->SetBranchAddress("MET_Truth_IntOutCover_sumet", &MET_Truth_IntOutCover_sumet);
        fChain->SetBranchAddress("MET_Truth_Muons_ex", &MET_Truth_Muons_ex);
        fChain->SetBranchAddress("MET_Truth_Muons_ey", &MET_Truth_Muons_ey);
        fChain->SetBranchAddress("MET_Truth_Muons_et", &MET_Truth_Muons_et);
        fChain->SetBranchAddress("MET_Truth_Muons_sumet", &MET_Truth_Muons_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_Int_ex", &MET_Truth_PileUp_Int_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_Int_ey", &MET_Truth_PileUp_Int_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_Int_et", &MET_Truth_PileUp_Int_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_Int_sumet", &MET_Truth_PileUp_Int_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_ex", &MET_Truth_PileUp_NonInt_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_ey", &MET_Truth_PileUp_NonInt_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_et", &MET_Truth_PileUp_NonInt_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_sumet", &MET_Truth_PileUp_NonInt_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_ex", &MET_Truth_PileUp_IntCentral_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_ey", &MET_Truth_PileUp_IntCentral_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_et", &MET_Truth_PileUp_IntCentral_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_sumet", &MET_Truth_PileUp_IntCentral_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_ex", &MET_Truth_PileUp_IntFwd_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_ey", &MET_Truth_PileUp_IntFwd_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_et", &MET_Truth_PileUp_IntFwd_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_sumet", &MET_Truth_PileUp_IntFwd_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_ex", &MET_Truth_PileUp_IntOutCover_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_ey", &MET_Truth_PileUp_IntOutCover_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_et", &MET_Truth_PileUp_IntOutCover_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_sumet", &MET_Truth_PileUp_IntOutCover_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_Muons_ex", &MET_Truth_PileUp_Muons_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_Muons_ey", &MET_Truth_PileUp_Muons_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_Muons_et", &MET_Truth_PileUp_Muons_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_Muons_sumet", &MET_Truth_PileUp_Muons_sumet);
        fChain->SetBranchAddress("El_N", &El_N);
        fChain->SetBranchAddress("Mu_N", &Mu_N);
        fChain->SetBranchAddress("JetC4T_N", &JetC4T_N);
        fChain->SetBranchAddress("Trk_N", &Trk_N);
        fChain->SetBranchAddress("T_Mu_N", &T_Mu_N);
        fChain->SetBranchAddress("T_El_N", &T_El_N);
        fChain->SetBranchAddress("T_JetC4_N", &T_JetC4_N);
        fChain->SetBranchAddress("El_E", &El_E);
        fChain->SetBranchAddress("El_p_T", &El_p_T);
        fChain->SetBranchAddress("El_phi", &El_phi);
        fChain->SetBranchAddress("El_eta", &El_eta);
        fChain->SetBranchAddress("El_px", &El_px);
        fChain->SetBranchAddress("El_py", &El_py);
        fChain->SetBranchAddress("El_pz", &El_pz);
        fChain->SetBranchAddress("El_m", &El_m);
        fChain->SetBranchAddress("El_charge", &El_charge);
        fChain->SetBranchAddress("El_pdgId", &El_pdgId);
        fChain->SetBranchAddress("El_EtaCorrMag", &El_EtaCorrMag);
        fChain->SetBranchAddress("El_EoverP", &El_EoverP);
        fChain->SetBranchAddress("El_deltaEta1", &El_deltaEta1);
        fChain->SetBranchAddress("El_deltaEta2", &El_deltaEta2);
        fChain->SetBranchAddress("El_deltaPhi2", &El_deltaPhi2);
        fChain->SetBranchAddress("El_etcone20", &El_etcone20);
        fChain->SetBranchAddress("El_T_El_DeltaR", &El_T_El_DeltaR);
        fChain->SetBranchAddress("Mu_E", &Mu_E);
        fChain->SetBranchAddress("Mu_p_T", &Mu_p_T);
        fChain->SetBranchAddress("Mu_phi", &Mu_phi);
        fChain->SetBranchAddress("Mu_eta", &Mu_eta);
        fChain->SetBranchAddress("Mu_px", &Mu_px);
        fChain->SetBranchAddress("Mu_py", &Mu_py);
        fChain->SetBranchAddress("Mu_pz", &Mu_pz);
        fChain->SetBranchAddress("Mu_m", &Mu_m);
        fChain->SetBranchAddress("Mu_charge", &Mu_charge);
        fChain->SetBranchAddress("Mu_pdgId", &Mu_pdgId);
        fChain->SetBranchAddress("Mu_etcone40", &Mu_etcone40);
        fChain->SetBranchAddress("Mu_nucone40", &Mu_nucone40);
        fChain->SetBranchAddress("Mu_etcone20", &Mu_etcone20);
        fChain->SetBranchAddress("Mu_matchChi2", &Mu_matchChi2);
        fChain->SetBranchAddress("Mu_matchChi2OverDoF", &Mu_matchChi2OverDoF);
        fChain->SetBranchAddress("Mu_SumTrkPtInCone", &Mu_SumTrkPtInCone);
        fChain->SetBranchAddress("Mu_T_Mu_DeltaR", &Mu_T_Mu_DeltaR);
        fChain->SetBranchAddress("JetC4T_E", &JetC4T_E);
        fChain->SetBranchAddress("JetC4T_p_T", &JetC4T_p_T);
        fChain->SetBranchAddress("JetC4T_phi", &JetC4T_phi);
        fChain->SetBranchAddress("JetC4T_eta", &JetC4T_eta);
        fChain->SetBranchAddress("JetC4T_px", &JetC4T_px);
        fChain->SetBranchAddress("JetC4T_py", &JetC4T_py);
        fChain->SetBranchAddress("JetC4T_pz", &JetC4T_pz);
        fChain->SetBranchAddress("JetC4T_m", &JetC4T_m);
        fChain->SetBranchAddress("JetC4T_charge", &JetC4T_charge);
        fChain->SetBranchAddress("JetC4T_pdgId", &JetC4T_pdgId);
        fChain->SetBranchAddress("JetC4T_weight", &JetC4T_weight);
        fChain->SetBranchAddress("JetC4T_SoftMuonWeight", &JetC4T_SoftMuonWeight);
        fChain->SetBranchAddress("JetC4T_SoftElectronWeight", &JetC4T_SoftElectronWeight);
        fChain->SetBranchAddress("JetC4T_IP1D", &JetC4T_IP1D);
        fChain->SetBranchAddress("JetC4T_IP2D", &JetC4T_IP2D);
        fChain->SetBranchAddress("JetC4T_IP3D", &JetC4T_IP3D);
        fChain->SetBranchAddress("JetC4T_SV1", &JetC4T_SV1);
        fChain->SetBranchAddress("JetC4T_SecVtxTagBU", &JetC4T_SecVtxTagBU);
        fChain->SetBranchAddress("JetC4T_SV2", &JetC4T_SV2);
        fChain->SetBranchAddress("JetC4T_T_Jet_DeltaR", &JetC4T_T_Jet_DeltaR);
        fChain->SetBranchAddress("JetC4T_T_El_DeltaR", &JetC4T_T_El_DeltaR);
        fChain->SetBranchAddress("JetC4T_T_Ph_DeltaR", &JetC4T_T_Ph_DeltaR);
        fChain->SetBranchAddress("Trk_E", &Trk_E);
        fChain->SetBranchAddress("Trk_p_T", &Trk_p_T);
        fChain->SetBranchAddress("Trk_phi", &Trk_phi);
        fChain->SetBranchAddress("Trk_eta", &Trk_eta);
        fChain->SetBranchAddress("Trk_px", &Trk_px);
        fChain->SetBranchAddress("Trk_py", &Trk_py);
        fChain->SetBranchAddress("Trk_pz", &Trk_pz);
        fChain->SetBranchAddress("Trk_m", &Trk_m);
        fChain->SetBranchAddress("Trk_charge", &Trk_charge);
        fChain->SetBranchAddress("Trk_pdgId", &Trk_pdgId);
        fChain->SetBranchAddress("T_Mu_E", &T_Mu_E);
        fChain->SetBranchAddress("T_Mu_p_T", &T_Mu_p_T);
        fChain->SetBranchAddress("T_Mu_phi", &T_Mu_phi);
        fChain->SetBranchAddress("T_Mu_eta", &T_Mu_eta);
        fChain->SetBranchAddress("T_Mu_px", &T_Mu_px);
        fChain->SetBranchAddress("T_Mu_py", &T_Mu_py);
        fChain->SetBranchAddress("T_Mu_pz", &T_Mu_pz);
        fChain->SetBranchAddress("T_Mu_m", &T_Mu_m);
        fChain->SetBranchAddress("T_Mu_charge", &T_Mu_charge);
        fChain->SetBranchAddress("T_Mu_pdgId", &T_Mu_pdgId);
        fChain->SetBranchAddress("T_El_E", &T_El_E);
        fChain->SetBranchAddress("T_El_p_T", &T_El_p_T);
        fChain->SetBranchAddress("T_El_phi", &T_El_phi);
        fChain->SetBranchAddress("T_El_eta", &T_El_eta);
        fChain->SetBranchAddress("T_El_px", &T_El_px);
        fChain->SetBranchAddress("T_El_py", &T_El_py);
        fChain->SetBranchAddress("T_El_pz", &T_El_pz);
        fChain->SetBranchAddress("T_El_m", &T_El_m);
        fChain->SetBranchAddress("T_El_charge", &T_El_charge);
        fChain->SetBranchAddress("T_El_pdgId", &T_El_pdgId);
        fChain->SetBranchAddress("T_JetC4_E", &T_JetC4_E);
        fChain->SetBranchAddress("T_JetC4_p_T", &T_JetC4_p_T);
        fChain->SetBranchAddress("T_JetC4_phi", &T_JetC4_phi);
        fChain->SetBranchAddress("T_JetC4_eta", &T_JetC4_eta);
        fChain->SetBranchAddress("T_JetC4_px", &T_JetC4_px);
        fChain->SetBranchAddress("T_JetC4_py", &T_JetC4_py);
        fChain->SetBranchAddress("T_JetC4_pz", &T_JetC4_pz);
        fChain->SetBranchAddress("T_JetC4_m", &T_JetC4_m);
        fChain->SetBranchAddress("T_JetC4_charge", &T_JetC4_charge);
        fChain->SetBranchAddress("T_JetC4_pdgId", &T_JetC4_pdgId);
        fChain->SetBranchAddress("T_JetC4_T_El_DeltaR", &T_JetC4_T_El_DeltaR);
        fChain->SetBranchAddress("T_JetC4_T_Mu_DeltaR", &T_JetC4_T_Mu_DeltaR);
        fChain->SetBranchAddress("T_JetC4_T_Ph_DeltaR", &T_JetC4_T_Ph_DeltaR);
        fChain->SetBranchAddress("T_JetC4_T_Jet_DeltaR", &T_JetC4_T_Jet_DeltaR);
        fChain->SetBranchAddress("El_IsEM", &El_IsEM);
        fChain->SetBranchAddress("El_author", &El_author);
        fChain->SetBranchAddress("El_T_El_Matched", &El_T_El_Matched);
        fChain->SetBranchAddress("Mu_author", &Mu_author);
        fChain->SetBranchAddress("Mu_hasCluster", &Mu_hasCluster);
        fChain->SetBranchAddress("Mu_hasCombinedMuon", &Mu_hasCombinedMuon);
        fChain->SetBranchAddress("Mu_nTrkInCone", &Mu_nTrkInCone);
        fChain->SetBranchAddress("Mu_T_Mu_Matched", &Mu_T_Mu_Matched);
        fChain->SetBranchAddress("JetC4T_SoftMuonNumTrack", &JetC4T_SoftMuonNumTrack);
        fChain->SetBranchAddress("JetC4T_SoftElectronNumTrack", &JetC4T_SoftElectronNumTrack);
        fChain->SetBranchAddress("JetC4T_T_Jet_Matched", &JetC4T_T_Jet_Matched);
        fChain->SetBranchAddress("JetC4T_T_El_Matched", &JetC4T_T_El_Matched);
        fChain->SetBranchAddress("JetC4T_T_Ph_Matched", &JetC4T_T_Ph_Matched);
#ifdef BA_TRUTH_VARIABLES
        fChain->SetBranchAddress("T_Mu_nParents", &T_Mu_nParents);
        fChain->SetBranchAddress("T_Mu_nDecay", &T_Mu_nDecay);
        fChain->SetBranchAddress("T_El_nParents", &T_El_nParents);
        fChain->SetBranchAddress("T_El_nDecay", &T_El_nDecay);
        fChain->SetBranchAddress("T_JetC4_T_El_Matched", &T_JetC4_T_El_Matched);
        fChain->SetBranchAddress("T_JetC4_T_Mu_Matched", &T_JetC4_T_Mu_Matched);
        fChain->SetBranchAddress("T_JetC4_T_Ph_Matched", &T_JetC4_T_Ph_Matched);
        fChain->SetBranchAddress("T_JetC4_T_Jet_Matched", &T_JetC4_T_Jet_Matched);
        fChain->SetBranchAddress("T_El_ParentIDs", &T_El_ParentIDs);
        fChain->SetBranchAddress("T_Mu_ParentIDs", &T_Mu_ParentIDs);
        fChain->SetBranchAddress("T_Mu_ParentBarcodes", &T_Mu_ParentBarcodes);
        fChain->SetBranchAddress("T_Mu_ParentStatus", &T_Mu_ParentStatus);
        fChain->SetBranchAddress("T_Mu_ParentPt", &T_Mu_ParentPt);
        fChain->SetBranchAddress("T_Mu_ParentEta", &T_Mu_ParentEta);
        fChain->SetBranchAddress("T_Mu_DecayIDs", &T_Mu_DecayIDs);
        fChain->SetBranchAddress("T_Mu_DecayBarcodes", &T_Mu_DecayBarcodes);
        fChain->SetBranchAddress("T_Mu_DecayStatus", &T_Mu_DecayStatus);
        fChain->SetBranchAddress("T_Mu_DecayPt", &T_Mu_DecayPt);
        fChain->SetBranchAddress("T_Mu_DecayEta", &T_Mu_DecayEta);
        fChain->SetBranchAddress("T_El_DecayIDs", &T_El_DecayIDs);
        fChain->SetBranchAddress("T_El_ParentBarcodes", &T_El_ParentBarcodes);
        fChain->SetBranchAddress("T_El_DecayBarcodes", &T_El_DecayBarcodes);
        fChain->SetBranchAddress("T_El_ParentStatus", &T_El_ParentStatus);
        fChain->SetBranchAddress("T_El_DecayStatus", &T_El_DecayStatus);
        fChain->SetBranchAddress("T_El_DecayPt", &T_El_DecayPt);
        fChain->SetBranchAddress("T_El_DecayEta", &T_El_DecayEta);
        fChain->SetBranchAddress("T_El_ParentPt", &T_El_ParentPt);
        fChain->SetBranchAddress("T_El_ParentEta", &T_El_ParentEta);
#endif
    }

}
