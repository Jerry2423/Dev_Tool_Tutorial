cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(Practice)

add_executable(Practice main.cpp)

add_subdirectory(foo)

target_link_libraries(Practice Foo)

target_include_directories(Practice PUBLIC "foo")
