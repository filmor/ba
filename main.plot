#!/usr/bin/env gnuplot

set terminal lua solid size 11cm, 6cm

s = 'analysis/output/%s/%s/%s.txt'

set style data boxes

set xlabel '$\unit{GeV}$'
set ylabel 'Ereignisanzahl'

set xrange [50:150]
# Z Masse
set output 'grafiken/signal/zmass.tikz'
plot sprintf(s, 'no_zmass', 'signal', 'Z mass') u ($1+50):2 notitle

set title 'Signal'
set output 'grafiken/signal/zmass_vs_no_zmass.tikz'
plot sprintf(s, 'no_zmass', 'signal', 'Z mass') u ($1<31||$1>51?$1+50:1/0):2 notitle, \
     sprintf(s, 'normal', 'signal', 'Z mass') u ($1+50):2 notitle
set title '$t\bar{t}$'
set output 'grafiken/ttbar/zmass_vs_no_zmass.tikz'
plot sprintf(s, 'no_zmass', 'ttbar', 'Z mass') u ($1<31||$1>51?$1+50:1/0):2 notitle, \
     sprintf(s, 'normal', 'ttbar', 'Z mass') u ($1+50):2 notitle
set title '$\Z\to\tau\tau$'
set output 'grafiken/ztautau/zmass_vs_no_zmass.tikz'
plot sprintf(s, 'no_zmass', 'ztautau', 'Z mass') u ($1<31||$1>51?$1+50:1/0):2 notitle, \
     sprintf(s, 'normal', 'ztautau', 'Z mass') u ($1+50):2 notitle


set xrange [0:300]
# L p_t Schnitt
set title 'Signal'
set output 'grafiken/signal/lpt_vs_no_lpt.tikz'
plot sprintf(s, 'no_lpt', 'signal', 'lepton p_t') u ($1<25?$1:1/0):2 notitle, \
     sprintf(s, 'normal', 'signal', 'lepton p_t') notitle

set xrange [0:300]
set title '$\Z\to ee$'
set output 'grafiken/zee/lpt_vs_no_lpt.tikz'
plot sprintf(s, 'no_lpt', 'zee', 'lepton p_t') u ($1<25?$1:1/0):2 notitle, \
     sprintf(s, 'normal', 'zee', 'lepton p_t') notitle

set xrange [0:300]
set title '$\Z\to\mu\mu$'
set output 'grafiken/zmumu/lpt_vs_no_lpt.tikz'
plot sprintf(s, 'no_lpt', 'zmumu', 'lepton p_t') u ($1<25?$1:1/0):2 notitle, \
     sprintf(s, 'normal', 'zmumu', 'lepton p_t') notitle

# Ergebnisse
set output 'grafiken/m_t.tikz'
set title 'Transversale Masse'
plot sprintf(s, 'normal', 'signal', 'm_t') title 'Signal', \
     sprintf(s, 'normal', 'ttbar', 'm_t') title '$t\bar{t}$', \
     sprintf(s, 'normal', 'zee', 'm_t') title '$\Z\to ee$', \
     sprintf(s, 'normal', 'zmumu', 'm_t') title '$\Z\to\mu\mu$', \
     sprintf(s, 'normal', 'ztautau', 'm_t') title '$\Z\to\tau\tau$'

# El Mu N
unset title
set xrange [0:4]
set yrange [0:4]
set xlabel 'Anzahl der Elektronen'
set ylabel 'Anzahl der Myonen'
set pm3d flush begin noftriangles scansforward
set xtics 1
set ytics 1
set pm3d map
set palette rgbformulae 30, 31, 32
set output 'grafiken/signal/el_mu_n.tikz'
splot sprintf(s, 'normal', 'signal', 'El Mu N') notitle w image
set output 'grafiken/ttbar/el_mu_n.tikz'
splot sprintf(s, 'normal', 'ttbar', 'El Mu N') notitle w image
set output 'grafiken/zee/el_mu_n.tikz'
splot sprintf(s, 'normal', 'zee', 'El Mu N') notitle w image
set output 'grafiken/zmumu/el_mu_n.tikz'
splot sprintf(s, 'normal', 'zmumu', 'El Mu N') notitle w image
set output 'grafiken/ztautau/el_mu_n.tikz'
splot sprintf(s, 'normal', 'ztautau', 'El Mu N') notitle w image

# Winkel
reset
set xrange [-4:4]
set xtics pi/4
set xlabel '$\Delta \phi_{W,\Z}$'
set output 'grafiken/delta_phi.tikz'
plot sprintf(s, 'normal', 'signal', 'delta phi_WZ') title 'Signal', \
     sprintf(s, 'normal', 'ttbar', 'delta phi_WZ') title '$t\bar{t}$', \
     sprintf(s, 'normal', 'zee', 'delta phi_WZ') title '$\Z\to ee$', \
     sprintf(s, 'normal', 'zmumu', 'delta phi_WZ') title '$\Z\to\mu\mu$', \
     sprintf(s, 'normal', 'ztautau', 'delta phi_WZ') title '$\Z\to\tau\tau$'


