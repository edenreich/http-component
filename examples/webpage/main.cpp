#include <http/platform/check.h>

#if IS_APPLE
#include <filesystem>
#else
#include <experimental/filesystem>
#endif

#include <http/server.h>
#include <http/response.h>
#include <http/interfaces/socket_stream_interface.h>
#include <http/interfaces/response_interface.h>
#include <http/interfaces/client_interface.h>

#include "helpers.h"

namespace fs = std::experimental::filesystem;

using namespace Http;

int main(int argc, char const *argv[])
{
    Server server;

    server.bind("0.0.0.0");

    server.listen(8080);

    server.onConnection([](Interfaces::ClientInterface * client) {

        Interfaces::SocketStreamInterface * stream = client->getRequest()->getBody();
        std::string content = getFileContent(fs::current_path().concat("/../examples/webpage/public/index.html"));

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
