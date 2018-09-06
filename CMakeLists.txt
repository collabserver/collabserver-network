cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-common)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Dependencies and Misc
# ------------------------------------------------------------------------------
set(collab_dependency_dir "${CMAKE_SOURCE_DIR}/dependencies/")

include("CMake/AddCompilerFlags.cmake")
include("CMake/Dependencies/AddMsgPack.cmake")


# ------------------------------------------------------------------------------
# Static lib
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/include/")
file(GLOB_RECURSE srcCommonFiles "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(collabcommon STATIC ${srcCommonFiles})


# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------
option(collab_tests "Build tests" OFF)

if(collab_tests)
    message(STATUS "Build tests")
    enable_testing()

    # Dependencies
    include("CMake/Dependencies/AddGoogleTest.cmake")

    # Executables
    file(GLOB_RECURSE srcFilesTests "${CMAKE_SOURCE_DIR}/test/*.cpp")

    add_executable(tests ${srcFilesTests})
    target_link_libraries(tests gtest collabcommon zmq)

    add_test(NAME googletests COMMAND tests)
    add_custom_target(runTests tests)
endif()

