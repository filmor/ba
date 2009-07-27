#ifndef BA_PARTICLE_HPP
#define BA_PARTICLE_HPP

#include <TLorentzVector.h>

namespace ba
{

    struct particle
    {
        enum kind_type { Z_BOSON, W_BOSON, UNDEFINED, ELECTRON, MUON };

#ifdef HAS_VARIADIC_TEMPLATES
        template <typename... Args>
        particle (kind_type kind_, Args const&... args)
            : momentum (args...)
            , kind (kind_)
        {}
#else
        particle (kind_type kind_, double px, double py,
                                   double pz, double E)
            : momentum(px, py, pz, E)
            , kind(kind_)
        {}
    
        particle (kind_type kind_, TLorentzVector const& p)
            : momentum(p)
            , kind(kind_)
        {}
#endif

        TLorentzVector momentum;
        kind_type kind;
    };

    struct charged_particle : particle
    {
#ifdef HAS_VARIADIC_TEMPLATES
        template <typename... Args>
        charged_particle (kind_type kind_, double charge_,
                          Args const&... args)
            : particle(kind_, args...)
            , charge(charge_)
        {}
#else
        charged_particle (kind_type kind_, double charge_,
                  double px, double py, double pz, double E)
            : particle(kind_, px, py, pz, E)
            , charge(charge_)
        {}

        charged_particle (kind_type kind_, double charge_,
                          TLorentzVector const& p)
            : particle(kind_, p)
            , charge(charge_)
        {}
#endif

        double charge;
    };

    // Make strings

}

#endif
