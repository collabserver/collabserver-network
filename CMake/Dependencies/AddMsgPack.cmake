# ------------------------------------------------------------------------------
# Download and build msgpack at cmake time
# Inspired from googletest
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

# Alias variables
set(COLLABSEVER_MSGPACK_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/extern/msgpack-c")

set(COLLABSEVER_MSGPACK_SOURCES  "${COLLABSEVER_MSGPACK_DIR}/sources")
set(COLLABSEVER_MSGPACK_HEADERS  "${COLLABSEVER_MSGPACK_DIR}/include")
set(COLLABSEVER_MSGPACK_DOWNLOAD "${CMAKE_BINARY_DIR}/msgpack-download")
set(COLLABSEVER_MSGPACK_BUILD    "${CMAKE_BINARY_DIR}/msgpack-build")


if(COLLABSEVER_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLABSEVER_MSGPACK_SOURCES}")
    file(MAKE_DIRECTORY "${COLLABSEVER_MSGPACK_HEADERS}")


    # Create Download CMakeLists
    configure_file(
        "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/MsgPack.cmake"
        "${COLLABSEVER_MSGPACK_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSEVER_MSGPACK_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for msgpack failed: ${result}")
    endif()

    # Clone (in sources folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSEVER_MSGPACK_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for msgpack failed: ${result}")
    endif()

    # Copy in dependency folder
    file(COPY "${COLLABSEVER_MSGPACK_SOURCES}/include"
         DESTINATION "${COLLABSEVER_MSGPACK_DIR}")

elseif(NOT IS_DIRECTORY "${COLLABSEVER_MSGPACK_DIR}")
    message("WARNING: MsgPack dependency is missing.")
    message("To download it automatically, set -DCOLLABSEVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


include_directories("${COLLABSEVER_MSGPACK_HEADERS}")


