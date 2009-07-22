#include "Analyse.hpp"
#include <cassert>
#include <iostream>

namespace ba
{

#define PARTICLE(nm, index, kind) \
    charged_particle(kind, (*nm##_charge)[index], (*nm##_px)[index], \
                     (*nm##_py)[index], (*nm##_pz)[index], \
                     (*nm##_E)[index])

    std::size_t Analyse::get_entry(std::size_t entry)
    {
        if (!fChain) return 0;
        std::size_t result = fChain->GetEntry(entry);
        // Read contents of entry.
        leptons_.clear();
        jets_.clear();
        // Die Jets werden in good_lepton verwendet.
        for (int i = 0; i < JetC4T_N; ++i)
            jets_.push_back(PARTICLE(JetC4T, i, particle::UNDEFINED));

        for (int i = 0; i < El_N; ++i)
        {
            charged_particle p = PARTICLE(El, i, particle::ELECTRON);
            if (good_lepton(p))
                leptons_.push_back(p);
        }
        for (int i = 0; i < Mu_N; ++i)
        {
            charged_particle p = PARTICLE(Mu, i, particle::MUON);
            if (good_lepton(p))
                leptons_.push_back(p);
        }

        // met_ = GET_PARTICLE_VECTOR(Met)(0);

        return result;
    }
    
#undef PARTICLE
}

