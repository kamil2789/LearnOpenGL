#include <iostream>
#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "ConfigOpenGL.h"
#include "ShaderProgram.h"
#include "FileReader.h"
#include "OpenGLRuntimeError.h"
#include "SimpleVertexArray.h"
#include "VertexBufferObject.h"

void processInput(GLFWwindow *window);

std::vector<float> vertices = {
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f
};

std::vector<float> vertices2 = {
1.0f, 1.0f, 0.0f,
0.0f, 1.0f, 0.0f,
1.0f, 0.7f, 0.0f
};

const std::string simpleFragmentShader{"Shaders/FragmentShader/GradientTriangle.frag"};
const std::string simpleVertexShader{"Shaders/VertexShaders/SimpleVertex.vert"};

int main()
{
    ConfigOpenGL configOpenGL{800, 600, "HelloWorld"};
    configOpenGL.initConfig();

    ShaderProgram blueTriangle{};
    try
    {
        blueTriangle.buildShaderProgram(FileReader::read(simpleVertexShader), FileReader::read(simpleFragmentShader));
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    SimpleVertexArray triangleOne{std::make_unique<VertexBufferObject>(vertices)};
    SimpleVertexArray triangleTwo{std::make_unique<VertexBufferObject>(vertices2)};
    triangleOne.bindBufferToVertexArray();
    triangleTwo.bindBufferToVertexArray();

    float color = 0.0f;
    bool isRising = true;

    while (!glfwWindowShouldClose(configOpenGL.getGLFWwindow()))
    {
        processInput(configOpenGL.getGLFWwindow());
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(blueTriangle.getShaderProgramID());
        int vertexColorLocation = glGetUniformLocation(blueTriangle.getShaderProgramID(), "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, color, 0.0f, 1.0f);


        glBindVertexArray(triangleOne.getVAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(triangleTwo.getVAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(configOpenGL.getGLFWwindow());
        glfwPollEvents();

        if (isRising)
        {
            color += 0.01;
            if (color > 0.98f)
            {
                isRising = false;
            }
        }
        else
        {
            color -= 0.01;
            if (color < 0.02f)
            {
                isRising = true;
            }
        }
    }

    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}