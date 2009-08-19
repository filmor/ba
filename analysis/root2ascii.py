#!/usr/bin/env python

from ROOT import TFile
from sys import argv, exit
from os.path import join

hists = ["Z mass", "Z p_t", "lepton p_t", "m_t", "delta phi_WZ",
         "W p_t", "MET p_t", "El Mu N"]

prefixes = ["signal", "zee", "ztautau", "zmumu", "ttbar"]

if len(argv) != 3:
    exit(1)

print argv[1]
f = TFile(argv[1])
out_dir = argv[2]

for prefix in prefixes:
    for hist_name in hists:
        hist = f.Get("[%s]%s" % (prefix, hist_name))
        assert hist != None
        dim = hist.GetDimension()

        out = file(join(out_dir, prefix, hist_name + '.txt'), 'w')
        assert out

        for i in xrange(hist.GetNbinsX()):
            for j in xrange(hist.GetNbinsY()):
                res = str(i)
                if dim == 2:
                    res += " %s" % j
                res += " %s" % hist.GetBinContent(i, j)
                out.write(res + "\n")

