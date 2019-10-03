#include <fstream>
#include <ios>
#include <cstring>
#include <string>
#include <iostream>

/**
 * Some function to return the file content.
 * 
 * @param const std::string & path
 */
inline std::string getFileContent(const std::string & path) 
{
    std::ifstream inputFile;
    std::string content;

    inputFile.open(path, std::ios::in);

    if (!inputFile) {
        std::cerr << "Could not open the file from path: " << path << '\n';
        return "";
    }

    inputFile.seekg(0, std::ios::end);
    std::streampos size = inputFile.tellg();
    content.reserve(size);
    inputFile.seekg(0, std::ios::beg);
    content.assign((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    inputFile.close();

    return content.c_str();
}