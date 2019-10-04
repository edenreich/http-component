#include <cstring>

#include <http/server.h>
#include <http/response.h>
#include <http/interfaces/client_socket_interface.h>
#include <http/interfaces/response_interface.h>
#include <http/interfaces/client_interface.h>

using namespace Http;


int main(int argc, char const *argv[])
{
    Server server;

    server.bind("0.0.0.0");

    server.listen(8080);

    server.onConnection([](Interfaces::ClientInterface * client) {

        Interfaces::ClientSocketInterface * stream = client->getRequest()->getBody();
        const char * content = R"HTML(
            <html>
                <head>
                    <title>First Home Page</title>
                </head>
                <body>
                    <h1>Hello World</h1>
                    <p>This is some awesome context</p>
                </body>
            </html>
        )HTML"; 

        *stream << "HTTP/1.1 200 OK\n";
        *stream << "Content-Type: text/html\n";
        *stream << "Content-Length: " << strlen(content) << "\n";
        *stream << "Connection: close\n";
        *stream << "\n";
        *stream << content;

        return new Response(stream);    
    });

    return 0;
}
