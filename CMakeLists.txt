cmake_minimum_required(VERSION 3.5)
project(nepali-unicode)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE nepali-unicode-sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)


add_library(nepali-unicode ${nepali-unicode-sources})
