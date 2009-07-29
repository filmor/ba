#!/bin/bash

DIR=data/background

if ! which root-config > /dev/null
then
    source setup-root -n -r 5.22.00
fi

TASKS=()

append_task()
{
    TASKS[${#TASKS[*]}]=$1
}

analyze()
{
    ./analyze $@ # >> ~/analyze_curr.log 2> ~/analyze_err.log
}

analyze_dir()
{
    dir=$1

    for file in $dir/*.root
    do
        CMD="${file} $2"

        append_task "$CMD"
    done
}

# for bg in zee ztautau zmumu
# do
#    for dir in $DIR/$bg/*
#    do
#        analyze_dir $dir $bg
#    done
# done

# analyze_dir data/background/ttbar

for dir in $DIR/zmumu/*
do
    analyze_dir $dir output/$(basename $dir).root
done

N=${#TASKS[@]}

for (( i = 1; i <= $N; i++))
do
    task=${TASKS[$i-1]}
    echo -ne "Task $i of $N:\n\t$task\n..."
    analyze $task && echo -e "done\n" || echo -e "failed\n"
done
