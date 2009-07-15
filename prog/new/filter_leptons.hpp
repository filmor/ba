#ifndef BA_FILTER_LEPTONS_HPP
#define BA_FILTER_LEPTONS_HPP

#include "particle.hpp"

namespace ba
{

    template <typename FilterPolicy, typename LeptonBase>
    class filter_leptons : public LeptonBase
                         , public FilterPolicy
    {
    public:
        void refresh ()
        {
            std::vector<unsigned> new_indices;
            for (int i = 0; i < LeptonBase::size(); ++i)
                if (FilterPolicy::good_lepton(LeptonBase::operator[] (i)))
                    new_indices.push_back(i);
            indices_.swap(new_indices);
        }

        charged_particle const& operator[] (int index) const
        {
            return LeptonBase::operator[] (indices_[index]);
        }

        size_t size () const
        {
            return indices_.size();
        }

    private:
        std::vector<unsigned> indices_;
    };

}

#endif
