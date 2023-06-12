cmake_minimum_required(VERSION 3.16)
project(main)
add_executable(main main.cpp)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_SOURCE_DIR}/black_box)
target_link_libraries(main black_box)
target_include_directories(main PUBLIC black_box)
