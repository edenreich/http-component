
#include <gtest/gtest.h>
#include <http/url.h>
#include <string>


TEST(UrlTest, ItRetrieveTheProtocol) {
    
    Http::Url url = Http::Url("http://www.google.com");
    std::string protocol = url.getProtocol();

    EXPECT_EQ(protocol, std::string("http"));
}