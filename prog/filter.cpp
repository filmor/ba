#include "analysis.hpp"

#include <cassert>
#include <limits>

namespace ba
{

    bool analysis::good_lepton (charged_particle const& lepton)
    {
        assert(lepton.kind == particle::ELECTRON ||
               lepton.kind == particle::MUON);

        // Leptonen ohne Ladung filtern
        if (lepton.charge == 0.0)
            return false;
        
        // Weitere mögliche Tests:
        //  Für Myonen: Mu_matchChi2 sollte klein sein
        //  Für Elektronen: El_IsEM, flags in TWiki nachsehen
        
        for (particle_vector::const_iterator i = jets_.begin();
             i != jets_.end(); ++i)
        {
            // Alle Leptonen, die näher als 0.4 an einem Jet liegen
            // filtern, da in Atlas Jets mit einem Radius von 0.4
            // rekonstruiert werden
            if (lepton.momentum.DeltaR(i->momentum) < 0.4)
                return false;
        }
        return true;
    }

}
