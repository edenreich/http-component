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

        *stream << "HTTP/1.1 200 OK\n";
        *stream << "Content-Type: application/json\n";
        *stream << "Content-Length: " << strlen(json) << "\n";
        *stream << "Connection: close\n";
        *stream << "\n";
        *stream << json;

        return new Response(stream);
    });

    return 0;
}
