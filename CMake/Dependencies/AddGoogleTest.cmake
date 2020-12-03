# ------------------------------------------------------------------------------
# Download and build at cmake time
# See https://crascit.com/2015/07/25/cmake-gtest/
# ------------------------------------------------------------------------------

# Alias variables
set(COLLABSERVER_GTEST_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest")

set(COLLABSERVER_GTEST_SOURCES    "${COLLABSERVER_GTEST_DIR}/sources")
set(COLLABSERVER_GTEST_HEADERS    "${COLLABSERVER_GTEST_DIR}/include")
set(COLLABSERVER_GTEST_DOWNLOAD   "${CMAKE_CURRENT_BINARY_DIR}/googletest-download")
set(COLLABSERVER_GTEST_BUILD      "${CMAKE_CURRENT_BINARY_DIR}/googletest-build")


if(COLLABSERVER_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLABSERVER_GTEST_SOURCES}")
    file(MAKE_DIRECTORY "${COLLABSERVER_GTEST_HEADERS}")


    # Create Download CMakeLists
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/CMake/ExternalProjects/GoogleTest.cmake"
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

    # Copy in dependency folder
    file(COPY "${COLLABSERVER_GTEST_SOURCES}/googletest/include"
         DESTINATION "${COLLABSERVER_GTEST_DIR}")

elseif(NOT IS_DIRECTORY "${COLLABSERVER_GTEST_DIR}")
    message("WARNING: GoogleTest dependency is missing.")
    message("To download it automatically, set -DCOLLABSERVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory("${COLLABSERVER_GTEST_SOURCES}"
                 "${COLLABSERVER_GTEST_BUILD}"
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()


