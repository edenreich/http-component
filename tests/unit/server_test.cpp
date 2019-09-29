#include <gtest/gtest.h>
#include <http/server.h>
#include <http/response.h>
#include <http/socket_stream.h>
#include <http/interfaces/response_interface.h>
#include <http/interfaces/client_interface.h>
#include <string>

using namespace Http;


TEST(ServerTest, ItRecievesAMessage) {
    
    Server server;

    server.bind("127.0.0.1");

    server.listen(8080);

    server.onConnection([](Interfaces::ClientInterface * client) {

        Interfaces::SocketStreamInterface * stream = client->getRequest()->getBody();

        const char * content = "Hello World";

        *stream << "HTTP/1.1 200 OK\n";
        *stream << "Content-Type: text/html\n";
        *stream << "Content-Length: " << strlen(content) << "\n";
        *stream << "Connection: close\n";
        *stream << "\n";
        *stream << content;

        return new Response(stream);    
    });
}
