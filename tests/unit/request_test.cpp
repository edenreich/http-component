
#include <gtest/gtest.h>
#include <http/message.h>
#include <http/request.h>
#include <http/response.h>
#include <http/interfaces/response_interface.h>
#include <http/url.h>
#include <http/types/status_codes.h>

#include <http/exceptions/invalid_message_exception.h>

using namespace Http;


TEST(RequestTest, ItThrowsAnInvalidMessageExceptionIfAnInvalidRequestMessageWasPassed) {
    EXPECT_THROW(new Request(new Message("HTTP/1.1 200 OK")), Exceptions::InvalidMessageException);
    EXPECT_THROW(new Request(new Message("UNKNOWN_HTTP_VERB /path Http/1.1")), Exceptions::InvalidMessageException);
}

// TEST(RequestTest, ItReturnsAnHttpStatusCode) {
    // Request request;

    // Interfaces::ResponseInterface * response = request.get(Url("https://www.google.com"));

    // StatusCode statusCode = response->getStatusCode();

    // EXPECT_EQ(statusCode, StatusCode::OK);
// }