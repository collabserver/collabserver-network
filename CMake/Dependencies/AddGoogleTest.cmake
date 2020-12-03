# ------------------------------------------------------------------------------
# Download and build GoogleTests at cmake time
# Inspired from googletest cmake
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

# Alias variables
set(COLLABSEVER_GTEST_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest")

set(COLLABSEVER_GTEST_SOURCES    "${COLLABSEVER_GTEST_DIR}/sources")
set(COLLABSEVER_GTEST_HEADERS    "${COLLABSEVER_GTEST_DIR}/include")
set(COLLABSEVER_GTEST_DOWNLOAD   "${CMAKE_BINARY_DIR}/googletest-download")
set(COLLABSEVER_GTEST_BUILD      "${CMAKE_BINARY_DIR}/googletest-build")


if(COLLABSEVER_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLABSEVER_GTEST_SOURCES}")
    file(MAKE_DIRECTORY "${COLLABSEVER_GTEST_HEADERS}")


    # Create Download CMakeLists
    configure_file(
        "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/GoogleTest.cmake"
        "${COLLABSEVER_GTEST_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSEVER_GTEST_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif()

    # Clone (in sources folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLABSEVER_GTEST_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif()

    # Copy in dependency folder
    file(COPY "${COLLABSEVER_GTEST_SOURCES}/googletest/include"
         DESTINATION "${COLLABSEVER_GTEST_DIR}")

elseif(NOT IS_DIRECTORY "${COLLABSEVER_GTEST_DIR}")
    message("WARNING: GoogleTest dependency is missing.")
    message("To download it automatically, set -DCOLLABSEVER_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory("${COLLABSEVER_GTEST_SOURCES}"
                 "${COLLABSEVER_GTEST_BUILD}"
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()


