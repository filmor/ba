import ROOT

if __name__ == '__main__':
    import sys

    lines = file(sys.argv[1]).readlines()

    names = ['Z mass', 'Z p_t', 'lepton p_t', 'transverse mass',
             'delta phi_WZ', 'W p_t', 'MET p_t']

    opts = [(100, 50, 150), (300, 0, 200), (300, 0, 200), (300, 0, 200),
            (100, -4, 4), (300, 0, 200), (300, 0, 200)]

    hists = dict(
                (names[i], ROOT.TH1D(names[i], names[i], *opts[i]))
                for i in xrange(len(names))
                )

    for l in lines:
        fn, css = l.split(':')
        css = float(css)
        
        root_file = ROOT.TFile(fn)

        luminosity = root_file.Get("count").GetUniqueID() / css

        target_luminosity = 1

        factor = target_luminosity / luminosity

        for name in names:
            hists[name].Add(root_file.Get(name), factor)

    out = ROOT.TFile("output.root", "UPDATE")
    out.cd()

    for i in hists.itervalues():
        i.Write()


