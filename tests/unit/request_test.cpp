
#include <gtest/gtest.h>
#include <http/request.h>
#include <http/response.h>
#include <http/interfaces/response_interface.h>
#include <http/url.h>

using namespace Http;


TEST(ClientTest, ItReturnsAnHttpStatusCode) {
    
    Request request = Request(Response());

    const Interfaces::ResponseInterface & response = request.get(Url("https://www.google.com"));

    int statusCode = response.getStatusCode();

    // EXPECT_EQ(statusCode, 200);
}