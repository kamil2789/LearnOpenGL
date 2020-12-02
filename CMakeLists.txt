cmake_minimum_required(VERSION 3.18)

project(LearnOpenGL VERSION 1.0)

add_subdirectory(MyOpenGL)
add_subdirectory(UnitTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)