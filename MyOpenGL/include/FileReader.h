#pragma once

#include <string>

class FileReader
{
public:
    FileReader() = delete;
    FileReader(const FileReader&) = delete;
    FileReader& operator=(const FileReader&) = delete;

    static std::string read(const std::string& path);
};