#include <stdexcept>
#include <iostream>
#include <TFile.h>
#include "Analyse.hpp"

int main (int argc, char** argv)
{
    if (argc != 2)
        throw std::runtime_error ("Aye");

    TFile* f = new TFile (argv[1]);
    TTree* t = reinterpret_cast<TTree*> (gDirectory->Get ("ControlSample0"));

    ba::Analyse a (t);
    a.Loop();
    std::cout << "Finished" << std::endl;
}
