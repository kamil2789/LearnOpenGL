#pragma once
#include <vector>

class VertexBufferObject
{
public:
    VertexBufferObject(const std::vector<float>& vertices);
    ~VertexBufferObject();
    unsigned int getId() const;
    const float* getVerticesData() const;
    size_t getSizeOfData() const;
private:
    unsigned int id;
    std::vector<float> vertices;
};