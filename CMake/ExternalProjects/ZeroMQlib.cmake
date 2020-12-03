cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)

project(libzmq-download NONE)

include(ExternalProject)
ExternalProject_Add(libzmq
    GIT_REPOSITORY      "https://github.com/zeromq/libzmq"
    GIT_TAG             "v4.3.0"
    SOURCE_DIR          "${COLLABSERVER_LIBZMQ_SOURCES}"
    BINARY_DIR          "${COLLABSERVER_LIBZMQ_BUILD}"
    CONFIGURE_COMMAND   ""
    BUILD_COMMAND       ""
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DZMQ_BUILD_TESTS=OFF -DWITH_PERF_TOOL=OFF"
)


