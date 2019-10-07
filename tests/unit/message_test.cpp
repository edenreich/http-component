
#include <gtest/gtest.h>
#include <http/message.h>
#include <http/interfaces/message_interface.h>
#include <http/exceptions/invalid_message_exception.h>

using namespace Http;


TEST(MessageTest, itRetrievesTheProtocolLine) {
    std::string content = R"REQUEST(
    POST /home HTTP/1.1\r\n
    Accept: */*\r\n
    Host: localhost:8080\r\n
    Cache-Control: no-cache\r\n
    Content-Length: CONTENT_LENGTH\r\n
    Connection: keep-alive\r\n
    \r\n
        {
            "key": "value"
        }
    )REQUEST";

    Interfaces::MessageInterface * message =  new Message(content);

    std::string line = message->getProtocolLine();

    EXPECT_EQ(line, "POST /home HTTP/1.1");

    delete message;
}

TEST(MessageTest, itThrowAnExceptionIfAnEmptyMessageWasPassed) {
    EXPECT_THROW(new Message(""), Exceptions::InvalidMessageException);
}

TEST(MessageTest, itReturnsTheMessageBody) {

    // std::string content = R"REQUEST(
    // POST /home HTTP/1.1\r\n
    // Accept: */*\r\n
    // Host: localhost:8080\r\n
    // Cache-Control: no-cache\r\n
    // Content-Length: CONTENT_LENGTH\r\n
    // Connection: keep-alive\r\n
    // \r\n
    //     {
    //         "key": "value"
    //     }
    // )REQUEST";

    // std::stringstream ss;
    // std::string contentLength;

    // ss << content.length();
    // ss >> contentLength;

    // content.replace(content.find("CONTENT_LENGTH"), 15, contentLength);

    // Interfaces::MessageInterface * message = new Message(content);

    // std::string messageBody = R"BODY(
    //     {
    //         "key": "value"
    //     }
    // )BODY";

    // EXPECT_EQ(message->getBody().str(), messageBody);
}