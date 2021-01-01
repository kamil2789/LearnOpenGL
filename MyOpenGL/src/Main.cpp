#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "ConfigOpenGL.h"
#include "ShaderProgram.h"
#include "FileReader.h"
#include "OpenGLRuntimeError.h"

void processInput(GLFWwindow *window);

float vertices[] = {
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f
};

const std::string simpleFragmentShader{"../../MyOpenGL/Shaders/FragmentShader/SimpleFragment.frag"};
const std::string simpleVertexShader{"../../MyOpenGL/Shaders/VertexShaders/SimpleVertex.vert"};

int main()
{
    ConfigOpenGL configOpenGL{800, 600, "HelloWorld"};
    configOpenGL.initConfig();

    ShaderProgram triangle{};
    try
    {
        triangle.buildShaderProgram(FileReader::read(simpleVertexShader), FileReader::read(simpleFragmentShader));
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

    while (!glfwWindowShouldClose(configOpenGL.getGLFWwindow()))
    {
        processInput(configOpenGL.getGLFWwindow());
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(triangle.getShaderProgramID());
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(configOpenGL.getGLFWwindow());
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}