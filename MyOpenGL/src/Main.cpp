#include <iostream>
#include <vector>
#include <chrono>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "ConfigOpenGL.h"
#include "ShaderProgram.h"
#include "FileReader.h"
#include "OpenGLRuntimeError.h"
#include "SimpleVertexArray.h"
#include "VertexBufferObject.h"
#include "ProgramExamples.h"

using namespace std::chrono_literals;

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

std::vector<float> verticesColors = {
0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 
-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
};

const std::string simpleFragmentShader{"Shaders/FragmentShader/FragmentColor.frag"};
const std::string simpleVertexShader{"Shaders/VertexShaders/VertexWithColors.vert"};

int main()
{
    ConfigOpenGL configOpenGL{800, 600, "HelloWorld"};
    configOpenGL.initConfig();

    if (ProgramExamples::twoGreenTriangles(configOpenGL.getGLFWwindow(), 3s))
    {
        std::cout<<"OK";
    }

    if (ProgramExamples::rainbowTriangle(configOpenGL.getGLFWwindow(), 3s))
    {
        std::cout<<"OK2";
    }

  //  while (!glfwWindowShouldClose(configOpenGL.getGLFWwindow()))
   // {
       // processInput(configOpenGL.getGLFWwindow());
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
       // glClear(GL_COLOR_BUFFER_BIT);

       // glUseProgram(blueTriangle.getShaderProgramID());
        //int vertexColorLocation = glGetUniformLocation(blueTriangle.getShaderProgramID(), "ourColor");
       // glUniform4f(vertexColorLocation, 0.0f, color, 0.0f, 1.0f);


        //glBindVertexArray(triangleOne.getVAO());
      //  glDrawArrays(GL_TRIANGLES, 0, 3);

      //  glfwSwapBuffers(configOpenGL.getGLFWwindow());
       // glfwPollEvents();
  //  }

    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}