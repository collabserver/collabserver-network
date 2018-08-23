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
- [ZeroMQ](http://zeromq.org/) (**Must be installed system-wide**)
- [GoogleTest](https://github.com/google/googletest) (CMake. Only for tests)


## Build instructions
collab-common is compiled as an object library.
You must also link the zmq library. (-lzmq)

### Build types
- CMake build types (ex: `-DCMAKE_BUILD_TYPE=Debug`):
    - Debug
    - Release
    - RelWithDebInfo
    - MinSizeRel

### Build object lib with CMake
```bash
# Build manually
mkdir build
cd build
cmake ..
make -j4
```

### Build tests with CMake
```bash
# Build manually
mkdir build
cd build
cmake ..
make -j4
make runTests

# Build from script
./build.sh
```


## Generate documentation
- [Doxygen](https://www.stack.nl/~dimitri/doxygen/)

Generate documentation with `doxygen Doxyfile`.
Generated files are places in `doc` folder.


## Author
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))

