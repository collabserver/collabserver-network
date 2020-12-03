#!/bin/bash

set -x
set -v
set -e

mkdir build || true
cd build

cmake -DCMAKE_BUILD_TYPE=${ENV_BUILD_TYPE} \
      -DCOLLABSERVER_TESTS=ON \
      -DCOLLABSERVER_DEPENDENCIES_DOWNLOAD=ON \
      ..

make
make runTests


