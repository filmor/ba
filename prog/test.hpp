#ifndef BA_TEST_HPP
#define BA_TEST_HPP

#include <TTree.h>

#include <boost/preprocessor.hpp>
#include <boost/fusion/container/generation/vector_tie.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/array.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <boost/fusion/view/zip_view.hpp>

#include <utility>
#include <string>
#include <iostream>

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

#define TEST_PARAMETERS(seq)                                        \
    BOOST_PP_SEQ_FOR_EACH(DO_MEMBER, _, seq)                        \
                                                                    \
public:                                                             \
    void initialize(TTree* tree)                                    \
    {                                                               \
        static const                                                \
            boost::array<const char*, BOOST_PP_SEQ_SIZE(seq)>       \
            names = {{                                              \
            BOOST_PP_SEQ_ENUM(                                      \
                BOOST_PP_SEQ_TRANSFORM(GET_NAME_STRING, 1, seq)     \
                )}};                                                \
                                                                    \
        BOOST_PP_CAT(boost::fusion::vector, BOOST_PP_SEQ_SIZE(seq)) \
            <                                                       \
                BOOST_PP_SEQ_ENUM(                                  \
                    BOOST_PP_SEQ_TRANSFORM(GET_TYPE, 0, seq)        \
                )                                                   \
            >                                                       \
            types (                                                 \
         BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(GET_NAME,1, seq)) \
               );                                                   \
        do_initialize(                                              \
            boost::fusion::vector_tie(names, types),                \
          tree                                                      \
        );                                                          \
    }                                                               \
private:

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
                tree_->SetBranchAddress(
                            at_c<0>(x),
                            reinterpret_cast<void*>(&(at_c<1>(x)))
                        );
            }
        };
    }

    template <typename DerivedT>
    class test
    {
    public:
        typedef void result_type;
        void result () {}
    protected:
        template <typename ParametersT>
        void do_initialize(ParametersT const& parameters, TTree* tree)
        {
            using namespace boost::fusion;

            for_each(
                zip_view<ParametersT>(parameters),
                initialize_parameter(tree)
                );
        }
    };

}

#endif
