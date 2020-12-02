cmake_minimum_required(VERSION 3.18)

project(MyOpenGL VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

 set (CMAKE_CXX_FLAGS "-O0 -Wall")

add_executable(${PROJECT_NAME} 
    src/Main.cpp
    ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c

)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/external/glfw/lib/libglfw3.a)
target_link_libraries(${PROJECT_NAME} opengl32.lib)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/external/glfw/include
    ${CMAKE_SOURCE_DIR}/external/glad/include
)