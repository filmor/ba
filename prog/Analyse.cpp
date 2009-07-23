#include "Analyse.hpp"

namespace ba
{
    Analyse::~Analyse()
    {
    }

    Analyse::Analyse(TTree& tree) : tree_(tree)
    {
        // Set object pointer
        El_E = 0;
        El_px = 0;
        El_py = 0;
        El_pz = 0;
        El_charge = 0;
        Mu_E = 0;
        Mu_px = 0;
        Mu_py = 0;
        Mu_pz = 0;
        Mu_charge = 0;
        JetC4T_E = 0;
        JetC4T_px = 0;
        JetC4T_py = 0;
        JetC4T_pz = 0;
        JetC4T_charge = 0;

        tree_.SetBranchAddress("MET_RefFinal_ex", &MET_RefFinal_ex);
        tree_.SetBranchAddress("MET_RefFinal_ey", &MET_RefFinal_ey);
        tree_.SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et);
        tree_.SetBranchAddress("El_N", &El_N);
        tree_.SetBranchAddress("Mu_N", &Mu_N);
        tree_.SetBranchAddress("JetC4T_N", &JetC4T_N);
        tree_.SetBranchAddress("El_E", &El_E);
        tree_.SetBranchAddress("El_px", &El_px);
        tree_.SetBranchAddress("El_py", &El_py);
        tree_.SetBranchAddress("El_pz", &El_pz);
        tree_.SetBranchAddress("El_charge", &El_charge);
        tree_.SetBranchAddress("Mu_E", &Mu_E);
        tree_.SetBranchAddress("Mu_px", &Mu_px);
        tree_.SetBranchAddress("Mu_py", &Mu_py);
        tree_.SetBranchAddress("Mu_pz", &Mu_pz);
        tree_.SetBranchAddress("Mu_charge", &Mu_charge);
        tree_.SetBranchAddress("JetC4T_E", &JetC4T_E);
        tree_.SetBranchAddress("JetC4T_px", &JetC4T_px);
        tree_.SetBranchAddress("JetC4T_py", &JetC4T_py);
        tree_.SetBranchAddress("JetC4T_pz", &JetC4T_pz);
        tree_.SetBranchAddress("JetC4T_charge", &JetC4T_charge);
    }

}
