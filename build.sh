#!/bin/bash

set -x
set -v
set -e

mkdir build || true
cd build

cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
      -Dcollab_tests=ON \
      ..
make
make runTests


