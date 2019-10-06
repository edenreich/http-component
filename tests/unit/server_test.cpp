#include <gtest/gtest.h>
#include <http/server.h>
#include <http/message.h>
#include <http/response.h>
#include <http/interfaces/client_socket_interface.h>
#include <http/interfaces/response_interface.h>
#include <http/interfaces/client_interface.h>
#include <string>

#include <sstream>

using namespace Http;


TEST(ServerTest, DISABLED_ItRecievesAMessage) {
    
    Server server;

    server.bind("127.0.0.1");

    server.listen(8080);

    server.onConnection([](Interfaces::ClientInterface * client) {

        std::stringstream body = client->getRequest()->getBody();

        const char * content = "Hello World";

        body << content;

        return new Response(new Message(body));    
    });
}
