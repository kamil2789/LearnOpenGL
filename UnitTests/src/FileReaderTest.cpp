#include <string>
#include "gtest\gtest.h"

#include "FileReader.h"

//TODO
//Replace it with a script that will generate a file nearby UnitTest exec
const std::string fileName{"ExampleSrcFile.txt"};

const std::string sourceCode{"This is example source file\n{\n    It can has fragment shader, vertex shader or any other kind of codes\n}"};

TEST(FileReader, read_readValidFile_returnString)
{
    auto result = FileReader::read(fileName);

    EXPECT_EQ(sourceCode, result);
}