#ifndef BA_PARTICLE_HPP
#define BA_PARTICLE_HPP

#include <root/TLorentzVector.h>

namespace ba
{

    struct particle
    {
        template <typename Args...>
        particle (Args const&... args) : momentum (args...)
        {}

        TLorentzVector momentum;
        enum { Z_BOSON, W_BOSON, UNDEFINED, ELECTRON, MUON }
            kind = UNDEFINED;
    };

    struct charged_particle : particle
    {
        template <typename Args...>
        charged_particle (double charge_, Args const&... args)
            : particle(args...)
            , charge(charge_)
        {}

        double charge;
    };

    // Make strings

}

#endif
