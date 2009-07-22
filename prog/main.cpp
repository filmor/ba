#include <stdexcept>
#include <iostream>
#include <TFile.h>
#include "Analyse.hpp"

int main (int argc, char** argv)
{
    if (argc < 2 || argc > 3)
        throw std::runtime_error ("Invalid number of arguments");

    TFile f (argv[1]);

    ba::Analyse a (
            *reinterpret_cast<TTree*> (gDirectory->Get("ControlSample0"))
            );

    if (argc == 3)
        a.loop(argv[2]);
    else
        a.loop(argv[1]);
}
