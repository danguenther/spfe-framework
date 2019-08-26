set(MERGER_LIB_SOURCE_FILES merger.cpp)
set(MERGER_LIB_HEADER_FILES merger.h)
add_library(merge_lib ${MERGER_LIB_HEADER_FILES} ${MERGER_LIB_SOURCE_FILES})

set(MERGER_SOURCE_FILES merger_main.cpp)
add_executable(merge ${MERGER_SOURCE_FILES})
target_link_libraries(merge merge_lib)
