#ifndef BA_ANALYZE_HPP
#define BA_ANALYZE_HPP

#include <TTree.h>
#include <iostream>

namespace ba
{

    template <class TestT>
    void analyze (TTree* tree, TestT& test)
    {
        tree->SetMakeClass(1);
        Long64_t nentries = tree->GetEntriesFast();
        test.initialize(tree);

        for (Long64_t i = 0; i < nentries; ++i)
        {
            tree->LoadTree(i);
            tree->GetEntry(i);
            test();
        }

        // Uninitialize! RAII?!
    }

}

#endif
