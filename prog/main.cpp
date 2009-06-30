#include "analyze.hpp"
#include "count_zs.hpp"

#include <TFile.h>

#include <stdexcept>

int main (int argc, char** argv)
{
    if (argc != 2)
        throw std::runtime_error ("Aye");

    TFile f (argv[1]);
    TTree* t = reinterpret_cast<TTree*> (gDirectory->Get ("ControlSample0"));

    ba::count_zs test;

    ba::analyze(t, test);

    TFile out ("histogramm.root", "UPDATE");
    out.cd();
    test.result()->Write();
}
