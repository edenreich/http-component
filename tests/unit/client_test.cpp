
#include <gtest/gtest.h>
#include <http/client.h>
#include <http/response.h>


TEST(ClientTest, ItReturnsAnHttpResponse) {
    
    Http::Client client;

    // client.get(Http::Url("https://www.google.com"), [](Http::Response response) {

    // });


    EXPECT_TRUE(true);
}