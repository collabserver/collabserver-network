enable_testing()

include_directories("${CMAKE_SOURCE_DIR}/include/")
file(GLOB_RECURSE srcFilesTests "${CMAKE_SOURCE_DIR}/test/*.cpp")

add_executable(tests $<TARGET_OBJECTS:collabcommon> ${srcFilesTests})
target_link_libraries(tests gtest zmq)

add_test(NAME googletests COMMAND tests)
add_custom_target(runTests tests)


