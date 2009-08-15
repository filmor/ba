#!/bin/bash

DATA_DIR=data
BG_DIR=${DATA_DIR}/background
OUTPUT_DIR=output
TESTS="isem jets zmass"

normalize()
{
    process=$1
    echo $process
    [ $# -lt 2 ] && k_factor=1.0 || k_factor=$2

    cmd="./normalize.py -u -t $process -k $k_factor -p [$process] "

    prefix=$OUTPUT_DIR/${process}
    
    $cmd $prefix.[^.]*.root -o $OUTPUT_DIR/result.root

    for t in $TESTS
    do
        $cmd $prefix.[^.]*.no_${t}.root \
            -o $OUTPUT_DIR/result.no_${t}.root
    done
}

for type in zmumu zee ztautau
do
    normalize ${type} 1.22
done

normalize ttbar
normalize signal
