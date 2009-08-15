#!/bin/bash

DATA_DIR=data/
BG_DIR=${DATA_DIR}/background/
OUTPUT_DIR=output/

if ! which root-config > /dev/null
then
    source setup-root -n -r 5.22.00
    if ! which root-config > /dev/null
    then
        echo "ROOT not found" 1>&2
        exit 1
    fi
fi

TASKS=()

append_task()
{
    [ ! -e ${!#} ] && TASKS[${#TASKS[*]}]=$@
}

run_task()
{
    task=${TASKS[$i-1]}
    build/default/analyze $task
}

analyze()
{
    out=$1
    shift
    append_task $@ ${OUTPUT_DIR}/$out.root
    append_task -i $@ ${OUTPUT_DIR}/${out}_no_isem.root
    append_task -j $@ ${OUTPUT_DIR}/${out}_no_jets.root
    append_task -z $@ ${OUTPUT_DIR}/${out}_no_zmass.root
}

for type in zmumu zee ztautau
do
    for dir in $BG_DIR/$type/*
    do
        analyze ${type}_$(basename $dir) $(echo $dir/*) 
    done
done

analyze ttbar_FullHad $(echo $BG_DIR/ttbar/FullHad/*.root)
analyze ttbar_lep $(echo $BG_DIR/ttbar/{T1*/,}*.root)

analyze signal_minus $(echo data/new/*WmZ*.root)
analyze signal_plus $(echo data/new/*WpZ*.root)

N=${#TASKS[@]}

for (( i = 1; i <= $N; i++))
do
    echo -ne "Task $i of $N:\n..."
    run_task $i && echo -e "done\n" || echo -e "failed\n"
done
