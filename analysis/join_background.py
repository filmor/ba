#!/usr/bin/env python

import ROOT

signal = [
        ("output/signal_minus.root", 10.7475),
        ("output/signal_plus.root", 18.7041)
        ]

target_luminosity = 20000.0 / signal[0][1]

background = [
        ("output/zmumu_Np0.root", 900.2),
        ("output/zmumu_Np1.root", 205.2),
        ("output/zmumu_Np2.root", 69.4),
        ("output/zmumu_Np3.root", 21.6),
        ("output/zmumu_Np4.root", 6.1),
        ("output/zmumu_Np5.root", 1.7)
        ]

names = ['Z mass', 'Z p_t', 'lepton p_t', 'transverse mass',
         'delta phi_WZ', 'W p_t', 'MET p_t']
opts = [(100, 50, 150), (300, 0, 200), (300, 0, 200), (300, 0, 200),
        (100, -4, 4), (300, 0, 200), (300, 0, 200)]

k_factor = 1.22

if __name__ == '__main__':
    get_count = lambda f: f.Get("count").GetUniqueID()

    def write(obj):
        out = ROOT.TFile("output/result.root", "UPDATE")
        out.cd()
        obj.Write()

    hists = dict(
                (names[i],
                    ROOT.TH1D('[zmumu] ' + names[i], names[i], *opts[i]))
                for i in xrange(len(names))
                )

    for filename, cross_section in background:
        cross_section *= k_factor
        
        root_file = ROOT.TFile(filename)

        luminosity = get_count(root_file) / cross_section
        
        factor = target_luminosity / luminosity

        for name in names:
            hists[name].Add(root_file.Get(name), factor)

    for i in hists.itervalues():
        write(i)

    for prefix, index in (("[plus] ", 0), ("[minus] ", 1)):
        root_file = ROOT.TFile(signal[index][0])
        luminosity = get_count(root_file) / signal[index][1]
        factor = target_luminosity / luminosity

        for name in names:
            histogram = root_file.Get(name)
            histogram.SetName(prefix + name)
            histogram.Scale(factor)
            write(histogram)


