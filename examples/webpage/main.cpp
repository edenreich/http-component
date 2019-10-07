#include <http/server.h>
#include <http/response.h>
#include <http/message.h>
#include <http/interfaces/client_interface.h>

#include <sstream>

using namespace Http;


int main(int argc, char const *argv[])
{
    Server server;

    server.bind("0.0.0.0");

    server.listen(8080);

    server.onConnection([](Interfaces::ClientInterface * client) {
        Interfaces::MessageInterface * requestMessage = client->getRequest()->getMessage();
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

        responseMessage << "HTTP/1.1 200 OK\r\n";
        responseMessage << "Content-Type: text/html\r\n";
        responseMessage << "Content-Length: " << content.length() << "\r\n";
        responseMessage << "Connection: close\r\n";
        responseMessage << "\r\n";
        responseMessage << "\r\n";
        responseMessage << content;

        return new Response(new Message(responseMessage));    
    });

    return 0;
}
