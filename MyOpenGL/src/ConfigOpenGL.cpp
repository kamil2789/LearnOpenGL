#include "ConfigOpenGL.h"
#include "OpenGLRuntimeError.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

bool ConfigOpenGL::isInitConfig = false;

ConfigOpenGL::ConfigOpenGL(unsigned int windowWidth, unsigned int windowHeight, std::string windowName):
    window{nullptr},
    windowWidth{windowWidth},
    windowHeight{windowHeight},
    windowName{windowName}
{}

ConfigOpenGL::~ConfigOpenGL()
{
    glfwTerminate();
}

bool ConfigOpenGL::initConfig()
{
    if (isInitConfig)
    {
        return false;
    }

    if (glfwInit() == GLFW_FALSE)
    {
        throw OpenGLRuntimeError{"error during glfw init"};
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(windowWidth, windowHeight, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        glfwTerminate();
        throw OpenGLRuntimeError{"error during creating a glfw window"};
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, ConfigOpenGL::frameBufferCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw OpenGLRuntimeError{"error during initialize GLAD"};
    }

    isInitConfig = true;
    return true;
}

GLFWwindow* ConfigOpenGL::getGLFWwindow()
{
    return window;
}

void ConfigOpenGL::frameBufferCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}