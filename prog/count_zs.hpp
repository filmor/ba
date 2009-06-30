#ifndef BA_COUNT_ZS_HPP
#define BA_COUNT_ZS_HPP

#include "test.hpp"

#include <vector>
#include <TH1D.h>
#include <TLorentzVector.h>

namespace ba
{

    class count_zs : public test<count_zs>
    {
    public:
        count_zs() : z_mass(new TH1D("Z Masse", "", 100, 50, 150))
        {}

        void operator()()
        {
            if (El_N == 2 && Mu_N == 0)
            {
                TLorentzVector v = get_electron_vector(0) + get_electron_vector(1);
                z_mass->Fill(v.M() / 1000);
            }

            if (Mu_N == 2 && El_N == 0)
            {
                TLorentzVector v = get_muon_vector(0) + get_muon_vector(1);
                z_mass->Fill(v.M() / 1000);
            }            
        }

        typedef TH1D* result_type;
        
        result_type result()
        {
            return z_mass;
        }

    protected:
#define GET_PARTICLE_VECTOR(name, nm) \
        TLorentzVector get_##name##_vector(int index) \
        { \
            return TLorentzVector(nm##_px[index], nm##_py[index], \
                    nm##_pz[index], nm##_E[index]); \
        }

        GET_PARTICLE_VECTOR(electron, El)
        GET_PARTICLE_VECTOR(muon, Mu)
#undef GET_PARTICLE_VECTOR

    private:
#define I(n) ((int, n))
#define V(n) ((std::vector<double>, n))
        TEST_PARAMETERS(
                I(El_N) I(Mu_N)
                V(El_E) V(El_px) V(El_py) V(El_pz)
                V(Mu_E) V(Mu_px) V(Mu_py) V(Mu_pz)
                )
#undef I
#undef V
        TH1D* z_mass;

    };

}

#endif  
