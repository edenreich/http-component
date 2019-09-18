
#include <gtest/gtest.h>
#include <http/url.h>
#include <string>


TEST(UrlTest, ItRetrieveTheRawUrlBack) {
    
    Http::Url url("http://www.google.com/some/path?value=key");
    std::string rawUrl = url.get();

    EXPECT_EQ(rawUrl, "http://www.google.com/some/path?value=key");
}

TEST(UrlTest, ItRetrieveTheEncodedUrl) {
    
    Http::Url url("http://www.google.com/some/path?value=key with space");
    std::string encodedUrl = url.getEncoded();

    EXPECT_EQ(encodedUrl, "http%3A%2F%2Fwww.google.com%2Fsome%2Fpath%3Fvalue%3Dkey+with+space");
}

TEST(UrlTest, ItRetrieveTheProtocol) {
    
    Http::Url url("http://www.google.com");
    std::string protocol = url.getScheme();

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