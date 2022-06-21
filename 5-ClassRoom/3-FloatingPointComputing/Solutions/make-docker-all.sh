#!/usr/bin/env bash

./make-docker.sh 17 3 saxpy-aos float 10000 10000
./make-docker.sh 17 3 saxpy-aos double 10000 10000
./make-docker.sh 17 3 saxpy-aos long 10000 10000
