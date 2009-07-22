#include "Analyse.hpp"

#include <cassert>
#include <iostream>

namespace ba
{

    bool Analyse::good_lepton(charged_particle const& lepton)
    {
        assert(lepton.kind == particle::ELECTRON ||
               lepton.kind == particle::MUON);

        for (particle_vector::const_iterator i = jets_.begin();
             i != jets_.end(); ++i)
        {
            if (lepton.momentum.DeltaR(i->momentum) < 0.4)
                return false;
        }
        return true;
    }

}
