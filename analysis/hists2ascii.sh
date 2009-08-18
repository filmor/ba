#!/bin/bash

SUFFIXES="no_isem no_zmass no_lpt no_jets normal"

TYPES="signal ttbar zee zmumu ztautau"

OUTPUT_DIR=output/

for s in $SUFFIXES
do
    for t in $TYPES
    do
        out_dir=$OUTPUT_DIR/$s
        [ ! -e $out_dir ] && mkdir -p $out_dir
    done

    ./root2ascii.py output/result.$s.root $OUTPUT_DIR/$s
done
