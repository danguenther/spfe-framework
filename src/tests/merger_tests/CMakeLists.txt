include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB merger_test_SOURCE_FILES "*.cpp")

add_executable(runMergerTests ${merger_test_SOURCE_FILES})

target_link_libraries(runMergerTests gtest gtest_main)
target_link_libraries(runMergerTests merge_lib)