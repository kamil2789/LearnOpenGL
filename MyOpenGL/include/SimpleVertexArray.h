#pragma once
#include <memory>
#include "VertexBufferObject.h"

class SimpleVertexArray
{
public:
    SimpleVertexArray(std::unique_ptr<VertexBufferObject> vertexBuffer);
    ~SimpleVertexArray();
    void bindBufferToVertexArray();
    unsigned int getVAO() const;
private:
    unsigned int vertexArrayObject;
    std::unique_ptr<VertexBufferObject> vertexObject;
};