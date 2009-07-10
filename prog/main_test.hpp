#ifndef BA_MAIN_TEST_HPP
#define BA_MAIN_TEST_HPP

#include <root/TTree.h>

namespace ba
{

    class main_test : public test<main_test>
    {
    public:
        bool operator() ()
        {
            TLorentzVector z, l, m;
            bool found_one = false;
            while (cand())
            {
                z = cand_.get_z_momentum();
                l = cand_.get_l_momentum();
                m = met_.get_momentum();

                TLorentzVector z2 = z + l + m;
                // z2 sollte wieder die Masse eines Z-Bosons haben:
                if (equals(z2.M(), Z_MASS))
                {
                    found_one = true;
                    break;
                }
            }

            if (found_one)
                std::cout << "Yay\n";

            return found_one;
        }

    private:
        z_candidate cand_;
        met_base met_;
    };

}

#endif
