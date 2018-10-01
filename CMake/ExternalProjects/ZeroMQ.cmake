cmake_minimum_required(VERSION 2.8.2)

project(libzmq-download NONE)

include(ExternalProject)
ExternalProject_Add(msgpack
    GIT_REPOSITORY      "https://github.com/zeromq/libzmq.git"
    GIT_TAG             "v4.2.5"
    SOURCE_DIR          "${COLLAB_ZMQ_SOURCES}"
    BINARY_DIR          "${COLLAB_ZMQ_BUILD}"
    CONFIGURE_COMMAND   ""
    BUILD_COMMAND       ""
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          ""
)
