cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
    GIT_REPOSITORY      "https://github.com/google/googletest.git"
    GIT_TAG             "release-1.10.0"
    SOURCE_DIR          "${COLLABSERVER_GTEST_SOURCES}"
    BINARY_DIR          "${COLLABSERVER_GTEST_BUILD}"
    CONFIGURE_COMMAND   ""
    BUILD_COMMAND       ""
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
)


