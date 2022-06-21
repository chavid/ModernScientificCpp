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

# header
echo \# ${prog} ${opt}

# commands compile and first run
rm -f tmp.${prog}.exe \
&& g++ -std=c++${std} -O${opt} -march=native -Wall -Wextra -Wfatal-errors ${prog}.cpp -o tmp.${prog}.exe \
&& ./tmp.${prog}.exe ${*}

# mean time
rm -f tmp.arrays.py
echo "t = 0" >> tmp.arrays.py
for i in 0 1 2 3 4 5 6 7 8 9
do \time -f "t += %U" -a -o ./tmp.arrays.py ./tmp.${prog}.exe ${*} >> /dev/null
done
echo "print('(~ {:.3f} s)'.format(t/10.))" >> tmp.arrays.py
python3 tmp.arrays.py














