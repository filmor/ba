#ifndef BA_TEST_HPP
#define BA_TEST_HPP

#include <TTree.h>

#include <boost/preprocessor.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/array.hpp>
#include <boost/fusion/adapted/array.hpp>

#include <utility>
#include <string>

namespace ba
{

#define DO_MEMBER(r, data, elem)                                    \
    BOOST_PP_TUPLE_ELEM(2, 0, elem) BOOST_PP_TUPLE_ELEM(2, 1, elem);

#define GET_TYPE(s, data, elem)                                     \
    BOOST_PP_TUPLE_ELEM(2, 0, elem)&

#define GET_NAME(s, data, elem)                                     \
    BOOST_PP_TUPLE_ELEM(2, 1, elem)

#define GET_NAME_STRING(s, data, elem)                              \
    BOOST_PP_STRINGIZE(GET_NAME(s, data, elem))

// Usage: TEST_PARAMETERS((type, name) (type, name) (type, name) ...)
#define PARAM(type, name)                                           \
    ((type, name))

#define TEST_PARAMETERS(seq)                                        \
    BOOST_PP_SEQ_FOR_EACH(DO_MEMBER, _, seq)                        \
                                                                    \
    typedef BOOST_PP_CAT(boost::fusion::vector,                     \
                         BOOST_PP_SEQ_SIZE(seq))<                   \
        BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(GET_TYPE, 0, seq)) \
    > parameter_types;                                              \
    parameter_types get_parameter_types ()                          \
    {                                                               \
        return parameter_types (                                    \
        BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(GET_NAME, 1, seq)) \
                );                                                  \
    }                                                               \
    static const boost::array<std::string, BOOST_PP_SEQ_SIZE(seq)>  \
        get_parameter_names()                                       \
    {                                                               \
        static const boost::array<std::string,                      \
                                  BOOST_PP_SEQ_SIZE(seq)>           \
            names = {{                                              \
            BOOST_PP_SEQ_ENUM(                                      \
                BOOST_PP_SEQ_TRANSFORM(GET_NAME_STRING, 1, seq)     \
                )}};                                                \
        return names;                                               \
    }

    namespace
    {
        using namespace boost::fusion;
        struct initialize_parameter
        {
            TTree* tree_;

            initialize_parameter(TTree* tree) : tree_(tree) {}

            template <typename T>
            void operator() (T const& x) const
            {
                tree_->SetBranchAddress(at_c<0>(x), at_c<1>(x));
            }
        };
    }

    template <typename DerivedT>
    class test
    {
    public:
        void initialize (TTree* tree)
        {
            using namespace boost::fusion;

         /*   for_each(zip_view(DerivedT::get_parameter_names(),
                              DerivedT::get_parameter_types()),
                     initialize_parameter(tree)); */
        }
    };

}

#endif
