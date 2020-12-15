#pragma once

#include <string>

struct GLFWwindow;

class ConfigOpenGL
{
public:
    ConfigOpenGL(unsigned int windowWidth, unsigned int windowHeight, std::string windowName);
    ConfigOpenGL(const ConfigOpenGL&) = delete;
    ConfigOpenGL& operator=(const ConfigOpenGL&) = delete;

    bool initConfig();
    GLFWwindow* getGLFWwindow();

private:
    GLFWwindow* window;
    const unsigned int windowWidth;
    const unsigned int windowHeight;
    const std::string windowName;

    static bool isInitConfig;
    static void frameBufferCallback(GLFWwindow* window, int width, int height);
};