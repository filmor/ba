#ifndef BA_LEPTON_BASE_HPP
#define BA_LEPTON_BASE_HPP

#include <cassert>
#include <vector>

#include "particle.hpp"

namespace ba
{

    class lepton_truth_base : public pool_client<lepton_base>
    {
    public:
        lepton_base()
            : electron_data_("El_E", "El_px", "El_pz", "El_charge")
            , muon_data_("Mu_E", "Mu_px", "Mu_pz", "Mu_charge")
        {
        }

        void init (TTree& tree)
        {
            electron_data_.allocate_for(tree);
            muon_data_.allocate_for(tree);
        }

        void operator() ()
        {
            {
                data_handle& data = electron_data_;
                std::vector<particle> v;
                for (int i = 0; i < data[0]; ++i)
                    v.push_back(particle(data[0], data[1], data[2],
                                         data[3], data[4]));
                v.swap(electrons);
            }
            {
                data_handle& data = muon_data_;
                std::vector<particle> v;
                for (int i = 0; i < data[0]; ++i)
                    v.push_back(particle(data[0], data[1], data[2],
                                         data[3], data[4]));
                v.swap(muons);
            }

        }

        std::vector<particle> electrons;
        std::vector<particle> muons;

    private:
        vector_pool_handler<std::vector<double> > electron_data_;
        vector_pool_handler<std::vector<double> > muon_data_;
    };

}

#endif
