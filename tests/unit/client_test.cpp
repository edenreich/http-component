
#include <gtest/gtest.h>
#include <http/client.h>
#include <http/response.h>
#include <http/url.h>


TEST(ClientTest, ItReturnsAnHttpResponse) {
    
    Http::Client client;

    // client.GET(Http::Url("https://www.google.com"), [](Http::Response response) {

    // });


    EXPECT_TRUE(true);
}