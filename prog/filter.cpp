#include "Analyse.hpp"

#include <cassert>
#include <limits>

namespace ba
{

    bool Analyse::good_lepton(charged_particle const& lepton)
    {
        assert(lepton.kind == particle::ELECTRON ||
               lepton.kind == particle::MUON);

        if (lepton.charge == 0.0)
            return false;
        
        // Für Myonen: Mu_matchChi2 sollte klein sein
        // Für Elektronen: El_IsEM, flags in TWiki nachsehen
        // Rekonstruktion der Jets mit delR = 0.4 in Atlas
        
        for (particle_vector::const_iterator i = jets_.begin();
             i != jets_.end(); ++i)
        {
            if (lepton.momentum.DeltaR(i->momentum) < 0.4)
                return false;
        }
        return true;
    }

}
