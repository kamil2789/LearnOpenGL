cmake_minimum_required(VERSION 3.18)

project(UnitTests VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/MainUT.cpp 
    #${CMAKE_SOURCE_DIR}/src/xxx.cpp
)

target_link_libraries(UnitTests ${CMAKE_SOURCE_DIR}/external/gtest/lib/libgtest.a)

target_include_directories(UnitTests PUBLIC 
    ${CMAKE_SOURCE_DIR}/external/gtest/include
    ${CMAKE_SOURCE_DIR}/src/include
)