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

        std::string json = R"JSON(
            [
                {
                    "id": 1,
                    "name": "Pizza",
                    "description": "lorem ipsum"
                },
                {
                    "id": 2,
                    "name": "Cola",
                    "description": "lorem ipsum"
                },
                {
                    "id": 3,
                    "name": "Hamburger",
                    "description": "lorem ipsum"
                }
            ]
        )JSON";

        responseMessage << "HTTP/1.1 200 OK\n";
        responseMessage << "Content-Type: application/json\n";
        responseMessage << "Content-Length: " << json.length() << "\n";
        responseMessage << "Connection: close\n";
        responseMessage << "\n";
        responseMessage << json;

        return new Response(new Message(responseMessage));
    });

    return 0;
}
