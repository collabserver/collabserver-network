#include "collabcommon/network/ZMQSocket.h"

#include <gtest/gtest.h>
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


ZMQSocketConfig conf {
    ZMQ_REP,
    &g_context,
    &(MessageFactory::getInstance())
};


// Just to compile ZMQSocket and check if its compiling
TEST(ZMQSocket, constructor) {
    ZMQSocket soso(conf);
}


} // End namespace


