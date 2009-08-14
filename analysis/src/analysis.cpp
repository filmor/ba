#include "analysis.hpp"

#include "boost/stringize.hpp"

namespace ba
{

    analysis::analysis (TTree& tree, int test_flags)
        : tree_(tree)
        // Zeiger auf 0 setzen, damit SetBranchAddress anständig
        // funktioniert
        , El_E (0), El_px (0), El_py (0), El_pz (0), El_charge (0)
        , Mu_E (0), Mu_px (0), Mu_py (0), Mu_pz (0), Mu_charge (0)
        , JetC4T_E (0), JetC4T_px (0), JetC4T_py (0), JetC4T_pz (0)
        , JetC4T_charge (0), El_IsEM (0), Mu_hasCombinedMuon (0)
        // Das Gewicht mit 1 initialisieren
        , eventWeight (1.)
        , flags_ (test_flags)
    {
        // Erstmal alle Zweige abschalten
        tree_.SetBranchStatus("*", 0);

#define ENABLE(name) \
        tree_.SetBranchStatus(BOOST_PP_STRINGIZE(name), 1); \
        tree_.SetBranchAddress(BOOST_PP_STRINGIZE(name), &name);

#define ENABLE_PARTICLE(name) \
        ENABLE(name##_N); ENABLE(name##_px); ENABLE(name##_py); \
        ENABLE(name##_pz); ENABLE(name##_E); ENABLE(name##_charge);

        // Die Zweigadressen auf die Membervariablen setzen
        ENABLE(MET_RefFinal_ex);
        ENABLE(MET_RefFinal_ey);
        ENABLE(MET_RefFinal_et);
        ENABLE(El_IsEM);
        ENABLE(Mu_hasCombinedMuon);
        ENABLE_PARTICLE(El);
        ENABLE_PARTICLE(Mu);
        ENABLE_PARTICLE(JetC4T);

        // Sorrgt dafür, dass eventWeight nur dann angeschaltet wird, wenn der
        // entsprechende Zweig auch vorhanden ist
        if (tree_.FindBranch("eventWeight"))
            tree_.SetBranchStatus("eventWeight", 1);
    }

}
