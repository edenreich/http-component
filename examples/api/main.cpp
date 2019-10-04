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

        Interfaces::ClientSocketInterface * socket = client->getRequest()->getBody();
        const char * json = R"JSON(
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

        *socket << "HTTP/1.1 200 OK\n";
        *socket << "Content-Type: application/json\n";
        *socket << "Content-Length: " << strlen(json) << "\n";
        *socket << "Connection: close\n";
        *socket << "\n";
        *socket << json;

        return new Response(socket);
    });

    return 0;
}
