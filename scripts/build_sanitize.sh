#!/bin/bash

set -e

rm -rf cm* CM* lib* Testing* tests* include tests Make* test sbva
CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DENABLE_TESTING=ON -DSANITIZE=ON ..
make -j26
make test
