#ifndef BA_Z_CANDIDATE_HPP
#define BA_Z_CANDIDATE_HPP

#include <utility>
#include <boost/iterator/iterator_facade.hpp>

#include "test.hpp"

namespace ba
{

    class z_candidate : public generator<z_candidate, particle, charged_particle>
                      , public boost::iterator_facade<
                            z_candidate,
                            std::pair<particle, charged_particle>,
                            boost::forward_traversal_tag
                        >
    {
    public:
        void operator() ()
        {
            for (int i = 0; i < filtered_.size(); ++i)
            {
                for (int j = i; j < filtered_.size(); ++i)
                {
                    EPS = 0.1;
                    charged_particle& l1 = filtered_[i];
                    charged_particle& l2 = filtered_[j];

                    if (l1.kind == l2.kind
                        && fabs(l1.charge + l2.charge) < EPS)
                    {
                        for (int k = 0; k < filtered_.size(); ++i)
                        {
                            // (l1 + l2, k) ist der Kandidat (Z, l)

                        }
                    }
                }
            }   
        }

    private:
        int i = 0, j = 0, k = 0;
        filter_leptons<lepton_base> filtered_;
    };

}

#endif
