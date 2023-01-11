cmake_minimum_required(VERSION 3.23)
project(CYC)

set(CMAKE_CXX_STANDARD 20)

add_executable(CYC main.cpp)

add_subdirectory(Google_tests)
