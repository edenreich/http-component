
#include <fstream>
#include <ios>
#include <cstring>
#include <iostream>
#include <experimental/filesystem>

#include <http/server.h>
#include <http/response.h>
#include <http/interfaces/socket_stream_interface.h>
#include <http/interfaces/response_interface.h>
#include <http/interfaces/client_interface.h>

using namespace Http;


/**
 * Some function to return the file content.
 */
std::string getFileContent(const std::string & path) 
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

int main(int argc, char const *argv[])
{
    Server server;

    server.bind("0.0.0.0");

    server.listen(8080);

    server.onConnection([](Interfaces::ClientInterface * client) {

        Interfaces::SocketStreamInterface * stream = client->getRequest()->getBody();
        std::string content = getFileContent(std::experimental::filesystem::current_path().concat("/../examples/webpage/public/index.html"));

        *stream << "HTTP/1.1 200 OK\n";
        *stream << "Content-Type: text/html\n";
        *stream << "Content-Length: " << strlen(content.c_str()) << "\n";
        *stream << "Connection: close\n";
        *stream << "\n";
        *stream << content.c_str();

        return new Response(stream);    
    });

    return 0;
}
