#ifndef BA_TEST_HPP
#define BA_TEST_HPP

#include <map>
#include <string>

#include <root/TTree.h>

namespace ba
{

    class test_base
    {
    public:
        template <typename T, typename... Args>
        static T& get_ref_to (std::string const& name,
                              Args const&... args)
        {
            if (addresses_.find(name) == addresses_.end())
            {
                void* ptr = ::operator new (sizeof(T));
                reinterpret_cast<T*>(ptr)->T(args...);
                addresses_[name] = ptr;
                // TODO Destructors!
            }
            return *reinterpret_cast<T*>(addresses_[name]);
        }

    protected:
        void set_tree(TTree* tree)
        {
            if(tree != tree_)
            {
                tree_ = tree;

                for (map_type::const_iterator i = addresses_.begin();
                     i != addresses_.end();
                     ++i)
                {
                    tree_->SetBranchAddress(i->first.c_str(),
                                            i->second);
                }

                index_ = 0;
                count_ = tree->GetEntriesFast();
            }
        }

        void next_entry()
        {
            get_entry(index_ + 1);
        }

        void set_entry(int i)
        {
            if (!tree) return;
            tree->LoadTree(i);
            tree->GetEntry(i);
            index_ = i;
        }

        // Current tree
        TTree* tree_ = 0;
        // Current index
        int index_ = 0;
        // Entry count
        int count_ = 0;

        typedef std::map<std::string, void*> map_type;
        // Maps names on addresses
        // Maybe as a singleton?
        static map_type addresses_;
    };

    template <typename DerivedT, typename... Results>
    class generator : public test_base,
                      public boost::iterator_facade<
                                DerivedT,
                                make_result_type<Results...>::type,
                                boost::forward_traversal_tag
                             >
    {
    public:
        typedef make_result_type<Results...>::type
            result_type;

        void increment()
        {
            increment();
        }

        result_type dereference()
        {
            return ;
        }

    private:

    };

}

#endif
