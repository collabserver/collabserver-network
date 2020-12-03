# ------------------------------------------------------------------------------
# Download and build at cmake time
# See https://crascit.com/2015/07/25/cmake-gtest/
# ------------------------------------------------------------------------------

# Alias variables
set(COLLABSERVER_MSGPACK_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/extern/msgpack-c")

set(COLLABSERVER_MSGPACK_SOURCES  "${COLLABSERVER_MSGPACK_DIR}/sources")
set(COLLABSERVER_MSGPACK_HEADERS  "${COLLABSERVER_MSGPACK_DIR}/include")
set(COLLABSERVER_MSGPACK_DOWNLOAD "${CMAKE_CURRENT_BINARY_DIR}/msgpack-download")
set(COLLABSERVER_MSGPACK_BUILD    "${CMAKE_CURRENT_BINARY_DIR}/msgpack-build")


if(COLLABSERVER_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLABSERVER_MSGPACK_SOURCES}")
    file(MAKE_DIRECTORY "${COLLABSERVER_MSGPACK_HEADERS}")


    # Create Download CMakeLists
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/CMake/ExternalProjects/MsgPack.cmake"
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

    # Copy in dependency folder
    file(COPY "${COLLABSERVER_MSGPACK_SOURCES}/include"
         DESTINATION "${COLLABSERVER_MSGPACK_DIR}")

elseif(NOT IS_DIRECTORY "${COLLABSERVER_MSGPACK_DIR}")
    message("WARNING: MsgPack dependency is missing.")
    message("To download it automatically, set -DCOLLABSERVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


include_directories("${COLLABSERVER_MSGPACK_HEADERS}")


