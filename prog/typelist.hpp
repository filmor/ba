#ifndef TYPELIST_HPP
#define TYPELIST_HPP

namespace ba
{

    struct none_type {};

    template <typename Head, typename Tail = none_type>
    struct list_element
    {
        typedef Head head;
        typedef Tail tail;
    };

    // Absichtlich undefiniert
    template <typename Tail> struct list_element<none_type, Tail>;

    template <typename TList> struct head { typedef typename TList::head type };
    template <typename TList> struct tail { typedef typename TList::tail type };

    template <typename TList1, typename TList2>
    struct concat : list_element<
                        typename head<TList1>::type,
                        typename concat<typename tail<TList1>::type, TList2>::type
                    >
    {}

    template <typename TList2> struct concat<none_type, TList2> : TList2 {};

    template <typename TList, unsigned N>
    struct index : index<typename tail<TList>::type
    {
        typedef typename index<typename tail<TList>::type, N-1> type;
    }

    template <typename TList>
    struct index<0> : head<TList

#define LE(A, B) ::ba::list_element<A, B>
#define TYPELIST0() none_type
#define TYPELIST1(T1) LE(T1, TYPELIST0())
#define TYPELIST2(T1, T2) LE(T1, TYPELIST1(T2))
#define TYPELIST3(T1, T2, T3) LE(T1, TYPELIST2(T2, T3))
#define TYPELIST4(T1, T2, T3, T4) LE(T1, TYPELIST3(T2, T3, T4))
#define TYPELIST5(T1, T2, T3, T4, T5) LE(T1, TYPELIST4(T2, T3, T4, T5))
#define TYPELIST6(T1, T2, T3, T4, T5, T6) LE(T1, TYPELIST5(T2, T3, T4, T5, T6))
#undef LE

}

#endif
