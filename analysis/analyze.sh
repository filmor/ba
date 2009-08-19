#!/bin/bash

DATA_DIR=data
BG_DIR=${DATA_DIR}/background
OUTPUT_DIR=output
TESTS="isem jets zmass lpt"

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
    if [ $(echo $1 | sed -e 's/\..*//') = 'zee' ]
    then
        append_task $@ ${out}.normal.root
        for t in $TESTS
        do
            append_task --disable-${t}-test --disable-isem-test \
                $@ ${out}.no_${t}.root
        done
    fi
    append_task $@ ${out}.normal.root
    for t in $TESTS
    do
        append_task --disable-${t}-test $@ ${out}.no_${t}.root
    done
}

for type in zmumu ztautau zee
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
