#pragma once
#include <memory>
#include "VertexBufferObject.h"

class SimpleVertexArray
{
public:
    SimpleVertexArray(std::unique_ptr<VertexBufferObject> vertexBuffer);
    ~SimpleVertexArray();
    void bindBufferToVertexArray();
    void bindBufferToVertexArray(unsigned int layouts);
    unsigned int getVAO() const;
private:
    unsigned int vertexArrayObject;
    std::unique_ptr<VertexBufferObject> vertexObject;
};