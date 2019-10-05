#include <http/server.h>
#include <http/response.h>
#include <http/message.h>
#include <http/interfaces/client_socket_interface.h>
#include <http/interfaces/client_interface.h>

#include <sstream>

using namespace Http;


int main(int argc, char const *argv[])
{
    Server server;

    server.bind("0.0.0.0");

    server.listen(8080);

    server.onConnection([](Interfaces::ClientInterface * client) {

        std::stringstream requestMessage = client->getRequest()->getBody();
        std::stringstream responseMessage;

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

        responseMessage << "HTTP/1.1 200 OK\n";
        responseMessage << "Content-Type: text/html\n";
        responseMessage << "Content-Length: " << content.length() << "\n";
        responseMessage << "Connection: close\n";
        responseMessage << "\n";
        responseMessage << content;

        return new Response(new Message(responseMessage));    
    });

    return 0;
}
