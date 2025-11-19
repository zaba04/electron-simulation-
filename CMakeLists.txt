cmake_minimum_required(VERSION 3.30)
project(kms_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(kms_2 main.cpp
        cmake-build-debug/wave_function.cpp
        cmake-build-debug/wave_function.h)
