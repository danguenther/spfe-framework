project(tests)

add_subdirectory(lib/googletest)

include_directories(merger_tests)
add_subdirectory(merger_tests)