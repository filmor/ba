#ifndef BA_MAIN_TEST_HPP
#define BA_MAIN_TEST_HPP

#include <root/TTree.h>
#include <root/TLorentzVector.h>

#include "constants.hpp"

namespace ba
{

    class main_test
    {
    public:
        bool operator() (TTree* tree)
        {
            test_base::set_tree(tree);

            data_provider<particle> met("Met_px", "Met_py", "Met_pz",
                                        "Met_E");

            for (int i = 0; i < test_base::count; test_base::next_entry())
            {
                for (z_candidate j; j; ++j)
                {
                    particle& z = j->first;
                    charged_particle& l = j->second;

                    TLorentzVector z2 = z.momentum + l.momentum
                                        + met.momentum;

                    // z2 sollte wieder die Masse eines Z-Bosons haben:
                    //if (equals(z2.M(), Z_MASS))
                    //{
                    //    found_one = true;
                    //    break;
                    //}
                }
            }
        }
    };

}

#endif
