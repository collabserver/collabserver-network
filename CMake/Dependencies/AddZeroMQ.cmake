# ------------------------------------------------------------------------------
# Download and build ZMQ at cmake time
# Inspired from googletest
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

# Alias variables
set(COLLAB_ZMQ_DIR      "${COLLAB_DEPENDENCIES_DIR}/libzmq")
set(COLLAB_ZMQ_SOURCES  "${COLLAB_ZMQ_DIR}/sources")
set(COLLAB_ZMQ_HEADERS  "${COLLAB_ZMQ_DIR}/include")
set(COLLAB_ZMQ_DOWNLOAD "${CMAKE_BINARY_DIR}/libzmq-download")
set(COLLAB_ZMQ_BUILD    "${CMAKE_BINARY_DIR}/libzmq-build")


if(COLLAB_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLAB_ZMQ_SOURCES}")
    file(MAKE_DIRECTORY "${COLLAB_ZMQ_HEADERS}")


    # Create Download CMakeLists
    configure_file(
        "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/ZeroMQ.cmake"
        "${COLLAB_ZMQ_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLAB_ZMQ_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for ZeroMQ failed: ${result}")
    endif()

    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLAB_ZMQ_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for ZeroMQ failed: ${result}")
    endif()

    # Copy headers (To follow dependency folder style)
    file(COPY "${COLLAB_ZMQ_SOURCES}/include"
         DESTINATION "${COLLAB_ZMQ_DIR}")

elseif(NOT IS_DIRECTORY "${COLLAB_ZMQ_DIR}")
    message("WARNING: ZeroMQ dependency is missing.")
    message("To download it automatically, set -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


include_directories("${COLLAB_ZMQ_HEADERS}")


