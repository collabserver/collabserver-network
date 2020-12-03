# ------------------------------------------------------------------------------
# Download and build at cmake time
# See https://crascit.com/2015/07/25/cmake-gtest/
# ------------------------------------------------------------------------------

set(COLLABSERVER_GTEST_SOURCES    "${PROJECT_SOURCE_DIR}/extern/googletest")
set(COLLABSERVER_GTEST_DOWNLOAD   "${PROJECT_BINARY_DIR}/googletest-download")
set(COLLABSERVER_GTEST_BUILD      "${PROJECT_BINARY_DIR}/googletest-build")

if(COLLABSERVER_DEPENDENCIES_DOWNLOAD)
    configure_file(
        "${PROJECT_SOURCE_DIR}/CMake/ExternalProjects/GoogleTest.cmake"
        "${COLLABSERVER_GTEST_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSERVER_GTEST_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif()

    # Clone (in sources folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSERVER_GTEST_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif()

elseif(NOT IS_DIRECTORY "${COLLABSERVER_GTEST_SOURCES}")
    message("WARNING: GoogleTest dependency is missing.")
    message("To download it automatically, set -DCOLLABSERVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory("${COLLABSERVER_GTEST_SOURCES}" EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

