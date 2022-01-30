find_package(Catch2 REQUIRED)

add_executable(nepaliunicode-tests common.h main.cpp nepaliunicode.test.cpp)
include_directories(${NEPALIUNICODE_CPP_INCLUDE_DIRS})

target_link_libraries(nepaliunicode-tests nepali-unicode  Catch2::Catch2)

add_test(nepaliunicode-unittests nepaliunicode-tests -v normal)