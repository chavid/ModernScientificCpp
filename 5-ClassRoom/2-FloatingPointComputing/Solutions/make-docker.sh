#!/usr/bin/env bash
docker run --rm -v "${PWD}":/work -w /work -it gcc:9.1.0 ./make.sh $*
