# Cmake minimum version
cmake_minimum_required(VERSION 2.8)

project(examinateRoundingBehavior)

# find OpenCL
find_package(OpenCL)

set(TARGET_NAME examinRounding)

add_executable(${TARGET_NAME} examin.cpp)

