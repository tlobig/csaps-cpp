cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(csaps)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_TESTING OFF)

find_package(Eigen3 3.1 REQUIRED)

add_subdirectory(src)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif()
