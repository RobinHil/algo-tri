#!/usr/bin/bash

rm plots/all_plots.png
rm plots/slow_running_time.png
rm plots/fast_running_time.png

g++ -Wall -Ofast -c main.cpp
for alg in stdSort bubbleSort insertionSort quicksort modifQuicksort
do
    echo Algorithm: $alg
    g++ -Wall -Ofast -c algo/$alg.cpp
    g++ -Wall -Ofast -o $alg main.o $alg.o
    rm $alg.o
    rm plots/individual/$alg.png
    for t in 1 2 3
    do
        rm data/$alg$t.data
        for ((i=1;i<=100;i++));
        do
            n=${i}000
            echo $alg $n $t
            timeout 10m ./$alg $n $t >> data/$alg$t.data
            ret=$?
            if [[ $ret -gt 120 ]]
            then
                echo TIMEOUT OR CORE DUMP ON $alg $t
                break
            fi
        done
    done
done

echo Creating plots...
sage plot.sage