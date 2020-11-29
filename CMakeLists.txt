cmake_minimum_required(VERSION 3.18)

project(LearnOpenGL VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set (CMAKE_CXX_FLAGS "-O0")

add_executable(${PROJECT_NAME} 
    src/Main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/include)