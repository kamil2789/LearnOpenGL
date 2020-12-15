#pragma once
#include <exception>
#include <string>

class OpenGLRuntimeError : public std::exception
{
public:
    OpenGLRuntimeError(std::string message);
    ~OpenGLRuntimeError() = default;
    const char* what() const noexcept override;
private:
    std::string errorMessage;
};