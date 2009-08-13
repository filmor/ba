#ifndef BA_PARTICLE_HPP
#define BA_PARTICLE_HPP

#include <TLorentzVector.h>

namespace ba
{

    struct particle
    {
        enum kind_type { Z_BOSON, W_BOSON, UNDEFINED, ELECTRON, MUON };

        particle (kind_type kind_, double px, double py,
                                   double pz, double E)
            : momentum(px, py, pz, E)
            , kind(kind_)
        {}
    
        particle (kind_type kind_, TLorentzVector const& p)
            : momentum(p)
            , kind(kind_)
        {}

        TLorentzVector momentum;
        kind_type kind;
    };

    struct charged_particle : particle
    {
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

        double charge;
    };

    inline double delta_R (particle const& p, particle const& q)
    {
        return p.momentum.DeltaR(q.momentum);
    }

}

#endif
