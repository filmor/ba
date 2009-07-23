#include <stdexcept>

#include <TFile.h>

#include "Analyse.hpp"

int main (int argc, char** argv)
{
    if (argc < 2 || argc > 4)
        throw std::runtime_error ("Invalid number of arguments");

    TFile f (argv[1]);

    ba::Analyse a (
            *reinterpret_cast<TTree*> (gDirectory->Get("ControlSample0"))
            );

    const char* output_file = "output.root";

    if (argc == 4)
        output_file = argv[3];

    TFile output (output_file, "UPDATE");
    output.cd();

    if (argc == 3)
        a.loop(argv[2]);
    else
        a.loop("");
}
