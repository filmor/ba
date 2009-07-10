#ifndef BA_TEST_HPP
#define BA_TEST_HPP

#include <TTree.h>

namespace ba
{

    namespace
    {
        class test_base
        {
        public:
            template <typename T, typename... Args>
            T& get_ref_to (std::string const& name, Args const&... args)
            {
                if (addresses_.find(name) == addresses_.end())
                {
                    void* ptr = pool_.ordered_malloc(sizeof(T));
                    reinterpret_cast<T*>(ptr)->T(args...);
                    addresses[name] = ptr;
                    // register destructors?
                }
                return *reinterpret_cast<T*>(addresses_[name]);
            }
            
        protected:
            void set_tree(TTree* tree)
            {
                if(tree != tree_)
                {
                    tree_ = tree;

                    for (std::map<std::string, void*>::const_iterator i = addresses_.begin();
                         i != addresses_.end();
                         ++i)
                    {
                        tree_.SetBranchAddress(i->first.c_str(), i->second);
                    }
                }
            }
        private:
            // Current tree
            TTree* tree_;
            // Maps names on addresses
            std::map<std::string, void*> addresses_;
            boost::singleton_pool<test_base, 1> pool_;
        };
    }

    // Vielleicht sollten alle Elemente den Pool benutzen, der in der
    // Vererbungs-/Nutzungshierarchie ganz unten sitzt
    template <typename DerivedT>
    class test : public test_base
    {
    public:
        inline friend void analyze(DerivedT& derived, TTree* tree)
        {
            set_tree(tree);
            Long64_t nentries = tree->GetEntriesFast();

            for (Long64_t i = 0; i < nentries; ++i)
            {
                tree->LoadTree(i);
                tree->GetEntry(i);
                derived();
            }
        }
    };

}

#endif
