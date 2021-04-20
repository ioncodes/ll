cmake_minimum_required(VERSION 3.17)
project(ll)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

add_executable(tests
        tests/test_pattern.cpp ll/pattern.hpp
        tests/test_file.cpp ll/file.hpp)

target_include_directories(tests PRIVATE ./)
target_link_libraries(tests Catch2::Catch2)

add_executable(ll ll/ll.hpp tests/test_pattern.cpp tests/test_file.cpp ll/file.hpp tests/test_file.cpp)