cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME demo)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

add_executable(main main.cpp)

