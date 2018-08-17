#include "collabcommon/msg/MsgDebug.h"

#include <gtest/gtest.h>
#include <sstream>

namespace collab {


// -----------------------------------------------------------------------------
// serialize / unserialize
// -----------------------------------------------------------------------------

TEST(MsgDebug, serializeUnserialize) {
    MsgDebug msg;
    MsgDebug msg_resp;

    std::stringstream buffer;
    msg.setcontent("Ellie");
    msg.serialize(buffer);

    msg_resp.unserialize(buffer);
    ASSERT_EQ(msg_resp.content(), msg.content());
}


} // End namespace


