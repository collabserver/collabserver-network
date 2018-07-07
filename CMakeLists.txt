cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-common)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Various
# ------------------------------------------------------------------------------
include("CMake/AddCompilerFlags.cmake")


# ------------------------------------------------------------------------------
# Static lib
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/include/")
file(GLOB_RECURSE srcCommonFiles "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(collabcommon STATIC ${srcCommonFiles})
target_link_libraries(collabcommon zmq)
