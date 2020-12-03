# ------------------------------------------------------------------------------
# Download and build at cmake time
# See https://crascit.com/2015/07/25/cmake-gtest/
# ------------------------------------------------------------------------------

set(COLLABSERVER_CPPZMQ_SOURCES  "${PROJECT_SOURCE_DIR}/extern/cppzmq")
set(COLLABSERVER_CPPZMQ_DOWNLOAD "${PROJECT_BINARY_DIR}/cppzmq-download")

if(COLLABSERVER_DEPENDENCIES_DOWNLOAD)
    # Create Download CMakeLists
    configure_file(
        "${PROJECT_SOURCE_DIR}/CMake/ExternalProjects/ZeroMQcpp.cmake"
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

elseif(NOT IS_DIRECTORY "${COLLABSERVER_CPPZMQ_SOURCES}")
    message("WARNING: CPP ZeroMQ dependency is missing.")
    message("To download it automatically, set -DCOLLABSERVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


include_directories("${COLLABSERVER_CPPZMQ_SOURCES}")

