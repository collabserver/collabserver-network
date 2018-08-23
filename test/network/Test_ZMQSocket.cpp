#include "collabcommon/network/ZMQSocket.h"

#include <gtest/gtest.h>

namespace collab {


ZMQSocketConfig conf {
    ZMQ_REP,
    &g_context,
    nullptr
};


// Just to compile ZMQSocket and check if its compiling
TEST(ZMQSocket, constructor) {
    ZMQSocket soso(conf);
}


} // End namespace


