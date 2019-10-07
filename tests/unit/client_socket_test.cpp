
#include <gtest/gtest.h>
#include <http/client_socket.h>
#include <http/interfaces/client_socket_interface.h>

using namespace Http;


TEST(ClientSocketTest, ItReturnsALineByGivenNumber) {
    
    Interfaces::ClientSocketInterface * socket = new ClientSocket;

    std::string content = R"JSON(
        {
            "key": "value"
        }
    )JSON";

    // Simulate a request message
    *socket << "POST /home HTTP/1.1\r\n";
    *socket << "Accept: */*\r\n";
    *socket << "Host: localhost:8080\r\n";
    *socket << "Cache-Control: no-cache\r\n";
    *socket << "Content-Length: " << content.length() << "\r\n";
    *socket << "Connection: keep-alive\r\n";
    *socket << "\r\n";
    *socket << content;

    EXPECT_EQ(socket->readLine(2), "Accept: */*");
}