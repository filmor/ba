#include "test.hpp"
#include "main_test.hpp"

#include <root/TFile.h>

#include <stdexcept>

int main (int argc, char** argv)
{
    if (argc != 2)
        throw std::runtime_error ("Aye");

    TFile f (argv[1]);
    TTree* t = reinterpret_cast<TTree*> (gDirectory->Get ("ControlSample0"));

    ba::main_test test; // ("histogramm.root");

    ba::analyze (t, test);
}
