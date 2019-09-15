
#include <gtest/gtest.h>
#include <http/url.h>
#include <string>


TEST(UrlTest, ItRetrieveTheProtocol) {
    
    Http::Url url("http://www.google.com");
    std::string protocol = url.getProtocol();

    EXPECT_EQ(protocol, "http");
}

TEST(UrlTest, ItRetrieveTheHost) {
    
    Http::Url url("http://www.google.com");
    std::string host = url.getHost();

    EXPECT_EQ(host, "www.google.com");
}

TEST(UrlTest, ItRetrieveThePath) {
    
    Http::Url url("http://www.google.com/some/path");
    std::string path = url.getPath();

    EXPECT_EQ(path, "/some/path");
}