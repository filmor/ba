#!/usr/bin/env python

import ROOT

signal = [
        ("output/signal_minus.root", 10.7475),
        ("output/signal_plus.root", 18.7041)
        ]

target_luminosity = 20000.0 / signal[0][1]

background = [
        ("output/Np0.root", 900.2),
        ("output/Np1.root", 205.2),
        ("output/Np2.root", 69.4),
        ("output/Np3.root", 21.6),
        ("output/Np4.root", 6.1),
        ("output/Np5.root", 1.7)
        ]

names = ['Z mass', 'Z p_t', 'lepton p_t', 'transverse mass',
         'delta phi_WZ', 'W p_t', 'MET p_t']
opts = [(100, 50, 150), (300, 0, 200), (300, 0, 200), (300, 0, 200),
        (100, -4, 4), (300, 0, 200), (300, 0, 200)]

k_factor = 1.22

if __name__ == '__main__':
    hists = dict(
                (names[i], ROOT.TH1D(names[i], names[i], *opts[i]))
                for i in xrange(len(names))
                )

    for filename, cross_section in background:
        cross_section *= k_factor
        
        root_file = ROOT.TFile(filename)

        luminosity = root_file.Get("count").GetUniqueID() / cross_section
        
        factor = target_luminosity / luminosity

        for name in names:
            hists[name].Add(root_file.Get(name), factor)

    out = ROOT.TFile("output/joined_background.root", "RECREATE")
    out.cd()

    for i in hists.itervalues():
        i.Write()

