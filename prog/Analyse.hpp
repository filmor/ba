#ifndef ANALYSE_HPP
#define ANALYSE_HPP

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <vector>

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
        Double_t        MET_RefTau_ex;
        Double_t        MET_RefTau_ey;
        Double_t        MET_RefTau_et;
        Double_t        MET_RefTau_sumet;
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
        Int_t           PassedTrigger;
        Int_t           PassedL1;
        Int_t           PassedL2;
        Int_t           PassedEF;
        Int_t           Passed;
        Int_t           PassedL1_EM3;
        Int_t           PassedL1_EM7;
        Int_t           PassedL1_2TAU6_TAU25;
        Int_t           PassedL1_EM13;
        Int_t           PassedL1_EM13I;
        Int_t           PassedL1_EM18;
        Int_t           PassedL1_EM18I;
        Int_t           PassedL1_EM23I;
        Int_t           PassedL1_EM100;
        Int_t           PassedL1_TAU25I_XE20;
        Int_t           PassedL1_2EM3;
        Int_t           PassedL1_2EM7;
        Int_t           PassedL1_TAU25_XE40;
        Int_t           PassedL1_2EM13;
        Int_t           PassedL1_2EM13I;
        Int_t           PassedL1_2EM18;
        Int_t           PassedL1_2EM18I;
        Int_t           PassedL1_2EM23I;
        Int_t           PassedL1_2EM3_EM7;
        Int_t           PassedL1_3EM7;
        Int_t           PassedL1_RD0_FILLED;
        Int_t           PassedL1_MU4;
        Int_t           PassedL1_MU6;
        Int_t           PassedL1_MU10;
        Int_t           PassedL1_MU11;
        Int_t           PassedL1_MU20;
        Int_t           PassedL1_MU40;
        Int_t           PassedL1_2MU4;
        Int_t           PassedL1_2MU6;
        Int_t           PassedL1_2MU10;
        Int_t           PassedL1_2MU11;
        Int_t           PassedL1_2MU20;
        Int_t           PassedL1_3MU6;
        Int_t           PassedL1_2MU4_MU6;
        Int_t           PassedL1_TAU5;
        Int_t           PassedL1_TAU6;
        Int_t           PassedL1_TAU9I;
        Int_t           PassedL1_TAU11I;
        Int_t           PassedL1_TAU16I;
        Int_t           PassedL1_TAU25;
        Int_t           PassedL1_TAU25I;
        Int_t           PassedL1_TAU40;
        Int_t           PassedL1_2TAU6;
        Int_t           PassedL1_2TAU9I;
        Int_t           PassedL1_2TAU6_TAU16I;
        Int_t           PassedL1_2TAU16I;
        Int_t           PassedL1_J5;
        Int_t           PassedL1_J10;
        Int_t           PassedL1_J18;
        Int_t           PassedL1_J23;
        Int_t           PassedL1_J35;
        Int_t           PassedL1_J42;
        Int_t           PassedL1_J70;
        Int_t           PassedL1_J120;
        Int_t           PassedL1_4J10;
        Int_t           PassedL1_3J18;
        Int_t           PassedL1_3J23;
        Int_t           PassedL1_4J18;
        Int_t           PassedL1_4J23;
        Int_t           PassedL1_4J35;
        Int_t           PassedL1_3J70;
        Int_t           PassedL1_FJ18;
        Int_t           PassedL1_FJ35;
        Int_t           PassedL1_FJ70;
        Int_t           PassedL1_FJ120;
        Int_t           PassedL1_2FJ18;
        Int_t           PassedL1_2FJ35;
        Int_t           PassedL1_2FJ70;
        Int_t           PassedL1_3J10;
        Int_t           PassedL1_XE15;
        Int_t           PassedL1_XE20;
        Int_t           PassedL1_XE25;
        Int_t           PassedL1_XE30;
        Int_t           PassedL1_XE40;
        Int_t           PassedL1_XE50;
        Int_t           PassedL1_XE70;
        Int_t           PassedL1_XE80;
        Int_t           PassedL1_TE150;
        Int_t           PassedL1_TE250;
        Int_t           PassedL1_TE360;
        Int_t           PassedL1_TE650;
        Int_t           PassedL1_JE120;
        Int_t           PassedL1_JE220;
        Int_t           PassedL1_JE280;
        Int_t           PassedL1_JE340;
        Int_t           PassedL1_EM13_XE20;
        Int_t           PassedL1_EM18_XE15;
        Int_t           PassedL1_2EM7_MU6;
        Int_t           PassedL1_2EM13_MU6;
        Int_t           PassedL1_2EM18_MU6;
        Int_t           PassedL1_EM7_MU6;
        Int_t           PassedL1_EM7_XE30;
        Int_t           PassedL1_2EM3_TAU6;
        Int_t           PassedL1_EM18_XE30;
        Int_t           PassedL1_EM13_MU11;
        Int_t           PassedL1_EM13I_MU11;
        Int_t           PassedL1_2TAU6_EM7;
        Int_t           PassedL1_2TAU6_TAU9I_EM7;
        Int_t           PassedL1_2TAU6_TAU11I_EM7;
        Int_t           PassedL1_2TAU9I_EM13I;
        Int_t           PassedL1_MU11_XE15;
        Int_t           PassedL1_MU4_J5;
        Int_t           PassedL1_MU4_J10;
        Int_t           PassedL1_MU4_J18;
        Int_t           PassedL1_MU4_J23;
        Int_t           PassedL1_MU4_J35;
        Int_t           PassedL1_MU4_J42;
        Int_t           PassedL1_MU4_EM3;
        Int_t           PassedL1_MU6_J5;
        Int_t           PassedL1_MU6_EM3;
        Int_t           PassedL1_2MU6_EM7;
        Int_t           PassedL1_MU20_XE30;
        Int_t           PassedL1_MU10_J18;
        Int_t           PassedL1_TAU9I_MU6;
        Int_t           PassedL1_TAU9I_MU10;
        Int_t           PassedL1_TAU11I_MU6;
        Int_t           PassedL1_TAU11I_MU10;
        Int_t           PassedL1_TAU11I_MU20;
        Int_t           PassedL1_J70_XE30;
        Int_t           PassedL1_2J42_XE30;
        Int_t           PassedL1_J42_XE30_EM13I;
        Int_t           PassedL1_J42_XE30_MU11;
        Int_t           PassedL1_4J23_EM13I;
        Int_t           PassedL1_4J23_MU11;
        Int_t           PassedL1_TAU6_XE20;
        Int_t           PassedL1_TAU9I_XE20;
        Int_t           PassedL1_TAU9I_XE30;
        Int_t           PassedL1_TAU9I_XE40;
        Int_t           PassedL1_TAU11I_XE30;
        Int_t           PassedL1_TAU16I_XE20;
        Int_t           PassedL1_TAU16I_XE30;
        Int_t           PassedL1_TAU16I_XE40;
        Int_t           PassedL1_2TAU11I_EM23I;
        Int_t           PassedL1_TAU9I_2J5_J35;
        Int_t           PassedL1_TAU11I_2J5_J18;
        Int_t           PassedL1_TAU11I_2J5_J35;
        Int_t           PassedL1_TAU9I_5J5_4J23;
        Int_t           PassedL1_TAU9I_3J5_2J23;
        Int_t           PassedL1_TAU11I_3J5_2J23;
        Int_t           PassedL1_TAU6_2J5_J35;
        Int_t           PassedL1_TAU6_3J5_J42;
        Int_t           PassedL1_TAU6_3J5_2J42_XE30;
        Int_t           PassedL1_MBTS_1;
        Int_t           PassedL1_MBTS_2;
        Int_t           PassedL1_MBTS_1_1;
        Int_t           PassedL2_te650;
        Int_t           PassedL2_g25_xe30;
        Int_t           PassedL2_mu4_j10_matched;
        Int_t           PassedL2_e10_mu6;
        Int_t           PassedL2_MU4_Upsimumu_FS;
        Int_t           PassedL2_g20_xe15;
        Int_t           PassedL2_tau16i_j70_WO;
        Int_t           PassedL2_tau12_loose;
        Int_t           PassedL2_tau38i_loose;
        Int_t           PassedL2_tau12_PT;
        Int_t           PassedL2_e6_medium1;
        Int_t           PassedL2_mu4_mu6;
        Int_t           PassedL2_JE280;
        Int_t           PassedL2_b23;
        Int_t           PassedL2_tau12_xe20;
        Int_t           PassedL2_j42_xe30_mu15;
        Int_t           PassedL2_mu4_j10;
        Int_t           PassedL2_g25;
        Int_t           PassedL2_g20;
        Int_t           PassedL2_tauNoCut;
        Int_t           PassedL2_tau16i_j70;
        Int_t           PassedL2_tau12_tau38;
        Int_t           PassedL2_e15_medium;
        Int_t           PassedL2_FJ70;
        Int_t           PassedL2_mu4_j18_matched;
        Int_t           PassedL2_tau12_tau29i_PT;
        Int_t           PassedL2_4J50;
        Int_t           PassedL2_xe80;
        Int_t           PassedL2_e12_medium;
        Int_t           PassedL2_tau16i_4j23_WO;
        Int_t           PassedL2_tau20i_e10;
        Int_t           PassedL2_tau29i_loose;
        Int_t           PassedL2_e105_loose1;
        Int_t           PassedL2_e20_loose_passEF;
        Int_t           PassedL2_e7_medium;
        Int_t           PassedL2_e15i_medium;
        Int_t           PassedL2_tau16i_mu10;
        Int_t           PassedL2_3g10;
        Int_t           PassedL2_tau16i_loose;
        Int_t           PassedL2_tau16i_4j23;
        Int_t           PassedL2_2g10_mu6;
        Int_t           PassedL2_2tau20i;
        Int_t           PassedL2_MbRndm;
        Int_t           PassedL2_g25i;
        Int_t           PassedL2_2MU4_Upsimumu;
        Int_t           PassedL2_tau20i_e15i;
        Int_t           PassedL2_3J120;
        Int_t           PassedL2_b70;
        Int_t           PassedL2_4j23_e15i;
        Int_t           PassedL2_tau50_loose;
        Int_t           PassedL2_tau38i_xe20;
        Int_t           PassedL2_g10_calib;
        Int_t           PassedL2_g15;
        Int_t           PassedL2_g10;
        Int_t           PassedL2_e20_xe15;
        Int_t           PassedL2_J150;
        Int_t           PassedL2_e6_medium;
        Int_t           PassedL2_xe20;
        Int_t           PassedL2_xe25;
        Int_t           PassedL2_mu15i_loose;
        Int_t           PassedL2_2e6_medium1;
        Int_t           PassedL2_mu4_j23_matched;
        Int_t           PassedL2_tau16i_xe30;
        Int_t           PassedL2_MU4_Bmumu_FS;
        Int_t           PassedL2_2MU4_DiMu;
        Int_t           PassedL2_MU4_Jpsie5e3_FS;
        Int_t           PassedL2_3mu6;
        Int_t           PassedL2_tau16i_2j70;
        Int_t           PassedL2_tau20i_mu6;
        Int_t           PassedL2_FJ120;
        Int_t           PassedL2_2g17i_tight;
        Int_t           PassedL2_mu20_xe30;
        Int_t           PassedL2_e5_medium;
        Int_t           PassedL2_tau20i_2b23;
        Int_t           PassedL2_2e6_medium;
        Int_t           PassedL2_tau16i_e10;
        Int_t           PassedL2_b35;
        Int_t           PassedL2_e10_xe30;
        Int_t           PassedL2_g20i_calib;
        Int_t           PassedL2_e5_e10_medium;
        Int_t           PassedL2_tau29i_xe20;
        Int_t           PassedL2_4j23_mu15;
        Int_t           PassedL2_trk16i_calib;
        Int_t           PassedL2_tau16i_j120;
        Int_t           PassedL2_2mu10;
        Int_t           PassedL2_3b18_4L1J18_passHLT;
        Int_t           PassedL2_mu40;
        Int_t           PassedL2_j70_xe30;
        Int_t           PassedL2_2g20;
        Int_t           PassedL2_J50;
        Int_t           PassedL2_e55_loose1;
        Int_t           PassedL2_tau20i_j120;
        Int_t           PassedL2_mu4_trod;
        Int_t           PassedL2_tau125_loose;
        Int_t           PassedL2_xe50;
        Int_t           PassedL2_tau16i_mu6;
        Int_t           PassedL2_tau12_b23_j42;
        Int_t           PassedL2_FJ18;
        Int_t           PassedL2_tau20i_e25i;
        Int_t           PassedL2_2j42_xe30;
        Int_t           PassedL2_mu4_tile;
        Int_t           PassedL2_2e5_medium1;
        Int_t           PassedL2_e5_e7_medium;
        Int_t           PassedL2_e20_g20;
        Int_t           PassedL2_tau20i_b18;
        Int_t           PassedL2_Zee;
        Int_t           PassedL2_JE340;
        Int_t           PassedL2_b42;
        Int_t           PassedL2_g3_nocut;
        Int_t           PassedL2_mu4_j42_matched;
        Int_t           PassedL2_te150;
        Int_t           PassedL2_2tau12;
        Int_t           PassedL2_te250;
        Int_t           PassedL2_4J80;
        Int_t           PassedL2_3J35;
        Int_t           PassedL2_tau12_e10;
        Int_t           PassedL2_e5_medium1;
        Int_t           PassedL2_J205;
        Int_t           PassedL2_e20_loose_passL2;
        Int_t           PassedL2_em20_passHLT;
        Int_t           PassedL2_2e15_medium;
        Int_t           PassedL2_2b23_3L1J23_passHLT;
        Int_t           PassedL2_xe15;
        Int_t           PassedL2_2FJ70;
        Int_t           PassedL2_2FJ18;
        Int_t           PassedL2_g105;
        Int_t           PassedL2_tau84_loose;
        Int_t           PassedL2_2e10_mu6;
        Int_t           PassedL2_mu4;
        Int_t           PassedL2_mu6;
        Int_t           PassedL2_MU4_Jpsimumu_FS;
        Int_t           PassedL2_e22i_tight;
        Int_t           PassedL2_em20i_passHLT;
        Int_t           PassedL2_g55_tight;
        Int_t           PassedL2_2mu6_g10;
        Int_t           PassedL2_tau20i_mu10;
        Int_t           PassedL2_J110;
        Int_t           PassedL2_e10_medium;
        Int_t           PassedL2_2tau20i_PT;
        Int_t           PassedL2_J60;
        Int_t           PassedL2_j42_xe30_e15i;
        Int_t           PassedL2_mu20_passHLT;
        Int_t           PassedL2_2mu6_e10;
        Int_t           PassedL2_MbSp;
        Int_t           PassedL2_g20i;
        Int_t           PassedL2_em105_passHLT;
        Int_t           PassedL2_2mu20;
        Int_t           PassedL2_2g10;
        Int_t           PassedL2_2g15;
        Int_t           PassedL2_tau16i_e15i;
        Int_t           PassedL2_e20i_loose;
        Int_t           PassedL2_e20_loose;
        Int_t           PassedL2_2e5_medium;
        Int_t           PassedL2_tau29i_xe30;
        Int_t           PassedL2_3b18_4L1J18;
        Int_t           PassedL2_xe40;
        Int_t           PassedL2_te360;
        Int_t           PassedL2_tau16i_2j23;
        Int_t           PassedL2_2FJ35;
        Int_t           PassedL2_4J15;
        Int_t           PassedL2_tau20i_j70;
        Int_t           PassedL2_tau12_b35;
        Int_t           PassedL2_trk9i_calib;
        Int_t           PassedL2_e25i_medium1;
        Int_t           PassedL2_2mu4;
        Int_t           PassedL2_mu20i_loose;
        Int_t           PassedL2_2mu6;
        Int_t           PassedL2_mu4_DsPhiPi_FS;
        Int_t           PassedL2_2tau29i;
        Int_t           PassedL2_mu10_j18;
        Int_t           PassedL2_g150;
        Int_t           PassedL2_mu10;
        Int_t           PassedL2_mu15;
        Int_t           PassedL2_g15i;
        Int_t           PassedL2_tau38_xe40;
        Int_t           PassedL2_tau20i_mu20;
        Int_t           PassedL2_J23;
        Int_t           PassedL2_2MU4_Jpsimumu;
        Int_t           PassedL2_tau38_loose;
        Int_t           PassedL2_J80;
        Int_t           PassedL2_JE120;
        Int_t           PassedL2_2e10_loose;
        Int_t           PassedL2_mu15_xe15;
        Int_t           PassedL2_2e20_loose;
        Int_t           PassedL2_4J35;
        Int_t           PassedL2_xe70;
        Int_t           PassedL2_mu4_j35_matched;
        Int_t           PassedL2_e15_xe20;
        Int_t           PassedL2_e20_xe30;
        Int_t           PassedL2_tau20i_xe30;
        Int_t           PassedL2_3e15_medium;
        Int_t           PassedL2_e25i_loose;
        Int_t           PassedL2_MbSpTrk;
        Int_t           PassedL2_tau29i_xe40;
        Int_t           PassedL2_tau20i_b35;
        Int_t           PassedL2_J10;
        Int_t           PassedL2_JE220;
        Int_t           PassedL2_tau16i_3j23;
        Int_t           PassedL2_e25_loose;
        Int_t           PassedL2_mu20;
        Int_t           PassedL2_2e12_tight;
        Int_t           PassedL2_3b23_3L1J23;
        Int_t           PassedL2_3J15;
        Int_t           PassedL2_b18;
        Int_t           PassedL2_FJ35;
        Int_t           PassedL2_stau;
        Int_t           PassedL2_xe30;
        Int_t           PassedL2_Jpsiee;
        Int_t           PassedL2_tau12_tau29i;
        Int_t           PassedL2_tau20i_loose;
        Int_t           PassedEF_te650;
        Int_t           PassedEF_g25_xe30;
        Int_t           PassedEF_mu4_j10_matched;
        Int_t           PassedEF_e10_mu6;
        Int_t           PassedEF_MU4_Upsimumu_FS;
        Int_t           PassedEF_g20_xe15;
        Int_t           PassedEF_tau16i_j70_WO;
        Int_t           PassedEF_tau12_loose;
        Int_t           PassedEF_tau38i_loose;
        Int_t           PassedEF_tau12_PT;
        Int_t           PassedEF_e6_medium1;
        Int_t           PassedEF_mu4_mu6;
        Int_t           PassedEF_JE280;
        Int_t           PassedEF_b23;
        Int_t           PassedEF_tau12_xe20;
        Int_t           PassedEF_j42_xe30_mu15;
        Int_t           PassedEF_mu4_j10;
        Int_t           PassedEF_g25;
        Int_t           PassedEF_g20;
        Int_t           PassedEF_tauNoCut;
        Int_t           PassedEF_tau16i_j70;
        Int_t           PassedEF_tau12_tau38;
        Int_t           PassedEF_e15_medium;
        Int_t           PassedEF_FJ70;
        Int_t           PassedEF_mu4_j18_matched;
        Int_t           PassedEF_tau12_tau29i_PT;
        Int_t           PassedEF_4J95;
        Int_t           PassedEF_xe80;
        Int_t           PassedEF_e12_medium;
        Int_t           PassedEF_tau16i_4j23_WO;
        Int_t           PassedEF_tau20i_e10;
        Int_t           PassedEF_tau29i_loose;
        Int_t           PassedEF_e105_loose1;
        Int_t           PassedEF_e20_loose_passEF;
        Int_t           PassedEF_e7_medium;
        Int_t           PassedEF_e15i_medium;
        Int_t           PassedEF_tau16i_mu10;
        Int_t           PassedEF_3g10;
        Int_t           PassedEF_tau16i_loose;
        Int_t           PassedEF_tau16i_4j23;
        Int_t           PassedEF_2g10_mu6;
        Int_t           PassedEF_2tau20i;
        Int_t           PassedEF_MbRndm;
        Int_t           PassedEF_g25i;
        Int_t           PassedEF_2MU4_Upsimumu;
        Int_t           PassedEF_tau20i_e15i;
        Int_t           PassedEF_3J180;
        Int_t           PassedEF_b70;
        Int_t           PassedEF_4j23_e15i;
        Int_t           PassedEF_tau50_loose;
        Int_t           PassedEF_tau38i_xe20;
        Int_t           PassedEF_g10_calib;
        Int_t           PassedEF_g15;
        Int_t           PassedEF_g10;
        Int_t           PassedEF_e20_xe15;
        Int_t           PassedEF_J265;
        Int_t           PassedEF_e6_medium;
        Int_t           PassedEF_xe20;
        Int_t           PassedEF_xe25;
        Int_t           PassedEF_mu15i_loose;
        Int_t           PassedEF_2e6_medium1;
        Int_t           PassedEF_mu4_j23_matched;
        Int_t           PassedEF_tau16i_xe30;
        Int_t           PassedEF_MU4_Bmumu_FS;
        Int_t           PassedEF_2MU4_DiMu;
        Int_t           PassedEF_MU4_Jpsie5e3_FS;
        Int_t           PassedEF_3mu6;
        Int_t           PassedEF_tau16i_2j70;
        Int_t           PassedEF_tau20i_mu6;
        Int_t           PassedEF_FJ120;
        Int_t           PassedEF_2g17i_tight;
        Int_t           PassedEF_mu20_xe30;
        Int_t           PassedEF_e5_medium;
        Int_t           PassedEF_tau20i_2b23;
        Int_t           PassedEF_2e6_medium;
        Int_t           PassedEF_tau16i_e10;
        Int_t           PassedEF_b35;
        Int_t           PassedEF_e10_xe30;
        Int_t           PassedEF_g20i_calib;
        Int_t           PassedEF_e5_e10_medium;
        Int_t           PassedEF_tau29i_xe20;
        Int_t           PassedEF_4j23_mu15;
        Int_t           PassedEF_tau16i_j120;
        Int_t           PassedEF_2mu10;
        Int_t           PassedEF_3b18_4L1J18_passHLT;
        Int_t           PassedEF_mu40;
        Int_t           PassedEF_j70_xe30;
        Int_t           PassedEF_2g20;
        Int_t           PassedEF_J80;
        Int_t           PassedEF_e55_loose1;
        Int_t           PassedEF_tau20i_j120;
        Int_t           PassedEF_mu4_trod;
        Int_t           PassedEF_tau125_loose;
        Int_t           PassedEF_xe50;
        Int_t           PassedEF_tau16i_mu6;
        Int_t           PassedEF_tau12_b23_j42;
        Int_t           PassedEF_FJ18;
        Int_t           PassedEF_tau20i_e25i;
        Int_t           PassedEF_2j42_xe30;
        Int_t           PassedEF_mu4_tile;
        Int_t           PassedEF_2e5_medium1;
        Int_t           PassedEF_e5_e7_medium;
        Int_t           PassedEF_e20_g20;
        Int_t           PassedEF_tau20i_b18;
        Int_t           PassedEF_Zee;
        Int_t           PassedEF_JE340;
        Int_t           PassedEF_b42;
        Int_t           PassedEF_g3_nocut;
        Int_t           PassedEF_mu4_j42_matched;
        Int_t           PassedEF_te150;
        Int_t           PassedEF_2tau12;
        Int_t           PassedEF_te250;
        Int_t           PassedEF_4J125;
        Int_t           PassedEF_3J60;
        Int_t           PassedEF_tau12_e10;
        Int_t           PassedEF_e5_medium1;
        Int_t           PassedEF_J350;
        Int_t           PassedEF_e20_loose_passL2;
        Int_t           PassedEF_em20_passHLT;
        Int_t           PassedEF_2e15_medium;
        Int_t           PassedEF_2b23_3L1J23_passHLT;
        Int_t           PassedEF_xe15;
        Int_t           PassedEF_2FJ70;
        Int_t           PassedEF_2FJ18;
        Int_t           PassedEF_g105;
        Int_t           PassedEF_tau84_loose;
        Int_t           PassedEF_2e10_mu6;
        Int_t           PassedEF_mu4;
        Int_t           PassedEF_mu6;
        Int_t           PassedEF_MU4_Jpsimumu_FS;
        Int_t           PassedEF_e22i_tight;
        Int_t           PassedEF_em20i_passHLT;
        Int_t           PassedEF_g55_tight;
        Int_t           PassedEF_2mu6_g10;
        Int_t           PassedEF_tau20i_mu10;
        Int_t           PassedEF_J180;
        Int_t           PassedEF_e10_medium;
        Int_t           PassedEF_2tau20i_PT;
        Int_t           PassedEF_J115;
        Int_t           PassedEF_j42_xe30_e15i;
        Int_t           PassedEF_mu20_passHLT;
        Int_t           PassedEF_2mu6_e10;
        Int_t           PassedEF_MbSp;
        Int_t           PassedEF_g20i;
        Int_t           PassedEF_em105_passHLT;
        Int_t           PassedEF_2mu20;
        Int_t           PassedEF_2g10;
        Int_t           PassedEF_2g15;
        Int_t           PassedEF_tau16i_e15i;
        Int_t           PassedEF_e20i_loose;
        Int_t           PassedEF_e20_loose;
        Int_t           PassedEF_2e5_medium;
        Int_t           PassedEF_tau29i_xe30;
        Int_t           PassedEF_3b18_4L1J18;
        Int_t           PassedEF_xe40;
        Int_t           PassedEF_te360;
        Int_t           PassedEF_tau16i_2j23;
        Int_t           PassedEF_2FJ35;
        Int_t           PassedEF_4J45;
        Int_t           PassedEF_tau20i_j70;
        Int_t           PassedEF_tau12_b35;
        Int_t           PassedEF_e25i_medium1;
        Int_t           PassedEF_2mu4;
        Int_t           PassedEF_mu20i_loose;
        Int_t           PassedEF_2mu6;
        Int_t           PassedEF_mu4_DsPhiPi_FS;
        Int_t           PassedEF_2tau29i;
        Int_t           PassedEF_mu10_j18;
        Int_t           PassedEF_g150;
        Int_t           PassedEF_mu10;
        Int_t           PassedEF_mu15;
        Int_t           PassedEF_g15i;
        Int_t           PassedEF_tau38_xe40;
        Int_t           PassedEF_tau20i_mu20;
        Int_t           PassedEF_J50;
        Int_t           PassedEF_2MU4_Jpsimumu;
        Int_t           PassedEF_tau38_loose;
        Int_t           PassedEF_J140;
        Int_t           PassedEF_JE120;
        Int_t           PassedEF_2e10_loose;
        Int_t           PassedEF_mu15_xe15;
        Int_t           PassedEF_2e20_loose;
        Int_t           PassedEF_4J80;
        Int_t           PassedEF_xe70;
        Int_t           PassedEF_mu4_j35_matched;
        Int_t           PassedEF_e15_xe20;
        Int_t           PassedEF_e20_xe30;
        Int_t           PassedEF_tau20i_xe30;
        Int_t           PassedEF_3e15_medium;
        Int_t           PassedEF_e25i_loose;
        Int_t           PassedEF_MbSpTrk;
        Int_t           PassedEF_tau29i_xe40;
        Int_t           PassedEF_tau20i_b35;
        Int_t           PassedEF_J10;
        Int_t           PassedEF_JE220;
        Int_t           PassedEF_tau16i_EFxe30;
        Int_t           PassedEF_tau16i_3j23;
        Int_t           PassedEF_e25_loose;
        Int_t           PassedEF_mu20;
        Int_t           PassedEF_2e12_tight;
        Int_t           PassedEF_3b23_3L1J23;
        Int_t           PassedEF_3J25;
        Int_t           PassedEF_b18;
        Int_t           PassedEF_FJ35;
        Int_t           PassedEF_stau;
        Int_t           PassedEF_xe30;
        Int_t           PassedEF_Jpsiee;
        Int_t           PassedEF_tau12_tau29i;
        Int_t           PassedEF_tau20i_loose;
        Int_t           Tau_N;
        Int_t           El_N;
        Int_t           Mu_N;
        Int_t           JetC4T_N;
        Int_t           Trk_N;
        Int_t           T_Tau_N;
        Int_t           T_TauVis_N;
        Int_t           T_Mu_N;
        Int_t           T_El_N;
        Int_t           T_JetC4_N;
        vector<double>  *Tau_E;
        vector<double>  *Tau_p_T;
        vector<double>  *Tau_phi;
        vector<double>  *Tau_eta;
        vector<double>  *Tau_px;
        vector<double>  *Tau_py;
        vector<double>  *Tau_pz;
        vector<double>  *Tau_m;
        vector<double>  *Tau_charge;
        vector<double>  *Tau_pdgId;
        vector<double>  *Tau_Likelihood;
        vector<double>  *Tau_TauJetLikelihoodOld;
        vector<double>  *Tau_TauELikelihoodLowPt;
        vector<double>  *Tau_TauElTauLikelihood;
        vector<double>  *Tau_TauJetNeuralNetwork;
        vector<double>  *Tau_TauENeuralNetwork;
        vector<double>  *Tau_DiscPDERS;
        vector<double>  *Tau_DiscCutTMVA;
        vector<double>  *Tau_totTrkCharge;
        vector<double>  *Tau_totTrkE;
        vector<double>  *Tau_track1_pT;
        vector<double>  *Tau_track2_pT;
        vector<double>  *Tau_track3_pT;
        vector<double>  *Tau_track1_phi;
        vector<double>  *Tau_track2_phi;
        vector<double>  *Tau_track3_phi;
        vector<double>  *Tau_track1_eta;
        vector<double>  *Tau_track2_eta;
        vector<double>  *Tau_track3_eta;
        vector<double>  *Tau_emRadius;
        vector<double>  *Tau_isolationFraction;
        vector<double>  *Tau_stripWidth2;
        vector<double>  *Tau_sumEMpx;
        vector<double>  *Tau_sumEMpy;
        vector<double>  *Tau_sumEMpz;
        vector<double>  *Tau_sumEMe;
        vector<double>  *Tau_secVtxX;
        vector<double>  *Tau_secVtxY;
        vector<double>  *Tau_secVtxZ;
        vector<double>  *Tau_secVtxCovXX;
        vector<double>  *Tau_secVtxCovYY;
        vector<double>  *Tau_secVtxCovZZ;
        vector<double>  *Tau_secVtxCovXY;
        vector<double>  *Tau_secVtxCovYZ;
        vector<double>  *Tau_secVtxCovXZ;
        vector<double>  *Tau_secVtxChi2;
        vector<double>  *Tau_secVtxNDoF;
        vector<double>  *Tau_trFlightPathSig;
        vector<double>  *Tau_etChrgHAD;
        vector<double>  *Tau_etIsolEM;
        vector<double>  *Tau_etIsolHAD;
        vector<double>  *Tau_massTrk3P;
        vector<double>  *Tau_rWidth2Trk3P;
        vector<double>  *Tau_signD0Trk3P;
        vector<double>  *Tau_etHadAtEMScale;
        vector<double>  *Tau_etEMAtEMScale;
        vector<double>  *Tau_etEMCL;
        vector<double>  *Tau_etChrgEM;
        vector<double>  *Tau_etNeuEM;
        vector<double>  *Tau_etResNeuEM;
        vector<double>  *Tau_etChrgEM01_1Trk;
        vector<double>  *Tau_etChrgEM01_2Trk;
        vector<double>  *Tau_etChrgEM01_3Trk;
        vector<double>  *Tau_etResChrgEM_1Trk;
        vector<double>  *Tau_etResChrgEM_2Trk;
        vector<double>  *Tau_etResChrgEM_3Trk;
        vector<double>  *Tau_z0SinThetaSig;
        vector<double>  *Tau_etChrgHADoverPttot;
        vector<double>  *Tau_etIsolFrac;
        vector<double>  *Tau_etEflow;
        vector<double>  *Tau_hadronicLeak;
        vector<double>  *Tau_secondaryMax;
        vector<double>  *Tau_sumEtCellsLArOverLeadTrackPt;
        vector<double>  *Tau_centralityFraction;
        vector<double>  *Tau_etEMCalib;
        vector<double>  *Tau_etHadCalib;
        vector<double>  *Tau_trackCaloEta1;
        vector<double>  *Tau_trackCaloEta2;
        vector<double>  *Tau_trackCaloEta3;
        vector<double>  *Tau_trackCaloPhi1;
        vector<double>  *Tau_trackCaloPhi2;
        vector<double>  *Tau_trackCaloPhi3;
        vector<double>  *Tau_leadingTrackPT;
        vector<double>  *Tau_ipSigLeadTrack;
        vector<double>  *Tau_etaCalo;
        vector<double>  *Tau_phiCalo;
        vector<double>  *Tau_hadRadius;
        vector<double>  *Tau_sumEmCellEt;
        vector<double>  *Tau_sumHadCellEt;
        vector<double>  *Tau_DiscCut;
        vector<double>  *Tau_DiscNN;
        vector<double>  *Tau_EfficNN;
        vector<double>  *Tau_T_HadTau_DeltaR;
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
        vector<double>  *JetC4T_T_TauVis_DeltaR;
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
        vector<double>  *T_Tau_E;
        vector<double>  *T_Tau_p_T;
        vector<double>  *T_Tau_phi;
        vector<double>  *T_Tau_eta;
        vector<double>  *T_Tau_px;
        vector<double>  *T_Tau_py;
        vector<double>  *T_Tau_pz;
        vector<double>  *T_Tau_m;
        vector<double>  *T_Tau_charge;
        vector<double>  *T_Tau_pdgId;
        vector<double>  *T_TauVis_E;
        vector<double>  *T_TauVis_p_T;
        vector<double>  *T_TauVis_phi;
        vector<double>  *T_TauVis_eta;
        vector<double>  *T_TauVis_px;
        vector<double>  *T_TauVis_py;
        vector<double>  *T_TauVis_pz;
        vector<double>  *T_TauVis_m;
        vector<double>  *T_TauVis_charge;
        vector<double>  *T_TauVis_pdgId;
        vector<double>  *T_TauVis_T_HadTau_DeltaR;
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
        vector<double>  *T_JetC4_T_TauVis_DeltaR;
        vector<double>  *T_JetC4_T_Jet_DeltaR;
        vector<int>     *Tau_isTauLoose;
        vector<int>     *Tau_isTauMedium;
        vector<int>     *Tau_isTauTight;
        vector<int>     *Tau_EgammaFlag;
        vector<int>     *Tau_numTrack;
        vector<int>     *Tau_numStripCells;
        vector<int>     *Tau_nAssocTracksCore;
        vector<int>     *Tau_nAssocTracksIsol;
        vector<int>     *Tau_numPi0;
        vector<int>     *Tau_nTracksdrdR;
        vector<int>     *Tau_numTrackDetails;
        vector<int>     *Tau_hasAuthor_TauRec;
        vector<int>     *Tau_hasAuthor_Tau1P3P;
        vector<int>     *Tau_ElectronFlag;
        vector<int>     *Tau_MuonFlag;
        vector<int>     *Tau_T_HadTau_Matched;
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
        vector<int>     *JetC4T_T_TauVis_Matched;
        vector<int>     *JetC4T_T_Ph_Matched;
        vector<int>     *T_Tau_nParents;
        vector<int>     *T_Tau_nDecay;
        vector<int>     *T_TauVis_T_HadTau_Matched;
        vector<int>     *T_Mu_nParents;
        vector<int>     *T_Mu_nDecay;
        vector<int>     *T_El_nParents;
        vector<int>     *T_El_nDecay;
        vector<int>     *T_JetC4_T_El_Matched;
        vector<int>     *T_JetC4_T_Mu_Matched;
        vector<int>     *T_JetC4_T_Ph_Matched;
        vector<int>     *T_JetC4_T_TauVis_Matched;
        vector<int>     *T_JetC4_T_Jet_Matched;
        vector<vector<int> > *T_Tau_ParentIDs;
        vector<vector<int> > *T_El_ParentIDs;
        vector<vector<double> > *Tau_Trk_pT;
        vector<vector<double> > *Tau_Trk_phi;
        vector<vector<double> > *Tau_Trk_eta;
        vector<vector<double> > *Tau_Pi0_eta;
        vector<vector<double> > *Tau_Pi0_phi;
        vector<vector<double> > *Tau_Pi0_et;
        vector<vector<double> > *Tau_Pi0_e;
        vector<vector<double> > *T_Tau_DecayIDs;
        vector<vector<double> > *T_Tau_ParentBarcodes;
        vector<vector<double> > *T_Tau_DecayBarcodes;
        vector<vector<double> > *T_Tau_ParentStatus;
        vector<vector<double> > *T_Tau_DecayStatus;
        vector<vector<double> > *T_Tau_DecayPt;
        vector<vector<double> > *T_Tau_DecayEta;
        vector<vector<double> > *T_Tau_ParentPt;
        vector<vector<double> > *T_Tau_ParentEta;
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
        Int_t           ControlSampleInstance;
        Int_t           ControlSampleCounter;
        Int_t           ControlSampleEventAndInstance;
        Int_t           ControlSampleRunNumber;
        Int_t           ControlSampleNInstance;

        // List of branches
        TBranch        *b_MET_RefFinal_ex;   //!
        TBranch        *b_MET_RefFinal_ey;   //!
        TBranch        *b_MET_RefFinal_et;   //!
        TBranch        *b_MET_RefFinal_sumet;   //!
        TBranch        *b_MET_RefEle_ex;   //!
        TBranch        *b_MET_RefEle_ey;   //!
        TBranch        *b_MET_RefEle_et;   //!
        TBranch        *b_MET_RefEle_sumet;   //!
        TBranch        *b_MET_RefMuon_ex;   //!
        TBranch        *b_MET_RefMuon_ey;   //!
        TBranch        *b_MET_RefMuon_et;   //!
        TBranch        *b_MET_RefMuon_sumet;   //!
        TBranch        *b_MET_RefJet_ex;   //!
        TBranch        *b_MET_RefJet_ey;   //!
        TBranch        *b_MET_RefJet_et;   //!
        TBranch        *b_MET_RefJet_sumet;   //!
        TBranch        *b_MET_RefGamma_ex;   //!
        TBranch        *b_MET_RefGamma_ey;   //!
        TBranch        *b_MET_RefGamma_et;   //!
        TBranch        *b_MET_RefGamma_sumet;   //!
        TBranch        *b_MET_RefTau_ex;   //!
        TBranch        *b_MET_RefTau_ey;   //!
        TBranch        *b_MET_RefTau_et;   //!
        TBranch        *b_MET_RefTau_sumet;   //!
        TBranch        *b_MET_CellOut_ex;   //!
        TBranch        *b_MET_CellOut_ey;   //!
        TBranch        *b_MET_CellOut_et;   //!
        TBranch        *b_MET_CellOut_sumet;   //!
        TBranch        *b_MET_MuonBoy_ex;   //!
        TBranch        *b_MET_MuonBoy_ey;   //!
        TBranch        *b_MET_MuonBoy_et;   //!
        TBranch        *b_MET_MuonBoy_sumet;   //!
        TBranch        *b_MET_CryoCone_ex;   //!
        TBranch        *b_MET_CryoCone_ey;   //!
        TBranch        *b_MET_CryoCone_et;   //!
        TBranch        *b_MET_CryoCone_sumet;   //!
        TBranch        *b_MET_LocHadTopoObj_ex;   //!
        TBranch        *b_MET_LocHadTopoObj_ey;   //!
        TBranch        *b_MET_LocHadTopoObj_et;   //!
        TBranch        *b_MET_LocHadTopoObj_sumet;   //!
        TBranch        *b_MET_LocHadTopo_ex;   //!
        TBranch        *b_MET_LocHadTopo_ey;   //!
        TBranch        *b_MET_LocHadTopo_et;   //!
        TBranch        *b_MET_LocHadTopo_sumet;   //!
        TBranch        *b_MET_Truth_Int_ex;   //!
        TBranch        *b_MET_Truth_Int_ey;   //!
        TBranch        *b_MET_Truth_Int_et;   //!
        TBranch        *b_MET_Truth_Int_sumet;   //!
        TBranch        *b_MET_Truth_NonInt_ex;   //!
        TBranch        *b_MET_Truth_NonInt_ey;   //!
        TBranch        *b_MET_Truth_NonInt_et;   //!
        TBranch        *b_MET_Truth_NonInt_sumet;   //!
        TBranch        *b_MET_Truth_IntCentral_ex;   //!
        TBranch        *b_MET_Truth_IntCentral_ey;   //!
        TBranch        *b_MET_Truth_IntCentral_et;   //!
        TBranch        *b_MET_Truth_IntCentral_sumet;   //!
        TBranch        *b_MET_Truth_IntFwd_ex;   //!
        TBranch        *b_MET_Truth_IntFwd_ey;   //!
        TBranch        *b_MET_Truth_IntFwd_et;   //!
        TBranch        *b_MET_Truth_IntFwd_sumet;   //!
        TBranch        *b_MET_Truth_IntOutCover_ex;   //!
        TBranch        *b_MET_Truth_IntOutCover_ey;   //!
        TBranch        *b_MET_Truth_IntOutCover_et;   //!
        TBranch        *b_MET_Truth_IntOutCover_sumet;   //!
        TBranch        *b_MET_Truth_Muons_ex;   //!
        TBranch        *b_MET_Truth_Muons_ey;   //!
        TBranch        *b_MET_Truth_Muons_et;   //!
        TBranch        *b_MET_Truth_Muons_sumet;   //!
        TBranch        *b_MET_Truth_PileUp_Int_ex;   //!
        TBranch        *b_MET_Truth_PileUp_Int_ey;   //!
        TBranch        *b_MET_Truth_PileUp_Int_et;   //!
        TBranch        *b_MET_Truth_PileUp_Int_sumet;   //!
        TBranch        *b_MET_Truth_PileUp_NonInt_ex;   //!
        TBranch        *b_MET_Truth_PileUp_NonInt_ey;   //!
        TBranch        *b_MET_Truth_PileUp_NonInt_et;   //!
        TBranch        *b_MET_Truth_PileUp_NonInt_sumet;   //!
        TBranch        *b_MET_Truth_PileUp_IntCentral_ex;   //!
        TBranch        *b_MET_Truth_PileUp_IntCentral_ey;   //!
        TBranch        *b_MET_Truth_PileUp_IntCentral_et;   //!
        TBranch        *b_MET_Truth_PileUp_IntCentral_sumet;   //!
        TBranch        *b_MET_Truth_PileUp_IntFwd_ex;   //!
        TBranch        *b_MET_Truth_PileUp_IntFwd_ey;   //!
        TBranch        *b_MET_Truth_PileUp_IntFwd_et;   //!
        TBranch        *b_MET_Truth_PileUp_IntFwd_sumet;   //!
        TBranch        *b_MET_Truth_PileUp_IntOutCover_ex;   //!
        TBranch        *b_MET_Truth_PileUp_IntOutCover_ey;   //!
        TBranch        *b_MET_Truth_PileUp_IntOutCover_et;   //!
        TBranch        *b_MET_Truth_PileUp_IntOutCover_sumet;   //!
        TBranch        *b_MET_Truth_PileUp_Muons_ex;   //!
        TBranch        *b_MET_Truth_PileUp_Muons_ey;   //!
        TBranch        *b_MET_Truth_PileUp_Muons_et;   //!
        TBranch        *b_MET_Truth_PileUp_Muons_sumet;   //!
        TBranch        *b_PassedTrigger;   //!
        TBranch        *b_PassedL1;   //!
        TBranch        *b_PassedL2;   //!
        TBranch        *b_PassedEF;   //!
        TBranch        *b_Passed;   //!
        TBranch        *b_PassedL1_EM3;   //!
        TBranch        *b_PassedL1_EM7;   //!
        TBranch        *b_PassedL1_2TAU6_TAU25;   //!
        TBranch        *b_PassedL1_EM13;   //!
        TBranch        *b_PassedL1_EM13I;   //!
        TBranch        *b_PassedL1_EM18;   //!
        TBranch        *b_PassedL1_EM18I;   //!
        TBranch        *b_PassedL1_EM23I;   //!
        TBranch        *b_PassedL1_EM100;   //!
        TBranch        *b_PassedL1_TAU25I_XE20;   //!
        TBranch        *b_PassedL1_2EM3;   //!
        TBranch        *b_PassedL1_2EM7;   //!
        TBranch        *b_PassedL1_TAU25_XE40;   //!
        TBranch        *b_PassedL1_2EM13;   //!
        TBranch        *b_PassedL1_2EM13I;   //!
        TBranch        *b_PassedL1_2EM18;   //!
        TBranch        *b_PassedL1_2EM18I;   //!
        TBranch        *b_PassedL1_2EM23I;   //!
        TBranch        *b_PassedL1_2EM3_EM7;   //!
        TBranch        *b_PassedL1_3EM7;   //!
        TBranch        *b_PassedL1_RD0_FILLED;   //!
        TBranch        *b_PassedL1_MU4;   //!
        TBranch        *b_PassedL1_MU6;   //!
        TBranch        *b_PassedL1_MU10;   //!
        TBranch        *b_PassedL1_MU11;   //!
        TBranch        *b_PassedL1_MU20;   //!
        TBranch        *b_PassedL1_MU40;   //!
        TBranch        *b_PassedL1_2MU4;   //!
        TBranch        *b_PassedL1_2MU6;   //!
        TBranch        *b_PassedL1_2MU10;   //!
        TBranch        *b_PassedL1_2MU11;   //!
        TBranch        *b_PassedL1_2MU20;   //!
        TBranch        *b_PassedL1_3MU6;   //!
        TBranch        *b_PassedL1_2MU4_MU6;   //!
        TBranch        *b_PassedL1_TAU5;   //!
        TBranch        *b_PassedL1_TAU6;   //!
        TBranch        *b_PassedL1_TAU9I;   //!
        TBranch        *b_PassedL1_TAU11I;   //!
        TBranch        *b_PassedL1_TAU16I;   //!
        TBranch        *b_PassedL1_TAU25;   //!
        TBranch        *b_PassedL1_TAU25I;   //!
        TBranch        *b_PassedL1_TAU40;   //!
        TBranch        *b_PassedL1_2TAU6;   //!
        TBranch        *b_PassedL1_2TAU9I;   //!
        TBranch        *b_PassedL1_2TAU6_TAU16I;   //!
        TBranch        *b_PassedL1_2TAU16I;   //!
        TBranch        *b_PassedL1_J5;   //!
        TBranch        *b_PassedL1_J10;   //!
        TBranch        *b_PassedL1_J18;   //!
        TBranch        *b_PassedL1_J23;   //!
        TBranch        *b_PassedL1_J35;   //!
        TBranch        *b_PassedL1_J42;   //!
        TBranch        *b_PassedL1_J70;   //!
        TBranch        *b_PassedL1_J120;   //!
        TBranch        *b_PassedL1_4J10;   //!
        TBranch        *b_PassedL1_3J18;   //!
        TBranch        *b_PassedL1_3J23;   //!
        TBranch        *b_PassedL1_4J18;   //!
        TBranch        *b_PassedL1_4J23;   //!
        TBranch        *b_PassedL1_4J35;   //!
        TBranch        *b_PassedL1_3J70;   //!
        TBranch        *b_PassedL1_FJ18;   //!
        TBranch        *b_PassedL1_FJ35;   //!
        TBranch        *b_PassedL1_FJ70;   //!
        TBranch        *b_PassedL1_FJ120;   //!
        TBranch        *b_PassedL1_2FJ18;   //!
        TBranch        *b_PassedL1_2FJ35;   //!
        TBranch        *b_PassedL1_2FJ70;   //!
        TBranch        *b_PassedL1_3J10;   //!
        TBranch        *b_PassedL1_XE15;   //!
        TBranch        *b_PassedL1_XE20;   //!
        TBranch        *b_PassedL1_XE25;   //!
        TBranch        *b_PassedL1_XE30;   //!
        TBranch        *b_PassedL1_XE40;   //!
        TBranch        *b_PassedL1_XE50;   //!
        TBranch        *b_PassedL1_XE70;   //!
        TBranch        *b_PassedL1_XE80;   //!
        TBranch        *b_PassedL1_TE150;   //!
        TBranch        *b_PassedL1_TE250;   //!
        TBranch        *b_PassedL1_TE360;   //!
        TBranch        *b_PassedL1_TE650;   //!
        TBranch        *b_PassedL1_JE120;   //!
        TBranch        *b_PassedL1_JE220;   //!
        TBranch        *b_PassedL1_JE280;   //!
        TBranch        *b_PassedL1_JE340;   //!
        TBranch        *b_PassedL1_EM13_XE20;   //!
        TBranch        *b_PassedL1_EM18_XE15;   //!
        TBranch        *b_PassedL1_2EM7_MU6;   //!
        TBranch        *b_PassedL1_2EM13_MU6;   //!
        TBranch        *b_PassedL1_2EM18_MU6;   //!
        TBranch        *b_PassedL1_EM7_MU6;   //!
        TBranch        *b_PassedL1_EM7_XE30;   //!
        TBranch        *b_PassedL1_2EM3_TAU6;   //!
        TBranch        *b_PassedL1_EM18_XE30;   //!
        TBranch        *b_PassedL1_EM13_MU11;   //!
        TBranch        *b_PassedL1_EM13I_MU11;   //!
        TBranch        *b_PassedL1_2TAU6_EM7;   //!
        TBranch        *b_PassedL1_2TAU6_TAU9I_EM7;   //!
        TBranch        *b_PassedL1_2TAU6_TAU11I_EM7;   //!
        TBranch        *b_PassedL1_2TAU9I_EM13I;   //!
        TBranch        *b_PassedL1_MU11_XE15;   //!
        TBranch        *b_PassedL1_MU4_J5;   //!
        TBranch        *b_PassedL1_MU4_J10;   //!
        TBranch        *b_PassedL1_MU4_J18;   //!
        TBranch        *b_PassedL1_MU4_J23;   //!
        TBranch        *b_PassedL1_MU4_J35;   //!
        TBranch        *b_PassedL1_MU4_J42;   //!
        TBranch        *b_PassedL1_MU4_EM3;   //!
        TBranch        *b_PassedL1_MU6_J5;   //!
        TBranch        *b_PassedL1_MU6_EM3;   //!
        TBranch        *b_PassedL1_2MU6_EM7;   //!
        TBranch        *b_PassedL1_MU20_XE30;   //!
        TBranch        *b_PassedL1_MU10_J18;   //!
        TBranch        *b_PassedL1_TAU9I_MU6;   //!
        TBranch        *b_PassedL1_TAU9I_MU10;   //!
        TBranch        *b_PassedL1_TAU11I_MU6;   //!
        TBranch        *b_PassedL1_TAU11I_MU10;   //!
        TBranch        *b_PassedL1_TAU11I_MU20;   //!
        TBranch        *b_PassedL1_J70_XE30;   //!
        TBranch        *b_PassedL1_2J42_XE30;   //!
        TBranch        *b_PassedL1_J42_XE30_EM13I;   //!
        TBranch        *b_PassedL1_J42_XE30_MU11;   //!
        TBranch        *b_PassedL1_4J23_EM13I;   //!
        TBranch        *b_PassedL1_4J23_MU11;   //!
        TBranch        *b_PassedL1_TAU6_XE20;   //!
        TBranch        *b_PassedL1_TAU9I_XE20;   //!
        TBranch        *b_PassedL1_TAU9I_XE30;   //!
        TBranch        *b_PassedL1_TAU9I_XE40;   //!
        TBranch        *b_PassedL1_TAU11I_XE30;   //!
        TBranch        *b_PassedL1_TAU16I_XE20;   //!
        TBranch        *b_PassedL1_TAU16I_XE30;   //!
        TBranch        *b_PassedL1_TAU16I_XE40;   //!
        TBranch        *b_PassedL1_2TAU11I_EM23I;   //!
        TBranch        *b_PassedL1_TAU9I_2J5_J35;   //!
        TBranch        *b_PassedL1_TAU11I_2J5_J18;   //!
        TBranch        *b_PassedL1_TAU11I_2J5_J35;   //!
        TBranch        *b_PassedL1_TAU9I_5J5_4J23;   //!
        TBranch        *b_PassedL1_TAU9I_3J5_2J23;   //!
        TBranch        *b_PassedL1_TAU11I_3J5_2J23;   //!
        TBranch        *b_PassedL1_TAU6_2J5_J35;   //!
        TBranch        *b_PassedL1_TAU6_3J5_J42;   //!
        TBranch        *b_PassedL1_TAU6_3J5_2J42_XE30;   //!
        TBranch        *b_PassedL1_MBTS_1;   //!
        TBranch        *b_PassedL1_MBTS_2;   //!
        TBranch        *b_PassedL1_MBTS_1_1;   //!
        TBranch        *b_PassedL2_te650;   //!
        TBranch        *b_PassedL2_g25_xe30;   //!
        TBranch        *b_PassedL2_mu4_j10_matched;   //!
        TBranch        *b_PassedL2_e10_mu6;   //!
        TBranch        *b_PassedL2_MU4_Upsimumu_FS;   //!
        TBranch        *b_PassedL2_g20_xe15;   //!
        TBranch        *b_PassedL2_tau16i_j70_WO;   //!
        TBranch        *b_PassedL2_tau12_loose;   //!
        TBranch        *b_PassedL2_tau38i_loose;   //!
        TBranch        *b_PassedL2_tau12_PT;   //!
        TBranch        *b_PassedL2_e6_medium1;   //!
        TBranch        *b_PassedL2_mu4_mu6;   //!
        TBranch        *b_PassedL2_JE280;   //!
        TBranch        *b_PassedL2_b23;   //!
        TBranch        *b_PassedL2_tau12_xe20;   //!
        TBranch        *b_PassedL2_j42_xe30_mu15;   //!
        TBranch        *b_PassedL2_mu4_j10;   //!
        TBranch        *b_PassedL2_g25;   //!
        TBranch        *b_PassedL2_g20;   //!
        TBranch        *b_PassedL2_tauNoCut;   //!
        TBranch        *b_PassedL2_tau16i_j70;   //!
        TBranch        *b_PassedL2_tau12_tau38;   //!
        TBranch        *b_PassedL2_e15_medium;   //!
        TBranch        *b_PassedL2_FJ70;   //!
        TBranch        *b_PassedL2_mu4_j18_matched;   //!
        TBranch        *b_PassedL2_tau12_tau29i_PT;   //!
        TBranch        *b_PassedL2_4J50;   //!
        TBranch        *b_PassedL2_xe80;   //!
        TBranch        *b_PassedL2_e12_medium;   //!
        TBranch        *b_PassedL2_tau16i_4j23_WO;   //!
        TBranch        *b_PassedL2_tau20i_e10;   //!
        TBranch        *b_PassedL2_tau29i_loose;   //!
        TBranch        *b_PassedL2_e105_loose1;   //!
        TBranch        *b_PassedL2_e20_loose_passEF;   //!
        TBranch        *b_PassedL2_e7_medium;   //!
        TBranch        *b_PassedL2_e15i_medium;   //!
        TBranch        *b_PassedL2_tau16i_mu10;   //!
        TBranch        *b_PassedL2_3g10;   //!
        TBranch        *b_PassedL2_tau16i_loose;   //!
        TBranch        *b_PassedL2_tau16i_4j23;   //!
        TBranch        *b_PassedL2_2g10_mu6;   //!
        TBranch        *b_PassedL2_2tau20i;   //!
        TBranch        *b_PassedL2_MbRndm;   //!
        TBranch        *b_PassedL2_g25i;   //!
        TBranch        *b_PassedL2_2MU4_Upsimumu;   //!
        TBranch        *b_PassedL2_tau20i_e15i;   //!
        TBranch        *b_PassedL2_3J120;   //!
        TBranch        *b_PassedL2_b70;   //!
        TBranch        *b_PassedL2_4j23_e15i;   //!
        TBranch        *b_PassedL2_tau50_loose;   //!
        TBranch        *b_PassedL2_tau38i_xe20;   //!
        TBranch        *b_PassedL2_g10_calib;   //!
        TBranch        *b_PassedL2_g15;   //!
        TBranch        *b_PassedL2_g10;   //!
        TBranch        *b_PassedL2_e20_xe15;   //!
        TBranch        *b_PassedL2_J150;   //!
        TBranch        *b_PassedL2_e6_medium;   //!
        TBranch        *b_PassedL2_xe20;   //!
        TBranch        *b_PassedL2_xe25;   //!
        TBranch        *b_PassedL2_mu15i_loose;   //!
        TBranch        *b_PassedL2_2e6_medium1;   //!
        TBranch        *b_PassedL2_mu4_j23_matched;   //!
        TBranch        *b_PassedL2_tau16i_xe30;   //!
        TBranch        *b_PassedL2_MU4_Bmumu_FS;   //!
        TBranch        *b_PassedL2_2MU4_DiMu;   //!
        TBranch        *b_PassedL2_MU4_Jpsie5e3_FS;   //!
        TBranch        *b_PassedL2_3mu6;   //!
        TBranch        *b_PassedL2_tau16i_2j70;   //!
        TBranch        *b_PassedL2_tau20i_mu6;   //!
        TBranch        *b_PassedL2_FJ120;   //!
        TBranch        *b_PassedL2_2g17i_tight;   //!
        TBranch        *b_PassedL2_mu20_xe30;   //!
        TBranch        *b_PassedL2_e5_medium;   //!
        TBranch        *b_PassedL2_tau20i_2b23;   //!
        TBranch        *b_PassedL2_2e6_medium;   //!
        TBranch        *b_PassedL2_tau16i_e10;   //!
        TBranch        *b_PassedL2_b35;   //!
        TBranch        *b_PassedL2_e10_xe30;   //!
        TBranch        *b_PassedL2_g20i_calib;   //!
        TBranch        *b_PassedL2_e5_e10_medium;   //!
        TBranch        *b_PassedL2_tau29i_xe20;   //!
        TBranch        *b_PassedL2_4j23_mu15;   //!
        TBranch        *b_PassedL2_trk16i_calib;   //!
        TBranch        *b_PassedL2_tau16i_j120;   //!
        TBranch        *b_PassedL2_2mu10;   //!
        TBranch        *b_PassedL2_3b18_4L1J18_passHLT;   //!
        TBranch        *b_PassedL2_mu40;   //!
        TBranch        *b_PassedL2_j70_xe30;   //!
        TBranch        *b_PassedL2_2g20;   //!
        TBranch        *b_PassedL2_J50;   //!
        TBranch        *b_PassedL2_e55_loose1;   //!
        TBranch        *b_PassedL2_tau20i_j120;   //!
        TBranch        *b_PassedL2_mu4_trod;   //!
        TBranch        *b_PassedL2_tau125_loose;   //!
        TBranch        *b_PassedL2_xe50;   //!
        TBranch        *b_PassedL2_tau16i_mu6;   //!
        TBranch        *b_PassedL2_tau12_b23_j42;   //!
        TBranch        *b_PassedL2_FJ18;   //!
        TBranch        *b_PassedL2_tau20i_e25i;   //!
        TBranch        *b_PassedL2_2j42_xe30;   //!
        TBranch        *b_PassedL2_mu4_tile;   //!
        TBranch        *b_PassedL2_2e5_medium1;   //!
        TBranch        *b_PassedL2_e5_e7_medium;   //!
        TBranch        *b_PassedL2_e20_g20;   //!
        TBranch        *b_PassedL2_tau20i_b18;   //!
        TBranch        *b_PassedL2_Zee;   //!
        TBranch        *b_PassedL2_JE340;   //!
        TBranch        *b_PassedL2_b42;   //!
        TBranch        *b_PassedL2_g3_nocut;   //!
        TBranch        *b_PassedL2_mu4_j42_matched;   //!
        TBranch        *b_PassedL2_te150;   //!
        TBranch        *b_PassedL2_2tau12;   //!
        TBranch        *b_PassedL2_te250;   //!
        TBranch        *b_PassedL2_4J80;   //!
        TBranch        *b_PassedL2_3J35;   //!
        TBranch        *b_PassedL2_tau12_e10;   //!
        TBranch        *b_PassedL2_e5_medium1;   //!
        TBranch        *b_PassedL2_J205;   //!
        TBranch        *b_PassedL2_e20_loose_passL2;   //!
        TBranch        *b_PassedL2_em20_passHLT;   //!
        TBranch        *b_PassedL2_2e15_medium;   //!
        TBranch        *b_PassedL2_2b23_3L1J23_passHLT;   //!
        TBranch        *b_PassedL2_xe15;   //!
        TBranch        *b_PassedL2_2FJ70;   //!
        TBranch        *b_PassedL2_2FJ18;   //!
        TBranch        *b_PassedL2_g105;   //!
        TBranch        *b_PassedL2_tau84_loose;   //!
        TBranch        *b_PassedL2_2e10_mu6;   //!
        TBranch        *b_PassedL2_mu4;   //!
        TBranch        *b_PassedL2_mu6;   //!
        TBranch        *b_PassedL2_MU4_Jpsimumu_FS;   //!
        TBranch        *b_PassedL2_e22i_tight;   //!
        TBranch        *b_PassedL2_em20i_passHLT;   //!
        TBranch        *b_PassedL2_g55_tight;   //!
        TBranch        *b_PassedL2_2mu6_g10;   //!
        TBranch        *b_PassedL2_tau20i_mu10;   //!
        TBranch        *b_PassedL2_J110;   //!
        TBranch        *b_PassedL2_e10_medium;   //!
        TBranch        *b_PassedL2_2tau20i_PT;   //!
        TBranch        *b_PassedL2_J60;   //!
        TBranch        *b_PassedL2_j42_xe30_e15i;   //!
        TBranch        *b_PassedL2_mu20_passHLT;   //!
        TBranch        *b_PassedL2_2mu6_e10;   //!
        TBranch        *b_PassedL2_MbSp;   //!
        TBranch        *b_PassedL2_g20i;   //!
        TBranch        *b_PassedL2_em105_passHLT;   //!
        TBranch        *b_PassedL2_2mu20;   //!
        TBranch        *b_PassedL2_2g10;   //!
        TBranch        *b_PassedL2_2g15;   //!
        TBranch        *b_PassedL2_tau16i_e15i;   //!
        TBranch        *b_PassedL2_e20i_loose;   //!
        TBranch        *b_PassedL2_e20_loose;   //!
        TBranch        *b_PassedL2_2e5_medium;   //!
        TBranch        *b_PassedL2_tau29i_xe30;   //!
        TBranch        *b_PassedL2_3b18_4L1J18;   //!
        TBranch        *b_PassedL2_xe40;   //!
        TBranch        *b_PassedL2_te360;   //!
        TBranch        *b_PassedL2_tau16i_2j23;   //!
        TBranch        *b_PassedL2_2FJ35;   //!
        TBranch        *b_PassedL2_4J15;   //!
        TBranch        *b_PassedL2_tau20i_j70;   //!
        TBranch        *b_PassedL2_tau12_b35;   //!
        TBranch        *b_PassedL2_trk9i_calib;   //!
        TBranch        *b_PassedL2_e25i_medium1;   //!
        TBranch        *b_PassedL2_2mu4;   //!
        TBranch        *b_PassedL2_mu20i_loose;   //!
        TBranch        *b_PassedL2_2mu6;   //!
        TBranch        *b_PassedL2_mu4_DsPhiPi_FS;   //!
        TBranch        *b_PassedL2_2tau29i;   //!
        TBranch        *b_PassedL2_mu10_j18;   //!
        TBranch        *b_PassedL2_g150;   //!
        TBranch        *b_PassedL2_mu10;   //!
        TBranch        *b_PassedL2_mu15;   //!
        TBranch        *b_PassedL2_g15i;   //!
        TBranch        *b_PassedL2_tau38_xe40;   //!
        TBranch        *b_PassedL2_tau20i_mu20;   //!
        TBranch        *b_PassedL2_J23;   //!
        TBranch        *b_PassedL2_2MU4_Jpsimumu;   //!
        TBranch        *b_PassedL2_tau38_loose;   //!
        TBranch        *b_PassedL2_J80;   //!
        TBranch        *b_PassedL2_JE120;   //!
        TBranch        *b_PassedL2_2e10_loose;   //!
        TBranch        *b_PassedL2_mu15_xe15;   //!
        TBranch        *b_PassedL2_2e20_loose;   //!
        TBranch        *b_PassedL2_4J35;   //!
        TBranch        *b_PassedL2_xe70;   //!
        TBranch        *b_PassedL2_mu4_j35_matched;   //!
        TBranch        *b_PassedL2_e15_xe20;   //!
        TBranch        *b_PassedL2_e20_xe30;   //!
        TBranch        *b_PassedL2_tau20i_xe30;   //!
        TBranch        *b_PassedL2_3e15_medium;   //!
        TBranch        *b_PassedL2_e25i_loose;   //!
        TBranch        *b_PassedL2_MbSpTrk;   //!
        TBranch        *b_PassedL2_tau29i_xe40;   //!
        TBranch        *b_PassedL2_tau20i_b35;   //!
        TBranch        *b_PassedL2_J10;   //!
        TBranch        *b_PassedL2_JE220;   //!
        TBranch        *b_PassedL2_tau16i_3j23;   //!
        TBranch        *b_PassedL2_e25_loose;   //!
        TBranch        *b_PassedL2_mu20;   //!
        TBranch        *b_PassedL2_2e12_tight;   //!
        TBranch        *b_PassedL2_3b23_3L1J23;   //!
        TBranch        *b_PassedL2_3J15;   //!
        TBranch        *b_PassedL2_b18;   //!
        TBranch        *b_PassedL2_FJ35;   //!
        TBranch        *b_PassedL2_stau;   //!
        TBranch        *b_PassedL2_xe30;   //!
        TBranch        *b_PassedL2_Jpsiee;   //!
        TBranch        *b_PassedL2_tau12_tau29i;   //!
        TBranch        *b_PassedL2_tau20i_loose;   //!
        TBranch        *b_PassedEF_te650;   //!
        TBranch        *b_PassedEF_g25_xe30;   //!
        TBranch        *b_PassedEF_mu4_j10_matched;   //!
        TBranch        *b_PassedEF_e10_mu6;   //!
        TBranch        *b_PassedEF_MU4_Upsimumu_FS;   //!
        TBranch        *b_PassedEF_g20_xe15;   //!
        TBranch        *b_PassedEF_tau16i_j70_WO;   //!
        TBranch        *b_PassedEF_tau12_loose;   //!
        TBranch        *b_PassedEF_tau38i_loose;   //!
        TBranch        *b_PassedEF_tau12_PT;   //!
        TBranch        *b_PassedEF_e6_medium1;   //!
        TBranch        *b_PassedEF_mu4_mu6;   //!
        TBranch        *b_PassedEF_JE280;   //!
        TBranch        *b_PassedEF_b23;   //!
        TBranch        *b_PassedEF_tau12_xe20;   //!
        TBranch        *b_PassedEF_j42_xe30_mu15;   //!
        TBranch        *b_PassedEF_mu4_j10;   //!
        TBranch        *b_PassedEF_g25;   //!
        TBranch        *b_PassedEF_g20;   //!
        TBranch        *b_PassedEF_tauNoCut;   //!
        TBranch        *b_PassedEF_tau16i_j70;   //!
        TBranch        *b_PassedEF_tau12_tau38;   //!
        TBranch        *b_PassedEF_e15_medium;   //!
        TBranch        *b_PassedEF_FJ70;   //!
        TBranch        *b_PassedEF_mu4_j18_matched;   //!
        TBranch        *b_PassedEF_tau12_tau29i_PT;   //!
        TBranch        *b_PassedEF_4J95;   //!
        TBranch        *b_PassedEF_xe80;   //!
        TBranch        *b_PassedEF_e12_medium;   //!
        TBranch        *b_PassedEF_tau16i_4j23_WO;   //!
        TBranch        *b_PassedEF_tau20i_e10;   //!
        TBranch        *b_PassedEF_tau29i_loose;   //!
        TBranch        *b_PassedEF_e105_loose1;   //!
        TBranch        *b_PassedEF_e20_loose_passEF;   //!
        TBranch        *b_PassedEF_e7_medium;   //!
        TBranch        *b_PassedEF_e15i_medium;   //!
        TBranch        *b_PassedEF_tau16i_mu10;   //!
        TBranch        *b_PassedEF_3g10;   //!
        TBranch        *b_PassedEF_tau16i_loose;   //!
        TBranch        *b_PassedEF_tau16i_4j23;   //!
        TBranch        *b_PassedEF_2g10_mu6;   //!
        TBranch        *b_PassedEF_2tau20i;   //!
        TBranch        *b_PassedEF_MbRndm;   //!
        TBranch        *b_PassedEF_g25i;   //!
        TBranch        *b_PassedEF_2MU4_Upsimumu;   //!
        TBranch        *b_PassedEF_tau20i_e15i;   //!
        TBranch        *b_PassedEF_3J180;   //!
        TBranch        *b_PassedEF_b70;   //!
        TBranch        *b_PassedEF_4j23_e15i;   //!
        TBranch        *b_PassedEF_tau50_loose;   //!
        TBranch        *b_PassedEF_tau38i_xe20;   //!
        TBranch        *b_PassedEF_g10_calib;   //!
        TBranch        *b_PassedEF_g15;   //!
        TBranch        *b_PassedEF_g10;   //!
        TBranch        *b_PassedEF_e20_xe15;   //!
        TBranch        *b_PassedEF_J265;   //!
        TBranch        *b_PassedEF_e6_medium;   //!
        TBranch        *b_PassedEF_xe20;   //!
        TBranch        *b_PassedEF_xe25;   //!
        TBranch        *b_PassedEF_mu15i_loose;   //!
        TBranch        *b_PassedEF_2e6_medium1;   //!
        TBranch        *b_PassedEF_mu4_j23_matched;   //!
        TBranch        *b_PassedEF_tau16i_xe30;   //!
        TBranch        *b_PassedEF_MU4_Bmumu_FS;   //!
        TBranch        *b_PassedEF_2MU4_DiMu;   //!
        TBranch        *b_PassedEF_MU4_Jpsie5e3_FS;   //!
        TBranch        *b_PassedEF_3mu6;   //!
        TBranch        *b_PassedEF_tau16i_2j70;   //!
        TBranch        *b_PassedEF_tau20i_mu6;   //!
        TBranch        *b_PassedEF_FJ120;   //!
        TBranch        *b_PassedEF_2g17i_tight;   //!
        TBranch        *b_PassedEF_mu20_xe30;   //!
        TBranch        *b_PassedEF_e5_medium;   //!
        TBranch        *b_PassedEF_tau20i_2b23;   //!
        TBranch        *b_PassedEF_2e6_medium;   //!
        TBranch        *b_PassedEF_tau16i_e10;   //!
        TBranch        *b_PassedEF_b35;   //!
        TBranch        *b_PassedEF_e10_xe30;   //!
        TBranch        *b_PassedEF_g20i_calib;   //!
        TBranch        *b_PassedEF_e5_e10_medium;   //!
        TBranch        *b_PassedEF_tau29i_xe20;   //!
        TBranch        *b_PassedEF_4j23_mu15;   //!
        TBranch        *b_PassedEF_tau16i_j120;   //!
        TBranch        *b_PassedEF_2mu10;   //!
        TBranch        *b_PassedEF_3b18_4L1J18_passHLT;   //!
        TBranch        *b_PassedEF_mu40;   //!
        TBranch        *b_PassedEF_j70_xe30;   //!
        TBranch        *b_PassedEF_2g20;   //!
        TBranch        *b_PassedEF_J80;   //!
        TBranch        *b_PassedEF_e55_loose1;   //!
        TBranch        *b_PassedEF_tau20i_j120;   //!
        TBranch        *b_PassedEF_mu4_trod;   //!
        TBranch        *b_PassedEF_tau125_loose;   //!
        TBranch        *b_PassedEF_xe50;   //!
        TBranch        *b_PassedEF_tau16i_mu6;   //!
        TBranch        *b_PassedEF_tau12_b23_j42;   //!
        TBranch        *b_PassedEF_FJ18;   //!
        TBranch        *b_PassedEF_tau20i_e25i;   //!
        TBranch        *b_PassedEF_2j42_xe30;   //!
        TBranch        *b_PassedEF_mu4_tile;   //!
        TBranch        *b_PassedEF_2e5_medium1;   //!
        TBranch        *b_PassedEF_e5_e7_medium;   //!
        TBranch        *b_PassedEF_e20_g20;   //!
        TBranch        *b_PassedEF_tau20i_b18;   //!
        TBranch        *b_PassedEF_Zee;   //!
        TBranch        *b_PassedEF_JE340;   //!
        TBranch        *b_PassedEF_b42;   //!
        TBranch        *b_PassedEF_g3_nocut;   //!
        TBranch        *b_PassedEF_mu4_j42_matched;   //!
        TBranch        *b_PassedEF_te150;   //!
        TBranch        *b_PassedEF_2tau12;   //!
        TBranch        *b_PassedEF_te250;   //!
        TBranch        *b_PassedEF_4J125;   //!
        TBranch        *b_PassedEF_3J60;   //!
        TBranch        *b_PassedEF_tau12_e10;   //!
        TBranch        *b_PassedEF_e5_medium1;   //!
        TBranch        *b_PassedEF_J350;   //!
        TBranch        *b_PassedEF_e20_loose_passL2;   //!
        TBranch        *b_PassedEF_em20_passHLT;   //!
        TBranch        *b_PassedEF_2e15_medium;   //!
        TBranch        *b_PassedEF_2b23_3L1J23_passHLT;   //!
        TBranch        *b_PassedEF_xe15;   //!
        TBranch        *b_PassedEF_2FJ70;   //!
        TBranch        *b_PassedEF_2FJ18;   //!
        TBranch        *b_PassedEF_g105;   //!
        TBranch        *b_PassedEF_tau84_loose;   //!
        TBranch        *b_PassedEF_2e10_mu6;   //!
        TBranch        *b_PassedEF_mu4;   //!
        TBranch        *b_PassedEF_mu6;   //!
        TBranch        *b_PassedEF_MU4_Jpsimumu_FS;   //!
        TBranch        *b_PassedEF_e22i_tight;   //!
        TBranch        *b_PassedEF_em20i_passHLT;   //!
        TBranch        *b_PassedEF_g55_tight;   //!
        TBranch        *b_PassedEF_2mu6_g10;   //!
        TBranch        *b_PassedEF_tau20i_mu10;   //!
        TBranch        *b_PassedEF_J180;   //!
        TBranch        *b_PassedEF_e10_medium;   //!
        TBranch        *b_PassedEF_2tau20i_PT;   //!
        TBranch        *b_PassedEF_J115;   //!
        TBranch        *b_PassedEF_j42_xe30_e15i;   //!
        TBranch        *b_PassedEF_mu20_passHLT;   //!
        TBranch        *b_PassedEF_2mu6_e10;   //!
        TBranch        *b_PassedEF_MbSp;   //!
        TBranch        *b_PassedEF_g20i;   //!
        TBranch        *b_PassedEF_em105_passHLT;   //!
        TBranch        *b_PassedEF_2mu20;   //!
        TBranch        *b_PassedEF_2g10;   //!
        TBranch        *b_PassedEF_2g15;   //!
        TBranch        *b_PassedEF_tau16i_e15i;   //!
        TBranch        *b_PassedEF_e20i_loose;   //!
        TBranch        *b_PassedEF_e20_loose;   //!
        TBranch        *b_PassedEF_2e5_medium;   //!
        TBranch        *b_PassedEF_tau29i_xe30;   //!
        TBranch        *b_PassedEF_3b18_4L1J18;   //!
        TBranch        *b_PassedEF_xe40;   //!
        TBranch        *b_PassedEF_te360;   //!
        TBranch        *b_PassedEF_tau16i_2j23;   //!
        TBranch        *b_PassedEF_2FJ35;   //!
        TBranch        *b_PassedEF_4J45;   //!
        TBranch        *b_PassedEF_tau20i_j70;   //!
        TBranch        *b_PassedEF_tau12_b35;   //!
        TBranch        *b_PassedEF_e25i_medium1;   //!
        TBranch        *b_PassedEF_2mu4;   //!
        TBranch        *b_PassedEF_mu20i_loose;   //!
        TBranch        *b_PassedEF_2mu6;   //!
        TBranch        *b_PassedEF_mu4_DsPhiPi_FS;   //!
        TBranch        *b_PassedEF_2tau29i;   //!
        TBranch        *b_PassedEF_mu10_j18;   //!
        TBranch        *b_PassedEF_g150;   //!
        TBranch        *b_PassedEF_mu10;   //!
        TBranch        *b_PassedEF_mu15;   //!
        TBranch        *b_PassedEF_g15i;   //!
        TBranch        *b_PassedEF_tau38_xe40;   //!
        TBranch        *b_PassedEF_tau20i_mu20;   //!
        TBranch        *b_PassedEF_J50;   //!
        TBranch        *b_PassedEF_2MU4_Jpsimumu;   //!
        TBranch        *b_PassedEF_tau38_loose;   //!
        TBranch        *b_PassedEF_J140;   //!
        TBranch        *b_PassedEF_JE120;   //!
        TBranch        *b_PassedEF_2e10_loose;   //!
        TBranch        *b_PassedEF_mu15_xe15;   //!
        TBranch        *b_PassedEF_2e20_loose;   //!
        TBranch        *b_PassedEF_4J80;   //!
        TBranch        *b_PassedEF_xe70;   //!
        TBranch        *b_PassedEF_mu4_j35_matched;   //!
        TBranch        *b_PassedEF_e15_xe20;   //!
        TBranch        *b_PassedEF_e20_xe30;   //!
        TBranch        *b_PassedEF_tau20i_xe30;   //!
        TBranch        *b_PassedEF_3e15_medium;   //!
        TBranch        *b_PassedEF_e25i_loose;   //!
        TBranch        *b_PassedEF_MbSpTrk;   //!
        TBranch        *b_PassedEF_tau29i_xe40;   //!
        TBranch        *b_PassedEF_tau20i_b35;   //!
        TBranch        *b_PassedEF_J10;   //!
        TBranch        *b_PassedEF_JE220;   //!
        TBranch        *b_PassedEF_tau16i_EFxe30;   //!
        TBranch        *b_PassedEF_tau16i_3j23;   //!
        TBranch        *b_PassedEF_e25_loose;   //!
        TBranch        *b_PassedEF_mu20;   //!
        TBranch        *b_PassedEF_2e12_tight;   //!
        TBranch        *b_PassedEF_3b23_3L1J23;   //!
        TBranch        *b_PassedEF_3J25;   //!
        TBranch        *b_PassedEF_b18;   //!
        TBranch        *b_PassedEF_FJ35;   //!
        TBranch        *b_PassedEF_stau;   //!
        TBranch        *b_PassedEF_xe30;   //!
        TBranch        *b_PassedEF_Jpsiee;   //!
        TBranch        *b_PassedEF_tau12_tau29i;   //!
        TBranch        *b_PassedEF_tau20i_loose;   //!
        TBranch        *b_Tau_N;   //!
        TBranch        *b_El_N;   //!
        TBranch        *b_Mu_N;   //!
        TBranch        *b_JetC4T_N;   //!
        TBranch        *b_Trk_N;   //!
        TBranch        *b_T_Tau_N;   //!
        TBranch        *b_T_TauVis_N;   //!
        TBranch        *b_T_Mu_N;   //!
        TBranch        *b_T_El_N;   //!
        TBranch        *b_T_JetC4_N;   //!
        TBranch        *b_Tau_E;   //!
        TBranch        *b_Tau_p_T;   //!
        TBranch        *b_Tau_phi;   //!
        TBranch        *b_Tau_eta;   //!
        TBranch        *b_Tau_px;   //!
        TBranch        *b_Tau_py;   //!
        TBranch        *b_Tau_pz;   //!
        TBranch        *b_Tau_m;   //!
        TBranch        *b_Tau_charge;   //!
        TBranch        *b_Tau_pdgId;   //!
        TBranch        *b_Tau_Likelihood;   //!
        TBranch        *b_Tau_TauJetLikelihoodOld;   //!
        TBranch        *b_Tau_TauELikelihoodLowPt;   //!
        TBranch        *b_Tau_TauElTauLikelihood;   //!
        TBranch        *b_Tau_TauJetNeuralNetwork;   //!
        TBranch        *b_Tau_TauENeuralNetwork;   //!
        TBranch        *b_Tau_DiscPDERS;   //!
        TBranch        *b_Tau_DiscCutTMVA;   //!
        TBranch        *b_Tau_totTrkCharge;   //!
        TBranch        *b_Tau_totTrkE;   //!
        TBranch        *b_Tau_track1_pT;   //!
        TBranch        *b_Tau_track2_pT;   //!
        TBranch        *b_Tau_track3_pT;   //!
        TBranch        *b_Tau_track1_phi;   //!
        TBranch        *b_Tau_track2_phi;   //!
        TBranch        *b_Tau_track3_phi;   //!
        TBranch        *b_Tau_track1_eta;   //!
        TBranch        *b_Tau_track2_eta;   //!
        TBranch        *b_Tau_track3_eta;   //!
        TBranch        *b_Tau_emRadius;   //!
        TBranch        *b_Tau_isolationFraction;   //!
        TBranch        *b_Tau_stripWidth2;   //!
        TBranch        *b_Tau_sumEMpx;   //!
        TBranch        *b_Tau_sumEMpy;   //!
        TBranch        *b_Tau_sumEMpz;   //!
        TBranch        *b_Tau_sumEMe;   //!
        TBranch        *b_Tau_secVtxX;   //!
        TBranch        *b_Tau_secVtxY;   //!
        TBranch        *b_Tau_secVtxZ;   //!
        TBranch        *b_Tau_secVtxCovXX;   //!
        TBranch        *b_Tau_secVtxCovYY;   //!
        TBranch        *b_Tau_secVtxCovZZ;   //!
        TBranch        *b_Tau_secVtxCovXY;   //!
        TBranch        *b_Tau_secVtxCovYZ;   //!
        TBranch        *b_Tau_secVtxCovXZ;   //!
        TBranch        *b_Tau_secVtxChi2;   //!
        TBranch        *b_Tau_secVtxNDoF;   //!
        TBranch        *b_Tau_trFlightPathSig;   //!
        TBranch        *b_Tau_etChrgHAD;   //!
        TBranch        *b_Tau_etIsolEM;   //!
        TBranch        *b_Tau_etIsolHAD;   //!
        TBranch        *b_Tau_massTrk3P;   //!
        TBranch        *b_Tau_rWidth2Trk3P;   //!
        TBranch        *b_Tau_signD0Trk3P;   //!
        TBranch        *b_Tau_etHadAtEMScale;   //!
        TBranch        *b_Tau_etEMAtEMScale;   //!
        TBranch        *b_Tau_etEMCL;   //!
        TBranch        *b_Tau_etChrgEM;   //!
        TBranch        *b_Tau_etNeuEM;   //!
        TBranch        *b_Tau_etResNeuEM;   //!
        TBranch        *b_Tau_etChrgEM01_1Trk;   //!
        TBranch        *b_Tau_etChrgEM01_2Trk;   //!
        TBranch        *b_Tau_etChrgEM01_3Trk;   //!
        TBranch        *b_Tau_etResChrgEM_1Trk;   //!
        TBranch        *b_Tau_etResChrgEM_2Trk;   //!
        TBranch        *b_Tau_etResChrgEM_3Trk;   //!
        TBranch        *b_Tau_z0SinThetaSig;   //!
        TBranch        *b_Tau_etChrgHADoverPttot;   //!
        TBranch        *b_Tau_etIsolFrac;   //!
        TBranch        *b_Tau_etEflow;   //!
        TBranch        *b_Tau_hadronicLeak;   //!
        TBranch        *b_Tau_secondaryMax;   //!
        TBranch        *b_Tau_sumEtCellsLArOverLeadTrackPt;   //!
        TBranch        *b_Tau_centralityFraction;   //!
        TBranch        *b_Tau_etEMCalib;   //!
        TBranch        *b_Tau_etHadCalib;   //!
        TBranch        *b_Tau_trackCaloEta1;   //!
        TBranch        *b_Tau_trackCaloEta2;   //!
        TBranch        *b_Tau_trackCaloEta3;   //!
        TBranch        *b_Tau_trackCaloPhi1;   //!
        TBranch        *b_Tau_trackCaloPhi2;   //!
        TBranch        *b_Tau_trackCaloPhi3;   //!
        TBranch        *b_Tau_leadingTrackPT;   //!
        TBranch        *b_Tau_ipSigLeadTrack;   //!
        TBranch        *b_Tau_etaCalo;   //!
        TBranch        *b_Tau_phiCalo;   //!
        TBranch        *b_Tau_hadRadius;   //!
        TBranch        *b_Tau_sumEmCellEt;   //!
        TBranch        *b_Tau_sumHadCellEt;   //!
        TBranch        *b_Tau_DiscCut;   //!
        TBranch        *b_Tau_DiscNN;   //!
        TBranch        *b_Tau_EfficNN;   //!
        TBranch        *b_Tau_T_HadTau_DeltaR;   //!
        TBranch        *b_El_E;   //!
        TBranch        *b_El_p_T;   //!
        TBranch        *b_El_phi;   //!
        TBranch        *b_El_eta;   //!
        TBranch        *b_El_px;   //!
        TBranch        *b_El_py;   //!
        TBranch        *b_El_pz;   //!
        TBranch        *b_El_m;   //!
        TBranch        *b_El_charge;   //!
        TBranch        *b_El_pdgId;   //!
        TBranch        *b_El_EtaCorrMag;   //!
        TBranch        *b_El_EoverP;   //!
        TBranch        *b_El_deltaEta1;   //!
        TBranch        *b_El_deltaEta2;   //!
        TBranch        *b_El_deltaPhi2;   //!
        TBranch        *b_El_etcone20;   //!
        TBranch        *b_El_T_El_DeltaR;   //!
        TBranch        *b_Mu_E;   //!
        TBranch        *b_Mu_p_T;   //!
        TBranch        *b_Mu_phi;   //!
        TBranch        *b_Mu_eta;   //!
        TBranch        *b_Mu_px;   //!
        TBranch        *b_Mu_py;   //!
        TBranch        *b_Mu_pz;   //!
        TBranch        *b_Mu_m;   //!
        TBranch        *b_Mu_charge;   //!
        TBranch        *b_Mu_pdgId;   //!
        TBranch        *b_Mu_etcone40;   //!
        TBranch        *b_Mu_nucone40;   //!
        TBranch        *b_Mu_etcone20;   //!
        TBranch        *b_Mu_matchChi2;   //!
        TBranch        *b_Mu_matchChi2OverDoF;   //!
        TBranch        *b_Mu_SumTrkPtInCone;   //!
        TBranch        *b_Mu_T_Mu_DeltaR;   //!
        TBranch        *b_JetC4T_E;   //!
        TBranch        *b_JetC4T_p_T;   //!
        TBranch        *b_JetC4T_phi;   //!
        TBranch        *b_JetC4T_eta;   //!
        TBranch        *b_JetC4T_px;   //!
        TBranch        *b_JetC4T_py;   //!
        TBranch        *b_JetC4T_pz;   //!
        TBranch        *b_JetC4T_m;   //!
        TBranch        *b_JetC4T_charge;   //!
        TBranch        *b_JetC4T_pdgId;   //!
        TBranch        *b_JetC4T_weight;   //!
        TBranch        *b_JetC4T_SoftMuonWeight;   //!
        TBranch        *b_JetC4T_SoftElectronWeight;   //!
        TBranch        *b_JetC4T_IP1D;   //!
        TBranch        *b_JetC4T_IP2D;   //!
        TBranch        *b_JetC4T_IP3D;   //!
        TBranch        *b_JetC4T_SV1;   //!
        TBranch        *b_JetC4T_SecVtxTagBU;   //!
        TBranch        *b_JetC4T_SV2;   //!
        TBranch        *b_JetC4T_T_Jet_DeltaR;   //!
        TBranch        *b_JetC4T_T_El_DeltaR;   //!
        TBranch        *b_JetC4T_T_TauVis_DeltaR;   //!
        TBranch        *b_JetC4T_T_Ph_DeltaR;   //!
        TBranch        *b_Trk_E;   //!
        TBranch        *b_Trk_p_T;   //!
        TBranch        *b_Trk_phi;   //!
        TBranch        *b_Trk_eta;   //!
        TBranch        *b_Trk_px;   //!
        TBranch        *b_Trk_py;   //!
        TBranch        *b_Trk_pz;   //!
        TBranch        *b_Trk_m;   //!
        TBranch        *b_Trk_charge;   //!
        TBranch        *b_Trk_pdgId;   //!
        TBranch        *b_T_Tau_E;   //!
        TBranch        *b_T_Tau_p_T;   //!
        TBranch        *b_T_Tau_phi;   //!
        TBranch        *b_T_Tau_eta;   //!
        TBranch        *b_T_Tau_px;   //!
        TBranch        *b_T_Tau_py;   //!
        TBranch        *b_T_Tau_pz;   //!
        TBranch        *b_T_Tau_m;   //!
        TBranch        *b_T_Tau_charge;   //!
        TBranch        *b_T_Tau_pdgId;   //!
        TBranch        *b_T_TauVis_E;   //!
        TBranch        *b_T_TauVis_p_T;   //!
        TBranch        *b_T_TauVis_phi;   //!
        TBranch        *b_T_TauVis_eta;   //!
        TBranch        *b_T_TauVis_px;   //!
        TBranch        *b_T_TauVis_py;   //!
        TBranch        *b_T_TauVis_pz;   //!
        TBranch        *b_T_TauVis_m;   //!
        TBranch        *b_T_TauVis_charge;   //!
        TBranch        *b_T_TauVis_pdgId;   //!
        TBranch        *b_T_TauVis_T_HadTau_DeltaR;   //!
        TBranch        *b_T_Mu_E;   //!
        TBranch        *b_T_Mu_p_T;   //!
        TBranch        *b_T_Mu_phi;   //!
        TBranch        *b_T_Mu_eta;   //!
        TBranch        *b_T_Mu_px;   //!
        TBranch        *b_T_Mu_py;   //!
        TBranch        *b_T_Mu_pz;   //!
        TBranch        *b_T_Mu_m;   //!
        TBranch        *b_T_Mu_charge;   //!
        TBranch        *b_T_Mu_pdgId;   //!
        TBranch        *b_T_El_E;   //!
        TBranch        *b_T_El_p_T;   //!
        TBranch        *b_T_El_phi;   //!
        TBranch        *b_T_El_eta;   //!
        TBranch        *b_T_El_px;   //!
        TBranch        *b_T_El_py;   //!
        TBranch        *b_T_El_pz;   //!
        TBranch        *b_T_El_m;   //!
        TBranch        *b_T_El_charge;   //!
        TBranch        *b_T_El_pdgId;   //!
        TBranch        *b_T_JetC4_E;   //!
        TBranch        *b_T_JetC4_p_T;   //!
        TBranch        *b_T_JetC4_phi;   //!
        TBranch        *b_T_JetC4_eta;   //!
        TBranch        *b_T_JetC4_px;   //!
        TBranch        *b_T_JetC4_py;   //!
        TBranch        *b_T_JetC4_pz;   //!
        TBranch        *b_T_JetC4_m;   //!
        TBranch        *b_T_JetC4_charge;   //!
        TBranch        *b_T_JetC4_pdgId;   //!
        TBranch        *b_T_JetC4_T_El_DeltaR;   //!
        TBranch        *b_T_JetC4_T_Mu_DeltaR;   //!
        TBranch        *b_T_JetC4_T_Ph_DeltaR;   //!
        TBranch        *b_T_JetC4_T_TauVis_DeltaR;   //!
        TBranch        *b_T_JetC4_T_Jet_DeltaR;   //!
        TBranch        *b_Tau_isTauLoose;   //!
        TBranch        *b_Tau_isTauMedium;   //!
        TBranch        *b_Tau_isTauTight;   //!
        TBranch        *b_Tau_EgammaFlag;   //!
        TBranch        *b_Tau_numTrack;   //!
        TBranch        *b_Tau_numStripCells;   //!
        TBranch        *b_Tau_nAssocTracksCore;   //!
        TBranch        *b_Tau_nAssocTracksIsol;   //!
        TBranch        *b_Tau_numPi0;   //!
        TBranch        *b_Tau_nTracksdrdR;   //!
        TBranch        *b_Tau_numTrackDetails;   //!
        TBranch        *b_Tau_hasAuthor_TauRec;   //!
        TBranch        *b_Tau_hasAuthor_Tau1P3P;   //!
        TBranch        *b_Tau_ElectronFlag;   //!
        TBranch        *b_Tau_MuonFlag;   //!
        TBranch        *b_Tau_T_HadTau_Matched;   //!
        TBranch        *b_El_IsEM;   //!
        TBranch        *b_El_author;   //!
        TBranch        *b_El_T_El_Matched;   //!
        TBranch        *b_Mu_author;   //!
        TBranch        *b_Mu_hasCluster;   //!
        TBranch        *b_Mu_hasCombinedMuon;   //!
        TBranch        *b_Mu_nTrkInCone;   //!
        TBranch        *b_Mu_T_Mu_Matched;   //!
        TBranch        *b_JetC4T_SoftMuonNumTrack;   //!
        TBranch        *b_JetC4T_SoftElectronNumTrack;   //!
        TBranch        *b_JetC4T_T_Jet_Matched;   //!
        TBranch        *b_JetC4T_T_El_Matched;   //!
        TBranch        *b_JetC4T_T_TauVis_Matched;   //!
        TBranch        *b_JetC4T_T_Ph_Matched;   //!
        TBranch        *b_T_Tau_nParents;   //!
        TBranch        *b_T_Tau_nDecay;   //!
        TBranch        *b_T_TauVis_T_HadTau_Matched;   //!
        TBranch        *b_T_Mu_nParents;   //!
        TBranch        *b_T_Mu_nDecay;   //!
        TBranch        *b_T_El_nParents;   //!
        TBranch        *b_T_El_nDecay;   //!
        TBranch        *b_T_JetC4_T_El_Matched;   //!
        TBranch        *b_T_JetC4_T_Mu_Matched;   //!
        TBranch        *b_T_JetC4_T_Ph_Matched;   //!
        TBranch        *b_T_JetC4_T_TauVis_Matched;   //!
        TBranch        *b_T_JetC4_T_Jet_Matched;   //!
        TBranch        *b_T_Tau_ParentIDs;   //!
        TBranch        *b_T_El_ParentIDs;   //!
        TBranch        *b_Tau_Trk_pT;   //!
        TBranch        *b_Tau_Trk_phi;   //!
        TBranch        *b_Tau_Trk_eta;   //!
        TBranch        *b_Tau_Pi0_eta;   //!
        TBranch        *b_Tau_Pi0_phi;   //!
        TBranch        *b_Tau_Pi0_et;   //!
        TBranch        *b_Tau_Pi0_e;   //!
        TBranch        *b_T_Tau_DecayIDs;   //!
        TBranch        *b_T_Tau_ParentBarcodes;   //!
        TBranch        *b_T_Tau_DecayBarcodes;   //!
        TBranch        *b_T_Tau_ParentStatus;   //!
        TBranch        *b_T_Tau_DecayStatus;   //!
        TBranch        *b_T_Tau_DecayPt;   //!
        TBranch        *b_T_Tau_DecayEta;   //!
        TBranch        *b_T_Tau_ParentPt;   //!
        TBranch        *b_T_Tau_ParentEta;   //!
        TBranch        *b_T_Mu_ParentIDs;   //!
        TBranch        *b_T_Mu_ParentBarcodes;   //!
        TBranch        *b_T_Mu_ParentStatus;   //!
        TBranch        *b_T_Mu_ParentPt;   //!
        TBranch        *b_T_Mu_ParentEta;   //!
        TBranch        *b_T_Mu_DecayIDs;   //!
        TBranch        *b_T_Mu_DecayBarcodes;   //!
        TBranch        *b_T_Mu_DecayStatus;   //!
        TBranch        *b_T_Mu_DecayPt;   //!
        TBranch        *b_T_Mu_DecayEta;   //!
        TBranch        *b_T_El_DecayIDs;   //!
        TBranch        *b_T_El_ParentBarcodes;   //!
        TBranch        *b_T_El_DecayBarcodes;   //!
        TBranch        *b_T_El_ParentStatus;   //!
        TBranch        *b_T_El_DecayStatus;   //!
        TBranch        *b_T_El_DecayPt;   //!
        TBranch        *b_T_El_DecayEta;   //!
        TBranch        *b_T_El_ParentPt;   //!
        TBranch        *b_T_El_ParentEta;   //!
        TBranch        *b_ControlSampleInstance;   //!
        TBranch        *b_ControlSampleCounter;   //!
        TBranch        *b_ControlSampleEventAndInstance;   //!
        TBranch        *b_ControlSampleRunNumber;   //!
        TBranch        *b_ControlSampleNInstance;   //!

    public:
        Analyse(TTree* tree = 0);
        ~Analyse();
        Int_t    Cut(Long64_t entry);
        Int_t    GetEntry(Long64_t entry);
        Long64_t LoadTree(Long64_t entry);
        void     Loop();

#define GET_PARTICLE_VECTOR(name, nm) \
        TLorentzVector get_##name##_vector(int index) \
        { \
            return TLorentzVector((*nm##_px)[index], (*nm##_py)[index], \
                    (*nm##_pz)[index], (*nm##_E)[index]); \
        }

        GET_PARTICLE_VECTOR(electron, El)
        GET_PARTICLE_VECTOR(muon, Mu)
    };
}

#endif

#ifdef Analyse_cpp
    using namespace ba;

    Analyse::~Analyse()
    {
        if (!fChain) return;
        delete fChain->GetCurrentFile();
    }

    Int_t Analyse::GetEntry(Long64_t entry)
    {
        // Read contents of entry.
        if (!fChain) return 0;
        return fChain->GetEntry(entry);
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
        Tau_E = 0;
        Tau_p_T = 0;
        Tau_phi = 0;
        Tau_eta = 0;
        Tau_px = 0;
        Tau_py = 0;
        Tau_pz = 0;
        Tau_m = 0;
        Tau_charge = 0;
        Tau_pdgId = 0;
        Tau_Likelihood = 0;
        Tau_TauJetLikelihoodOld = 0;
        Tau_TauELikelihoodLowPt = 0;
        Tau_TauElTauLikelihood = 0;
        Tau_TauJetNeuralNetwork = 0;
        Tau_TauENeuralNetwork = 0;
        Tau_DiscPDERS = 0;
        Tau_DiscCutTMVA = 0;
        Tau_totTrkCharge = 0;
        Tau_totTrkE = 0;
        Tau_track1_pT = 0;
        Tau_track2_pT = 0;
        Tau_track3_pT = 0;
        Tau_track1_phi = 0;
        Tau_track2_phi = 0;
        Tau_track3_phi = 0;
        Tau_track1_eta = 0;
        Tau_track2_eta = 0;
        Tau_track3_eta = 0;
        Tau_emRadius = 0;
        Tau_isolationFraction = 0;
        Tau_stripWidth2 = 0;
        Tau_sumEMpx = 0;
        Tau_sumEMpy = 0;
        Tau_sumEMpz = 0;
        Tau_sumEMe = 0;
        Tau_secVtxX = 0;
        Tau_secVtxY = 0;
        Tau_secVtxZ = 0;
        Tau_secVtxCovXX = 0;
        Tau_secVtxCovYY = 0;
        Tau_secVtxCovZZ = 0;
        Tau_secVtxCovXY = 0;
        Tau_secVtxCovYZ = 0;
        Tau_secVtxCovXZ = 0;
        Tau_secVtxChi2 = 0;
        Tau_secVtxNDoF = 0;
        Tau_trFlightPathSig = 0;
        Tau_etChrgHAD = 0;
        Tau_etIsolEM = 0;
        Tau_etIsolHAD = 0;
        Tau_massTrk3P = 0;
        Tau_rWidth2Trk3P = 0;
        Tau_signD0Trk3P = 0;
        Tau_etHadAtEMScale = 0;
        Tau_etEMAtEMScale = 0;
        Tau_etEMCL = 0;
        Tau_etChrgEM = 0;
        Tau_etNeuEM = 0;
        Tau_etResNeuEM = 0;
        Tau_etChrgEM01_1Trk = 0;
        Tau_etChrgEM01_2Trk = 0;
        Tau_etChrgEM01_3Trk = 0;
        Tau_etResChrgEM_1Trk = 0;
        Tau_etResChrgEM_2Trk = 0;
        Tau_etResChrgEM_3Trk = 0;
        Tau_z0SinThetaSig = 0;
        Tau_etChrgHADoverPttot = 0;
        Tau_etIsolFrac = 0;
        Tau_etEflow = 0;
        Tau_hadronicLeak = 0;
        Tau_secondaryMax = 0;
        Tau_sumEtCellsLArOverLeadTrackPt = 0;
        Tau_centralityFraction = 0;
        Tau_etEMCalib = 0;
        Tau_etHadCalib = 0;
        Tau_trackCaloEta1 = 0;
        Tau_trackCaloEta2 = 0;
        Tau_trackCaloEta3 = 0;
        Tau_trackCaloPhi1 = 0;
        Tau_trackCaloPhi2 = 0;
        Tau_trackCaloPhi3 = 0;
        Tau_leadingTrackPT = 0;
        Tau_ipSigLeadTrack = 0;
        Tau_etaCalo = 0;
        Tau_phiCalo = 0;
        Tau_hadRadius = 0;
        Tau_sumEmCellEt = 0;
        Tau_sumHadCellEt = 0;
        Tau_DiscCut = 0;
        Tau_DiscNN = 0;
        Tau_EfficNN = 0;
        Tau_T_HadTau_DeltaR = 0;
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
        JetC4T_T_TauVis_DeltaR = 0;
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
        T_Tau_E = 0;
        T_Tau_p_T = 0;
        T_Tau_phi = 0;
        T_Tau_eta = 0;
        T_Tau_px = 0;
        T_Tau_py = 0;
        T_Tau_pz = 0;
        T_Tau_m = 0;
        T_Tau_charge = 0;
        T_Tau_pdgId = 0;
        T_TauVis_E = 0;
        T_TauVis_p_T = 0;
        T_TauVis_phi = 0;
        T_TauVis_eta = 0;
        T_TauVis_px = 0;
        T_TauVis_py = 0;
        T_TauVis_pz = 0;
        T_TauVis_m = 0;
        T_TauVis_charge = 0;
        T_TauVis_pdgId = 0;
        T_TauVis_T_HadTau_DeltaR = 0;
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
        T_JetC4_T_TauVis_DeltaR = 0;
        T_JetC4_T_Jet_DeltaR = 0;
        Tau_isTauLoose = 0;
        Tau_isTauMedium = 0;
        Tau_isTauTight = 0;
        Tau_EgammaFlag = 0;
        Tau_numTrack = 0;
        Tau_numStripCells = 0;
        Tau_nAssocTracksCore = 0;
        Tau_nAssocTracksIsol = 0;
        Tau_numPi0 = 0;
        Tau_nTracksdrdR = 0;
        Tau_numTrackDetails = 0;
        Tau_hasAuthor_TauRec = 0;
        Tau_hasAuthor_Tau1P3P = 0;
        Tau_ElectronFlag = 0;
        Tau_MuonFlag = 0;
        Tau_T_HadTau_Matched = 0;
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
        JetC4T_T_TauVis_Matched = 0;
        JetC4T_T_Ph_Matched = 0;
        T_Tau_nParents = 0;
        T_Tau_nDecay = 0;
        T_TauVis_T_HadTau_Matched = 0;
        T_Mu_nParents = 0;
        T_Mu_nDecay = 0;
        T_El_nParents = 0;
        T_El_nDecay = 0;
        T_JetC4_T_El_Matched = 0;
        T_JetC4_T_Mu_Matched = 0;
        T_JetC4_T_Ph_Matched = 0;
        T_JetC4_T_TauVis_Matched = 0;
        T_JetC4_T_Jet_Matched = 0;
        T_Tau_ParentIDs = 0;
        T_El_ParentIDs = 0;
        Tau_Trk_pT = 0;
        Tau_Trk_phi = 0;
        Tau_Trk_eta = 0;
        Tau_Pi0_eta = 0;
        Tau_Pi0_phi = 0;
        Tau_Pi0_et = 0;
        Tau_Pi0_e = 0;
        T_Tau_DecayIDs = 0;
        T_Tau_ParentBarcodes = 0;
        T_Tau_DecayBarcodes = 0;
        T_Tau_ParentStatus = 0;
        T_Tau_DecayStatus = 0;
        T_Tau_DecayPt = 0;
        T_Tau_DecayEta = 0;
        T_Tau_ParentPt = 0;
        T_Tau_ParentEta = 0;
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
        fChain->SetMakeClass(1);

        fChain->SetBranchAddress("MET_RefFinal_ex", &MET_RefFinal_ex, &b_MET_RefFinal_ex);
        fChain->SetBranchAddress("MET_RefFinal_ey", &MET_RefFinal_ey, &b_MET_RefFinal_ey);
        fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
        fChain->SetBranchAddress("MET_RefFinal_sumet", &MET_RefFinal_sumet, &b_MET_RefFinal_sumet);
        fChain->SetBranchAddress("MET_RefEle_ex", &MET_RefEle_ex, &b_MET_RefEle_ex);
        fChain->SetBranchAddress("MET_RefEle_ey", &MET_RefEle_ey, &b_MET_RefEle_ey);
        fChain->SetBranchAddress("MET_RefEle_et", &MET_RefEle_et, &b_MET_RefEle_et);
        fChain->SetBranchAddress("MET_RefEle_sumet", &MET_RefEle_sumet, &b_MET_RefEle_sumet);
        fChain->SetBranchAddress("MET_RefMuon_ex", &MET_RefMuon_ex, &b_MET_RefMuon_ex);
        fChain->SetBranchAddress("MET_RefMuon_ey", &MET_RefMuon_ey, &b_MET_RefMuon_ey);
        fChain->SetBranchAddress("MET_RefMuon_et", &MET_RefMuon_et, &b_MET_RefMuon_et);
        fChain->SetBranchAddress("MET_RefMuon_sumet", &MET_RefMuon_sumet, &b_MET_RefMuon_sumet);
        fChain->SetBranchAddress("MET_RefJet_ex", &MET_RefJet_ex, &b_MET_RefJet_ex);
        fChain->SetBranchAddress("MET_RefJet_ey", &MET_RefJet_ey, &b_MET_RefJet_ey);
        fChain->SetBranchAddress("MET_RefJet_et", &MET_RefJet_et, &b_MET_RefJet_et);
        fChain->SetBranchAddress("MET_RefJet_sumet", &MET_RefJet_sumet, &b_MET_RefJet_sumet);
        fChain->SetBranchAddress("MET_RefGamma_ex", &MET_RefGamma_ex, &b_MET_RefGamma_ex);
        fChain->SetBranchAddress("MET_RefGamma_ey", &MET_RefGamma_ey, &b_MET_RefGamma_ey);
        fChain->SetBranchAddress("MET_RefGamma_et", &MET_RefGamma_et, &b_MET_RefGamma_et);
        fChain->SetBranchAddress("MET_RefGamma_sumet", &MET_RefGamma_sumet, &b_MET_RefGamma_sumet);
        fChain->SetBranchAddress("MET_RefTau_ex", &MET_RefTau_ex, &b_MET_RefTau_ex);
        fChain->SetBranchAddress("MET_RefTau_ey", &MET_RefTau_ey, &b_MET_RefTau_ey);
        fChain->SetBranchAddress("MET_RefTau_et", &MET_RefTau_et, &b_MET_RefTau_et);
        fChain->SetBranchAddress("MET_RefTau_sumet", &MET_RefTau_sumet, &b_MET_RefTau_sumet);
        fChain->SetBranchAddress("MET_CellOut_ex", &MET_CellOut_ex, &b_MET_CellOut_ex);
        fChain->SetBranchAddress("MET_CellOut_ey", &MET_CellOut_ey, &b_MET_CellOut_ey);
        fChain->SetBranchAddress("MET_CellOut_et", &MET_CellOut_et, &b_MET_CellOut_et);
        fChain->SetBranchAddress("MET_CellOut_sumet", &MET_CellOut_sumet, &b_MET_CellOut_sumet);
        fChain->SetBranchAddress("MET_MuonBoy_ex", &MET_MuonBoy_ex, &b_MET_MuonBoy_ex);
        fChain->SetBranchAddress("MET_MuonBoy_ey", &MET_MuonBoy_ey, &b_MET_MuonBoy_ey);
        fChain->SetBranchAddress("MET_MuonBoy_et", &MET_MuonBoy_et, &b_MET_MuonBoy_et);
        fChain->SetBranchAddress("MET_MuonBoy_sumet", &MET_MuonBoy_sumet, &b_MET_MuonBoy_sumet);
        fChain->SetBranchAddress("MET_CryoCone_ex", &MET_CryoCone_ex, &b_MET_CryoCone_ex);
        fChain->SetBranchAddress("MET_CryoCone_ey", &MET_CryoCone_ey, &b_MET_CryoCone_ey);
        fChain->SetBranchAddress("MET_CryoCone_et", &MET_CryoCone_et, &b_MET_CryoCone_et);
        fChain->SetBranchAddress("MET_CryoCone_sumet", &MET_CryoCone_sumet, &b_MET_CryoCone_sumet);
        fChain->SetBranchAddress("MET_LocHadTopoObj_ex", &MET_LocHadTopoObj_ex, &b_MET_LocHadTopoObj_ex);
        fChain->SetBranchAddress("MET_LocHadTopoObj_ey", &MET_LocHadTopoObj_ey, &b_MET_LocHadTopoObj_ey);
        fChain->SetBranchAddress("MET_LocHadTopoObj_et", &MET_LocHadTopoObj_et, &b_MET_LocHadTopoObj_et);
        fChain->SetBranchAddress("MET_LocHadTopoObj_sumet", &MET_LocHadTopoObj_sumet, &b_MET_LocHadTopoObj_sumet);
        fChain->SetBranchAddress("MET_LocHadTopo_ex", &MET_LocHadTopo_ex, &b_MET_LocHadTopo_ex);
        fChain->SetBranchAddress("MET_LocHadTopo_ey", &MET_LocHadTopo_ey, &b_MET_LocHadTopo_ey);
        fChain->SetBranchAddress("MET_LocHadTopo_et", &MET_LocHadTopo_et, &b_MET_LocHadTopo_et);
        fChain->SetBranchAddress("MET_LocHadTopo_sumet", &MET_LocHadTopo_sumet, &b_MET_LocHadTopo_sumet);
        fChain->SetBranchAddress("MET_Truth_Int_ex", &MET_Truth_Int_ex, &b_MET_Truth_Int_ex);
        fChain->SetBranchAddress("MET_Truth_Int_ey", &MET_Truth_Int_ey, &b_MET_Truth_Int_ey);
        fChain->SetBranchAddress("MET_Truth_Int_et", &MET_Truth_Int_et, &b_MET_Truth_Int_et);
        fChain->SetBranchAddress("MET_Truth_Int_sumet", &MET_Truth_Int_sumet, &b_MET_Truth_Int_sumet);
        fChain->SetBranchAddress("MET_Truth_NonInt_ex", &MET_Truth_NonInt_ex, &b_MET_Truth_NonInt_ex);
        fChain->SetBranchAddress("MET_Truth_NonInt_ey", &MET_Truth_NonInt_ey, &b_MET_Truth_NonInt_ey);
        fChain->SetBranchAddress("MET_Truth_NonInt_et", &MET_Truth_NonInt_et, &b_MET_Truth_NonInt_et);
        fChain->SetBranchAddress("MET_Truth_NonInt_sumet", &MET_Truth_NonInt_sumet, &b_MET_Truth_NonInt_sumet);
        fChain->SetBranchAddress("MET_Truth_IntCentral_ex", &MET_Truth_IntCentral_ex, &b_MET_Truth_IntCentral_ex);
        fChain->SetBranchAddress("MET_Truth_IntCentral_ey", &MET_Truth_IntCentral_ey, &b_MET_Truth_IntCentral_ey);
        fChain->SetBranchAddress("MET_Truth_IntCentral_et", &MET_Truth_IntCentral_et, &b_MET_Truth_IntCentral_et);
        fChain->SetBranchAddress("MET_Truth_IntCentral_sumet", &MET_Truth_IntCentral_sumet, &b_MET_Truth_IntCentral_sumet);
        fChain->SetBranchAddress("MET_Truth_IntFwd_ex", &MET_Truth_IntFwd_ex, &b_MET_Truth_IntFwd_ex);
        fChain->SetBranchAddress("MET_Truth_IntFwd_ey", &MET_Truth_IntFwd_ey, &b_MET_Truth_IntFwd_ey);
        fChain->SetBranchAddress("MET_Truth_IntFwd_et", &MET_Truth_IntFwd_et, &b_MET_Truth_IntFwd_et);
        fChain->SetBranchAddress("MET_Truth_IntFwd_sumet", &MET_Truth_IntFwd_sumet, &b_MET_Truth_IntFwd_sumet);
        fChain->SetBranchAddress("MET_Truth_IntOutCover_ex", &MET_Truth_IntOutCover_ex, &b_MET_Truth_IntOutCover_ex);
        fChain->SetBranchAddress("MET_Truth_IntOutCover_ey", &MET_Truth_IntOutCover_ey, &b_MET_Truth_IntOutCover_ey);
        fChain->SetBranchAddress("MET_Truth_IntOutCover_et", &MET_Truth_IntOutCover_et, &b_MET_Truth_IntOutCover_et);
        fChain->SetBranchAddress("MET_Truth_IntOutCover_sumet", &MET_Truth_IntOutCover_sumet, &b_MET_Truth_IntOutCover_sumet);
        fChain->SetBranchAddress("MET_Truth_Muons_ex", &MET_Truth_Muons_ex, &b_MET_Truth_Muons_ex);
        fChain->SetBranchAddress("MET_Truth_Muons_ey", &MET_Truth_Muons_ey, &b_MET_Truth_Muons_ey);
        fChain->SetBranchAddress("MET_Truth_Muons_et", &MET_Truth_Muons_et, &b_MET_Truth_Muons_et);
        fChain->SetBranchAddress("MET_Truth_Muons_sumet", &MET_Truth_Muons_sumet, &b_MET_Truth_Muons_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_Int_ex", &MET_Truth_PileUp_Int_ex, &b_MET_Truth_PileUp_Int_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_Int_ey", &MET_Truth_PileUp_Int_ey, &b_MET_Truth_PileUp_Int_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_Int_et", &MET_Truth_PileUp_Int_et, &b_MET_Truth_PileUp_Int_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_Int_sumet", &MET_Truth_PileUp_Int_sumet, &b_MET_Truth_PileUp_Int_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_ex", &MET_Truth_PileUp_NonInt_ex, &b_MET_Truth_PileUp_NonInt_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_ey", &MET_Truth_PileUp_NonInt_ey, &b_MET_Truth_PileUp_NonInt_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_et", &MET_Truth_PileUp_NonInt_et, &b_MET_Truth_PileUp_NonInt_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_NonInt_sumet", &MET_Truth_PileUp_NonInt_sumet, &b_MET_Truth_PileUp_NonInt_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_ex", &MET_Truth_PileUp_IntCentral_ex, &b_MET_Truth_PileUp_IntCentral_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_ey", &MET_Truth_PileUp_IntCentral_ey, &b_MET_Truth_PileUp_IntCentral_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_et", &MET_Truth_PileUp_IntCentral_et, &b_MET_Truth_PileUp_IntCentral_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntCentral_sumet", &MET_Truth_PileUp_IntCentral_sumet, &b_MET_Truth_PileUp_IntCentral_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_ex", &MET_Truth_PileUp_IntFwd_ex, &b_MET_Truth_PileUp_IntFwd_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_ey", &MET_Truth_PileUp_IntFwd_ey, &b_MET_Truth_PileUp_IntFwd_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_et", &MET_Truth_PileUp_IntFwd_et, &b_MET_Truth_PileUp_IntFwd_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntFwd_sumet", &MET_Truth_PileUp_IntFwd_sumet, &b_MET_Truth_PileUp_IntFwd_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_ex", &MET_Truth_PileUp_IntOutCover_ex, &b_MET_Truth_PileUp_IntOutCover_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_ey", &MET_Truth_PileUp_IntOutCover_ey, &b_MET_Truth_PileUp_IntOutCover_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_et", &MET_Truth_PileUp_IntOutCover_et, &b_MET_Truth_PileUp_IntOutCover_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_IntOutCover_sumet", &MET_Truth_PileUp_IntOutCover_sumet, &b_MET_Truth_PileUp_IntOutCover_sumet);
        fChain->SetBranchAddress("MET_Truth_PileUp_Muons_ex", &MET_Truth_PileUp_Muons_ex, &b_MET_Truth_PileUp_Muons_ex);
        fChain->SetBranchAddress("MET_Truth_PileUp_Muons_ey", &MET_Truth_PileUp_Muons_ey, &b_MET_Truth_PileUp_Muons_ey);
        fChain->SetBranchAddress("MET_Truth_PileUp_Muons_et", &MET_Truth_PileUp_Muons_et, &b_MET_Truth_PileUp_Muons_et);
        fChain->SetBranchAddress("MET_Truth_PileUp_Muons_sumet", &MET_Truth_PileUp_Muons_sumet, &b_MET_Truth_PileUp_Muons_sumet);
        fChain->SetBranchAddress("PassedTrigger", &PassedTrigger, &b_PassedTrigger);
        fChain->SetBranchAddress("PassedL1", &PassedL1, &b_PassedL1);
        fChain->SetBranchAddress("PassedL2", &PassedL2, &b_PassedL2);
        fChain->SetBranchAddress("PassedEF", &PassedEF, &b_PassedEF);
        fChain->SetBranchAddress("Passed", &Passed, &b_Passed);
        fChain->SetBranchAddress("PassedL1_EM3", &PassedL1_EM3, &b_PassedL1_EM3);
        fChain->SetBranchAddress("PassedL1_EM7", &PassedL1_EM7, &b_PassedL1_EM7);
        fChain->SetBranchAddress("PassedL1_2TAU6_TAU25", &PassedL1_2TAU6_TAU25, &b_PassedL1_2TAU6_TAU25);
        fChain->SetBranchAddress("PassedL1_EM13", &PassedL1_EM13, &b_PassedL1_EM13);
        fChain->SetBranchAddress("PassedL1_EM13I", &PassedL1_EM13I, &b_PassedL1_EM13I);
        fChain->SetBranchAddress("PassedL1_EM18", &PassedL1_EM18, &b_PassedL1_EM18);
        fChain->SetBranchAddress("PassedL1_EM18I", &PassedL1_EM18I, &b_PassedL1_EM18I);
        fChain->SetBranchAddress("PassedL1_EM23I", &PassedL1_EM23I, &b_PassedL1_EM23I);
        fChain->SetBranchAddress("PassedL1_EM100", &PassedL1_EM100, &b_PassedL1_EM100);
        fChain->SetBranchAddress("PassedL1_TAU25I_XE20", &PassedL1_TAU25I_XE20, &b_PassedL1_TAU25I_XE20);
        fChain->SetBranchAddress("PassedL1_2EM3", &PassedL1_2EM3, &b_PassedL1_2EM3);
        fChain->SetBranchAddress("PassedL1_2EM7", &PassedL1_2EM7, &b_PassedL1_2EM7);
        fChain->SetBranchAddress("PassedL1_TAU25_XE40", &PassedL1_TAU25_XE40, &b_PassedL1_TAU25_XE40);
        fChain->SetBranchAddress("PassedL1_2EM13", &PassedL1_2EM13, &b_PassedL1_2EM13);
        fChain->SetBranchAddress("PassedL1_2EM13I", &PassedL1_2EM13I, &b_PassedL1_2EM13I);
        fChain->SetBranchAddress("PassedL1_2EM18", &PassedL1_2EM18, &b_PassedL1_2EM18);
        fChain->SetBranchAddress("PassedL1_2EM18I", &PassedL1_2EM18I, &b_PassedL1_2EM18I);
        fChain->SetBranchAddress("PassedL1_2EM23I", &PassedL1_2EM23I, &b_PassedL1_2EM23I);
        fChain->SetBranchAddress("PassedL1_2EM3_EM7", &PassedL1_2EM3_EM7, &b_PassedL1_2EM3_EM7);
        fChain->SetBranchAddress("PassedL1_3EM7", &PassedL1_3EM7, &b_PassedL1_3EM7);
        fChain->SetBranchAddress("PassedL1_RD0_FILLED", &PassedL1_RD0_FILLED, &b_PassedL1_RD0_FILLED);
        fChain->SetBranchAddress("PassedL1_MU4", &PassedL1_MU4, &b_PassedL1_MU4);
        fChain->SetBranchAddress("PassedL1_MU6", &PassedL1_MU6, &b_PassedL1_MU6);
        fChain->SetBranchAddress("PassedL1_MU10", &PassedL1_MU10, &b_PassedL1_MU10);
        fChain->SetBranchAddress("PassedL1_MU11", &PassedL1_MU11, &b_PassedL1_MU11);
        fChain->SetBranchAddress("PassedL1_MU20", &PassedL1_MU20, &b_PassedL1_MU20);
        fChain->SetBranchAddress("PassedL1_MU40", &PassedL1_MU40, &b_PassedL1_MU40);
        fChain->SetBranchAddress("PassedL1_2MU4", &PassedL1_2MU4, &b_PassedL1_2MU4);
        fChain->SetBranchAddress("PassedL1_2MU6", &PassedL1_2MU6, &b_PassedL1_2MU6);
        fChain->SetBranchAddress("PassedL1_2MU10", &PassedL1_2MU10, &b_PassedL1_2MU10);
        fChain->SetBranchAddress("PassedL1_2MU11", &PassedL1_2MU11, &b_PassedL1_2MU11);
        fChain->SetBranchAddress("PassedL1_2MU20", &PassedL1_2MU20, &b_PassedL1_2MU20);
        fChain->SetBranchAddress("PassedL1_3MU6", &PassedL1_3MU6, &b_PassedL1_3MU6);
        fChain->SetBranchAddress("PassedL1_2MU4_MU6", &PassedL1_2MU4_MU6, &b_PassedL1_2MU4_MU6);
        fChain->SetBranchAddress("PassedL1_TAU5", &PassedL1_TAU5, &b_PassedL1_TAU5);
        fChain->SetBranchAddress("PassedL1_TAU6", &PassedL1_TAU6, &b_PassedL1_TAU6);
        fChain->SetBranchAddress("PassedL1_TAU9I", &PassedL1_TAU9I, &b_PassedL1_TAU9I);
        fChain->SetBranchAddress("PassedL1_TAU11I", &PassedL1_TAU11I, &b_PassedL1_TAU11I);
        fChain->SetBranchAddress("PassedL1_TAU16I", &PassedL1_TAU16I, &b_PassedL1_TAU16I);
        fChain->SetBranchAddress("PassedL1_TAU25", &PassedL1_TAU25, &b_PassedL1_TAU25);
        fChain->SetBranchAddress("PassedL1_TAU25I", &PassedL1_TAU25I, &b_PassedL1_TAU25I);
        fChain->SetBranchAddress("PassedL1_TAU40", &PassedL1_TAU40, &b_PassedL1_TAU40);
        fChain->SetBranchAddress("PassedL1_2TAU6", &PassedL1_2TAU6, &b_PassedL1_2TAU6);
        fChain->SetBranchAddress("PassedL1_2TAU9I", &PassedL1_2TAU9I, &b_PassedL1_2TAU9I);
        fChain->SetBranchAddress("PassedL1_2TAU6_TAU16I", &PassedL1_2TAU6_TAU16I, &b_PassedL1_2TAU6_TAU16I);
        fChain->SetBranchAddress("PassedL1_2TAU16I", &PassedL1_2TAU16I, &b_PassedL1_2TAU16I);
        fChain->SetBranchAddress("PassedL1_J5", &PassedL1_J5, &b_PassedL1_J5);
        fChain->SetBranchAddress("PassedL1_J10", &PassedL1_J10, &b_PassedL1_J10);
        fChain->SetBranchAddress("PassedL1_J18", &PassedL1_J18, &b_PassedL1_J18);
        fChain->SetBranchAddress("PassedL1_J23", &PassedL1_J23, &b_PassedL1_J23);
        fChain->SetBranchAddress("PassedL1_J35", &PassedL1_J35, &b_PassedL1_J35);
        fChain->SetBranchAddress("PassedL1_J42", &PassedL1_J42, &b_PassedL1_J42);
        fChain->SetBranchAddress("PassedL1_J70", &PassedL1_J70, &b_PassedL1_J70);
        fChain->SetBranchAddress("PassedL1_J120", &PassedL1_J120, &b_PassedL1_J120);
        fChain->SetBranchAddress("PassedL1_4J10", &PassedL1_4J10, &b_PassedL1_4J10);
        fChain->SetBranchAddress("PassedL1_3J18", &PassedL1_3J18, &b_PassedL1_3J18);
        fChain->SetBranchAddress("PassedL1_3J23", &PassedL1_3J23, &b_PassedL1_3J23);
        fChain->SetBranchAddress("PassedL1_4J18", &PassedL1_4J18, &b_PassedL1_4J18);
        fChain->SetBranchAddress("PassedL1_4J23", &PassedL1_4J23, &b_PassedL1_4J23);
        fChain->SetBranchAddress("PassedL1_4J35", &PassedL1_4J35, &b_PassedL1_4J35);
        fChain->SetBranchAddress("PassedL1_3J70", &PassedL1_3J70, &b_PassedL1_3J70);
        fChain->SetBranchAddress("PassedL1_FJ18", &PassedL1_FJ18, &b_PassedL1_FJ18);
        fChain->SetBranchAddress("PassedL1_FJ35", &PassedL1_FJ35, &b_PassedL1_FJ35);
        fChain->SetBranchAddress("PassedL1_FJ70", &PassedL1_FJ70, &b_PassedL1_FJ70);
        fChain->SetBranchAddress("PassedL1_FJ120", &PassedL1_FJ120, &b_PassedL1_FJ120);
        fChain->SetBranchAddress("PassedL1_2FJ18", &PassedL1_2FJ18, &b_PassedL1_2FJ18);
        fChain->SetBranchAddress("PassedL1_2FJ35", &PassedL1_2FJ35, &b_PassedL1_2FJ35);
        fChain->SetBranchAddress("PassedL1_2FJ70", &PassedL1_2FJ70, &b_PassedL1_2FJ70);
        fChain->SetBranchAddress("PassedL1_3J10", &PassedL1_3J10, &b_PassedL1_3J10);
        fChain->SetBranchAddress("PassedL1_XE15", &PassedL1_XE15, &b_PassedL1_XE15);
        fChain->SetBranchAddress("PassedL1_XE20", &PassedL1_XE20, &b_PassedL1_XE20);
        fChain->SetBranchAddress("PassedL1_XE25", &PassedL1_XE25, &b_PassedL1_XE25);
        fChain->SetBranchAddress("PassedL1_XE30", &PassedL1_XE30, &b_PassedL1_XE30);
        fChain->SetBranchAddress("PassedL1_XE40", &PassedL1_XE40, &b_PassedL1_XE40);
        fChain->SetBranchAddress("PassedL1_XE50", &PassedL1_XE50, &b_PassedL1_XE50);
        fChain->SetBranchAddress("PassedL1_XE70", &PassedL1_XE70, &b_PassedL1_XE70);
        fChain->SetBranchAddress("PassedL1_XE80", &PassedL1_XE80, &b_PassedL1_XE80);
        fChain->SetBranchAddress("PassedL1_TE150", &PassedL1_TE150, &b_PassedL1_TE150);
        fChain->SetBranchAddress("PassedL1_TE250", &PassedL1_TE250, &b_PassedL1_TE250);
        fChain->SetBranchAddress("PassedL1_TE360", &PassedL1_TE360, &b_PassedL1_TE360);
        fChain->SetBranchAddress("PassedL1_TE650", &PassedL1_TE650, &b_PassedL1_TE650);
        fChain->SetBranchAddress("PassedL1_JE120", &PassedL1_JE120, &b_PassedL1_JE120);
        fChain->SetBranchAddress("PassedL1_JE220", &PassedL1_JE220, &b_PassedL1_JE220);
        fChain->SetBranchAddress("PassedL1_JE280", &PassedL1_JE280, &b_PassedL1_JE280);
        fChain->SetBranchAddress("PassedL1_JE340", &PassedL1_JE340, &b_PassedL1_JE340);
        fChain->SetBranchAddress("PassedL1_EM13_XE20", &PassedL1_EM13_XE20, &b_PassedL1_EM13_XE20);
        fChain->SetBranchAddress("PassedL1_EM18_XE15", &PassedL1_EM18_XE15, &b_PassedL1_EM18_XE15);
        fChain->SetBranchAddress("PassedL1_2EM7_MU6", &PassedL1_2EM7_MU6, &b_PassedL1_2EM7_MU6);
        fChain->SetBranchAddress("PassedL1_2EM13_MU6", &PassedL1_2EM13_MU6, &b_PassedL1_2EM13_MU6);
        fChain->SetBranchAddress("PassedL1_2EM18_MU6", &PassedL1_2EM18_MU6, &b_PassedL1_2EM18_MU6);
        fChain->SetBranchAddress("PassedL1_EM7_MU6", &PassedL1_EM7_MU6, &b_PassedL1_EM7_MU6);
        fChain->SetBranchAddress("PassedL1_EM7_XE30", &PassedL1_EM7_XE30, &b_PassedL1_EM7_XE30);
        fChain->SetBranchAddress("PassedL1_2EM3_TAU6", &PassedL1_2EM3_TAU6, &b_PassedL1_2EM3_TAU6);
        fChain->SetBranchAddress("PassedL1_EM18_XE30", &PassedL1_EM18_XE30, &b_PassedL1_EM18_XE30);
        fChain->SetBranchAddress("PassedL1_EM13_MU11", &PassedL1_EM13_MU11, &b_PassedL1_EM13_MU11);
        fChain->SetBranchAddress("PassedL1_EM13I_MU11", &PassedL1_EM13I_MU11, &b_PassedL1_EM13I_MU11);
        fChain->SetBranchAddress("PassedL1_2TAU6_EM7", &PassedL1_2TAU6_EM7, &b_PassedL1_2TAU6_EM7);
        fChain->SetBranchAddress("PassedL1_2TAU6_TAU9I_EM7", &PassedL1_2TAU6_TAU9I_EM7, &b_PassedL1_2TAU6_TAU9I_EM7);
        fChain->SetBranchAddress("PassedL1_2TAU6_TAU11I_EM7", &PassedL1_2TAU6_TAU11I_EM7, &b_PassedL1_2TAU6_TAU11I_EM7);
        fChain->SetBranchAddress("PassedL1_2TAU9I_EM13I", &PassedL1_2TAU9I_EM13I, &b_PassedL1_2TAU9I_EM13I);
        fChain->SetBranchAddress("PassedL1_MU11_XE15", &PassedL1_MU11_XE15, &b_PassedL1_MU11_XE15);
        fChain->SetBranchAddress("PassedL1_MU4_J5", &PassedL1_MU4_J5, &b_PassedL1_MU4_J5);
        fChain->SetBranchAddress("PassedL1_MU4_J10", &PassedL1_MU4_J10, &b_PassedL1_MU4_J10);
        fChain->SetBranchAddress("PassedL1_MU4_J18", &PassedL1_MU4_J18, &b_PassedL1_MU4_J18);
        fChain->SetBranchAddress("PassedL1_MU4_J23", &PassedL1_MU4_J23, &b_PassedL1_MU4_J23);
        fChain->SetBranchAddress("PassedL1_MU4_J35", &PassedL1_MU4_J35, &b_PassedL1_MU4_J35);
        fChain->SetBranchAddress("PassedL1_MU4_J42", &PassedL1_MU4_J42, &b_PassedL1_MU4_J42);
        fChain->SetBranchAddress("PassedL1_MU4_EM3", &PassedL1_MU4_EM3, &b_PassedL1_MU4_EM3);
        fChain->SetBranchAddress("PassedL1_MU6_J5", &PassedL1_MU6_J5, &b_PassedL1_MU6_J5);
        fChain->SetBranchAddress("PassedL1_MU6_EM3", &PassedL1_MU6_EM3, &b_PassedL1_MU6_EM3);
        fChain->SetBranchAddress("PassedL1_2MU6_EM7", &PassedL1_2MU6_EM7, &b_PassedL1_2MU6_EM7);
        fChain->SetBranchAddress("PassedL1_MU20_XE30", &PassedL1_MU20_XE30, &b_PassedL1_MU20_XE30);
        fChain->SetBranchAddress("PassedL1_MU10_J18", &PassedL1_MU10_J18, &b_PassedL1_MU10_J18);
        fChain->SetBranchAddress("PassedL1_TAU9I_MU6", &PassedL1_TAU9I_MU6, &b_PassedL1_TAU9I_MU6);
        fChain->SetBranchAddress("PassedL1_TAU9I_MU10", &PassedL1_TAU9I_MU10, &b_PassedL1_TAU9I_MU10);
        fChain->SetBranchAddress("PassedL1_TAU11I_MU6", &PassedL1_TAU11I_MU6, &b_PassedL1_TAU11I_MU6);
        fChain->SetBranchAddress("PassedL1_TAU11I_MU10", &PassedL1_TAU11I_MU10, &b_PassedL1_TAU11I_MU10);
        fChain->SetBranchAddress("PassedL1_TAU11I_MU20", &PassedL1_TAU11I_MU20, &b_PassedL1_TAU11I_MU20);
        fChain->SetBranchAddress("PassedL1_J70_XE30", &PassedL1_J70_XE30, &b_PassedL1_J70_XE30);
        fChain->SetBranchAddress("PassedL1_2J42_XE30", &PassedL1_2J42_XE30, &b_PassedL1_2J42_XE30);
        fChain->SetBranchAddress("PassedL1_J42_XE30_EM13I", &PassedL1_J42_XE30_EM13I, &b_PassedL1_J42_XE30_EM13I);
        fChain->SetBranchAddress("PassedL1_J42_XE30_MU11", &PassedL1_J42_XE30_MU11, &b_PassedL1_J42_XE30_MU11);
        fChain->SetBranchAddress("PassedL1_4J23_EM13I", &PassedL1_4J23_EM13I, &b_PassedL1_4J23_EM13I);
        fChain->SetBranchAddress("PassedL1_4J23_MU11", &PassedL1_4J23_MU11, &b_PassedL1_4J23_MU11);
        fChain->SetBranchAddress("PassedL1_TAU6_XE20", &PassedL1_TAU6_XE20, &b_PassedL1_TAU6_XE20);
        fChain->SetBranchAddress("PassedL1_TAU9I_XE20", &PassedL1_TAU9I_XE20, &b_PassedL1_TAU9I_XE20);
        fChain->SetBranchAddress("PassedL1_TAU9I_XE30", &PassedL1_TAU9I_XE30, &b_PassedL1_TAU9I_XE30);
        fChain->SetBranchAddress("PassedL1_TAU9I_XE40", &PassedL1_TAU9I_XE40, &b_PassedL1_TAU9I_XE40);
        fChain->SetBranchAddress("PassedL1_TAU11I_XE30", &PassedL1_TAU11I_XE30, &b_PassedL1_TAU11I_XE30);
        fChain->SetBranchAddress("PassedL1_TAU16I_XE20", &PassedL1_TAU16I_XE20, &b_PassedL1_TAU16I_XE20);
        fChain->SetBranchAddress("PassedL1_TAU16I_XE30", &PassedL1_TAU16I_XE30, &b_PassedL1_TAU16I_XE30);
        fChain->SetBranchAddress("PassedL1_TAU16I_XE40", &PassedL1_TAU16I_XE40, &b_PassedL1_TAU16I_XE40);
        fChain->SetBranchAddress("PassedL1_2TAU11I_EM23I", &PassedL1_2TAU11I_EM23I, &b_PassedL1_2TAU11I_EM23I);
        fChain->SetBranchAddress("PassedL1_TAU9I_2J5_J35", &PassedL1_TAU9I_2J5_J35, &b_PassedL1_TAU9I_2J5_J35);
        fChain->SetBranchAddress("PassedL1_TAU11I_2J5_J18", &PassedL1_TAU11I_2J5_J18, &b_PassedL1_TAU11I_2J5_J18);
        fChain->SetBranchAddress("PassedL1_TAU11I_2J5_J35", &PassedL1_TAU11I_2J5_J35, &b_PassedL1_TAU11I_2J5_J35);
        fChain->SetBranchAddress("PassedL1_TAU9I_5J5_4J23", &PassedL1_TAU9I_5J5_4J23, &b_PassedL1_TAU9I_5J5_4J23);
        fChain->SetBranchAddress("PassedL1_TAU9I_3J5_2J23", &PassedL1_TAU9I_3J5_2J23, &b_PassedL1_TAU9I_3J5_2J23);
        fChain->SetBranchAddress("PassedL1_TAU11I_3J5_2J23", &PassedL1_TAU11I_3J5_2J23, &b_PassedL1_TAU11I_3J5_2J23);
        fChain->SetBranchAddress("PassedL1_TAU6_2J5_J35", &PassedL1_TAU6_2J5_J35, &b_PassedL1_TAU6_2J5_J35);
        fChain->SetBranchAddress("PassedL1_TAU6_3J5_J42", &PassedL1_TAU6_3J5_J42, &b_PassedL1_TAU6_3J5_J42);
        fChain->SetBranchAddress("PassedL1_TAU6_3J5_2J42_XE30", &PassedL1_TAU6_3J5_2J42_XE30, &b_PassedL1_TAU6_3J5_2J42_XE30);
        fChain->SetBranchAddress("PassedL1_MBTS_1", &PassedL1_MBTS_1, &b_PassedL1_MBTS_1);
        fChain->SetBranchAddress("PassedL1_MBTS_2", &PassedL1_MBTS_2, &b_PassedL1_MBTS_2);
        fChain->SetBranchAddress("PassedL1_MBTS_1_1", &PassedL1_MBTS_1_1, &b_PassedL1_MBTS_1_1);
        fChain->SetBranchAddress("PassedL2_te650", &PassedL2_te650, &b_PassedL2_te650);
        fChain->SetBranchAddress("PassedL2_g25_xe30", &PassedL2_g25_xe30, &b_PassedL2_g25_xe30);
        fChain->SetBranchAddress("PassedL2_mu4_j10_matched", &PassedL2_mu4_j10_matched, &b_PassedL2_mu4_j10_matched);
        fChain->SetBranchAddress("PassedL2_e10_mu6", &PassedL2_e10_mu6, &b_PassedL2_e10_mu6);
        fChain->SetBranchAddress("PassedL2_MU4_Upsimumu_FS", &PassedL2_MU4_Upsimumu_FS, &b_PassedL2_MU4_Upsimumu_FS);
        fChain->SetBranchAddress("PassedL2_g20_xe15", &PassedL2_g20_xe15, &b_PassedL2_g20_xe15);
        fChain->SetBranchAddress("PassedL2_tau16i_j70_WO", &PassedL2_tau16i_j70_WO, &b_PassedL2_tau16i_j70_WO);
        fChain->SetBranchAddress("PassedL2_tau12_loose", &PassedL2_tau12_loose, &b_PassedL2_tau12_loose);
        fChain->SetBranchAddress("PassedL2_tau38i_loose", &PassedL2_tau38i_loose, &b_PassedL2_tau38i_loose);
        fChain->SetBranchAddress("PassedL2_tau12_PT", &PassedL2_tau12_PT, &b_PassedL2_tau12_PT);
        fChain->SetBranchAddress("PassedL2_e6_medium1", &PassedL2_e6_medium1, &b_PassedL2_e6_medium1);
        fChain->SetBranchAddress("PassedL2_mu4_mu6", &PassedL2_mu4_mu6, &b_PassedL2_mu4_mu6);
        fChain->SetBranchAddress("PassedL2_JE280", &PassedL2_JE280, &b_PassedL2_JE280);
        fChain->SetBranchAddress("PassedL2_b23", &PassedL2_b23, &b_PassedL2_b23);
        fChain->SetBranchAddress("PassedL2_tau12_xe20", &PassedL2_tau12_xe20, &b_PassedL2_tau12_xe20);
        fChain->SetBranchAddress("PassedL2_j42_xe30_mu15", &PassedL2_j42_xe30_mu15, &b_PassedL2_j42_xe30_mu15);
        fChain->SetBranchAddress("PassedL2_mu4_j10", &PassedL2_mu4_j10, &b_PassedL2_mu4_j10);
        fChain->SetBranchAddress("PassedL2_g25", &PassedL2_g25, &b_PassedL2_g25);
        fChain->SetBranchAddress("PassedL2_g20", &PassedL2_g20, &b_PassedL2_g20);
        fChain->SetBranchAddress("PassedL2_tauNoCut", &PassedL2_tauNoCut, &b_PassedL2_tauNoCut);
        fChain->SetBranchAddress("PassedL2_tau16i_j70", &PassedL2_tau16i_j70, &b_PassedL2_tau16i_j70);
        fChain->SetBranchAddress("PassedL2_tau12_tau38", &PassedL2_tau12_tau38, &b_PassedL2_tau12_tau38);
        fChain->SetBranchAddress("PassedL2_e15_medium", &PassedL2_e15_medium, &b_PassedL2_e15_medium);
        fChain->SetBranchAddress("PassedL2_FJ70", &PassedL2_FJ70, &b_PassedL2_FJ70);
        fChain->SetBranchAddress("PassedL2_mu4_j18_matched", &PassedL2_mu4_j18_matched, &b_PassedL2_mu4_j18_matched);
        fChain->SetBranchAddress("PassedL2_tau12_tau29i_PT", &PassedL2_tau12_tau29i_PT, &b_PassedL2_tau12_tau29i_PT);
        fChain->SetBranchAddress("PassedL2_4J50", &PassedL2_4J50, &b_PassedL2_4J50);
        fChain->SetBranchAddress("PassedL2_xe80", &PassedL2_xe80, &b_PassedL2_xe80);
        fChain->SetBranchAddress("PassedL2_e12_medium", &PassedL2_e12_medium, &b_PassedL2_e12_medium);
        fChain->SetBranchAddress("PassedL2_tau16i_4j23_WO", &PassedL2_tau16i_4j23_WO, &b_PassedL2_tau16i_4j23_WO);
        fChain->SetBranchAddress("PassedL2_tau20i_e10", &PassedL2_tau20i_e10, &b_PassedL2_tau20i_e10);
        fChain->SetBranchAddress("PassedL2_tau29i_loose", &PassedL2_tau29i_loose, &b_PassedL2_tau29i_loose);
        fChain->SetBranchAddress("PassedL2_e105_loose1", &PassedL2_e105_loose1, &b_PassedL2_e105_loose1);
        fChain->SetBranchAddress("PassedL2_e20_loose_passEF", &PassedL2_e20_loose_passEF, &b_PassedL2_e20_loose_passEF);
        fChain->SetBranchAddress("PassedL2_e7_medium", &PassedL2_e7_medium, &b_PassedL2_e7_medium);
        fChain->SetBranchAddress("PassedL2_e15i_medium", &PassedL2_e15i_medium, &b_PassedL2_e15i_medium);
        fChain->SetBranchAddress("PassedL2_tau16i_mu10", &PassedL2_tau16i_mu10, &b_PassedL2_tau16i_mu10);
        fChain->SetBranchAddress("PassedL2_3g10", &PassedL2_3g10, &b_PassedL2_3g10);
        fChain->SetBranchAddress("PassedL2_tau16i_loose", &PassedL2_tau16i_loose, &b_PassedL2_tau16i_loose);
        fChain->SetBranchAddress("PassedL2_tau16i_4j23", &PassedL2_tau16i_4j23, &b_PassedL2_tau16i_4j23);
        fChain->SetBranchAddress("PassedL2_2g10_mu6", &PassedL2_2g10_mu6, &b_PassedL2_2g10_mu6);
        fChain->SetBranchAddress("PassedL2_2tau20i", &PassedL2_2tau20i, &b_PassedL2_2tau20i);
        fChain->SetBranchAddress("PassedL2_MbRndm", &PassedL2_MbRndm, &b_PassedL2_MbRndm);
        fChain->SetBranchAddress("PassedL2_g25i", &PassedL2_g25i, &b_PassedL2_g25i);
        fChain->SetBranchAddress("PassedL2_2MU4_Upsimumu", &PassedL2_2MU4_Upsimumu, &b_PassedL2_2MU4_Upsimumu);
        fChain->SetBranchAddress("PassedL2_tau20i_e15i", &PassedL2_tau20i_e15i, &b_PassedL2_tau20i_e15i);
        fChain->SetBranchAddress("PassedL2_3J120", &PassedL2_3J120, &b_PassedL2_3J120);
        fChain->SetBranchAddress("PassedL2_b70", &PassedL2_b70, &b_PassedL2_b70);
        fChain->SetBranchAddress("PassedL2_4j23_e15i", &PassedL2_4j23_e15i, &b_PassedL2_4j23_e15i);
        fChain->SetBranchAddress("PassedL2_tau50_loose", &PassedL2_tau50_loose, &b_PassedL2_tau50_loose);
        fChain->SetBranchAddress("PassedL2_tau38i_xe20", &PassedL2_tau38i_xe20, &b_PassedL2_tau38i_xe20);
        fChain->SetBranchAddress("PassedL2_g10_calib", &PassedL2_g10_calib, &b_PassedL2_g10_calib);
        fChain->SetBranchAddress("PassedL2_g15", &PassedL2_g15, &b_PassedL2_g15);
        fChain->SetBranchAddress("PassedL2_g10", &PassedL2_g10, &b_PassedL2_g10);
        fChain->SetBranchAddress("PassedL2_e20_xe15", &PassedL2_e20_xe15, &b_PassedL2_e20_xe15);
        fChain->SetBranchAddress("PassedL2_J150", &PassedL2_J150, &b_PassedL2_J150);
        fChain->SetBranchAddress("PassedL2_e6_medium", &PassedL2_e6_medium, &b_PassedL2_e6_medium);
        fChain->SetBranchAddress("PassedL2_xe20", &PassedL2_xe20, &b_PassedL2_xe20);
        fChain->SetBranchAddress("PassedL2_xe25", &PassedL2_xe25, &b_PassedL2_xe25);
        fChain->SetBranchAddress("PassedL2_mu15i_loose", &PassedL2_mu15i_loose, &b_PassedL2_mu15i_loose);
        fChain->SetBranchAddress("PassedL2_2e6_medium1", &PassedL2_2e6_medium1, &b_PassedL2_2e6_medium1);
        fChain->SetBranchAddress("PassedL2_mu4_j23_matched", &PassedL2_mu4_j23_matched, &b_PassedL2_mu4_j23_matched);
        fChain->SetBranchAddress("PassedL2_tau16i_xe30", &PassedL2_tau16i_xe30, &b_PassedL2_tau16i_xe30);
        fChain->SetBranchAddress("PassedL2_MU4_Bmumu_FS", &PassedL2_MU4_Bmumu_FS, &b_PassedL2_MU4_Bmumu_FS);
        fChain->SetBranchAddress("PassedL2_2MU4_DiMu", &PassedL2_2MU4_DiMu, &b_PassedL2_2MU4_DiMu);
        fChain->SetBranchAddress("PassedL2_MU4_Jpsie5e3_FS", &PassedL2_MU4_Jpsie5e3_FS, &b_PassedL2_MU4_Jpsie5e3_FS);
        fChain->SetBranchAddress("PassedL2_3mu6", &PassedL2_3mu6, &b_PassedL2_3mu6);
        fChain->SetBranchAddress("PassedL2_tau16i_2j70", &PassedL2_tau16i_2j70, &b_PassedL2_tau16i_2j70);
        fChain->SetBranchAddress("PassedL2_tau20i_mu6", &PassedL2_tau20i_mu6, &b_PassedL2_tau20i_mu6);
        fChain->SetBranchAddress("PassedL2_FJ120", &PassedL2_FJ120, &b_PassedL2_FJ120);
        fChain->SetBranchAddress("PassedL2_2g17i_tight", &PassedL2_2g17i_tight, &b_PassedL2_2g17i_tight);
        fChain->SetBranchAddress("PassedL2_mu20_xe30", &PassedL2_mu20_xe30, &b_PassedL2_mu20_xe30);
        fChain->SetBranchAddress("PassedL2_e5_medium", &PassedL2_e5_medium, &b_PassedL2_e5_medium);
        fChain->SetBranchAddress("PassedL2_tau20i_2b23", &PassedL2_tau20i_2b23, &b_PassedL2_tau20i_2b23);
        fChain->SetBranchAddress("PassedL2_2e6_medium", &PassedL2_2e6_medium, &b_PassedL2_2e6_medium);
        fChain->SetBranchAddress("PassedL2_tau16i_e10", &PassedL2_tau16i_e10, &b_PassedL2_tau16i_e10);
        fChain->SetBranchAddress("PassedL2_b35", &PassedL2_b35, &b_PassedL2_b35);
        fChain->SetBranchAddress("PassedL2_e10_xe30", &PassedL2_e10_xe30, &b_PassedL2_e10_xe30);
        fChain->SetBranchAddress("PassedL2_g20i_calib", &PassedL2_g20i_calib, &b_PassedL2_g20i_calib);
        fChain->SetBranchAddress("PassedL2_e5_e10_medium", &PassedL2_e5_e10_medium, &b_PassedL2_e5_e10_medium);
        fChain->SetBranchAddress("PassedL2_tau29i_xe20", &PassedL2_tau29i_xe20, &b_PassedL2_tau29i_xe20);
        fChain->SetBranchAddress("PassedL2_4j23_mu15", &PassedL2_4j23_mu15, &b_PassedL2_4j23_mu15);
        fChain->SetBranchAddress("PassedL2_trk16i_calib", &PassedL2_trk16i_calib, &b_PassedL2_trk16i_calib);
        fChain->SetBranchAddress("PassedL2_tau16i_j120", &PassedL2_tau16i_j120, &b_PassedL2_tau16i_j120);
        fChain->SetBranchAddress("PassedL2_2mu10", &PassedL2_2mu10, &b_PassedL2_2mu10);
        fChain->SetBranchAddress("PassedL2_3b18_4L1J18_passHLT", &PassedL2_3b18_4L1J18_passHLT, &b_PassedL2_3b18_4L1J18_passHLT);
        fChain->SetBranchAddress("PassedL2_mu40", &PassedL2_mu40, &b_PassedL2_mu40);
        fChain->SetBranchAddress("PassedL2_j70_xe30", &PassedL2_j70_xe30, &b_PassedL2_j70_xe30);
        fChain->SetBranchAddress("PassedL2_2g20", &PassedL2_2g20, &b_PassedL2_2g20);
        fChain->SetBranchAddress("PassedL2_J50", &PassedL2_J50, &b_PassedL2_J50);
        fChain->SetBranchAddress("PassedL2_e55_loose1", &PassedL2_e55_loose1, &b_PassedL2_e55_loose1);
        fChain->SetBranchAddress("PassedL2_tau20i_j120", &PassedL2_tau20i_j120, &b_PassedL2_tau20i_j120);
        fChain->SetBranchAddress("PassedL2_mu4_trod", &PassedL2_mu4_trod, &b_PassedL2_mu4_trod);
        fChain->SetBranchAddress("PassedL2_tau125_loose", &PassedL2_tau125_loose, &b_PassedL2_tau125_loose);
        fChain->SetBranchAddress("PassedL2_xe50", &PassedL2_xe50, &b_PassedL2_xe50);
        fChain->SetBranchAddress("PassedL2_tau16i_mu6", &PassedL2_tau16i_mu6, &b_PassedL2_tau16i_mu6);
        fChain->SetBranchAddress("PassedL2_tau12_b23_j42", &PassedL2_tau12_b23_j42, &b_PassedL2_tau12_b23_j42);
        fChain->SetBranchAddress("PassedL2_FJ18", &PassedL2_FJ18, &b_PassedL2_FJ18);
        fChain->SetBranchAddress("PassedL2_tau20i_e25i", &PassedL2_tau20i_e25i, &b_PassedL2_tau20i_e25i);
        fChain->SetBranchAddress("PassedL2_2j42_xe30", &PassedL2_2j42_xe30, &b_PassedL2_2j42_xe30);
        fChain->SetBranchAddress("PassedL2_mu4_tile", &PassedL2_mu4_tile, &b_PassedL2_mu4_tile);
        fChain->SetBranchAddress("PassedL2_2e5_medium1", &PassedL2_2e5_medium1, &b_PassedL2_2e5_medium1);
        fChain->SetBranchAddress("PassedL2_e5_e7_medium", &PassedL2_e5_e7_medium, &b_PassedL2_e5_e7_medium);
        fChain->SetBranchAddress("PassedL2_e20_g20", &PassedL2_e20_g20, &b_PassedL2_e20_g20);
        fChain->SetBranchAddress("PassedL2_tau20i_b18", &PassedL2_tau20i_b18, &b_PassedL2_tau20i_b18);
        fChain->SetBranchAddress("PassedL2_Zee", &PassedL2_Zee, &b_PassedL2_Zee);
        fChain->SetBranchAddress("PassedL2_JE340", &PassedL2_JE340, &b_PassedL2_JE340);
        fChain->SetBranchAddress("PassedL2_b42", &PassedL2_b42, &b_PassedL2_b42);
        fChain->SetBranchAddress("PassedL2_g3_nocut", &PassedL2_g3_nocut, &b_PassedL2_g3_nocut);
        fChain->SetBranchAddress("PassedL2_mu4_j42_matched", &PassedL2_mu4_j42_matched, &b_PassedL2_mu4_j42_matched);
        fChain->SetBranchAddress("PassedL2_te150", &PassedL2_te150, &b_PassedL2_te150);
        fChain->SetBranchAddress("PassedL2_2tau12", &PassedL2_2tau12, &b_PassedL2_2tau12);
        fChain->SetBranchAddress("PassedL2_te250", &PassedL2_te250, &b_PassedL2_te250);
        fChain->SetBranchAddress("PassedL2_4J80", &PassedL2_4J80, &b_PassedL2_4J80);
        fChain->SetBranchAddress("PassedL2_3J35", &PassedL2_3J35, &b_PassedL2_3J35);
        fChain->SetBranchAddress("PassedL2_tau12_e10", &PassedL2_tau12_e10, &b_PassedL2_tau12_e10);
        fChain->SetBranchAddress("PassedL2_e5_medium1", &PassedL2_e5_medium1, &b_PassedL2_e5_medium1);
        fChain->SetBranchAddress("PassedL2_J205", &PassedL2_J205, &b_PassedL2_J205);
        fChain->SetBranchAddress("PassedL2_e20_loose_passL2", &PassedL2_e20_loose_passL2, &b_PassedL2_e20_loose_passL2);
        fChain->SetBranchAddress("PassedL2_em20_passHLT", &PassedL2_em20_passHLT, &b_PassedL2_em20_passHLT);
        fChain->SetBranchAddress("PassedL2_2e15_medium", &PassedL2_2e15_medium, &b_PassedL2_2e15_medium);
        fChain->SetBranchAddress("PassedL2_2b23_3L1J23_passHLT", &PassedL2_2b23_3L1J23_passHLT, &b_PassedL2_2b23_3L1J23_passHLT);
        fChain->SetBranchAddress("PassedL2_xe15", &PassedL2_xe15, &b_PassedL2_xe15);
        fChain->SetBranchAddress("PassedL2_2FJ70", &PassedL2_2FJ70, &b_PassedL2_2FJ70);
        fChain->SetBranchAddress("PassedL2_2FJ18", &PassedL2_2FJ18, &b_PassedL2_2FJ18);
        fChain->SetBranchAddress("PassedL2_g105", &PassedL2_g105, &b_PassedL2_g105);
        fChain->SetBranchAddress("PassedL2_tau84_loose", &PassedL2_tau84_loose, &b_PassedL2_tau84_loose);
        fChain->SetBranchAddress("PassedL2_2e10_mu6", &PassedL2_2e10_mu6, &b_PassedL2_2e10_mu6);
        fChain->SetBranchAddress("PassedL2_mu4", &PassedL2_mu4, &b_PassedL2_mu4);
        fChain->SetBranchAddress("PassedL2_mu6", &PassedL2_mu6, &b_PassedL2_mu6);
        fChain->SetBranchAddress("PassedL2_MU4_Jpsimumu_FS", &PassedL2_MU4_Jpsimumu_FS, &b_PassedL2_MU4_Jpsimumu_FS);
        fChain->SetBranchAddress("PassedL2_e22i_tight", &PassedL2_e22i_tight, &b_PassedL2_e22i_tight);
        fChain->SetBranchAddress("PassedL2_em20i_passHLT", &PassedL2_em20i_passHLT, &b_PassedL2_em20i_passHLT);
        fChain->SetBranchAddress("PassedL2_g55_tight", &PassedL2_g55_tight, &b_PassedL2_g55_tight);
        fChain->SetBranchAddress("PassedL2_2mu6_g10", &PassedL2_2mu6_g10, &b_PassedL2_2mu6_g10);
        fChain->SetBranchAddress("PassedL2_tau20i_mu10", &PassedL2_tau20i_mu10, &b_PassedL2_tau20i_mu10);
        fChain->SetBranchAddress("PassedL2_J110", &PassedL2_J110, &b_PassedL2_J110);
        fChain->SetBranchAddress("PassedL2_e10_medium", &PassedL2_e10_medium, &b_PassedL2_e10_medium);
        fChain->SetBranchAddress("PassedL2_2tau20i_PT", &PassedL2_2tau20i_PT, &b_PassedL2_2tau20i_PT);
        fChain->SetBranchAddress("PassedL2_J60", &PassedL2_J60, &b_PassedL2_J60);
        fChain->SetBranchAddress("PassedL2_j42_xe30_e15i", &PassedL2_j42_xe30_e15i, &b_PassedL2_j42_xe30_e15i);
        fChain->SetBranchAddress("PassedL2_mu20_passHLT", &PassedL2_mu20_passHLT, &b_PassedL2_mu20_passHLT);
        fChain->SetBranchAddress("PassedL2_2mu6_e10", &PassedL2_2mu6_e10, &b_PassedL2_2mu6_e10);
        fChain->SetBranchAddress("PassedL2_MbSp", &PassedL2_MbSp, &b_PassedL2_MbSp);
        fChain->SetBranchAddress("PassedL2_g20i", &PassedL2_g20i, &b_PassedL2_g20i);
        fChain->SetBranchAddress("PassedL2_em105_passHLT", &PassedL2_em105_passHLT, &b_PassedL2_em105_passHLT);
        fChain->SetBranchAddress("PassedL2_2mu20", &PassedL2_2mu20, &b_PassedL2_2mu20);
        fChain->SetBranchAddress("PassedL2_2g10", &PassedL2_2g10, &b_PassedL2_2g10);
        fChain->SetBranchAddress("PassedL2_2g15", &PassedL2_2g15, &b_PassedL2_2g15);
        fChain->SetBranchAddress("PassedL2_tau16i_e15i", &PassedL2_tau16i_e15i, &b_PassedL2_tau16i_e15i);
        fChain->SetBranchAddress("PassedL2_e20i_loose", &PassedL2_e20i_loose, &b_PassedL2_e20i_loose);
        fChain->SetBranchAddress("PassedL2_e20_loose", &PassedL2_e20_loose, &b_PassedL2_e20_loose);
        fChain->SetBranchAddress("PassedL2_2e5_medium", &PassedL2_2e5_medium, &b_PassedL2_2e5_medium);
        fChain->SetBranchAddress("PassedL2_tau29i_xe30", &PassedL2_tau29i_xe30, &b_PassedL2_tau29i_xe30);
        fChain->SetBranchAddress("PassedL2_3b18_4L1J18", &PassedL2_3b18_4L1J18, &b_PassedL2_3b18_4L1J18);
        fChain->SetBranchAddress("PassedL2_xe40", &PassedL2_xe40, &b_PassedL2_xe40);
        fChain->SetBranchAddress("PassedL2_te360", &PassedL2_te360, &b_PassedL2_te360);
        fChain->SetBranchAddress("PassedL2_tau16i_2j23", &PassedL2_tau16i_2j23, &b_PassedL2_tau16i_2j23);
        fChain->SetBranchAddress("PassedL2_2FJ35", &PassedL2_2FJ35, &b_PassedL2_2FJ35);
        fChain->SetBranchAddress("PassedL2_4J15", &PassedL2_4J15, &b_PassedL2_4J15);
        fChain->SetBranchAddress("PassedL2_tau20i_j70", &PassedL2_tau20i_j70, &b_PassedL2_tau20i_j70);
        fChain->SetBranchAddress("PassedL2_tau12_b35", &PassedL2_tau12_b35, &b_PassedL2_tau12_b35);
        fChain->SetBranchAddress("PassedL2_trk9i_calib", &PassedL2_trk9i_calib, &b_PassedL2_trk9i_calib);
        fChain->SetBranchAddress("PassedL2_e25i_medium1", &PassedL2_e25i_medium1, &b_PassedL2_e25i_medium1);
        fChain->SetBranchAddress("PassedL2_2mu4", &PassedL2_2mu4, &b_PassedL2_2mu4);
        fChain->SetBranchAddress("PassedL2_mu20i_loose", &PassedL2_mu20i_loose, &b_PassedL2_mu20i_loose);
        fChain->SetBranchAddress("PassedL2_2mu6", &PassedL2_2mu6, &b_PassedL2_2mu6);
        fChain->SetBranchAddress("PassedL2_mu4_DsPhiPi_FS", &PassedL2_mu4_DsPhiPi_FS, &b_PassedL2_mu4_DsPhiPi_FS);
        fChain->SetBranchAddress("PassedL2_2tau29i", &PassedL2_2tau29i, &b_PassedL2_2tau29i);
        fChain->SetBranchAddress("PassedL2_mu10_j18", &PassedL2_mu10_j18, &b_PassedL2_mu10_j18);
        fChain->SetBranchAddress("PassedL2_g150", &PassedL2_g150, &b_PassedL2_g150);
        fChain->SetBranchAddress("PassedL2_mu10", &PassedL2_mu10, &b_PassedL2_mu10);
        fChain->SetBranchAddress("PassedL2_mu15", &PassedL2_mu15, &b_PassedL2_mu15);
        fChain->SetBranchAddress("PassedL2_g15i", &PassedL2_g15i, &b_PassedL2_g15i);
        fChain->SetBranchAddress("PassedL2_tau38_xe40", &PassedL2_tau38_xe40, &b_PassedL2_tau38_xe40);
        fChain->SetBranchAddress("PassedL2_tau20i_mu20", &PassedL2_tau20i_mu20, &b_PassedL2_tau20i_mu20);
        fChain->SetBranchAddress("PassedL2_J23", &PassedL2_J23, &b_PassedL2_J23);
        fChain->SetBranchAddress("PassedL2_2MU4_Jpsimumu", &PassedL2_2MU4_Jpsimumu, &b_PassedL2_2MU4_Jpsimumu);
        fChain->SetBranchAddress("PassedL2_tau38_loose", &PassedL2_tau38_loose, &b_PassedL2_tau38_loose);
        fChain->SetBranchAddress("PassedL2_J80", &PassedL2_J80, &b_PassedL2_J80);
        fChain->SetBranchAddress("PassedL2_JE120", &PassedL2_JE120, &b_PassedL2_JE120);
        fChain->SetBranchAddress("PassedL2_2e10_loose", &PassedL2_2e10_loose, &b_PassedL2_2e10_loose);
        fChain->SetBranchAddress("PassedL2_mu15_xe15", &PassedL2_mu15_xe15, &b_PassedL2_mu15_xe15);
        fChain->SetBranchAddress("PassedL2_2e20_loose", &PassedL2_2e20_loose, &b_PassedL2_2e20_loose);
        fChain->SetBranchAddress("PassedL2_4J35", &PassedL2_4J35, &b_PassedL2_4J35);
        fChain->SetBranchAddress("PassedL2_xe70", &PassedL2_xe70, &b_PassedL2_xe70);
        fChain->SetBranchAddress("PassedL2_mu4_j35_matched", &PassedL2_mu4_j35_matched, &b_PassedL2_mu4_j35_matched);
        fChain->SetBranchAddress("PassedL2_e15_xe20", &PassedL2_e15_xe20, &b_PassedL2_e15_xe20);
        fChain->SetBranchAddress("PassedL2_e20_xe30", &PassedL2_e20_xe30, &b_PassedL2_e20_xe30);
        fChain->SetBranchAddress("PassedL2_tau20i_xe30", &PassedL2_tau20i_xe30, &b_PassedL2_tau20i_xe30);
        fChain->SetBranchAddress("PassedL2_3e15_medium", &PassedL2_3e15_medium, &b_PassedL2_3e15_medium);
        fChain->SetBranchAddress("PassedL2_e25i_loose", &PassedL2_e25i_loose, &b_PassedL2_e25i_loose);
        fChain->SetBranchAddress("PassedL2_MbSpTrk", &PassedL2_MbSpTrk, &b_PassedL2_MbSpTrk);
        fChain->SetBranchAddress("PassedL2_tau29i_xe40", &PassedL2_tau29i_xe40, &b_PassedL2_tau29i_xe40);
        fChain->SetBranchAddress("PassedL2_tau20i_b35", &PassedL2_tau20i_b35, &b_PassedL2_tau20i_b35);
        fChain->SetBranchAddress("PassedL2_J10", &PassedL2_J10, &b_PassedL2_J10);
        fChain->SetBranchAddress("PassedL2_JE220", &PassedL2_JE220, &b_PassedL2_JE220);
        fChain->SetBranchAddress("PassedL2_tau16i_3j23", &PassedL2_tau16i_3j23, &b_PassedL2_tau16i_3j23);
        fChain->SetBranchAddress("PassedL2_e25_loose", &PassedL2_e25_loose, &b_PassedL2_e25_loose);
        fChain->SetBranchAddress("PassedL2_mu20", &PassedL2_mu20, &b_PassedL2_mu20);
        fChain->SetBranchAddress("PassedL2_2e12_tight", &PassedL2_2e12_tight, &b_PassedL2_2e12_tight);
        fChain->SetBranchAddress("PassedL2_3b23_3L1J23", &PassedL2_3b23_3L1J23, &b_PassedL2_3b23_3L1J23);
        fChain->SetBranchAddress("PassedL2_3J15", &PassedL2_3J15, &b_PassedL2_3J15);
        fChain->SetBranchAddress("PassedL2_b18", &PassedL2_b18, &b_PassedL2_b18);
        fChain->SetBranchAddress("PassedL2_FJ35", &PassedL2_FJ35, &b_PassedL2_FJ35);
        fChain->SetBranchAddress("PassedL2_stau", &PassedL2_stau, &b_PassedL2_stau);
        fChain->SetBranchAddress("PassedL2_xe30", &PassedL2_xe30, &b_PassedL2_xe30);
        fChain->SetBranchAddress("PassedL2_Jpsiee", &PassedL2_Jpsiee, &b_PassedL2_Jpsiee);
        fChain->SetBranchAddress("PassedL2_tau12_tau29i", &PassedL2_tau12_tau29i, &b_PassedL2_tau12_tau29i);
        fChain->SetBranchAddress("PassedL2_tau20i_loose", &PassedL2_tau20i_loose, &b_PassedL2_tau20i_loose);
        fChain->SetBranchAddress("PassedEF_te650", &PassedEF_te650, &b_PassedEF_te650);
        fChain->SetBranchAddress("PassedEF_g25_xe30", &PassedEF_g25_xe30, &b_PassedEF_g25_xe30);
        fChain->SetBranchAddress("PassedEF_mu4_j10_matched", &PassedEF_mu4_j10_matched, &b_PassedEF_mu4_j10_matched);
        fChain->SetBranchAddress("PassedEF_e10_mu6", &PassedEF_e10_mu6, &b_PassedEF_e10_mu6);
        fChain->SetBranchAddress("PassedEF_MU4_Upsimumu_FS", &PassedEF_MU4_Upsimumu_FS, &b_PassedEF_MU4_Upsimumu_FS);
        fChain->SetBranchAddress("PassedEF_g20_xe15", &PassedEF_g20_xe15, &b_PassedEF_g20_xe15);
        fChain->SetBranchAddress("PassedEF_tau16i_j70_WO", &PassedEF_tau16i_j70_WO, &b_PassedEF_tau16i_j70_WO);
        fChain->SetBranchAddress("PassedEF_tau12_loose", &PassedEF_tau12_loose, &b_PassedEF_tau12_loose);
        fChain->SetBranchAddress("PassedEF_tau38i_loose", &PassedEF_tau38i_loose, &b_PassedEF_tau38i_loose);
        fChain->SetBranchAddress("PassedEF_tau12_PT", &PassedEF_tau12_PT, &b_PassedEF_tau12_PT);
        fChain->SetBranchAddress("PassedEF_e6_medium1", &PassedEF_e6_medium1, &b_PassedEF_e6_medium1);
        fChain->SetBranchAddress("PassedEF_mu4_mu6", &PassedEF_mu4_mu6, &b_PassedEF_mu4_mu6);
        fChain->SetBranchAddress("PassedEF_JE280", &PassedEF_JE280, &b_PassedEF_JE280);
        fChain->SetBranchAddress("PassedEF_b23", &PassedEF_b23, &b_PassedEF_b23);
        fChain->SetBranchAddress("PassedEF_tau12_xe20", &PassedEF_tau12_xe20, &b_PassedEF_tau12_xe20);
        fChain->SetBranchAddress("PassedEF_j42_xe30_mu15", &PassedEF_j42_xe30_mu15, &b_PassedEF_j42_xe30_mu15);
        fChain->SetBranchAddress("PassedEF_mu4_j10", &PassedEF_mu4_j10, &b_PassedEF_mu4_j10);
        fChain->SetBranchAddress("PassedEF_g25", &PassedEF_g25, &b_PassedEF_g25);
        fChain->SetBranchAddress("PassedEF_g20", &PassedEF_g20, &b_PassedEF_g20);
        fChain->SetBranchAddress("PassedEF_tauNoCut", &PassedEF_tauNoCut, &b_PassedEF_tauNoCut);
        fChain->SetBranchAddress("PassedEF_tau16i_j70", &PassedEF_tau16i_j70, &b_PassedEF_tau16i_j70);
        fChain->SetBranchAddress("PassedEF_tau12_tau38", &PassedEF_tau12_tau38, &b_PassedEF_tau12_tau38);
        fChain->SetBranchAddress("PassedEF_e15_medium", &PassedEF_e15_medium, &b_PassedEF_e15_medium);
        fChain->SetBranchAddress("PassedEF_FJ70", &PassedEF_FJ70, &b_PassedEF_FJ70);
        fChain->SetBranchAddress("PassedEF_mu4_j18_matched", &PassedEF_mu4_j18_matched, &b_PassedEF_mu4_j18_matched);
        fChain->SetBranchAddress("PassedEF_tau12_tau29i_PT", &PassedEF_tau12_tau29i_PT, &b_PassedEF_tau12_tau29i_PT);
        fChain->SetBranchAddress("PassedEF_4J95", &PassedEF_4J95, &b_PassedEF_4J95);
        fChain->SetBranchAddress("PassedEF_xe80", &PassedEF_xe80, &b_PassedEF_xe80);
        fChain->SetBranchAddress("PassedEF_e12_medium", &PassedEF_e12_medium, &b_PassedEF_e12_medium);
        fChain->SetBranchAddress("PassedEF_tau16i_4j23_WO", &PassedEF_tau16i_4j23_WO, &b_PassedEF_tau16i_4j23_WO);
        fChain->SetBranchAddress("PassedEF_tau20i_e10", &PassedEF_tau20i_e10, &b_PassedEF_tau20i_e10);
        fChain->SetBranchAddress("PassedEF_tau29i_loose", &PassedEF_tau29i_loose, &b_PassedEF_tau29i_loose);
        fChain->SetBranchAddress("PassedEF_e105_loose1", &PassedEF_e105_loose1, &b_PassedEF_e105_loose1);
        fChain->SetBranchAddress("PassedEF_e20_loose_passEF", &PassedEF_e20_loose_passEF, &b_PassedEF_e20_loose_passEF);
        fChain->SetBranchAddress("PassedEF_e7_medium", &PassedEF_e7_medium, &b_PassedEF_e7_medium);
        fChain->SetBranchAddress("PassedEF_e15i_medium", &PassedEF_e15i_medium, &b_PassedEF_e15i_medium);
        fChain->SetBranchAddress("PassedEF_tau16i_mu10", &PassedEF_tau16i_mu10, &b_PassedEF_tau16i_mu10);
        fChain->SetBranchAddress("PassedEF_3g10", &PassedEF_3g10, &b_PassedEF_3g10);
        fChain->SetBranchAddress("PassedEF_tau16i_loose", &PassedEF_tau16i_loose, &b_PassedEF_tau16i_loose);
        fChain->SetBranchAddress("PassedEF_tau16i_4j23", &PassedEF_tau16i_4j23, &b_PassedEF_tau16i_4j23);
        fChain->SetBranchAddress("PassedEF_2g10_mu6", &PassedEF_2g10_mu6, &b_PassedEF_2g10_mu6);
        fChain->SetBranchAddress("PassedEF_2tau20i", &PassedEF_2tau20i, &b_PassedEF_2tau20i);
        fChain->SetBranchAddress("PassedEF_MbRndm", &PassedEF_MbRndm, &b_PassedEF_MbRndm);
        fChain->SetBranchAddress("PassedEF_g25i", &PassedEF_g25i, &b_PassedEF_g25i);
        fChain->SetBranchAddress("PassedEF_2MU4_Upsimumu", &PassedEF_2MU4_Upsimumu, &b_PassedEF_2MU4_Upsimumu);
        fChain->SetBranchAddress("PassedEF_tau20i_e15i", &PassedEF_tau20i_e15i, &b_PassedEF_tau20i_e15i);
        fChain->SetBranchAddress("PassedEF_3J180", &PassedEF_3J180, &b_PassedEF_3J180);
        fChain->SetBranchAddress("PassedEF_b70", &PassedEF_b70, &b_PassedEF_b70);
        fChain->SetBranchAddress("PassedEF_4j23_e15i", &PassedEF_4j23_e15i, &b_PassedEF_4j23_e15i);
        fChain->SetBranchAddress("PassedEF_tau50_loose", &PassedEF_tau50_loose, &b_PassedEF_tau50_loose);
        fChain->SetBranchAddress("PassedEF_tau38i_xe20", &PassedEF_tau38i_xe20, &b_PassedEF_tau38i_xe20);
        fChain->SetBranchAddress("PassedEF_g10_calib", &PassedEF_g10_calib, &b_PassedEF_g10_calib);
        fChain->SetBranchAddress("PassedEF_g15", &PassedEF_g15, &b_PassedEF_g15);
        fChain->SetBranchAddress("PassedEF_g10", &PassedEF_g10, &b_PassedEF_g10);
        fChain->SetBranchAddress("PassedEF_e20_xe15", &PassedEF_e20_xe15, &b_PassedEF_e20_xe15);
        fChain->SetBranchAddress("PassedEF_J265", &PassedEF_J265, &b_PassedEF_J265);
        fChain->SetBranchAddress("PassedEF_e6_medium", &PassedEF_e6_medium, &b_PassedEF_e6_medium);
        fChain->SetBranchAddress("PassedEF_xe20", &PassedEF_xe20, &b_PassedEF_xe20);
        fChain->SetBranchAddress("PassedEF_xe25", &PassedEF_xe25, &b_PassedEF_xe25);
        fChain->SetBranchAddress("PassedEF_mu15i_loose", &PassedEF_mu15i_loose, &b_PassedEF_mu15i_loose);
        fChain->SetBranchAddress("PassedEF_2e6_medium1", &PassedEF_2e6_medium1, &b_PassedEF_2e6_medium1);
        fChain->SetBranchAddress("PassedEF_mu4_j23_matched", &PassedEF_mu4_j23_matched, &b_PassedEF_mu4_j23_matched);
        fChain->SetBranchAddress("PassedEF_tau16i_xe30", &PassedEF_tau16i_xe30, &b_PassedEF_tau16i_xe30);
        fChain->SetBranchAddress("PassedEF_MU4_Bmumu_FS", &PassedEF_MU4_Bmumu_FS, &b_PassedEF_MU4_Bmumu_FS);
        fChain->SetBranchAddress("PassedEF_2MU4_DiMu", &PassedEF_2MU4_DiMu, &b_PassedEF_2MU4_DiMu);
        fChain->SetBranchAddress("PassedEF_MU4_Jpsie5e3_FS", &PassedEF_MU4_Jpsie5e3_FS, &b_PassedEF_MU4_Jpsie5e3_FS);
        fChain->SetBranchAddress("PassedEF_3mu6", &PassedEF_3mu6, &b_PassedEF_3mu6);
        fChain->SetBranchAddress("PassedEF_tau16i_2j70", &PassedEF_tau16i_2j70, &b_PassedEF_tau16i_2j70);
        fChain->SetBranchAddress("PassedEF_tau20i_mu6", &PassedEF_tau20i_mu6, &b_PassedEF_tau20i_mu6);
        fChain->SetBranchAddress("PassedEF_FJ120", &PassedEF_FJ120, &b_PassedEF_FJ120);
        fChain->SetBranchAddress("PassedEF_2g17i_tight", &PassedEF_2g17i_tight, &b_PassedEF_2g17i_tight);
        fChain->SetBranchAddress("PassedEF_mu20_xe30", &PassedEF_mu20_xe30, &b_PassedEF_mu20_xe30);
        fChain->SetBranchAddress("PassedEF_e5_medium", &PassedEF_e5_medium, &b_PassedEF_e5_medium);
        fChain->SetBranchAddress("PassedEF_tau20i_2b23", &PassedEF_tau20i_2b23, &b_PassedEF_tau20i_2b23);
        fChain->SetBranchAddress("PassedEF_2e6_medium", &PassedEF_2e6_medium, &b_PassedEF_2e6_medium);
        fChain->SetBranchAddress("PassedEF_tau16i_e10", &PassedEF_tau16i_e10, &b_PassedEF_tau16i_e10);
        fChain->SetBranchAddress("PassedEF_b35", &PassedEF_b35, &b_PassedEF_b35);
        fChain->SetBranchAddress("PassedEF_e10_xe30", &PassedEF_e10_xe30, &b_PassedEF_e10_xe30);
        fChain->SetBranchAddress("PassedEF_g20i_calib", &PassedEF_g20i_calib, &b_PassedEF_g20i_calib);
        fChain->SetBranchAddress("PassedEF_e5_e10_medium", &PassedEF_e5_e10_medium, &b_PassedEF_e5_e10_medium);
        fChain->SetBranchAddress("PassedEF_tau29i_xe20", &PassedEF_tau29i_xe20, &b_PassedEF_tau29i_xe20);
        fChain->SetBranchAddress("PassedEF_4j23_mu15", &PassedEF_4j23_mu15, &b_PassedEF_4j23_mu15);
        fChain->SetBranchAddress("PassedEF_tau16i_j120", &PassedEF_tau16i_j120, &b_PassedEF_tau16i_j120);
        fChain->SetBranchAddress("PassedEF_2mu10", &PassedEF_2mu10, &b_PassedEF_2mu10);
        fChain->SetBranchAddress("PassedEF_3b18_4L1J18_passHLT", &PassedEF_3b18_4L1J18_passHLT, &b_PassedEF_3b18_4L1J18_passHLT);
        fChain->SetBranchAddress("PassedEF_mu40", &PassedEF_mu40, &b_PassedEF_mu40);
        fChain->SetBranchAddress("PassedEF_j70_xe30", &PassedEF_j70_xe30, &b_PassedEF_j70_xe30);
        fChain->SetBranchAddress("PassedEF_2g20", &PassedEF_2g20, &b_PassedEF_2g20);
        fChain->SetBranchAddress("PassedEF_J80", &PassedEF_J80, &b_PassedEF_J80);
        fChain->SetBranchAddress("PassedEF_e55_loose1", &PassedEF_e55_loose1, &b_PassedEF_e55_loose1);
        fChain->SetBranchAddress("PassedEF_tau20i_j120", &PassedEF_tau20i_j120, &b_PassedEF_tau20i_j120);
        fChain->SetBranchAddress("PassedEF_mu4_trod", &PassedEF_mu4_trod, &b_PassedEF_mu4_trod);
        fChain->SetBranchAddress("PassedEF_tau125_loose", &PassedEF_tau125_loose, &b_PassedEF_tau125_loose);
        fChain->SetBranchAddress("PassedEF_xe50", &PassedEF_xe50, &b_PassedEF_xe50);
        fChain->SetBranchAddress("PassedEF_tau16i_mu6", &PassedEF_tau16i_mu6, &b_PassedEF_tau16i_mu6);
        fChain->SetBranchAddress("PassedEF_tau12_b23_j42", &PassedEF_tau12_b23_j42, &b_PassedEF_tau12_b23_j42);
        fChain->SetBranchAddress("PassedEF_FJ18", &PassedEF_FJ18, &b_PassedEF_FJ18);
        fChain->SetBranchAddress("PassedEF_tau20i_e25i", &PassedEF_tau20i_e25i, &b_PassedEF_tau20i_e25i);
        fChain->SetBranchAddress("PassedEF_2j42_xe30", &PassedEF_2j42_xe30, &b_PassedEF_2j42_xe30);
        fChain->SetBranchAddress("PassedEF_mu4_tile", &PassedEF_mu4_tile, &b_PassedEF_mu4_tile);
        fChain->SetBranchAddress("PassedEF_2e5_medium1", &PassedEF_2e5_medium1, &b_PassedEF_2e5_medium1);
        fChain->SetBranchAddress("PassedEF_e5_e7_medium", &PassedEF_e5_e7_medium, &b_PassedEF_e5_e7_medium);
        fChain->SetBranchAddress("PassedEF_e20_g20", &PassedEF_e20_g20, &b_PassedEF_e20_g20);
        fChain->SetBranchAddress("PassedEF_tau20i_b18", &PassedEF_tau20i_b18, &b_PassedEF_tau20i_b18);
        fChain->SetBranchAddress("PassedEF_Zee", &PassedEF_Zee, &b_PassedEF_Zee);
        fChain->SetBranchAddress("PassedEF_JE340", &PassedEF_JE340, &b_PassedEF_JE340);
        fChain->SetBranchAddress("PassedEF_b42", &PassedEF_b42, &b_PassedEF_b42);
        fChain->SetBranchAddress("PassedEF_g3_nocut", &PassedEF_g3_nocut, &b_PassedEF_g3_nocut);
        fChain->SetBranchAddress("PassedEF_mu4_j42_matched", &PassedEF_mu4_j42_matched, &b_PassedEF_mu4_j42_matched);
        fChain->SetBranchAddress("PassedEF_te150", &PassedEF_te150, &b_PassedEF_te150);
        fChain->SetBranchAddress("PassedEF_2tau12", &PassedEF_2tau12, &b_PassedEF_2tau12);
        fChain->SetBranchAddress("PassedEF_te250", &PassedEF_te250, &b_PassedEF_te250);
        fChain->SetBranchAddress("PassedEF_4J125", &PassedEF_4J125, &b_PassedEF_4J125);
        fChain->SetBranchAddress("PassedEF_3J60", &PassedEF_3J60, &b_PassedEF_3J60);
        fChain->SetBranchAddress("PassedEF_tau12_e10", &PassedEF_tau12_e10, &b_PassedEF_tau12_e10);
        fChain->SetBranchAddress("PassedEF_e5_medium1", &PassedEF_e5_medium1, &b_PassedEF_e5_medium1);
        fChain->SetBranchAddress("PassedEF_J350", &PassedEF_J350, &b_PassedEF_J350);
        fChain->SetBranchAddress("PassedEF_e20_loose_passL2", &PassedEF_e20_loose_passL2, &b_PassedEF_e20_loose_passL2);
        fChain->SetBranchAddress("PassedEF_em20_passHLT", &PassedEF_em20_passHLT, &b_PassedEF_em20_passHLT);
        fChain->SetBranchAddress("PassedEF_2e15_medium", &PassedEF_2e15_medium, &b_PassedEF_2e15_medium);
        fChain->SetBranchAddress("PassedEF_2b23_3L1J23_passHLT", &PassedEF_2b23_3L1J23_passHLT, &b_PassedEF_2b23_3L1J23_passHLT);
        fChain->SetBranchAddress("PassedEF_xe15", &PassedEF_xe15, &b_PassedEF_xe15);
        fChain->SetBranchAddress("PassedEF_2FJ70", &PassedEF_2FJ70, &b_PassedEF_2FJ70);
        fChain->SetBranchAddress("PassedEF_2FJ18", &PassedEF_2FJ18, &b_PassedEF_2FJ18);
        fChain->SetBranchAddress("PassedEF_g105", &PassedEF_g105, &b_PassedEF_g105);
        fChain->SetBranchAddress("PassedEF_tau84_loose", &PassedEF_tau84_loose, &b_PassedEF_tau84_loose);
        fChain->SetBranchAddress("PassedEF_2e10_mu6", &PassedEF_2e10_mu6, &b_PassedEF_2e10_mu6);
        fChain->SetBranchAddress("PassedEF_mu4", &PassedEF_mu4, &b_PassedEF_mu4);
        fChain->SetBranchAddress("PassedEF_mu6", &PassedEF_mu6, &b_PassedEF_mu6);
        fChain->SetBranchAddress("PassedEF_MU4_Jpsimumu_FS", &PassedEF_MU4_Jpsimumu_FS, &b_PassedEF_MU4_Jpsimumu_FS);
        fChain->SetBranchAddress("PassedEF_e22i_tight", &PassedEF_e22i_tight, &b_PassedEF_e22i_tight);
        fChain->SetBranchAddress("PassedEF_em20i_passHLT", &PassedEF_em20i_passHLT, &b_PassedEF_em20i_passHLT);
        fChain->SetBranchAddress("PassedEF_g55_tight", &PassedEF_g55_tight, &b_PassedEF_g55_tight);
        fChain->SetBranchAddress("PassedEF_2mu6_g10", &PassedEF_2mu6_g10, &b_PassedEF_2mu6_g10);
        fChain->SetBranchAddress("PassedEF_tau20i_mu10", &PassedEF_tau20i_mu10, &b_PassedEF_tau20i_mu10);
        fChain->SetBranchAddress("PassedEF_J180", &PassedEF_J180, &b_PassedEF_J180);
        fChain->SetBranchAddress("PassedEF_e10_medium", &PassedEF_e10_medium, &b_PassedEF_e10_medium);
        fChain->SetBranchAddress("PassedEF_2tau20i_PT", &PassedEF_2tau20i_PT, &b_PassedEF_2tau20i_PT);
        fChain->SetBranchAddress("PassedEF_J115", &PassedEF_J115, &b_PassedEF_J115);
        fChain->SetBranchAddress("PassedEF_j42_xe30_e15i", &PassedEF_j42_xe30_e15i, &b_PassedEF_j42_xe30_e15i);
        fChain->SetBranchAddress("PassedEF_mu20_passHLT", &PassedEF_mu20_passHLT, &b_PassedEF_mu20_passHLT);
        fChain->SetBranchAddress("PassedEF_2mu6_e10", &PassedEF_2mu6_e10, &b_PassedEF_2mu6_e10);
        fChain->SetBranchAddress("PassedEF_MbSp", &PassedEF_MbSp, &b_PassedEF_MbSp);
        fChain->SetBranchAddress("PassedEF_g20i", &PassedEF_g20i, &b_PassedEF_g20i);
        fChain->SetBranchAddress("PassedEF_em105_passHLT", &PassedEF_em105_passHLT, &b_PassedEF_em105_passHLT);
        fChain->SetBranchAddress("PassedEF_2mu20", &PassedEF_2mu20, &b_PassedEF_2mu20);
        fChain->SetBranchAddress("PassedEF_2g10", &PassedEF_2g10, &b_PassedEF_2g10);
        fChain->SetBranchAddress("PassedEF_2g15", &PassedEF_2g15, &b_PassedEF_2g15);
        fChain->SetBranchAddress("PassedEF_tau16i_e15i", &PassedEF_tau16i_e15i, &b_PassedEF_tau16i_e15i);
        fChain->SetBranchAddress("PassedEF_e20i_loose", &PassedEF_e20i_loose, &b_PassedEF_e20i_loose);
        fChain->SetBranchAddress("PassedEF_e20_loose", &PassedEF_e20_loose, &b_PassedEF_e20_loose);
        fChain->SetBranchAddress("PassedEF_2e5_medium", &PassedEF_2e5_medium, &b_PassedEF_2e5_medium);
        fChain->SetBranchAddress("PassedEF_tau29i_xe30", &PassedEF_tau29i_xe30, &b_PassedEF_tau29i_xe30);
        fChain->SetBranchAddress("PassedEF_3b18_4L1J18", &PassedEF_3b18_4L1J18, &b_PassedEF_3b18_4L1J18);
        fChain->SetBranchAddress("PassedEF_xe40", &PassedEF_xe40, &b_PassedEF_xe40);
        fChain->SetBranchAddress("PassedEF_te360", &PassedEF_te360, &b_PassedEF_te360);
        fChain->SetBranchAddress("PassedEF_tau16i_2j23", &PassedEF_tau16i_2j23, &b_PassedEF_tau16i_2j23);
        fChain->SetBranchAddress("PassedEF_2FJ35", &PassedEF_2FJ35, &b_PassedEF_2FJ35);
        fChain->SetBranchAddress("PassedEF_4J45", &PassedEF_4J45, &b_PassedEF_4J45);
        fChain->SetBranchAddress("PassedEF_tau20i_j70", &PassedEF_tau20i_j70, &b_PassedEF_tau20i_j70);
        fChain->SetBranchAddress("PassedEF_tau12_b35", &PassedEF_tau12_b35, &b_PassedEF_tau12_b35);
        fChain->SetBranchAddress("PassedEF_e25i_medium1", &PassedEF_e25i_medium1, &b_PassedEF_e25i_medium1);
        fChain->SetBranchAddress("PassedEF_2mu4", &PassedEF_2mu4, &b_PassedEF_2mu4);
        fChain->SetBranchAddress("PassedEF_mu20i_loose", &PassedEF_mu20i_loose, &b_PassedEF_mu20i_loose);
        fChain->SetBranchAddress("PassedEF_2mu6", &PassedEF_2mu6, &b_PassedEF_2mu6);
        fChain->SetBranchAddress("PassedEF_mu4_DsPhiPi_FS", &PassedEF_mu4_DsPhiPi_FS, &b_PassedEF_mu4_DsPhiPi_FS);
        fChain->SetBranchAddress("PassedEF_2tau29i", &PassedEF_2tau29i, &b_PassedEF_2tau29i);
        fChain->SetBranchAddress("PassedEF_mu10_j18", &PassedEF_mu10_j18, &b_PassedEF_mu10_j18);
        fChain->SetBranchAddress("PassedEF_g150", &PassedEF_g150, &b_PassedEF_g150);
        fChain->SetBranchAddress("PassedEF_mu10", &PassedEF_mu10, &b_PassedEF_mu10);
        fChain->SetBranchAddress("PassedEF_mu15", &PassedEF_mu15, &b_PassedEF_mu15);
        fChain->SetBranchAddress("PassedEF_g15i", &PassedEF_g15i, &b_PassedEF_g15i);
        fChain->SetBranchAddress("PassedEF_tau38_xe40", &PassedEF_tau38_xe40, &b_PassedEF_tau38_xe40);
        fChain->SetBranchAddress("PassedEF_tau20i_mu20", &PassedEF_tau20i_mu20, &b_PassedEF_tau20i_mu20);
        fChain->SetBranchAddress("PassedEF_J50", &PassedEF_J50, &b_PassedEF_J50);
        fChain->SetBranchAddress("PassedEF_2MU4_Jpsimumu", &PassedEF_2MU4_Jpsimumu, &b_PassedEF_2MU4_Jpsimumu);
        fChain->SetBranchAddress("PassedEF_tau38_loose", &PassedEF_tau38_loose, &b_PassedEF_tau38_loose);
        fChain->SetBranchAddress("PassedEF_J140", &PassedEF_J140, &b_PassedEF_J140);
        fChain->SetBranchAddress("PassedEF_JE120", &PassedEF_JE120, &b_PassedEF_JE120);
        fChain->SetBranchAddress("PassedEF_2e10_loose", &PassedEF_2e10_loose, &b_PassedEF_2e10_loose);
        fChain->SetBranchAddress("PassedEF_mu15_xe15", &PassedEF_mu15_xe15, &b_PassedEF_mu15_xe15);
        fChain->SetBranchAddress("PassedEF_2e20_loose", &PassedEF_2e20_loose, &b_PassedEF_2e20_loose);
        fChain->SetBranchAddress("PassedEF_4J80", &PassedEF_4J80, &b_PassedEF_4J80);
        fChain->SetBranchAddress("PassedEF_xe70", &PassedEF_xe70, &b_PassedEF_xe70);
        fChain->SetBranchAddress("PassedEF_mu4_j35_matched", &PassedEF_mu4_j35_matched, &b_PassedEF_mu4_j35_matched);
        fChain->SetBranchAddress("PassedEF_e15_xe20", &PassedEF_e15_xe20, &b_PassedEF_e15_xe20);
        fChain->SetBranchAddress("PassedEF_e20_xe30", &PassedEF_e20_xe30, &b_PassedEF_e20_xe30);
        fChain->SetBranchAddress("PassedEF_tau20i_xe30", &PassedEF_tau20i_xe30, &b_PassedEF_tau20i_xe30);
        fChain->SetBranchAddress("PassedEF_3e15_medium", &PassedEF_3e15_medium, &b_PassedEF_3e15_medium);
        fChain->SetBranchAddress("PassedEF_e25i_loose", &PassedEF_e25i_loose, &b_PassedEF_e25i_loose);
        fChain->SetBranchAddress("PassedEF_MbSpTrk", &PassedEF_MbSpTrk, &b_PassedEF_MbSpTrk);
        fChain->SetBranchAddress("PassedEF_tau29i_xe40", &PassedEF_tau29i_xe40, &b_PassedEF_tau29i_xe40);
        fChain->SetBranchAddress("PassedEF_tau20i_b35", &PassedEF_tau20i_b35, &b_PassedEF_tau20i_b35);
        fChain->SetBranchAddress("PassedEF_J10", &PassedEF_J10, &b_PassedEF_J10);
        fChain->SetBranchAddress("PassedEF_JE220", &PassedEF_JE220, &b_PassedEF_JE220);
        fChain->SetBranchAddress("PassedEF_tau16i_EFxe30", &PassedEF_tau16i_EFxe30, &b_PassedEF_tau16i_EFxe30);
        fChain->SetBranchAddress("PassedEF_tau16i_3j23", &PassedEF_tau16i_3j23, &b_PassedEF_tau16i_3j23);
        fChain->SetBranchAddress("PassedEF_e25_loose", &PassedEF_e25_loose, &b_PassedEF_e25_loose);
        fChain->SetBranchAddress("PassedEF_mu20", &PassedEF_mu20, &b_PassedEF_mu20);
        fChain->SetBranchAddress("PassedEF_2e12_tight", &PassedEF_2e12_tight, &b_PassedEF_2e12_tight);
        fChain->SetBranchAddress("PassedEF_3b23_3L1J23", &PassedEF_3b23_3L1J23, &b_PassedEF_3b23_3L1J23);
        fChain->SetBranchAddress("PassedEF_3J25", &PassedEF_3J25, &b_PassedEF_3J25);
        fChain->SetBranchAddress("PassedEF_b18", &PassedEF_b18, &b_PassedEF_b18);
        fChain->SetBranchAddress("PassedEF_FJ35", &PassedEF_FJ35, &b_PassedEF_FJ35);
        fChain->SetBranchAddress("PassedEF_stau", &PassedEF_stau, &b_PassedEF_stau);
        fChain->SetBranchAddress("PassedEF_xe30", &PassedEF_xe30, &b_PassedEF_xe30);
        fChain->SetBranchAddress("PassedEF_Jpsiee", &PassedEF_Jpsiee, &b_PassedEF_Jpsiee);
        fChain->SetBranchAddress("PassedEF_tau12_tau29i", &PassedEF_tau12_tau29i, &b_PassedEF_tau12_tau29i);
        fChain->SetBranchAddress("PassedEF_tau20i_loose", &PassedEF_tau20i_loose, &b_PassedEF_tau20i_loose);
        fChain->SetBranchAddress("Tau_N", &Tau_N, &b_Tau_N);
        fChain->SetBranchAddress("El_N", &El_N, &b_El_N);
        fChain->SetBranchAddress("Mu_N", &Mu_N, &b_Mu_N);
        fChain->SetBranchAddress("JetC4T_N", &JetC4T_N, &b_JetC4T_N);
        fChain->SetBranchAddress("Trk_N", &Trk_N, &b_Trk_N);
        fChain->SetBranchAddress("T_Tau_N", &T_Tau_N, &b_T_Tau_N);
        fChain->SetBranchAddress("T_TauVis_N", &T_TauVis_N, &b_T_TauVis_N);
        fChain->SetBranchAddress("T_Mu_N", &T_Mu_N, &b_T_Mu_N);
        fChain->SetBranchAddress("T_El_N", &T_El_N, &b_T_El_N);
        fChain->SetBranchAddress("T_JetC4_N", &T_JetC4_N, &b_T_JetC4_N);
        fChain->SetBranchAddress("Tau_E", &Tau_E, &b_Tau_E);
        fChain->SetBranchAddress("Tau_p_T", &Tau_p_T, &b_Tau_p_T);
        fChain->SetBranchAddress("Tau_phi", &Tau_phi, &b_Tau_phi);
        fChain->SetBranchAddress("Tau_eta", &Tau_eta, &b_Tau_eta);
        fChain->SetBranchAddress("Tau_px", &Tau_px, &b_Tau_px);
        fChain->SetBranchAddress("Tau_py", &Tau_py, &b_Tau_py);
        fChain->SetBranchAddress("Tau_pz", &Tau_pz, &b_Tau_pz);
        fChain->SetBranchAddress("Tau_m", &Tau_m, &b_Tau_m);
        fChain->SetBranchAddress("Tau_charge", &Tau_charge, &b_Tau_charge);
        fChain->SetBranchAddress("Tau_pdgId", &Tau_pdgId, &b_Tau_pdgId);
        fChain->SetBranchAddress("Tau_Likelihood", &Tau_Likelihood, &b_Tau_Likelihood);
        fChain->SetBranchAddress("Tau_TauJetLikelihoodOld", &Tau_TauJetLikelihoodOld, &b_Tau_TauJetLikelihoodOld);
        fChain->SetBranchAddress("Tau_TauELikelihoodLowPt", &Tau_TauELikelihoodLowPt, &b_Tau_TauELikelihoodLowPt);
        fChain->SetBranchAddress("Tau_TauElTauLikelihood", &Tau_TauElTauLikelihood, &b_Tau_TauElTauLikelihood);
        fChain->SetBranchAddress("Tau_TauJetNeuralNetwork", &Tau_TauJetNeuralNetwork, &b_Tau_TauJetNeuralNetwork);
        fChain->SetBranchAddress("Tau_TauENeuralNetwork", &Tau_TauENeuralNetwork, &b_Tau_TauENeuralNetwork);
        fChain->SetBranchAddress("Tau_DiscPDERS", &Tau_DiscPDERS, &b_Tau_DiscPDERS);
        fChain->SetBranchAddress("Tau_DiscCutTMVA", &Tau_DiscCutTMVA, &b_Tau_DiscCutTMVA);
        fChain->SetBranchAddress("Tau_totTrkCharge", &Tau_totTrkCharge, &b_Tau_totTrkCharge);
        fChain->SetBranchAddress("Tau_totTrkE", &Tau_totTrkE, &b_Tau_totTrkE);
        fChain->SetBranchAddress("Tau_track1_pT", &Tau_track1_pT, &b_Tau_track1_pT);
        fChain->SetBranchAddress("Tau_track2_pT", &Tau_track2_pT, &b_Tau_track2_pT);
        fChain->SetBranchAddress("Tau_track3_pT", &Tau_track3_pT, &b_Tau_track3_pT);
        fChain->SetBranchAddress("Tau_track1_phi", &Tau_track1_phi, &b_Tau_track1_phi);
        fChain->SetBranchAddress("Tau_track2_phi", &Tau_track2_phi, &b_Tau_track2_phi);
        fChain->SetBranchAddress("Tau_track3_phi", &Tau_track3_phi, &b_Tau_track3_phi);
        fChain->SetBranchAddress("Tau_track1_eta", &Tau_track1_eta, &b_Tau_track1_eta);
        fChain->SetBranchAddress("Tau_track2_eta", &Tau_track2_eta, &b_Tau_track2_eta);
        fChain->SetBranchAddress("Tau_track3_eta", &Tau_track3_eta, &b_Tau_track3_eta);
        fChain->SetBranchAddress("Tau_emRadius", &Tau_emRadius, &b_Tau_emRadius);
        fChain->SetBranchAddress("Tau_isolationFraction", &Tau_isolationFraction, &b_Tau_isolationFraction);
        fChain->SetBranchAddress("Tau_stripWidth2", &Tau_stripWidth2, &b_Tau_stripWidth2);
        fChain->SetBranchAddress("Tau_sumEMpx", &Tau_sumEMpx, &b_Tau_sumEMpx);
        fChain->SetBranchAddress("Tau_sumEMpy", &Tau_sumEMpy, &b_Tau_sumEMpy);
        fChain->SetBranchAddress("Tau_sumEMpz", &Tau_sumEMpz, &b_Tau_sumEMpz);
        fChain->SetBranchAddress("Tau_sumEMe", &Tau_sumEMe, &b_Tau_sumEMe);
        fChain->SetBranchAddress("Tau_secVtxX", &Tau_secVtxX, &b_Tau_secVtxX);
        fChain->SetBranchAddress("Tau_secVtxY", &Tau_secVtxY, &b_Tau_secVtxY);
        fChain->SetBranchAddress("Tau_secVtxZ", &Tau_secVtxZ, &b_Tau_secVtxZ);
        fChain->SetBranchAddress("Tau_secVtxCovXX", &Tau_secVtxCovXX, &b_Tau_secVtxCovXX);
        fChain->SetBranchAddress("Tau_secVtxCovYY", &Tau_secVtxCovYY, &b_Tau_secVtxCovYY);
        fChain->SetBranchAddress("Tau_secVtxCovZZ", &Tau_secVtxCovZZ, &b_Tau_secVtxCovZZ);
        fChain->SetBranchAddress("Tau_secVtxCovXY", &Tau_secVtxCovXY, &b_Tau_secVtxCovXY);
        fChain->SetBranchAddress("Tau_secVtxCovYZ", &Tau_secVtxCovYZ, &b_Tau_secVtxCovYZ);
        fChain->SetBranchAddress("Tau_secVtxCovXZ", &Tau_secVtxCovXZ, &b_Tau_secVtxCovXZ);
        fChain->SetBranchAddress("Tau_secVtxChi2", &Tau_secVtxChi2, &b_Tau_secVtxChi2);
        fChain->SetBranchAddress("Tau_secVtxNDoF", &Tau_secVtxNDoF, &b_Tau_secVtxNDoF);
        fChain->SetBranchAddress("Tau_trFlightPathSig", &Tau_trFlightPathSig, &b_Tau_trFlightPathSig);
        fChain->SetBranchAddress("Tau_etChrgHAD", &Tau_etChrgHAD, &b_Tau_etChrgHAD);
        fChain->SetBranchAddress("Tau_etIsolEM", &Tau_etIsolEM, &b_Tau_etIsolEM);
        fChain->SetBranchAddress("Tau_etIsolHAD", &Tau_etIsolHAD, &b_Tau_etIsolHAD);
        fChain->SetBranchAddress("Tau_massTrk3P", &Tau_massTrk3P, &b_Tau_massTrk3P);
        fChain->SetBranchAddress("Tau_rWidth2Trk3P", &Tau_rWidth2Trk3P, &b_Tau_rWidth2Trk3P);
        fChain->SetBranchAddress("Tau_signD0Trk3P", &Tau_signD0Trk3P, &b_Tau_signD0Trk3P);
        fChain->SetBranchAddress("Tau_etHadAtEMScale", &Tau_etHadAtEMScale, &b_Tau_etHadAtEMScale);
        fChain->SetBranchAddress("Tau_etEMAtEMScale", &Tau_etEMAtEMScale, &b_Tau_etEMAtEMScale);
        fChain->SetBranchAddress("Tau_etEMCL", &Tau_etEMCL, &b_Tau_etEMCL);
        fChain->SetBranchAddress("Tau_etChrgEM", &Tau_etChrgEM, &b_Tau_etChrgEM);
        fChain->SetBranchAddress("Tau_etNeuEM", &Tau_etNeuEM, &b_Tau_etNeuEM);
        fChain->SetBranchAddress("Tau_etResNeuEM", &Tau_etResNeuEM, &b_Tau_etResNeuEM);
        fChain->SetBranchAddress("Tau_etChrgEM01_1Trk", &Tau_etChrgEM01_1Trk, &b_Tau_etChrgEM01_1Trk);
        fChain->SetBranchAddress("Tau_etChrgEM01_2Trk", &Tau_etChrgEM01_2Trk, &b_Tau_etChrgEM01_2Trk);
        fChain->SetBranchAddress("Tau_etChrgEM01_3Trk", &Tau_etChrgEM01_3Trk, &b_Tau_etChrgEM01_3Trk);
        fChain->SetBranchAddress("Tau_etResChrgEM_1Trk", &Tau_etResChrgEM_1Trk, &b_Tau_etResChrgEM_1Trk);
        fChain->SetBranchAddress("Tau_etResChrgEM_2Trk", &Tau_etResChrgEM_2Trk, &b_Tau_etResChrgEM_2Trk);
        fChain->SetBranchAddress("Tau_etResChrgEM_3Trk", &Tau_etResChrgEM_3Trk, &b_Tau_etResChrgEM_3Trk);
        fChain->SetBranchAddress("Tau_z0SinThetaSig", &Tau_z0SinThetaSig, &b_Tau_z0SinThetaSig);
        fChain->SetBranchAddress("Tau_etChrgHADoverPttot", &Tau_etChrgHADoverPttot, &b_Tau_etChrgHADoverPttot);
        fChain->SetBranchAddress("Tau_etIsolFrac", &Tau_etIsolFrac, &b_Tau_etIsolFrac);
        fChain->SetBranchAddress("Tau_etEflow", &Tau_etEflow, &b_Tau_etEflow);
        fChain->SetBranchAddress("Tau_hadronicLeak", &Tau_hadronicLeak, &b_Tau_hadronicLeak);
        fChain->SetBranchAddress("Tau_secondaryMax", &Tau_secondaryMax, &b_Tau_secondaryMax);
        fChain->SetBranchAddress("Tau_sumEtCellsLArOverLeadTrackPt", &Tau_sumEtCellsLArOverLeadTrackPt, &b_Tau_sumEtCellsLArOverLeadTrackPt);
        fChain->SetBranchAddress("Tau_centralityFraction", &Tau_centralityFraction, &b_Tau_centralityFraction);
        fChain->SetBranchAddress("Tau_etEMCalib", &Tau_etEMCalib, &b_Tau_etEMCalib);
        fChain->SetBranchAddress("Tau_etHadCalib", &Tau_etHadCalib, &b_Tau_etHadCalib);
        fChain->SetBranchAddress("Tau_trackCaloEta1", &Tau_trackCaloEta1, &b_Tau_trackCaloEta1);
        fChain->SetBranchAddress("Tau_trackCaloEta2", &Tau_trackCaloEta2, &b_Tau_trackCaloEta2);
        fChain->SetBranchAddress("Tau_trackCaloEta3", &Tau_trackCaloEta3, &b_Tau_trackCaloEta3);
        fChain->SetBranchAddress("Tau_trackCaloPhi1", &Tau_trackCaloPhi1, &b_Tau_trackCaloPhi1);
        fChain->SetBranchAddress("Tau_trackCaloPhi2", &Tau_trackCaloPhi2, &b_Tau_trackCaloPhi2);
        fChain->SetBranchAddress("Tau_trackCaloPhi3", &Tau_trackCaloPhi3, &b_Tau_trackCaloPhi3);
        fChain->SetBranchAddress("Tau_leadingTrackPT", &Tau_leadingTrackPT, &b_Tau_leadingTrackPT);
        fChain->SetBranchAddress("Tau_ipSigLeadTrack", &Tau_ipSigLeadTrack, &b_Tau_ipSigLeadTrack);
        fChain->SetBranchAddress("Tau_etaCalo", &Tau_etaCalo, &b_Tau_etaCalo);
        fChain->SetBranchAddress("Tau_phiCalo", &Tau_phiCalo, &b_Tau_phiCalo);
        fChain->SetBranchAddress("Tau_hadRadius", &Tau_hadRadius, &b_Tau_hadRadius);
        fChain->SetBranchAddress("Tau_sumEmCellEt", &Tau_sumEmCellEt, &b_Tau_sumEmCellEt);
        fChain->SetBranchAddress("Tau_sumHadCellEt", &Tau_sumHadCellEt, &b_Tau_sumHadCellEt);
        fChain->SetBranchAddress("Tau_DiscCut", &Tau_DiscCut, &b_Tau_DiscCut);
        fChain->SetBranchAddress("Tau_DiscNN", &Tau_DiscNN, &b_Tau_DiscNN);
        fChain->SetBranchAddress("Tau_EfficNN", &Tau_EfficNN, &b_Tau_EfficNN);
        fChain->SetBranchAddress("Tau_T_HadTau_DeltaR", &Tau_T_HadTau_DeltaR, &b_Tau_T_HadTau_DeltaR);
        fChain->SetBranchAddress("El_E", &El_E, &b_El_E);
        fChain->SetBranchAddress("El_p_T", &El_p_T, &b_El_p_T);
        fChain->SetBranchAddress("El_phi", &El_phi, &b_El_phi);
        fChain->SetBranchAddress("El_eta", &El_eta, &b_El_eta);
        fChain->SetBranchAddress("El_px", &El_px, &b_El_px);
        fChain->SetBranchAddress("El_py", &El_py, &b_El_py);
        fChain->SetBranchAddress("El_pz", &El_pz, &b_El_pz);
        fChain->SetBranchAddress("El_m", &El_m, &b_El_m);
        fChain->SetBranchAddress("El_charge", &El_charge, &b_El_charge);
        fChain->SetBranchAddress("El_pdgId", &El_pdgId, &b_El_pdgId);
        fChain->SetBranchAddress("El_EtaCorrMag", &El_EtaCorrMag, &b_El_EtaCorrMag);
        fChain->SetBranchAddress("El_EoverP", &El_EoverP, &b_El_EoverP);
        fChain->SetBranchAddress("El_deltaEta1", &El_deltaEta1, &b_El_deltaEta1);
        fChain->SetBranchAddress("El_deltaEta2", &El_deltaEta2, &b_El_deltaEta2);
        fChain->SetBranchAddress("El_deltaPhi2", &El_deltaPhi2, &b_El_deltaPhi2);
        fChain->SetBranchAddress("El_etcone20", &El_etcone20, &b_El_etcone20);
        fChain->SetBranchAddress("El_T_El_DeltaR", &El_T_El_DeltaR, &b_El_T_El_DeltaR);
        fChain->SetBranchAddress("Mu_E", &Mu_E, &b_Mu_E);
        fChain->SetBranchAddress("Mu_p_T", &Mu_p_T, &b_Mu_p_T);
        fChain->SetBranchAddress("Mu_phi", &Mu_phi, &b_Mu_phi);
        fChain->SetBranchAddress("Mu_eta", &Mu_eta, &b_Mu_eta);
        fChain->SetBranchAddress("Mu_px", &Mu_px, &b_Mu_px);
        fChain->SetBranchAddress("Mu_py", &Mu_py, &b_Mu_py);
        fChain->SetBranchAddress("Mu_pz", &Mu_pz, &b_Mu_pz);
        fChain->SetBranchAddress("Mu_m", &Mu_m, &b_Mu_m);
        fChain->SetBranchAddress("Mu_charge", &Mu_charge, &b_Mu_charge);
        fChain->SetBranchAddress("Mu_pdgId", &Mu_pdgId, &b_Mu_pdgId);
        fChain->SetBranchAddress("Mu_etcone40", &Mu_etcone40, &b_Mu_etcone40);
        fChain->SetBranchAddress("Mu_nucone40", &Mu_nucone40, &b_Mu_nucone40);
        fChain->SetBranchAddress("Mu_etcone20", &Mu_etcone20, &b_Mu_etcone20);
        fChain->SetBranchAddress("Mu_matchChi2", &Mu_matchChi2, &b_Mu_matchChi2);
        fChain->SetBranchAddress("Mu_matchChi2OverDoF", &Mu_matchChi2OverDoF, &b_Mu_matchChi2OverDoF);
        fChain->SetBranchAddress("Mu_SumTrkPtInCone", &Mu_SumTrkPtInCone, &b_Mu_SumTrkPtInCone);
        fChain->SetBranchAddress("Mu_T_Mu_DeltaR", &Mu_T_Mu_DeltaR, &b_Mu_T_Mu_DeltaR);
        fChain->SetBranchAddress("JetC4T_E", &JetC4T_E, &b_JetC4T_E);
        fChain->SetBranchAddress("JetC4T_p_T", &JetC4T_p_T, &b_JetC4T_p_T);
        fChain->SetBranchAddress("JetC4T_phi", &JetC4T_phi, &b_JetC4T_phi);
        fChain->SetBranchAddress("JetC4T_eta", &JetC4T_eta, &b_JetC4T_eta);
        fChain->SetBranchAddress("JetC4T_px", &JetC4T_px, &b_JetC4T_px);
        fChain->SetBranchAddress("JetC4T_py", &JetC4T_py, &b_JetC4T_py);
        fChain->SetBranchAddress("JetC4T_pz", &JetC4T_pz, &b_JetC4T_pz);
        fChain->SetBranchAddress("JetC4T_m", &JetC4T_m, &b_JetC4T_m);
        fChain->SetBranchAddress("JetC4T_charge", &JetC4T_charge, &b_JetC4T_charge);
        fChain->SetBranchAddress("JetC4T_pdgId", &JetC4T_pdgId, &b_JetC4T_pdgId);
        fChain->SetBranchAddress("JetC4T_weight", &JetC4T_weight, &b_JetC4T_weight);
        fChain->SetBranchAddress("JetC4T_SoftMuonWeight", &JetC4T_SoftMuonWeight, &b_JetC4T_SoftMuonWeight);
        fChain->SetBranchAddress("JetC4T_SoftElectronWeight", &JetC4T_SoftElectronWeight, &b_JetC4T_SoftElectronWeight);
        fChain->SetBranchAddress("JetC4T_IP1D", &JetC4T_IP1D, &b_JetC4T_IP1D);
        fChain->SetBranchAddress("JetC4T_IP2D", &JetC4T_IP2D, &b_JetC4T_IP2D);
        fChain->SetBranchAddress("JetC4T_IP3D", &JetC4T_IP3D, &b_JetC4T_IP3D);
        fChain->SetBranchAddress("JetC4T_SV1", &JetC4T_SV1, &b_JetC4T_SV1);
        fChain->SetBranchAddress("JetC4T_SecVtxTagBU", &JetC4T_SecVtxTagBU, &b_JetC4T_SecVtxTagBU);
        fChain->SetBranchAddress("JetC4T_SV2", &JetC4T_SV2, &b_JetC4T_SV2);
        fChain->SetBranchAddress("JetC4T_T_Jet_DeltaR", &JetC4T_T_Jet_DeltaR, &b_JetC4T_T_Jet_DeltaR);
        fChain->SetBranchAddress("JetC4T_T_El_DeltaR", &JetC4T_T_El_DeltaR, &b_JetC4T_T_El_DeltaR);
        fChain->SetBranchAddress("JetC4T_T_TauVis_DeltaR", &JetC4T_T_TauVis_DeltaR, &b_JetC4T_T_TauVis_DeltaR);
        fChain->SetBranchAddress("JetC4T_T_Ph_DeltaR", &JetC4T_T_Ph_DeltaR, &b_JetC4T_T_Ph_DeltaR);
        fChain->SetBranchAddress("Trk_E", &Trk_E, &b_Trk_E);
        fChain->SetBranchAddress("Trk_p_T", &Trk_p_T, &b_Trk_p_T);
        fChain->SetBranchAddress("Trk_phi", &Trk_phi, &b_Trk_phi);
        fChain->SetBranchAddress("Trk_eta", &Trk_eta, &b_Trk_eta);
        fChain->SetBranchAddress("Trk_px", &Trk_px, &b_Trk_px);
        fChain->SetBranchAddress("Trk_py", &Trk_py, &b_Trk_py);
        fChain->SetBranchAddress("Trk_pz", &Trk_pz, &b_Trk_pz);
        fChain->SetBranchAddress("Trk_m", &Trk_m, &b_Trk_m);
        fChain->SetBranchAddress("Trk_charge", &Trk_charge, &b_Trk_charge);
        fChain->SetBranchAddress("Trk_pdgId", &Trk_pdgId, &b_Trk_pdgId);
        fChain->SetBranchAddress("T_Tau_E", &T_Tau_E, &b_T_Tau_E);
        fChain->SetBranchAddress("T_Tau_p_T", &T_Tau_p_T, &b_T_Tau_p_T);
        fChain->SetBranchAddress("T_Tau_phi", &T_Tau_phi, &b_T_Tau_phi);
        fChain->SetBranchAddress("T_Tau_eta", &T_Tau_eta, &b_T_Tau_eta);
        fChain->SetBranchAddress("T_Tau_px", &T_Tau_px, &b_T_Tau_px);
        fChain->SetBranchAddress("T_Tau_py", &T_Tau_py, &b_T_Tau_py);
        fChain->SetBranchAddress("T_Tau_pz", &T_Tau_pz, &b_T_Tau_pz);
        fChain->SetBranchAddress("T_Tau_m", &T_Tau_m, &b_T_Tau_m);
        fChain->SetBranchAddress("T_Tau_charge", &T_Tau_charge, &b_T_Tau_charge);
        fChain->SetBranchAddress("T_Tau_pdgId", &T_Tau_pdgId, &b_T_Tau_pdgId);
        fChain->SetBranchAddress("T_TauVis_E", &T_TauVis_E, &b_T_TauVis_E);
        fChain->SetBranchAddress("T_TauVis_p_T", &T_TauVis_p_T, &b_T_TauVis_p_T);
        fChain->SetBranchAddress("T_TauVis_phi", &T_TauVis_phi, &b_T_TauVis_phi);
        fChain->SetBranchAddress("T_TauVis_eta", &T_TauVis_eta, &b_T_TauVis_eta);
        fChain->SetBranchAddress("T_TauVis_px", &T_TauVis_px, &b_T_TauVis_px);
        fChain->SetBranchAddress("T_TauVis_py", &T_TauVis_py, &b_T_TauVis_py);
        fChain->SetBranchAddress("T_TauVis_pz", &T_TauVis_pz, &b_T_TauVis_pz);
        fChain->SetBranchAddress("T_TauVis_m", &T_TauVis_m, &b_T_TauVis_m);
        fChain->SetBranchAddress("T_TauVis_charge", &T_TauVis_charge, &b_T_TauVis_charge);
        fChain->SetBranchAddress("T_TauVis_pdgId", &T_TauVis_pdgId, &b_T_TauVis_pdgId);
        fChain->SetBranchAddress("T_TauVis_T_HadTau_DeltaR", &T_TauVis_T_HadTau_DeltaR, &b_T_TauVis_T_HadTau_DeltaR);
        fChain->SetBranchAddress("T_Mu_E", &T_Mu_E, &b_T_Mu_E);
        fChain->SetBranchAddress("T_Mu_p_T", &T_Mu_p_T, &b_T_Mu_p_T);
        fChain->SetBranchAddress("T_Mu_phi", &T_Mu_phi, &b_T_Mu_phi);
        fChain->SetBranchAddress("T_Mu_eta", &T_Mu_eta, &b_T_Mu_eta);
        fChain->SetBranchAddress("T_Mu_px", &T_Mu_px, &b_T_Mu_px);
        fChain->SetBranchAddress("T_Mu_py", &T_Mu_py, &b_T_Mu_py);
        fChain->SetBranchAddress("T_Mu_pz", &T_Mu_pz, &b_T_Mu_pz);
        fChain->SetBranchAddress("T_Mu_m", &T_Mu_m, &b_T_Mu_m);
        fChain->SetBranchAddress("T_Mu_charge", &T_Mu_charge, &b_T_Mu_charge);
        fChain->SetBranchAddress("T_Mu_pdgId", &T_Mu_pdgId, &b_T_Mu_pdgId);
        fChain->SetBranchAddress("T_El_E", &T_El_E, &b_T_El_E);
        fChain->SetBranchAddress("T_El_p_T", &T_El_p_T, &b_T_El_p_T);
        fChain->SetBranchAddress("T_El_phi", &T_El_phi, &b_T_El_phi);
        fChain->SetBranchAddress("T_El_eta", &T_El_eta, &b_T_El_eta);
        fChain->SetBranchAddress("T_El_px", &T_El_px, &b_T_El_px);
        fChain->SetBranchAddress("T_El_py", &T_El_py, &b_T_El_py);
        fChain->SetBranchAddress("T_El_pz", &T_El_pz, &b_T_El_pz);
        fChain->SetBranchAddress("T_El_m", &T_El_m, &b_T_El_m);
        fChain->SetBranchAddress("T_El_charge", &T_El_charge, &b_T_El_charge);
        fChain->SetBranchAddress("T_El_pdgId", &T_El_pdgId, &b_T_El_pdgId);
        fChain->SetBranchAddress("T_JetC4_E", &T_JetC4_E, &b_T_JetC4_E);
        fChain->SetBranchAddress("T_JetC4_p_T", &T_JetC4_p_T, &b_T_JetC4_p_T);
        fChain->SetBranchAddress("T_JetC4_phi", &T_JetC4_phi, &b_T_JetC4_phi);
        fChain->SetBranchAddress("T_JetC4_eta", &T_JetC4_eta, &b_T_JetC4_eta);
        fChain->SetBranchAddress("T_JetC4_px", &T_JetC4_px, &b_T_JetC4_px);
        fChain->SetBranchAddress("T_JetC4_py", &T_JetC4_py, &b_T_JetC4_py);
        fChain->SetBranchAddress("T_JetC4_pz", &T_JetC4_pz, &b_T_JetC4_pz);
        fChain->SetBranchAddress("T_JetC4_m", &T_JetC4_m, &b_T_JetC4_m);
        fChain->SetBranchAddress("T_JetC4_charge", &T_JetC4_charge, &b_T_JetC4_charge);
        fChain->SetBranchAddress("T_JetC4_pdgId", &T_JetC4_pdgId, &b_T_JetC4_pdgId);
        fChain->SetBranchAddress("T_JetC4_T_El_DeltaR", &T_JetC4_T_El_DeltaR, &b_T_JetC4_T_El_DeltaR);
        fChain->SetBranchAddress("T_JetC4_T_Mu_DeltaR", &T_JetC4_T_Mu_DeltaR, &b_T_JetC4_T_Mu_DeltaR);
        fChain->SetBranchAddress("T_JetC4_T_Ph_DeltaR", &T_JetC4_T_Ph_DeltaR, &b_T_JetC4_T_Ph_DeltaR);
        fChain->SetBranchAddress("T_JetC4_T_TauVis_DeltaR", &T_JetC4_T_TauVis_DeltaR, &b_T_JetC4_T_TauVis_DeltaR);
        fChain->SetBranchAddress("T_JetC4_T_Jet_DeltaR", &T_JetC4_T_Jet_DeltaR, &b_T_JetC4_T_Jet_DeltaR);
        fChain->SetBranchAddress("Tau_isTauLoose", &Tau_isTauLoose, &b_Tau_isTauLoose);
        fChain->SetBranchAddress("Tau_isTauMedium", &Tau_isTauMedium, &b_Tau_isTauMedium);
        fChain->SetBranchAddress("Tau_isTauTight", &Tau_isTauTight, &b_Tau_isTauTight);
        fChain->SetBranchAddress("Tau_EgammaFlag", &Tau_EgammaFlag, &b_Tau_EgammaFlag);
        fChain->SetBranchAddress("Tau_numTrack", &Tau_numTrack, &b_Tau_numTrack);
        fChain->SetBranchAddress("Tau_numStripCells", &Tau_numStripCells, &b_Tau_numStripCells);
        fChain->SetBranchAddress("Tau_nAssocTracksCore", &Tau_nAssocTracksCore, &b_Tau_nAssocTracksCore);
        fChain->SetBranchAddress("Tau_nAssocTracksIsol", &Tau_nAssocTracksIsol, &b_Tau_nAssocTracksIsol);
        fChain->SetBranchAddress("Tau_numPi0", &Tau_numPi0, &b_Tau_numPi0);
        fChain->SetBranchAddress("Tau_nTracksdrdR", &Tau_nTracksdrdR, &b_Tau_nTracksdrdR);
        fChain->SetBranchAddress("Tau_numTrackDetails", &Tau_numTrackDetails, &b_Tau_numTrackDetails);
        fChain->SetBranchAddress("Tau_hasAuthor_TauRec", &Tau_hasAuthor_TauRec, &b_Tau_hasAuthor_TauRec);
        fChain->SetBranchAddress("Tau_hasAuthor_Tau1P3P", &Tau_hasAuthor_Tau1P3P, &b_Tau_hasAuthor_Tau1P3P);
        fChain->SetBranchAddress("Tau_ElectronFlag", &Tau_ElectronFlag, &b_Tau_ElectronFlag);
        fChain->SetBranchAddress("Tau_MuonFlag", &Tau_MuonFlag, &b_Tau_MuonFlag);
        fChain->SetBranchAddress("Tau_T_HadTau_Matched", &Tau_T_HadTau_Matched, &b_Tau_T_HadTau_Matched);
        fChain->SetBranchAddress("El_IsEM", &El_IsEM, &b_El_IsEM);
        fChain->SetBranchAddress("El_author", &El_author, &b_El_author);
        fChain->SetBranchAddress("El_T_El_Matched", &El_T_El_Matched, &b_El_T_El_Matched);
        fChain->SetBranchAddress("Mu_author", &Mu_author, &b_Mu_author);
        fChain->SetBranchAddress("Mu_hasCluster", &Mu_hasCluster, &b_Mu_hasCluster);
        fChain->SetBranchAddress("Mu_hasCombinedMuon", &Mu_hasCombinedMuon, &b_Mu_hasCombinedMuon);
        fChain->SetBranchAddress("Mu_nTrkInCone", &Mu_nTrkInCone, &b_Mu_nTrkInCone);
        fChain->SetBranchAddress("Mu_T_Mu_Matched", &Mu_T_Mu_Matched, &b_Mu_T_Mu_Matched);
        fChain->SetBranchAddress("JetC4T_SoftMuonNumTrack", &JetC4T_SoftMuonNumTrack, &b_JetC4T_SoftMuonNumTrack);
        fChain->SetBranchAddress("JetC4T_SoftElectronNumTrack", &JetC4T_SoftElectronNumTrack, &b_JetC4T_SoftElectronNumTrack);
        fChain->SetBranchAddress("JetC4T_T_Jet_Matched", &JetC4T_T_Jet_Matched, &b_JetC4T_T_Jet_Matched);
        fChain->SetBranchAddress("JetC4T_T_El_Matched", &JetC4T_T_El_Matched, &b_JetC4T_T_El_Matched);
        fChain->SetBranchAddress("JetC4T_T_TauVis_Matched", &JetC4T_T_TauVis_Matched, &b_JetC4T_T_TauVis_Matched);
        fChain->SetBranchAddress("JetC4T_T_Ph_Matched", &JetC4T_T_Ph_Matched, &b_JetC4T_T_Ph_Matched);
        fChain->SetBranchAddress("T_Tau_nParents", &T_Tau_nParents, &b_T_Tau_nParents);
        fChain->SetBranchAddress("T_Tau_nDecay", &T_Tau_nDecay, &b_T_Tau_nDecay);
        fChain->SetBranchAddress("T_TauVis_T_HadTau_Matched", &T_TauVis_T_HadTau_Matched, &b_T_TauVis_T_HadTau_Matched);
        fChain->SetBranchAddress("T_Mu_nParents", &T_Mu_nParents, &b_T_Mu_nParents);
        fChain->SetBranchAddress("T_Mu_nDecay", &T_Mu_nDecay, &b_T_Mu_nDecay);
        fChain->SetBranchAddress("T_El_nParents", &T_El_nParents, &b_T_El_nParents);
        fChain->SetBranchAddress("T_El_nDecay", &T_El_nDecay, &b_T_El_nDecay);
        fChain->SetBranchAddress("T_JetC4_T_El_Matched", &T_JetC4_T_El_Matched, &b_T_JetC4_T_El_Matched);
        fChain->SetBranchAddress("T_JetC4_T_Mu_Matched", &T_JetC4_T_Mu_Matched, &b_T_JetC4_T_Mu_Matched);
        fChain->SetBranchAddress("T_JetC4_T_Ph_Matched", &T_JetC4_T_Ph_Matched, &b_T_JetC4_T_Ph_Matched);
        fChain->SetBranchAddress("T_JetC4_T_TauVis_Matched", &T_JetC4_T_TauVis_Matched, &b_T_JetC4_T_TauVis_Matched);
        fChain->SetBranchAddress("T_JetC4_T_Jet_Matched", &T_JetC4_T_Jet_Matched, &b_T_JetC4_T_Jet_Matched);
        fChain->SetBranchAddress("T_Tau_ParentIDs", &T_Tau_ParentIDs, &b_T_Tau_ParentIDs);
        fChain->SetBranchAddress("T_El_ParentIDs", &T_El_ParentIDs, &b_T_El_ParentIDs);
        fChain->SetBranchAddress("Tau_Trk_pT", &Tau_Trk_pT, &b_Tau_Trk_pT);
        fChain->SetBranchAddress("Tau_Trk_phi", &Tau_Trk_phi, &b_Tau_Trk_phi);
        fChain->SetBranchAddress("Tau_Trk_eta", &Tau_Trk_eta, &b_Tau_Trk_eta);
        fChain->SetBranchAddress("Tau_Pi0_eta", &Tau_Pi0_eta, &b_Tau_Pi0_eta);
        fChain->SetBranchAddress("Tau_Pi0_phi", &Tau_Pi0_phi, &b_Tau_Pi0_phi);
        fChain->SetBranchAddress("Tau_Pi0_et", &Tau_Pi0_et, &b_Tau_Pi0_et);
        fChain->SetBranchAddress("Tau_Pi0_e", &Tau_Pi0_e, &b_Tau_Pi0_e);
        fChain->SetBranchAddress("T_Tau_DecayIDs", &T_Tau_DecayIDs, &b_T_Tau_DecayIDs);
        fChain->SetBranchAddress("T_Tau_ParentBarcodes", &T_Tau_ParentBarcodes, &b_T_Tau_ParentBarcodes);
        fChain->SetBranchAddress("T_Tau_DecayBarcodes", &T_Tau_DecayBarcodes, &b_T_Tau_DecayBarcodes);
        fChain->SetBranchAddress("T_Tau_ParentStatus", &T_Tau_ParentStatus, &b_T_Tau_ParentStatus);
        fChain->SetBranchAddress("T_Tau_DecayStatus", &T_Tau_DecayStatus, &b_T_Tau_DecayStatus);
        fChain->SetBranchAddress("T_Tau_DecayPt", &T_Tau_DecayPt, &b_T_Tau_DecayPt);
        fChain->SetBranchAddress("T_Tau_DecayEta", &T_Tau_DecayEta, &b_T_Tau_DecayEta);
        fChain->SetBranchAddress("T_Tau_ParentPt", &T_Tau_ParentPt, &b_T_Tau_ParentPt);
        fChain->SetBranchAddress("T_Tau_ParentEta", &T_Tau_ParentEta, &b_T_Tau_ParentEta);
        fChain->SetBranchAddress("T_Mu_ParentIDs", &T_Mu_ParentIDs, &b_T_Mu_ParentIDs);
        fChain->SetBranchAddress("T_Mu_ParentBarcodes", &T_Mu_ParentBarcodes, &b_T_Mu_ParentBarcodes);
        fChain->SetBranchAddress("T_Mu_ParentStatus", &T_Mu_ParentStatus, &b_T_Mu_ParentStatus);
        fChain->SetBranchAddress("T_Mu_ParentPt", &T_Mu_ParentPt, &b_T_Mu_ParentPt);
        fChain->SetBranchAddress("T_Mu_ParentEta", &T_Mu_ParentEta, &b_T_Mu_ParentEta);
        fChain->SetBranchAddress("T_Mu_DecayIDs", &T_Mu_DecayIDs, &b_T_Mu_DecayIDs);
        fChain->SetBranchAddress("T_Mu_DecayBarcodes", &T_Mu_DecayBarcodes, &b_T_Mu_DecayBarcodes);
        fChain->SetBranchAddress("T_Mu_DecayStatus", &T_Mu_DecayStatus, &b_T_Mu_DecayStatus);
        fChain->SetBranchAddress("T_Mu_DecayPt", &T_Mu_DecayPt, &b_T_Mu_DecayPt);
        fChain->SetBranchAddress("T_Mu_DecayEta", &T_Mu_DecayEta, &b_T_Mu_DecayEta);
        fChain->SetBranchAddress("T_El_DecayIDs", &T_El_DecayIDs, &b_T_El_DecayIDs);
        fChain->SetBranchAddress("T_El_ParentBarcodes", &T_El_ParentBarcodes, &b_T_El_ParentBarcodes);
        fChain->SetBranchAddress("T_El_DecayBarcodes", &T_El_DecayBarcodes, &b_T_El_DecayBarcodes);
        fChain->SetBranchAddress("T_El_ParentStatus", &T_El_ParentStatus, &b_T_El_ParentStatus);
        fChain->SetBranchAddress("T_El_DecayStatus", &T_El_DecayStatus, &b_T_El_DecayStatus);
        fChain->SetBranchAddress("T_El_DecayPt", &T_El_DecayPt, &b_T_El_DecayPt);
        fChain->SetBranchAddress("T_El_DecayEta", &T_El_DecayEta, &b_T_El_DecayEta);
        fChain->SetBranchAddress("T_El_ParentPt", &T_El_ParentPt, &b_T_El_ParentPt);
        fChain->SetBranchAddress("T_El_ParentEta", &T_El_ParentEta, &b_T_El_ParentEta);
        fChain->SetBranchAddress("ControlSampleInstance", &ControlSampleInstance, &b_ControlSampleInstance);
        fChain->SetBranchAddress("ControlSampleCounter", &ControlSampleCounter, &b_ControlSampleCounter);
        fChain->SetBranchAddress("ControlSampleEventAndInstance", &ControlSampleEventAndInstance, &b_ControlSampleEventAndInstance);
        fChain->SetBranchAddress("ControlSampleRunNumber", &ControlSampleRunNumber, &b_ControlSampleRunNumber);
        fChain->SetBranchAddress("ControlSampleNInstance", &ControlSampleNInstance, &b_ControlSampleNInstance);
    }

#endif
