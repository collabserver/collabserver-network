# ------------------------------------------------------------------------------
# Download and build at cmake time
# See https://crascit.com/2015/07/25/cmake-gtest/
# ------------------------------------------------------------------------------

set(COLLABSERVER_MSGPACK_SOURCES  "${PROJECT_SOURCE_DIR}/extern/msgpack-c")
set(COLLABSERVER_MSGPACK_DOWNLOAD "${PROJECT_BINARY_DIR}/msgpack-download")

if(COLLABSERVER_DEPENDENCIES_DOWNLOAD)
    # Create Download CMakeLists
    configure_file(
        "${PROJECT_SOURCE_DIR}/CMake/ExternalProjects/MsgPack.cmake"
        "${COLLABSERVER_MSGPACK_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSERVER_MSGPACK_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for msgpack failed: ${result}")
    endif()

    # Clone (in sources folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSERVER_MSGPACK_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for msgpack failed: ${result}")
    endif()

elseif(NOT IS_DIRECTORY "${COLLABSERVER_MSGPACK_SOURCES}")
    message("WARNING: MsgPack dependency is missing.")
    message("To download it automatically, set -DCOLLABSERVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


include_directories("${COLLABSERVER_MSGPACK_SOURCES}")

