#!/usr/bin/env gnuplot

set terminal lua solid size 11cm, 6cm nobitmap font '\small'

s = 'analysis/output/%s/%s/%s.txt'

set style data steps

set ylabel 'Ereignisanzahl'

set xrange [51:150]
# Z Masse
set xlabel '$m_{ll}/\unit{GeV}$'
set output 'grafiken/signal/zmass.tikz'
plot sprintf(s, 'no_zmass', 'signal', 'Z mass') u ($1+50):2 notitle

set title '{\Large Signal}'
set output 'grafiken/signal/zmass_vs_no_zmass.tikz'
plot sprintf(s, 'no_zmass', 'signal', 'Z mass') u ($1<32||$1>50?$1+50:1/0):2 notitle, \
     sprintf(s, 'normal', 'signal', 'Z mass') u ($1+50):2 notitle
set title '{\Large$t\bar{t}$}'
set output 'grafiken/ttbar/zmass_vs_no_zmass.tikz'
plot sprintf(s, 'no_zmass', 'ttbar', 'Z mass') u ($1<32||$1>50?$1+50:1/0):2 notitle, \
     sprintf(s, 'normal', 'ttbar', 'Z mass') u ($1+50):2 notitle
set title '{\Large $\Z\to\tau\tau$}'
set output 'grafiken/ztautau/zmass_vs_no_zmass.tikz'
plot sprintf(s, 'no_zmass', 'ztautau', 'Z mass') u ($1<32||$1>50?$1+50:1/0):2 notitle, \
     sprintf(s, 'normal', 'ztautau', 'Z mass') u ($1+50):2 notitle


set autoscale
# L p_t Schnitt
set xlabel '$p_t/\unit{GeV}$'
set title '{\Large Signal}'
set output 'grafiken/signal/lpt_vs_no_lpt.tikz'
plot sprintf(s, 'no_lpt', 'signal', 'lepton p_t') u ($1<43*3.0/2?$1*2.0/3:1/0):2 notitle, \
     sprintf(s, 'normal', 'signal', 'lepton p_t') notitle

set title '{\Large$\Z\to ee$}'
set output 'grafiken/zee/lpt_vs_no_lpt.tikz'
set yrange [0:100]
plot sprintf(s, 'no_lpt', 'zee', 'lepton p_t') u ($1<43*3.0/2?$1*2.0/3:1/0):2 notitle, \
     sprintf(s, 'no_isem', 'zee', 'lepton p_t') notitle

set title '{\Large$\Z\to\mu\mu$}'
set output 'grafiken/zmumu/lpt_vs_no_lpt.tikz'
plot sprintf(s, 'no_lpt', 'zmumu', 'lepton p_t') u ($1<43.0*3.0/2?$1*2.0/3:1/0):2 notitle, \
     sprintf(s, 'normal', 'zmumu', 'lepton p_t') notitle

set terminal lua solid size 11cm, 9cm font '\small'
# Ergebnisse
unset title
set xlabel '$m_t/\unit{GeV}$'
set output 'grafiken/m_t.tikz'
plot sprintf(s, 'normal', 'signal', 'm_t') u ($1*2/3.0):2 title 'Signal', \
     sprintf(s, 'normal', 'ttbar', 'm_t') u ($1*2/3.0):2 title '$t\bar{t}$', \
     sprintf(s, 'normal', 'zee', 'm_t') u ($1*2/3.0):2 title '$\Z\to ee$', \
     sprintf(s, 'normal', 'zmumu', 'm_t') u ($1*2/3.0):2 title '$\Z\to\mu\mu$', \
     sprintf(s, 'normal', 'ztautau', 'm_t') u ($1*2/3.0):2 title '$\Z\to\tau\tau$'

# Winkel
set autoscale
set mxtics pi/8
f(x) = 4/50.0 * x - 4
set xtics ('$-\pi$' -pi, '$-\frac\pi 2$' -pi/2, '$0$' 0, '$\frac\pi 2$'\
        pi/2, '$\pi$' pi)
set xlabel '$\Delta \phi_{W,\Z}$'
set output 'grafiken/delta_phi.tikz'
plot sprintf(s, 'normal', 'signal', 'delta phi_WZ') u (f($1)):2 title 'Signal', \
     sprintf(s, 'normal', 'ttbar', 'delta phi_WZ') u (f($1)):2 title '$t\bar{t}$', \
     sprintf(s, 'normal', 'zee', 'delta phi_WZ') u (f($1)):2 title '$\Z\to ee$', \
     sprintf(s, 'normal', 'zmumu', 'delta phi_WZ') u (f($1)):2 title '$\Z\to\mu\mu$', \
     sprintf(s, 'normal', 'ztautau', 'delta phi_WZ') u (f($1)):2 title '$\Z\to\tau\tau$'
     

# El Mu N
set terminal lua solid size 6cm, 9cm nobitmap font '\small' originreset
set size square
unset title
set xrange [-0.5:3.5]
set yrange [-0.5:3.5]
set xlabel 'Anzahl der Elektronen'
set ylabel 'Anzahl der Myonen'
set xtics 1
set ytics 1
set pm3d map
set palette mode CMY rgbformulae 7, 5, 15
set output 'grafiken/signal/el_mu_n.tikz'
splot sprintf(s, 'normal', 'signal', 'El Mu N') u ($1-1):($2-1):3 \
    title '{\Large Signal}' w image
set output 'grafiken/ttbar/el_mu_n.tikz'
splot sprintf(s, 'normal', 'ttbar', 'El Mu N') u ($1-1):($2-1):3 \
    title '{\Large $t\bar{t}$}' w image
set output 'grafiken/zee/el_mu_n.tikz'
splot sprintf(s, 'normal', 'zee', 'El Mu N') u ($1-1):($2-1):3 \
    title '{\Large $\Z\to ee$}' w image
set output 'grafiken/zmumu/el_mu_n.tikz'
splot sprintf(s, 'normal', 'zmumu', 'El Mu N') u ($1-1):($2-1):3 \
    title '{\Large $\Z\to\mu\mu$}' w image
set output 'grafiken/ztautau/el_mu_n.tikz'
splot sprintf(s, 'normal', 'ztautau', 'El Mu N') u ($1-1):($2-1):3 \
    title '{\Large $\Z\to\tau\tau$}' w image

