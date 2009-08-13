#include "analysis.hpp"

#include "athena/egammaPIDdefs.h"

#include <cassert>

namespace ba
{
    static const int electron_identification = egammaPID::ElectronMedium;

    typedef std::vector<charged_particle> particle_vector;

    void filter_by_dr (particle_vector const& input1,
                       particle_vector const& input2,
                       particle_vector& output,
                       const double threshold)
    {
        for (particle_vector::const_iterator i = input1.begin();
             i != input1.end(); ++i)
        {
            particle_vector::const_iterator j = input2.begin();
            // Falls ein Teilchen zu nah am anderen Teilchen ist ...
            for (; j != input2.end(); ++j)
                if (delta_R (*j, *i) < threshold)
                    break;

            // ... wird es hier nicht aufgenommen
            if (j == input2.end())
                output.push_back(*i);
        }
    }

    void analysis::get_entry(std::size_t entry)
    {
        tree_.GetEntry(entry);

        leptons_.clear();
        jets_.clear();

#define PARTICLE(nm, index, kind) \
    kind, (*nm##_charge)[index], (*nm##_px)[index], \
          (*nm##_py)[index], (*nm##_pz)[index], \
          (*nm##_E)[index]

        particle_vector leptons, jets;
        leptons.reserve (El_N + Mu_N);

        // Elektronen in den Leptonenvektor eintragen
        for (int i = 0; i < El_N; ++i)
        {
            charged_particle p (PARTICLE(El, i, particle::ELECTRON));
            // Prüfe die Güte der Identifikation
            if ((*El_IsEM)[i] & electron_identification)
                leptons.push_back (p);
        }
        
        // Myonen in den Leptonenvektor eintragen
        for (int i = 0; i < Mu_N; ++i)
        {
            charged_particle p (PARTICLE(Mu, i, particle::MUON));
            // Prüfe die Sicherheit der Zuordnung
            if ((*Mu_hasCombinedMuon)[i])
                leptons.push_back (p);
        }

        for (int i = 0; i < JetC4T_N; ++i)
            jets.push_back(charged_particle(PARTICLE(JetC4T, i, particle::UNDEFINED)));
        
        // Alle Jets, die näher als 0.15 an einem Lepton liegen
        // sind vermutlich von diesem gefaket.
        filter_by_dr (jets, leptons, jets_, 0.15);

        // Alle Leptonen, die näher als 0.4 an einem Jet liegen
        // filtern, da in Atlas Jets mit einem Radius von 0.4
        // rekonstruiert werden
        filter_by_dr (leptons, jets_, leptons_, 0.4);
#undef PARTICLE
    }

}

