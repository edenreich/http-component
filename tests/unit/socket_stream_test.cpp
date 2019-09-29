#include <gtest/gtest.h>
#include <http/socket_stream.h>
#include <string>

using namespace Http;


TEST(StreamTest, CanCreateAStreamWithDefaultConstructor) {

    Interfaces::SocketStreamInterface * stream = new SocketStream;
}
