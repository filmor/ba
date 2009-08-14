#!/usr/bin/env python

from ROOT import TH1D, TH2I, TFile
from ConfigParser import ConfigParser
from optparse import OptionParser

get_count = lambda f: f.Get("count").GetUniqueID()
objects = {
        'Z mass': (TH1D, (100, 50, 150)),
        'Z p_t': (TH1D, (300, 0, 200)),
        'lepton p_t': (TH1D, (300, 0, 200)),
        'transverse mass': (TH1D, (300, 0, 200)),
        'delta phi_WZ': (TH1D, (100, -4, 4)),
        'W p_t': (TH1D, (300, 0, 200)),
        'MET p_t': (TH1D, (300, 0, 200)),
        'El Mu N': (TH2I, (5, 0, 5, 5, 0, 5)),
        }

op = OptionParser()
add = op.add_option

add('-t', '--process-type', help='Type of the to be normalized data')
add('-p', '--prefix', help='Prefix for the histogram names', default='')
add('-k', '--k-factor', type='float', help='Set the k-factor',
        default=1.0)
add('-c', '--cross-sections', help='File containing the cross sections',
        default='cross_sections.txt')
add('-l', '--luminosity', type='float', default=2000.0,
        help='The luminosity to which all inputs are normalized')
add('-u', '--update', action='store_true', default=False,
        help='Update the output file instead of recreating')
add('-o', '--output-file', default='output.root',
        help='Output file')

(options, input_files) = op.parse_args()

k_factor = options.k_factor
target_luminosity = options.luminosity
prefix = options.prefix
process = options.process_type

cross_sections = ConfigParser()
cross_sections.read(options.cross_sections)

# Parse input_files
input_files = [ i.split(':', 1) for i in input_files ]

# Resultierende Histogramme
merged = dict(
                (name, i[0](prefix + name, name, *i[1]))
                for name, i in objects.iteritems()
            )

for filename, variant in input_files:
    cross_section = cross_sections.getfloat(process, variant)
    cross_section *= k_factor
    
    root_file = TFile(filename)

    luminosity = get_count(root_file) / cross_section
    
    factor = target_luminosity / luminosity

    for name in merged:
        merged[name].Add(root_file.Get(name), factor)

out = TFile(options.output_file, options.update and "UPDATE" or "RECREATE")
out.cd()
for i in merged.itervalues():
    i.Write()

