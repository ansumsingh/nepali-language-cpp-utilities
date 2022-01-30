cmake_minimum_required(VERSION 3.5)
project(nepali-unicode)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE nepali-unicode-sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
list(APPEND NEPALIUNICODE_CPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(nepali-unicode ${nepali-unicode-sources})

target_include_directories(nepali-unicode PUBLIC ${NEPALIUNICODE_CPP_INCLUDE_DIRS} )

enable_testing()
add_subdirectory("test")
