#!/usr/bin/env gnuplot

set terminal lua solid size 10cm, 7cm

s = 'analysis/output/%s/%s/%s.txt'

set style data boxes

set xlabel '$\unit{GeV}$'
set ylabel 'Ereignisanzahl'

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


set output 'grafiken/ttbar/zmass.no_zmass.tikz'
set output 'grafiken/ttbar/zmass.tikz'


