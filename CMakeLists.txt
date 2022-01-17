cmake_minimum_required(VERSION 3.5)
project(nepali-unicode)

set(CMAKE_CXX_STANDARD 17)

list(APPEND NEPALIUNICODE_CPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
add_subdirectory("test")
