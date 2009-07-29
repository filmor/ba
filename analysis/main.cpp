#include <stdexcept>

#include <TFile.h>

#include "analysis.hpp"

int main (int argc, char** argv)
{
    if (argc < 2 || argc > 4)
        throw std::runtime_error ("Invalid number of arguments");

    TFile f (argv[1]);

    // Analyse mit der geladenen Datei initialisieren
    ba::analysis a (
            *reinterpret_cast<TTree*> (gDirectory->Get("ControlSample0"))
            );

    const char* output_file = "output.root";

    // Falls es ein drittes Argument ist ist dies die Ausgabedatei
    if (argc == 3)
        output_file = argv[2];

    // Ausgabedatei öffnen
    TFile output (output_file, "UPDATE");
    if (output.IsZombie())
        throw std::runtime_error ("Can't use output file");
    output.cd();

    // Hauptschleife ausführen
    a.loop();
}
