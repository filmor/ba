#include <stdexcept>
#include <iostream>
#include <TFile.h>
#include "Analyse.hpp"

int main (int argc, char** argv)
{
    if (argc != 2)
        throw std::runtime_error ("Aye");

    TFile f (argv[1]);

    ba::Analyse a (
            *reinterpret_cast<TTree*> (gDirectory->Get("ControlSample0"))
            );
    a.loop();
}
