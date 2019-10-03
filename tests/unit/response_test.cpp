
#include <gtest/gtest.h>
#include <http/response.h>
#include <http/socket_stream.h>


using namespace Http;


TEST(ResponseTest, ItReturnsNotFoundByDefault) {

    Interfaces::ResponseInterface * response = new Response;

    StatusCode statusCode = response->getStatusCode();

    delete response;

    EXPECT_EQ(statusCode, StatusCode::NOT_FOUND);
}

TEST(ResponseTest, ItReturnsAStatusCodeProperly) {

    Interfaces::SocketStreamInterface * socket = new SocketStream;

    *socket << "HTTP/1.1 200 OK";

    Interfaces::ResponseInterface * response = new Response(socket);

    StatusCode statusCode = response->getStatusCode();

    delete response;

    EXPECT_EQ(statusCode, StatusCode::OK);
}
