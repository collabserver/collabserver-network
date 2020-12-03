cmake_minimum_required(VERSION 2.8.2)
project(collabserver-network)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()

# Dependencies and Misc
include("CMake/AddCompilerFlags.cmake")
include("CMake/AddDependencies.cmake")

# Static lib and Object lib
message(STATUS "Building static library")
include_directories("${PROJECT_SOURCE_DIR}/include/")
file(GLOB_RECURSE srcLibFiles "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(collabserver_network STATIC ${srcLibFiles})

# Tests
option(COLLABSERVER_TESTS "Build tests" OFF)
if(COLLABSERVER_TESTS)
    message(STATUS "Building tests")
    enable_testing()

    file(GLOB_RECURSE srcTestFiles "${PROJECT_SOURCE_DIR}/tests/*.cpp")

    add_executable(tests ${srcTestFiles})
    target_link_libraries(tests collabserver_network gtest zmq)

    add_test(NAME googletests COMMAND tests)
    add_custom_target(runTests tests)
endif()


