# ------------------------------------------------------------------------------
# Download and build at cmake time
# See https://crascit.com/2015/07/25/cmake-gtest/
# ------------------------------------------------------------------------------

# Alias variables
set(COLLABSERVER_CPPZMQ_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/extern/cppzmq")

set(COLLABSERVER_CPPZMQ_SOURCES  "${COLLABSERVER_CPPZMQ_DIR}/sources")
set(COLLABSERVER_CPPZMQ_HEADERS  "${COLLABSERVER_CPPZMQ_DIR}/include")
set(COLLABSERVER_CPPZMQ_DOWNLOAD "${CMAKE_CURRENT_BINARY_DIR}/cppzmq-download")
set(COLLABSERVER_CPPZMQ_BUILD    "${CMAKE_CURRENT_BINARY_DIR}/cppzmq-build")


if(COLLABSERVER_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLABSERVER_CPPZMQ_SOURCES}")
    file(MAKE_DIRECTORY "${COLLABSERVER_CPPZMQ_HEADERS}")


    # Create Download CMakeLists
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/CMake/ExternalProjects/ZeroMQcpp.cmake"
        "${COLLABSERVER_CPPZMQ_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSERVER_CPPZMQ_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for CPP ZeroMQ failed: ${result}")
    endif()

    # Clone (in sources folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSERVER_CPPZMQ_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for CPP ZeroMQ failed: ${result}")
    endif()

    # Copy headers (To follow dependency folder style)
    file(COPY "${COLLABSERVER_CPPZMQ_SOURCES}/zmq.hpp"
         DESTINATION "${COLLABSERVER_CPPZMQ_HEADERS}")
    file(COPY "${COLLABSERVER_CPPZMQ_SOURCES}/zmq_addon.hpp"
         DESTINATION "${COLLABSERVER_CPPZMQ_HEADERS}")

elseif(NOT IS_DIRECTORY "${COLLABSERVER_CPPZMQ_DIR}")
    message("WARNING: CPP ZeroMQ dependency is missing.")
    message("To download it automatically, set -DCOLLABSERVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


include_directories("${COLLABSERVER_CPPZMQ_HEADERS}")


