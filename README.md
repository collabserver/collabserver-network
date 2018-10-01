# Collab Common

[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-common/blob/master/LICENSE.txt)
[![Build Status](https://travis-ci.org/CollabServer/collab-common.svg?branch=master)](https://travis-ci.org/CollabServer/collab-common)

| master | dev |
| :-----: | :-----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-common.svg?branch=master)](https://travis-ci.org/CollabServer/collab-common) | [![Build Status](https://travis-ci.org/CollabServer/collab-common.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-common) |


## Description
Common library used by both collab-server and collab-client-interface projects.


## Features
- Messaging system
- Network wrapper
- Utils


## Build instructions (CMake)
Collab is compiled as a static library. If built manually, you must link with
`zmq` and `collabcommon` and include the `msgpack/include` folder (Header only).

### Requirements
- C++11
- `pragma once` support
- Tested with gcc 4.8.4
- Tested with clang 5.0.0
- Tested only on Linux. Not support certified for Mac and Windows

### Dependencies
All dependencies are automatically downloaded by CMake and placed in a folder
named `dependencies`.
You may move this folder in another place later and request CMake not to
download dependencies anymore (**See CMake options**).

If you are using a custom permanent location for your dependencies, a convenient
solution is to set the environment variable `COLLAB_DEPENDENCIES_DIR` with this path.
CMake will use this one as the default location (Except if a custom path is
given as CMake parameter).

- [MessagePack](https://msgpack.org/)
- [ZeroMQ C++](https://github.com/zeromq/cppzmq) (C++ binding for ZeroMQ lib)
- [GoogleTest](https://github.com/google/googletest) (Only required by tests)

### Manual dependencies (System Wide)
**These dependencies must be installed system-wide** and are not downloaded by CMake.
Check the instructions specific to your operating system for further information.

- [ZeroMQ](http://zeromq.org/)
    - `pacman -S zeromq` on ArchLinux
    - `apt-get install libzmq3 libzmq3-dev` on Ubuntu
    - There is also a [Windows binary here](http://zeromq.org/distro:microsoft-windows))

### CMake options
| Name | Description |
| --- | --- |
| COLLAB_DEPENDENCIES_DIR | (STRING) Path to a directory where to find all dependencies (By default, uses current cmake build) |
| COLLAB_DEPENDENCIES_DOWNLOAD | (ON/OFF) Set ON to also download dependencies at cmake time. This is useful the first time you setup the project. Dependencies are placed in COLLAB_DEPENDENCIES_DIR. (By default: OFF).|
| COLLAB_TESTS | (ON/OFF) Set ON to build unit tests |
| CMAKE_BUILD_TYPE | Debug, Release, RelWithDebInfo, MinSizeRel |

### Build static lib with CMake
```bash
mkdir build
cd build
cmake -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON ..
make -j4
```

### Build and run tests with CMake
```bash
# Build manually
mkdir build
cd build
cmake -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON -DCOLLAB_TESTS=ON ..
make -j4
make runTests

# Build from script
./build.sh
```


## Generate documentation
- [Doxygen](https://www.stack.nl/~dimitri/doxygen/)

Generate documentation with `doxygen Doxyfile`.
Generated files are places in `doc` folder.


## Contribution
Feel free to ask me any question, share your ideas or open an issue.
I created this project during my master thesis at University of Montreal.
I generally try to follow the [Google C++ Coding Style](https://google.github.io/styleguide/cppguide.html)
with some exceptions (For instance, I use 4 space indentation).


## Author
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))


