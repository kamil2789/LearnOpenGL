#include "ShaderProgram.h"
#include "OpenGLRuntimeError.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

ShaderProgram::ShaderProgram(): 
    compilationMessage{""},
    isProgram(false)
{
    shaderProgramID = glCreateProgram();
    if (shaderProgramID == 0)
    {
        throw OpenGLRuntimeError{"error during creating a shader program"};
    }
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(shaderProgramID);
}

void ShaderProgram::buildShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
{
    if (isProgram)
    {
        return;
    }

    int vertexShaderID = compileShader(vertexShader.data(), GL_VERTEX_SHADER);
    if (vertexShaderID == 0)
    {
        throw OpenGLRuntimeError{compilationMessage};
    }

    int fragmentShaderID = compileShader(fragmentShader.data(), GL_FRAGMENT_SHADER);
    if (fragmentShaderID == 0)
    {
        glDeleteShader(vertexShaderID);
        throw OpenGLRuntimeError{compilationMessage};
    }

    glAttachShader(shaderProgramID, vertexShaderID);
    glAttachShader(shaderProgramID, fragmentShaderID);
    glLinkProgram(shaderProgramID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    if (checkLinkStatus(shaderProgramID) == false)
    {
        throw OpenGLRuntimeError{compilationMessage};
    }

    isProgram = true;
}

int ShaderProgram::compileShader(const char* shaderSourceCode, int shaderType)
{
    int shaderID = glCreateShader(shaderType);
    if (shaderID == 0)
    {
        return 0;
    }

    glShaderSource(shaderID, 1, &shaderSourceCode, nullptr);
    glCompileShader(shaderID);

    return checkCompileStatus(shaderID) ? shaderID : 0;
}

bool ShaderProgram::checkCompileStatus(int shaderID)
{
    auto success = 0;
    char infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (success == false)
    {
        glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
        compilationMessage.append("Shader compilation failed: ");
        compilationMessage.append(infoLog);

        return false;
    }

    return true;
}

bool ShaderProgram::checkLinkStatus(int shaderProgramID)
{
    auto success = 0;
    char infoLog[512];
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if (success == false) 
    {
        glGetProgramInfoLog(shaderProgramID, 512, nullptr, infoLog);
        compilationMessage.append("Shader program linking failed: ");
        compilationMessage.append(infoLog);

        return false;
    }

    return true;
}

bool ShaderProgram::isValid() const
{
    return isProgram;
}

int ShaderProgram::getShaderProgramID() const
{
    return shaderProgramID;
}