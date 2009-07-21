#ifndef BA_PARTICLE_HPP
#define BA_PARTICLE_HPP

#include <root/TLorentzVector.h>

namespace ba
{

    struct particle
    {
        enum kind_type { Z_BOSON, W_BOSON, UNDEFINED, ELECTRON, MUON };

        template <typename... Args>
        particle (kind_type kind_, Args const&... args)
            : momentum (args...)
            , kind (kind_)
        {}

        TLorentzVector momentum;
        kind_type kind;
    };

    struct charged_particle : particle
    {
        template <typename... Args>
        charged_particle (kind_type kind_, double charge_,
                          Args const&... args)
            : particle(kind_, args...)
            , charge(charge_)
        {}

        double charge;
    };

    // Make strings

}

#endif
