#pragma once
#include <string>

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();
    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;

    void buildShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
    int getShaderProgramID() const;
    bool isValid() const;

private:
    int shaderProgramID;
    std::string compilationMessage;
    bool isProgram;

    int compileShader(const char* shaderSourceCode, int shaderType);
    bool linkShaders();
    bool checkCompileStatus(int shaderID);
    bool checkLinkStatus(int shaderProgramID);
};