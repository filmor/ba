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
                  double px, double py, double pz, double E,
                  int index_ = -1)
            : particle(kind_, px, py, pz, E)
            , charge(charge_)
            , index(index_)
        {}

        charged_particle (kind_type kind_, double charge_,
                          TLorentzVector const& p, int index_ = -1)
            : particle(kind_, p)
            , charge(charge_)
        {}

        int index;
        double charge;
    };

}

#endif
