#include <fstream>
#include <sstream>
#include <string>

#include "FileReader.h"

std::string FileReader::read(const std::string& path)
{
    std::stringstream buffer;
    std::ifstream file{path, std::ios_base::in};
    if (file.is_open())
    {
        buffer << file.rdbuf();
    }
    else
    {
        return std::string{""};
    }

    file.close();
    return buffer.str();
}