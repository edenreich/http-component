
#include <gtest/gtest.h>
#include <http/server.h>
#include <http/interfaces/server_interface.h>
#include <string>

using namespace Http;


TEST(ServerTest, DISABLED_ItRecievesAMessage) {
    
    Server server;

    server.bind("127.0.0.1");

    server.listen(8080);

    server.onMessage([](Interfaces::ServerInterface const* server, const std::string & message) {
        std::cout << message << '\n';    
    });
}
