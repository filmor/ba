#!/bin/bash

DIR=data/background
EXE=./analyse

if ! which root-config > /dev/null
then
    source skitathena -r 15.3.0 -n
fi

TASKS=()

append_task()
{
    TASKS[${#TASKS[*]}]=$1
}

analyze_dir()
{
    dir=$1
    if [ $2x != x ]
    then
        out=$2
    else
        out=$(basename $dir)
    fi

    for file in $dir/*.root
    do
        CMD="${file} $(basename $dir) output/${out}.root"

        append_task "$CMD"
    done
}

for bg in zee ztautau zmumu
do
    for dir in $DIR/$bg/*
    do
        analyze_dir $dir $bg
    done
done

analyze_dir data/background/ttbar

N=${#TASKS[@]}

for (( i = 0; i < N; i++))
do
    task=${TASKS[$i]}
    echo -ne "Task $i of $N:\n\t$task\n..."
    $EXE $task > /dev/null && echo -e "done\n" || echo -e "failed\n"
done
