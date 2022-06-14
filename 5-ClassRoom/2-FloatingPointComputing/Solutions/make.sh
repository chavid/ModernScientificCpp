#!/usr/bin/env bash

# expected arguments :
# - which C++ standard to use : 98, 17, ...
# - which level of optimization : 0, 1, 2, ...
# - which program to make : particules-oo, particules-11, ...

std=${1}
shift
opt=${1}
shift
prog=${1}
shift

# commands
#rm -f tmp.${prog}.exe \
#&& g++ -std=c++${std} -O${opt} -march=native -Wall -Wextra -Wfatal-errors ${prog}.cpp -o ${prog}.exe \
#&& for i in 0 1 2 3 4 5 6 7 8 9 ; do time ./${prog}.exe ${*} ; done | tee ${prog}.log

rm -f tmp.${prog}.exe
g++ -std=c++${std} -O${opt} ${prog}.cpp -o tmp.${prog}.exe

rm -f tmp.${prog}.log

for i in 0 1 2 3 4 5 6 7 8 9 ; do
  ( time ./tmp.${prog}.exe $* ) >> ./tmp.${prog}.log 2>&1
done

./mean-user-time.py ./tmp.${prog}.log $*
