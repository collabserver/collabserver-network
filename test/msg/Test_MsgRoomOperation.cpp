#include "collabcommon/messaging/MessageList.h"

#include <sstream>
#include <gtest/gtest.h>

namespace collab {


TEST(MsgRoomOperation, serializeUnserialize) {
    MsgRoomOperation msg1;
    std::stringstream buff1;
    msg1.setUserID(4);
    msg1.setRoomID(8);
    msg1.serialize(buff1);

    MsgRoomOperation msg2;
    std::stringstream buff2;
    msg2.setUserID(512);
    msg2.setRoomID(256);
    msg2.serialize(buff2);

    msg1.unserialize(buff2);
    msg2.unserialize(buff1);

    ASSERT_EQ(msg1.getUserID(), 512);
    ASSERT_EQ(msg1.getRoomID(), 256);
    ASSERT_EQ(msg2.getUserID(), 4);
    ASSERT_EQ(msg2.getRoomID(), 8);
}


} // End namespace



