#include "analysis.hpp"

#include <cassert>

namespace ba
{

#define PARTICLE(nm, index, kind) \
    charged_particle(kind, (*nm##_charge)[index], (*nm##_px)[index], \
                     (*nm##_py)[index], (*nm##_pz)[index], \
                     (*nm##_E)[index])

    void analysis::get_entry(std::size_t entry)
    {
        tree_.GetEntry(entry);

        leptons_.clear();
        jets_.clear();

        // Die Jets werden in good_lepton verwendet, müssen also vorher
        // initialisiert sein
        for (int i = 0; i < JetC4T_N; ++i)
            jets_.push_back(PARTICLE(JetC4T, i, particle::UNDEFINED));

        // Elektronen in den Leptonenvektor eintragen
        for (int i = 0; i < El_N; ++i)
        {
            charged_particle p = PARTICLE(El, i, particle::ELECTRON);
            if (good_lepton(p))
                leptons_.push_back(p);
        }

        // Myonen in den Leptonenvektor eintragen
        for (int i = 0; i < Mu_N; ++i)
        {
            charged_particle p = PARTICLE(Mu, i, particle::MUON);
            if (good_lepton(p))
                leptons_.push_back(p);
        }
    }
    
#undef PARTICLE

}

