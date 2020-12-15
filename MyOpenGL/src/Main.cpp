#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "ConfigOpenGL.h"

void processInput(GLFWwindow *window);

int main()
{
    ConfigOpenGL configOpenGL{800, 600, "HelloWorld"};
    configOpenGL.initConfig();

    while (!glfwWindowShouldClose(configOpenGL.getGLFWwindow()))
    {
        processInput(configOpenGL.getGLFWwindow());
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(configOpenGL.getGLFWwindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}