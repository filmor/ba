#include "Analyse.hpp"

int main (int argc, char** argv)
{
    TFile* f = 0;
    TTree* t = 0;
    if (argc == 2)
    {
        f = new TFile(argv[1]);
        t = (TTree*)gDirectory->Get("ControlSample0");
    }
        
    ba::Analyse a (t);
    a.Loop();
}
