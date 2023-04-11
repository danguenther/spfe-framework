cmake_minimum_required(VERSION 3.10)
project(InsuranceCalculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE String
            "Choose the type how to build, options are: None, Release, Debug, RelWithDebInfo, MinSizeRel."
            FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)

find_package(ABY QUIET)
if(ABY_FOUND)
    message(STATUS "found ABY")
else()
    add_subdirectory(extern/privdev18-ak2-aby)
endif()

add_subdirectory(src)
add_subdirectory(extern/privdev18-ak2-uc)
