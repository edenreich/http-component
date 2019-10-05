#include <http/server.h>
#include <http/response.h>
#include <http/interfaces/client_socket_interface.h>
#include <http/interfaces/client_interface.h>

using namespace Http;


int main(int argc, char const *argv[])
{
    Server server;

    server.bind("0.0.0.0");

    server.listen(8080);

    server.onConnection([](Interfaces::ClientInterface * client) {

        Interfaces::ClientSocketInterface * socket = client->getRequest()->getBody();
        std::string content = R"HTML(
            <html>
                <head>
                    <title>First Home Page</title>
                </head>
                <body>
                    <h1>Hello World</h1>
                    <p>This is some awesome homepage</p>
                </body>
            </html>
        )HTML"; 

        *socket << "HTTP/1.1 200 OK\n";
        *socket << "Content-Type: text/html\n";
        *socket << "Content-Length: " << content.length() << "\n";
        *socket << "Connection: close\n";
        *socket << "\n";
        *socket << content;

        return new Response(socket);    
    });

    return 0;
}
