#!/bin/bash

DIR=data/background

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
    TASKS[${#TASKS[*]}]=$@
}

analyze()
{
    ./analyze $@
}

run_task()
{
    task=${TASKS[$i-1]}
    analyze $task
}

for dir in $DIR/zmumu/*
do
    out=output/$(basename $dir).root
    [ ! -e $out ] && append_task $(echo $dir/*) $out
done

append_task $(echo data/new/*WmZ*.root) output/signal_minus.root
append_task $(echo data/new/*WpZ*.root) output/signal_plus.root

N=${#TASKS[@]}

for (( i = 1; i <= $N; i++))
do
    echo -ne "Task $i of $N:\n\t$task\n..."
    run_task $i && echo -e "done\n" || echo -e "failed\n"
done
