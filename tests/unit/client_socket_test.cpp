
#include <gtest/gtest.h>
#include <http/client_socket.h>
#include <http/interfaces/client_socket_interface.h>

using namespace Http;


TEST(ClientSocketTest, itReturnsALineByGivenNumber) {
    
    Interfaces::ClientSocketInterface * socket = new ClientSocket;

    std::string content = R"JSON(
        {
            "key": "value"
        }
    )JSON";

    // Simulate a request message
    *socket << "POST /home HTTP/1.1\n";
    *socket << "Accept: */*\n";
    *socket << "Host: localhost:8080\n";
    *socket << "Cache-Control: no-cache\n";
    *socket << "Content-Length: " << content.length() << "\n";
    *socket << "Connection: keep-alive\n";
    *socket << "\n";
    *socket << content;

    EXPECT_EQ(socket->readLine(2), "Accept: */*");
}