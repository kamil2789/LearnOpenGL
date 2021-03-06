#include <memory>
#include "SimpleVertexArray.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

SimpleVertexArray::SimpleVertexArray(std::unique_ptr<VertexBufferObject> vertexBuffer):
    vertexObject{std::move(vertexBuffer)}
{
    glGenVertexArrays(1, &vertexArrayObject);
}

SimpleVertexArray::~SimpleVertexArray()
{
    glDeleteVertexArrays(1, &vertexArrayObject);
}

unsigned int SimpleVertexArray::getVAO() const
{
    return vertexArrayObject;
}

void SimpleVertexArray::bindBufferToVertexArray()
{
    glBindVertexArray(vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, vertexObject->getId());
    glBufferData(GL_ARRAY_BUFFER, vertexObject->getSizeOfData(), vertexObject->getVerticesData(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0); 
}

void SimpleVertexArray::bindBufferToVertexArray(unsigned int layouts)
{
    glBindVertexArray(vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, vertexObject->getId());
    glBufferData(GL_ARRAY_BUFFER, vertexObject->getSizeOfData(), vertexObject->getVerticesData(), GL_STATIC_DRAW);
    for (int i = 0; i <= layouts; i++)
    {
        glVertexAttribPointer(i, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<void*>(3 * i * sizeof(float)));
        glEnableVertexAttribArray(i);
    }
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0); 
}