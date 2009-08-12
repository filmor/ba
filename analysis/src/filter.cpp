#include "analysis.hpp"

#include "athena/egammaPIDdefs.h"

#include <cassert>

namespace ba
{
    static const int electron_identification = egammaPID::ElectronTight;

    bool analysis::good_lepton (charged_particle const& lepton)
    {
        assert(lepton.kind == particle::ELECTRON ||
               lepton.kind == particle::MUON);

        // Leptonen ohne Ladung filtern
        if (lepton.charge == 0.0)
            return false;

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

    void analysis::get_entry(std::size_t entry)
    {
        tree_.GetEntry(entry);

        leptons_.clear();
        jets_.clear();

#define PARTICLE(nm, index, kind) \
    charged_particle(kind, (*nm##_charge)[index], (*nm##_px)[index], \
                     (*nm##_py)[index], (*nm##_pz)[index], \
                     (*nm##_E)[index])

        // Die Jets werden in good_lepton verwendet, müssen also vorher
        // initialisiert sein
        for (int i = 0; i < JetC4T_N; ++i)
            jets_.push_back(PARTICLE(JetC4T, i, particle::UNDEFINED));

        // Elektronen in den Leptonenvektor eintragen
        for (int i = 0; i < El_N; ++i)
        {
            charged_particle p = PARTICLE(El, i, particle::ELECTRON);

            // Prüfe neben den gemeinsamen Tests die Güte der Identifikation
            if (((*El_IsEM)[i] & electron_identification)
                && good_lepton(p))
            {
                leptons_.push_back(p);
            }
        }

        // Myonen in den Leptonenvektor eintragen
        for (int i = 0; i < Mu_N; ++i)
        {
            charged_particle p = PARTICLE(Mu, i, particle::MUON);

            // Prüfe neben den gemeinsamen Tests die Sicherheit der Zuordnung
            if (((*Mu_matchChi2)[i] < 10)
                && good_lepton(p))
            {
                leptons_.push_back(p);
            }
        }
#undef PARTICLE
    }
    

}

