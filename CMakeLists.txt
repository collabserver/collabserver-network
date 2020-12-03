cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collabserver-network)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()

# Dependencies and Misc
include("CMake/AddCompilerFlags.cmake")
include("CMake/AddDependencies.cmake")

# Static lib and Object lib
message(STATUS "Building static library")
include_directories("${CMAKE_SOURCE_DIR}/include/")
file(GLOB_RECURSE srcLibFiles "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library(collabserver_network STATIC ${srcLibFiles})

# Tests
option(COLLABSEVER_TESTS "Build tests" OFF)
if(COLLABSEVER_TESTS)
    message(STATUS "Building tests")
    enable_testing()

    file(GLOB_RECURSE srcTestFiles "${CMAKE_SOURCE_DIR}/tests/*.cpp")

    add_executable(tests ${srcTestFiles})
    target_link_libraries(tests collabserver_network gtest zmq)

    add_test(NAME googletests COMMAND tests)
    add_custom_target(runTests tests)
endif()


