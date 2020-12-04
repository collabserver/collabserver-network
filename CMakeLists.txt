cmake_minimum_required(VERSION 3.14)
project(collabserver-network)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# Compiler flags
message(STATUS "Detected Operating System: ${CMAKE_SYSTEM_NAME}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No BUILD_TYPE set: uses Release")
    message(STATUS "Available build types: Debug Release RelWithDebInfo MinSizeRel")
    set(CMAKE_BUILD_TYPE Release)
else()
    message(STATUS "BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
endif()


# Dependencies
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest-1.10.0")
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/cppzmq-4.7.1")
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/libzmq-4.3.3")
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/msgpack-c-3.3.0")


# Library
message(STATUS "Building static library")
include_directories("${PROJECT_SOURCE_DIR}/include/")
file(GLOB_RECURSE srcLibFiles "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(${PROJECT_NAME}-lib STATIC ${srcLibFiles})


# Tests
option(COLLABSERVER_TESTS "Build tests" OFF)
if(COLLABSERVER_TESTS)
    message(STATUS "Building tests")
    enable_testing()

    file(GLOB_RECURSE srcTestFiles "${PROJECT_SOURCE_DIR}/tests/*.cpp")

    add_executable(${PROJECT_NAME}-tests ${srcTestFiles})
    target_link_libraries(${PROJECT_NAME}-tests ${PROJECT_NAME}-lib gtest zmq)

    add_test(NAME googletests COMMAND ${PROJECT_NAME}-tests)
    add_custom_target(runTests ${PROJECT_NAME}-tests)
endif()

