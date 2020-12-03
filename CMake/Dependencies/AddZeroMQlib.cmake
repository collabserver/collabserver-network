# ------------------------------------------------------------------------------
# Download and build at cmake time
# See https://crascit.com/2015/07/25/cmake-gtest/
# ------------------------------------------------------------------------------

# Alias variables
set(COLLABSERVER_LIBZMQ_DOWNLOAD   "${CMAKE_CURRENT_BINARY_DIR}/libzmq-download")
set(COLLABSERVER_LIBZMQ_BUILD      "${CMAKE_CURRENT_BINARY_DIR}/libzmq-build")
set(COLLABSERVER_LIBZMQ_SOURCES    "${CMAKE_CURRENT_SOURCE_DIR}/extern/libzmq")


if(COLLABSERVER_DEPENDENCIES_DOWNLOAD)

    # Create Download CMakeLists
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/CMake/ExternalProjects/ZeroMQlib.cmake"
        "${COLLABSERVER_LIBZMQ_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSERVER_LIBZMQ_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for libzmq failed: ${result}")
    endif()

    # Clone (in sources folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSERVER_LIBZMQ_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for libzmq failed: ${result}")
    endif()

elseif(NOT IS_DIRECTORY "${COLLABSERVER_LIBZMQ_SOURCES}")
    message("WARNING: libzmq dependency is missing.")
    message("To download it automatically, set -DCOLLABSERVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


# Add libzmq directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory("${COLLABSERVER_LIBZMQ_SOURCES}" EXCLUDE_FROM_ALL)

