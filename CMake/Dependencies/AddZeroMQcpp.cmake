# ------------------------------------------------------------------------------
# Download and build ZMQ (CPP Header) at cmake time
# Inspired from googletest
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

# Alias variables
set(COLLABSEVER_CPPZMQ_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/extern/cppzmq")

set(COLLABSEVER_CPPZMQ_SOURCES  "${COLLABSEVER_CPPZMQ_DIR}/sources")
set(COLLABSEVER_CPPZMQ_HEADERS  "${COLLABSEVER_CPPZMQ_DIR}/include")
set(COLLABSEVER_CPPZMQ_DOWNLOAD "${CMAKE_BINARY_DIR}/cppzmq-download")
set(COLLABSEVER_CPPZMQ_BUILD    "${CMAKE_BINARY_DIR}/cppzmq-build")


if(COLLABSEVER_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLABSEVER_CPPZMQ_SOURCES}")
    file(MAKE_DIRECTORY "${COLLABSEVER_CPPZMQ_HEADERS}")


    # Create Download CMakeLists
    configure_file(
        "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/ZeroMQcpp.cmake"
        "${COLLABSEVER_CPPZMQ_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSEVER_CPPZMQ_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for CPP ZeroMQ failed: ${result}")
    endif()

    # Clone (in sources folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSEVER_CPPZMQ_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for CPP ZeroMQ failed: ${result}")
    endif()

    # Copy headers (To follow dependency folder style)
    file(COPY "${COLLABSEVER_CPPZMQ_SOURCES}/zmq.hpp"
         DESTINATION "${COLLABSEVER_CPPZMQ_HEADERS}")
    file(COPY "${COLLABSEVER_CPPZMQ_SOURCES}/zmq_addon.hpp"
         DESTINATION "${COLLABSEVER_CPPZMQ_HEADERS}")

elseif(NOT IS_DIRECTORY "${COLLABSEVER_CPPZMQ_DIR}")
    message("WARNING: CPP ZeroMQ dependency is missing.")
    message("To download it automatically, set -DCOLLABSEVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


include_directories("${COLLABSEVER_CPPZMQ_HEADERS}")


