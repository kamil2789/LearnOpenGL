
#include <chrono>
#include <vector>
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "ShaderProgram.h"
#include "FileReader.h"
#include "OpenGLRuntimeError.h"
#include "SimpleVertexArray.h"
#include "VertexBufferObject.h"
#include "ProgramExamples.h"

using namespace std::chrono_literals;

bool ProgramExamples::twoGreenTriangles(GLFWwindow* window, std::chrono::seconds duration)
{
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

    ShaderProgram greenTriangle{};
    try
    {
        greenTriangle.buildShaderProgram(FileReader::read(simpleVertexShader), FileReader::read(simpleFragmentShader));
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }

    SimpleVertexArray triangleOne{std::make_unique<VertexBufferObject>(vertices)};
    SimpleVertexArray triangleTwo{std::make_unique<VertexBufferObject>(vertices2)};
    triangleOne.bindBufferToVertexArray();
    triangleTwo.bindBufferToVertexArray();

    float color = 0.0f;
    bool isRising = true;
    auto start = std::chrono::system_clock::now();
    auto now = std::chrono::system_clock::now();
    auto maxTime = duration;
    auto actualTime = 0s;

    while (maxTime.count() >= actualTime.count())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(greenTriangle.getShaderProgramID());
        int vertexColorLocation = glGetUniformLocation(greenTriangle.getShaderProgramID(), "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, color, 0.0f, 1.0f);

        glBindVertexArray(triangleOne.getVAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(triangleTwo.getVAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
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

        now = std::chrono::system_clock::now();
        actualTime = std::chrono::duration_cast<std::chrono::seconds>(now - start);
    }

    return true;
}

bool ProgramExamples::rainbowTriangle(GLFWwindow* window, std::chrono::seconds duration)
{
    const std::string fragmentShader{"Shaders/FragmentShader/FragmentColor.frag"};
    const std::string vertexShader{"Shaders/VertexShaders/VertexWithColors.vert"};

    std::vector<float> verticesColors = {
    .5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    ShaderProgram rainbowTriangle{};
    try
    {
        rainbowTriangle.buildShaderProgram(FileReader::read(vertexShader), FileReader::read(fragmentShader));
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }

    SimpleVertexArray triangleOne{std::make_unique<VertexBufferObject>(verticesColors)};
    triangleOne.bindBufferToVertexArray(1);

    auto start = std::chrono::system_clock::now();
    auto now = std::chrono::system_clock::now();
    auto maxTime = duration;
    auto actualTime = 0s;

    while (maxTime.count() >= actualTime.count())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(rainbowTriangle.getShaderProgramID());

        glBindVertexArray(triangleOne.getVAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();

        now = std::chrono::system_clock::now();
        actualTime = std::chrono::duration_cast<std::chrono::seconds>(now - start);
    }

    return true;
}