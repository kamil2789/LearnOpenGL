cmake_minimum_required(VERSION 3.18)

project(UnitTests VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/MainUT.cpp 
    src/FileReaderTest.cpp
    ${CMAKE_SOURCE_DIR}/MyOpenGL/src/FileReader.cpp
)

target_link_libraries(UnitTests ${CMAKE_SOURCE_DIR}/external/gtest/lib/libgtest.a)

target_include_directories(UnitTests PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/gtest/include
    ${CMAKE_SOURCE_DIR}/MyOpenGL/include
)

add_custom_command(TARGET UnitTests POST_BUILD
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/post_build.py)