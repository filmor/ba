#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <argp.h>

#include <TFile.h>
#include <TChain.h>

#include "analysis.hpp"

/// argp Variablen zum parsen der Kommandozeile
const char* argp_program_version = __DATE__;
const char* argp_program_bug_address = "<bcsauer at uni-bonn punkt de>";

static char doc[] = "Analyzes W->lllnu";

static char args_doc[] = "input-files+ output-file";

static argp_option options[] = {
    {"disable-jets-test", 'j', 0, 0, "Disable Jet-dependent tests"},
    {"disable-isem-test", 'i', 0, 0, "Disable IsEM tests"},
    {"disable-zmass-test", 'z', 0, 0, "Disable Z mass test"},
    { 0 }
};


struct arguments
{
    int flags;
    TChain inputs;
    const char* output;
};

static error_t parse_opt (int key, char* arg, struct argp_state* state)
{
    arguments& args = *reinterpret_cast<arguments*> (state->input);

    
    switch (key)
    {
#define FLAG(key, name) \
    case key: args.flags &= ~ba::analysis::flags:: name; break;
        FLAG('j', JETS);
        FLAG('i', ISEM);
        FLAG('z', Z_MASS);
#undef FLAG

    case ARGP_KEY_ARG:
        if (state->next == state->argc - 1)
        {
            args.output = state->argv[state->next];
            state->next = state->argc;
        }
        args.inputs.AddFile (arg, TChain::kBigNumber, "ControlSample0");
        break;

    case ARGP_KEY_END:
        if (state->arg_num < 2)
            argp_usage(state);
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static argp argp = { options, parse_opt, args_doc, doc };

int main (int argc, char** argv)
{
    arguments args;
    args.flags = ~0;

    argp_parse (&argp, argc, argv, 0, 0, &args);

    // Analyse mit der geladenen Kette initialisieren
    ba::analysis a (args.inputs, args.flags);

    // Ausgabedatei öffnen
    TFile output (args.output, "UPDATE");
    if (output.IsZombie())
        throw std::runtime_error ("Can't use output file");
    output.cd();

    // Hauptschleife ausführen
    a.loop();
}
