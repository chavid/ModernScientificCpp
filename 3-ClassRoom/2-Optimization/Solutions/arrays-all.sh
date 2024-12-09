#!/usr/bin/env bash

rm -f tmp.*.log

./arrays.sh 17 0 aos-carray   1024 300000
./arrays.sh 17 0 aos-array    1024 300000
./arrays.sh 17 0 aos-valarray 1024 300000
./arrays.sh 17 0 aos-vector   1024 300000
./arrays.sh 17 0 aos-list     1024 300000

./arrays.sh 17 2 aos-carray   1024 300000
./arrays.sh 17 2 aos-array    1024 300000
./arrays.sh 17 2 aos-valarray 1024 300000
./arrays.sh 17 2 aos-vector   1024 300000
./arrays.sh 17 2 aos-list     1024 300000

./arrays.sh 17 3 aos-carray   1024 300000
./arrays.sh 17 3 aos-array    1024 300000
./arrays.sh 17 3 aos-valarray 1024 300000
./arrays.sh 17 3 aos-vector   1024 300000
./arrays.sh 17 3 aos-list     1024 300000

./arrays.sh 17 0 soa-carray   1024 300000
./arrays.sh 17 0 soa-array    1024 300000
./arrays.sh 17 0 soa-valarray 1024 300000
./arrays.sh 17 0 soa-vector1  1024 300000
./arrays.sh 17 0 soa-vector2  1024 300000
./arrays.sh 17 0 soa-list     1024 300000

./arrays.sh 17 2 soa-carray   1024 300000
./arrays.sh 17 2 soa-array    1024 300000
./arrays.sh 17 2 soa-valarray 1024 300000
./arrays.sh 17 2 soa-vector1  1024 300000
./arrays.sh 17 2 soa-vector2  1024 300000
./arrays.sh 17 2 soa-list     1024 300000

./arrays.sh 17 3 soa-carray   1024 300000
./arrays.sh 17 3 soa-array    1024 300000
./arrays.sh 17 3 soa-valarray 1024 300000
./arrays.sh 17 3 soa-vector1  1024 300000
./arrays.sh 17 3 soa-vector2  1024 300000
./arrays.sh 17 3 soa-list     1024 300000
