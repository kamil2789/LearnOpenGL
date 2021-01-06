#include "VertexBufferObject.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

VertexBufferObject::VertexBufferObject(const std::vector<float>& vertices):
    vertices(vertices)
{
    glGenBuffers(1, &id);
}

VertexBufferObject::~VertexBufferObject()
{
    glDeleteBuffers(1, &id);
}

unsigned int VertexBufferObject::getId() const
{
    return id;
}

const float* VertexBufferObject::getVerticesData() const
{
    return vertices.data();
}

size_t VertexBufferObject::getSizeOfData() const
{
    return vertices.size() * sizeof(float);
}