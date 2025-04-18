# Minimum CMake version required
cmake_minimum_required(VERSION 3.26.5)

# Project name
project(CppUtils VERSION 0.1 LANGUAGES CXX)

# Set the source directory
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Include Google Test framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/6910c9d9165801d8827d628cb72eb7ea9dd538c5.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(${SRC_DIR}/core_util)
add_subdirectory(${SRC_DIR}/example_project)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_CLANG_TIDY
    "clang-tidy;
    -header-filter=.;
    -checks=*;
    -warnings-as-errors=*;")
