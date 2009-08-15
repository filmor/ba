#!/bin/bash

DATA_DIR=data/
BG_DIR=${DATA_DIR}/background/
OUTPUT_DIR=output/
TESTS="isem jets zmass"

if ! which root-config > /dev/null
then
    source setup-root -n -r 5.22.00
    if ! which root-config > /dev/null
    then
        echo "ROOT not found" 1>&2
        exit 1
    fi
fi

run_task()
{
    task=${TASKS[$i-1]}
    build/default/analyze $task
}

TASKS=()
append_task()
{
    [ ! -e ${!#} ] && TASKS[${#TASKS[*]}]=$@
}

analyze()
{
    out=${OUTPUT_DIR}/$1
    shift
    append_task $@ $out.root
    for t in $TESTS
    do
        append_task --disable-${t}-test $@ ${out}.no_${t}.root
    done
}

normalize()
{
    process=$1
    [ $# -lt 2 ] && k_factor=1.0 || k_factor=$2 ]

    cmd=./normalize.py -u -t $1 -k $k_factor

    prefix=$OUTPUT_DIR/${process}
    
    $cmd $prefix.[^.]*.root -o $OUTPUT_DIR/result.root

    for t in $TESTS
    do
        $cmd $prefix.[^.]*.no_${t}.root -o $OUTPUT_DIR/result.${t}.root
    done
}

for type in zmumu zee ztautau
do
    for dir in $BG_DIR/$type/*
    do
        analyze ${type}.$(basename $dir) $(echo $dir/*) 
    done
done

analyze ttbar.FullHad $(echo $BG_DIR/ttbar/FullHad/*.root)
analyze ttbar.lep $(echo $BG_DIR/ttbar/{T1*/,}*.root)

analyze signal.minus $(echo data/new/*WmZ*.root)
analyze signal.plus $(echo data/new/*WpZ*.root)

N=${#TASKS[@]}

for (( i = 1; i <= $N; i++))
do
    echo -ne "Analysis $i of $N:\n..."
    run_task $i && echo -e "done\n" || echo -e "failed\n"
done

for type in zmumu zee ztautau
do
    normalize ${type} 1.22
done

normalize ttbar
normalize signal.plus
normalize signal.minus
