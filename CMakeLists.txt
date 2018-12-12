cmake_minimum_required(VERSION 3.13)
project(soa_vs_aos)

set(CMAKE_CXX_STANDARD 14)

add_executable(aos aos.cpp)
add_executable(soa soa.cpp)