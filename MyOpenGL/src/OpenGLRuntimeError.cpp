#include <exception>
#include <string>

#include "OpenGLRuntimeError.h"

OpenGLRuntimeError::OpenGLRuntimeError(std::string message):
    errorMessage{message}
{
    errorMessage.append("\n");
}

const char* OpenGLRuntimeError::what() const noexcept 
{
    return errorMessage.data();
}
