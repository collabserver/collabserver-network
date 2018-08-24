#include "collabcommon/network/ZMQSocket.h"

#include <gtest/gtest.h>
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


ZMQSocketConfig conf {
    ZMQ_REP,
    &g_context,
    &(MessageFactory::getInstance())
};


TEST(ZMQSocket, constructor_OnStack) {
    ZMQSocket coco(conf);
}

TEST(ZMQSocket, constructor_OnHead) {
    ZMQSocket *coco = new ZMQSocket(conf);
    ASSERT_NE(coco, nullptr);
    delete coco;
}


} // End namespace


