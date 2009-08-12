#ifndef EGAMMAEVENT_EGAMMAPIDDEFS_H
#define EGAMMAEVENT_EGAMMAPIDDEFS_H
/*****************************************************************************
Name    : egammaPIDdefs.h
Package : offline/Reconstruction/egammaEvent
Author  : Dirk Zerwas
Created : December 2004
Note    : 

DESCRIPTION:

This file defines the bit-occupation of the isEM flag of egamma
and the enum definition of the Identification results
*****************************************************************************
copied from revision 1.16
*****************************************************************************/

namespace egammaPID { 
  
  /*! \enum Bitdefinitons for the egamma class 
    see egammaParameters for info on the variable definitions */
  enum BitDef {
    // Cluster based egamma
    /** @brief cluster eta range */
    ClusterEtaRange        =  0,
    /** @brief cluster leakage into the hadronic calorimeter (ethad1/et_37),
	eta dependent for eta<0,8 and et>7,5GeV*/
    ClusterHadronicLeakage =  1,
    /** @brief energy in 2nd sampling (e277) */
    ClusterMiddleEnergy    =  4, 
    /** @brief energy ratio in 2nd sampling (e237/e277) */
    ClusterMiddleEratio37  =  5,
    /** @brief energy ratio in 2nd sampling (e233/e237) for photons */
    ClusterMiddleEratio33  =  6,
    /** @brief width in the second sampling (weta2) */
    ClusterMiddleWidth     =  7,
    /** @brief fraction of energy found in 1st sampling (f1) */
    ClusterStripsEratio    =  8,
    /** @brief energy of 2nd maximum in 1st sampling ~e2tsts1/(1000+const_lumi*et) */
    ClusterStripsDeltaEmax2=  9,
    /** @brief difference between 2nd maximum and 1st minimum in strips (e2tsts1-emins1) */
    ClusterStripsDeltaE    = 10,
    /** @brief shower width in 1st sampling (wtots1) */
    ClusterStripsWtot      = 11,
    /** @brief shower shape in shower core 1st sampling (fracs1) */
    ClusterStripsFracm     = 12,
    /** @brief shower width weighted by distance from the maximum one (weta1) */
    ClusterStripsWeta1c    = 13,
    /** @brief calorimetric isolation (etcone20) */
    ClusterIsolation       = 14,
    //Track based egamma
    /** @brief B layer hit */
    TrackBlayer            = 16,
    /** @brief number of Pixel hits */
    TrackPixel             = 17,
    /** @brief number of Pixel and SCT hits */
    TrackSi                = 18,
    /** @brief distance of closet approach */
    TrackA0                = 19,
    /** @brief eta difference between cluster and extrapolated track in the 1st sampling */
    TrackMatchEta          = 20,
    /** @brief phi difference between cluster and extrapolated track in the 2nd sampling */
    TrackMatchPhi          = 21,
    /** @brief energy-momentum match */
    TrackMatchEoverP       = 22,
    /** @brief number of TRT hits */
    TrackTRThits           = 24,
    /** @brief ratio of high to all TRT hits for isolated electrons */
    TrackTRTratio          = 25,
    /** @brief ratio of high to all TRT hits for non-isolated electrons */    
    TrackTRTratio90        = 26
  };

 /*! \enum Bitdefinitons for the egamma identification tools */
  enum PID {
    /** cut-based identification for egamma and softe
	see egammaRec/python/EMPIDBuilderBase.py for cut definitions */
    IsEM                = 0,
    /** @brief loglikelihood identification */
    ElectronWeight,
    /** @brief loglikelihood identification */
    BgWeight,
    NeuralNet,
    Hmatrix,
    Hmatrix5,
    /** @brief cut-based identification for softe electrons in jets (for btag) */
    SofteIsEM,
    /** @brief loglikelihood identification */
    SofteElectronWeight,
    /** @brief loglikelihood identification */
    SofteBgWeight,
    SofteNeuralNet,
    IsolationLikelihood,
    AdaBoost,
    /** @brief loglikelihood identification */
    PhotonWeight,
    /** @brief loglikelihood identification */
    BgPhotonWeight,
    LastEgammaPID
  };

  const double EgPidUndefined = -999.;
  /// for simplification
  const unsigned int HADLEAKETA = 
    0x1 << ClusterEtaRange        | 
    0x1 << ClusterHadronicLeakage;
  const unsigned int CALOSTRIPS=
    0x1 << ClusterStripsEratio     |
    0x1 << ClusterStripsDeltaEmax2 |
    0x1 << ClusterStripsDeltaE     |
    0x1 << ClusterStripsWtot       |
    0x1 << ClusterStripsFracm      |
    0x1 << ClusterStripsWeta1c    ;
  const unsigned int CALOMIDDLE=    
    0x1 << ClusterMiddleEnergy     |
    0x1 << ClusterMiddleEratio37   |
    0x1 << ClusterMiddleEratio33   |
    0x1 << ClusterMiddleWidth     ;
  const unsigned int CALOISO = 0x1 << ClusterIsolation ;
  const unsigned int CALONOISO = HADLEAKETA | CALOSTRIPS | CALOMIDDLE ;
  const unsigned int CALO = CALONOISO | CALOISO ;
  const unsigned int TRACKINGNOBLAYER =     
    0x1 << TrackPixel   |
    0x1 << TrackSi      |
    0x1 << TrackA0     ;
  const unsigned int TRACKING = TRACKINGNOBLAYER |  0x1 << TrackBlayer;
  const unsigned int TRACKMATCHDETA =
    0x1 << TrackMatchEta;
  const unsigned int TRACKMATCH =
    0x1 << TrackMatchEta      |
    0x1 << TrackMatchPhi      |
    0x1 << TrackMatchEoverP  ;
  const unsigned int TRACKMATCHNOEOVERP =
    0x1 << TrackMatchEta      |
    0x1 << TrackMatchPhi     ;
  const unsigned int TRT = 
    0x1 << TrackTRThits   |
    0x1 << TrackTRTratio ;
  const unsigned int TRT90 = 
    0x1 << TrackTRThits   |
    0x1 << TrackTRTratio90 ;
  const unsigned int ALLNOTRT= TRACKING | TRACKMATCH | CALO;
  const unsigned int ALL= ALLNOTRT | TRT;

  const unsigned int ElectronLoose = CALOMIDDLE | HADLEAKETA;
  const unsigned int ElectronMedium= CALO | TRACKINGNOBLAYER | TRACKMATCHDETA;
  const unsigned int ElectronMediumNoIso = CALONOISO | TRACKINGNOBLAYER | TRACKMATCHDETA ;
  const unsigned int ElectronTight = ALL;
  const unsigned int ElectronTightTRTNoIso = TRACKING | TRACKMATCH | CALONOISO | TRT90 ;
  const unsigned int ElectronTightNoIsolation = ElectronTightTRTNoIso;

  const unsigned int PhotonTight = CALO;

}
#endif // EGAMMAREC_EGAMMAPIDDEFS_H
