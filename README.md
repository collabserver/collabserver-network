# Collab Common

[![Build Status](https://travis-ci.org/CollabServer/collab-common.svg?branch=master)](https://travis-ci.org/CollabServer/collab-common)
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-common/blob/master/LICENSE.txt)

| master | dev |
| :-----: | :-----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-common.svg?branch=master)](https://travis-ci.org/CollabServer/collab-common) | [![Build Status](https://travis-ci.org/CollabServer/collab-common.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-common) |


## Description
Common library used by both collab-server and collab-client.


## Requirements
- C++11
- `pragma once` support
- Tested only on Linux. Not support certified for Mac and Windows


## Dependencies
> Dependencies marked with *(CMake)* are automatically downloaded by CMake
> script and placed in *dependencies* folder.
> Others must be installed manually (Generally system-wide install).
- [MessagePack](https://msgpack.org/) (CMake. Only required by Simple Graph)
- [GoogleTest](https://github.com/google/googletest) (CMake. Only for tests)


## Build instructions
### Build static lib with CMake
```bash
# Build manually
mkdir build
cd build
cmake ..
make -j4

# Build from script
./build.sh
```


## Author
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))

