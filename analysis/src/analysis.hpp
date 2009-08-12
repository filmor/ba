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
        analysis (TTree& tree);

        void loop ();

    protected:
        void get_entry (std::size_t entry);
        bool good_lepton (charged_particle const&);

    private:
        typedef std::vector<double>* double_vp;
        typedef std::vector<int>* int_vp;
        typedef std::vector<charged_particle> particle_vector;

        /// Teilchenvektoren
        particle_vector jets_, leptons_;

        /// Referenz auf den zu untersuchenden Baum
        TTree&          tree_;  

        /// Komponenten der fehlenden Transversalenergie \{
        double MET_RefFinal_ex;
        double MET_RefFinal_ey;
        double MET_RefFinal_et;
        /// \}

        /// Gewichtung des Ereignisses
        double eventWeight;

        /// Hat sowohl innere als auch äußere Spur
        int_vp Mu_hasCombinedMuon;

        /// Elektronenqualität
        int_vp El_IsEM;

        /// Elektronendaten (Zahl, Impuls, Ladung) \{
        int El_N;
        double_vp El_E;
        double_vp El_px;
        double_vp El_py;
        double_vp El_pz;
        double_vp El_charge;
        /// \}

        /// Myonendaten \{
        int Mu_N;
        double_vp Mu_E;
        double_vp Mu_px;
        double_vp Mu_py;
        double_vp Mu_pz;
        double_vp Mu_charge;
        /// \}
        
        /// Jetdaten \{
        int JetC4T_N;
        double_vp JetC4T_E;
        double_vp JetC4T_px;
        double_vp JetC4T_py;
        double_vp JetC4T_pz;
        double_vp JetC4T_charge;
        /// \}
   };
}

#endif
