option(COLLABSEVER_DEPENDENCIES_DOWNLOAD "Download dependencies" OFF)


# ------------------------------------------------------------------------------
# Dependencies path
# ------------------------------------------------------------------------------

# Priority: argument > env > default
if(DEFINED COLLABSEVER_DEPENDENCIES_DIR)
    set(COLLABSEVER_DEPENDENCIES_DIR ${COLLABSEVER_DEPENDENCIES_DIR}
        CACHE PATH "Path to the dependencies folder")

elseif(IS_DIRECTORY $ENV{COLLABSEVER_DEPENDENCIES_DIR})
    set(COLLABSEVER_DEPENDENCIES_DIR $ENV{COLLABSEVER_DEPENDENCIES_DIR}
        CACHE PATH "Path to the dependencies folder")

else()
    set(COLLABSEVER_DEPENDENCIES_DIR "${CMAKE_BINARY_DIR}/dependencies"
        CACHE PATH "Path to the dependencies folder")
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/dependencies")

endif()

message(STATUS "Dependencies path: ${COLLABSEVER_DEPENDENCIES_DIR}")
if(NOT IS_DIRECTORY ${COLLABSEVER_DEPENDENCIES_DIR})
    # Here, must stop right now
    message("WARNING: Invalid dependencies folder")
    message(FATAL_ERROR "The path to dependencies is not a valid directory")
endif()


# ------------------------------------------------------------------------------
# Add Dependencies
# ------------------------------------------------------------------------------

include("CMake/Dependencies/AddMsgPack.cmake")
include("CMake/Dependencies/AddGoogleTest.cmake")
include("CMake/Dependencies/AddZeroMQcpp.cmake")

