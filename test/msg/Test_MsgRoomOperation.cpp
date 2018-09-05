#include "collabcommon/messaging/MessageList.h"

#include <sstream>
#include <gtest/gtest.h>

namespace collab {


TEST(MsgRoomOperation, serializeUnserialize) {
    MsgRoomOperation msg1;
    msg1.setUserID(4);
    msg1.setRoomID(8);
    msg1.getOperationBuffer() = "OpOne";

    MsgRoomOperation msg2;
    msg2.setUserID(512);
    msg2.setRoomID(256);
    msg2.getOperationBuffer() = "OpTwo";

    std::stringstream buffer1;
    std::stringstream buffer2;
    msg1.serialize(buffer1);
    msg2.serialize(buffer2);

    // Simulate send buffer
    buffer1.seekg(0);
    buffer2.seekg(0);

    msg1.unserialize(buffer2);
    msg2.unserialize(buffer1);

    ASSERT_EQ(msg1.getUserID(), 512);
    ASSERT_EQ(msg1.getRoomID(), 256);
    ASSERT_EQ(msg1.getOperationBuffer(), "OpTwo");

    ASSERT_EQ(msg2.getUserID(), 4);
    ASSERT_EQ(msg2.getRoomID(), 8);
    ASSERT_EQ(msg2.getOperationBuffer(), "OpOne");
}


} // End namespace



