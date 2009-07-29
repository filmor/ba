#ifndef ANALYSE_HPP
#define ANALYSE_HPP

#include <vector>
#include <set>

#include <TTree.h>

#include "particle.hpp"

namespace ba
{

    class analysis
    {
    public:
        analysis(TTree& tree);

        void loop (Long64_t begin = 0, Long64_t end = -1);

    private:
        void get_entry (std::size_t entry);
        bool good_lepton (charged_particle const&);

        typedef std::vector<charged_particle> particle_vector;
        particle_vector jets_, leptons_;
        TTree&          tree_;  

        // Declaration of leave types
        Double_t             MET_RefFinal_ex;
        Double_t             MET_RefFinal_ey;
        Double_t             MET_RefFinal_et;
        Double_t             eventWeight;
        Int_t                El_N;
        Int_t                Mu_N;
        Int_t                JetC4T_N;
        std::vector<double>  *El_E;
        std::vector<double>  *El_px;
        std::vector<double>  *El_py;
        std::vector<double>  *El_pz;
        std::vector<double>  *El_charge;
        std::vector<double>  *Mu_E;
        std::vector<double>  *Mu_px;
        std::vector<double>  *Mu_py;
        std::vector<double>  *Mu_pz;
        std::vector<double>  *Mu_charge;
        std::vector<double>  *JetC4T_E;
        std::vector<double>  *JetC4T_px;
        std::vector<double>  *JetC4T_py;
        std::vector<double>  *JetC4T_pz;
        std::vector<double>  *JetC4T_charge;
   };
}

#endif
