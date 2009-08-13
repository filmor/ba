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
    [ ! -e ${!#} ] && TASKS[${#TASKS[*]}]=$@
    echo $@
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

for type in zmumu zee ztautau
do
    for dir in $DIR/$type/*
    do
        append_task $(echo $dir/*) output/${type}_$(basename $dir).root
    done
done

append_task $(find $DIR/ttbar | grep '\.root$' ) output/ttbar.root

append_task $(echo data/new/*WmZ*.root) output/signal_minus.root
append_task $(echo data/new/*WpZ*.root) output/signal_plus.root

N=${#TASKS[@]}

for (( i = 1; i <= $N; i++))
do
    echo -ne "Task $i of $N:\n\t$task\n..."
    run_task $i && echo -e "done\n" || echo -e "failed\n"
done
