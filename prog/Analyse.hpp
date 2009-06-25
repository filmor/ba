#ifndef ANALYSE_HPP
#define ANALYSE_HPP

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <vector>

#include <typelist.hpp>

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

        template <typename TList>
        void     Loop(int start_index, int end_index); // cut_callback

    private:
        template <typename Head, typename Tail>
        void    do_loop (Head&, Tail&)

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
