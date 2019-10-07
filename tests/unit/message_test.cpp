
#include <gtest/gtest.h>
#include <http/message.h>
#include <http/interfaces/message_interface.h>
#include <http/exceptions/invalid_message_exception.h>

using namespace Http;


TEST(MessageTest, itRetrievesTheProtocolLine) {
    std::string content =
    "POST /home HTTP/1.1\r\n"
    "Accept: */*\r\n"
    "Host: localhost:8080\r\n"
    "Cache-Control: no-cache\r\n"
    "Content-Length: CONTENT_LENGTH\r\n"
    "Connection: keep-alive\r\n"
    "\r\n"
        "{"
            "\"key\": \"value\""
        "}"
    ;

    Interfaces::MessageInterface * message =  new Message(content);

    std::string line = message->getProtocolLine();

    EXPECT_EQ(line, "POST /home HTTP/1.1");

    delete message;
}

TEST(MessageTest, itThrowAnExceptionIfAnEmptyMessageWasPassed) {
    EXPECT_THROW(new Message(""), Exceptions::InvalidMessageException);
}

TEST(MessageTest, itRetrieveTheHeadersOfTheMessage) {
    std::string content =
    "POST /home HTTP/1.1\r\n"
    "Accept: */*\r\n"
    "Host: localhost:8080\r\n"
    "Cache-Control: no-cache\r\n"
    "Content-Length: CONTENT_LENGTH\r\n"
    "Connection: keep-alive\r\n"
    "\r\n"
        "{"
            "\"key\": \"value\""
        "}"
    ;

    Interfaces::MessageInterface * message =  new Message(content);

    Headers headers = message->getHeaders();

    EXPECT_EQ(headers["Accept"], "*/*");
    EXPECT_EQ(headers["Cache-Control"], "no-cache");

    delete message;
}

TEST(MessageTest, itRetrieveTheBodyOfTheMessage) {
    std::string content =
    "POST /home HTTP/1.1\r\n"
    "Accept: */*\r\n"
    "Host: localhost:8080\r\n"
    "Cache-Control: no-cache\r\n"
    "Content-Length: CONTENT_LENGTH\r\n"
    "Connection: keep-alive\r\n"
    "\r\n"
        "{\"key\": \"value\"}"
    ;

    Interfaces::MessageInterface * message =  new Message(content);

    const std::stringstream & body = message->getBody();

    std::string json = R"({"key": "value"})";

    EXPECT_EQ(body.str(), json);

    delete message;
}