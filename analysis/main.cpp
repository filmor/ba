#include <cstdlib>
#include <stdexcept>
#include <iostream>

#include <TFile.h>
#include <TChain.h>

#include "analysis.hpp"

int main (int argc, char** argv)
{
    if (argc < 3)
    {
        std::cerr << "Invalid number of arguments\n";
        std::cout << "Usage: " << argv[0] << " *input_files output_file\n";
        std::exit(1);
    }

    TChain chain ("Input");

    for (int i = 1; i < argc - 1; ++i)
        chain.AddFile (argv[i], TChain::kBigNumber, "ControlSample0");

    // Analyse mit der geladenen Kette initialisieren
    ba::analysis a (chain);

    // Die Ausgabedatei ist das letzte Argument
    const char* output_file = argv[argc - 1];

    // Ausgabedatei öffnen
    TFile output (output_file, "UPDATE");
    if (output.IsZombie())
        throw std::runtime_error ("Can't use output file");
    output.cd();

    // Hauptschleife ausführen
    a.loop();
}
