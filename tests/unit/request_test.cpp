
#include <gtest/gtest.h>
#include <http/request.h>
#include <http/response.h>
#include <http/interfaces/response_interface.h>
#include <http/url.h>
#include <http/types/status_codes.h>

using namespace Http;


TEST(RequestTest, ItReturnsAnHttpStatusCode) {
    
    Request request;

    Interfaces::ResponseInterface * response = request.get(Url("https://www.google.com"));

    StatusCode statusCode = response->getStatusCode();

    EXPECT_EQ(statusCode, StatusCode::OK);
}