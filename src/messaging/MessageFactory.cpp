#include "collabcommon/messaging/MessageFactory.h"

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageList.h"

namespace collab {


std::unique_ptr<Message> MessageFactory::newMessage(const int type) const {
    switch(type) {
        case MSG_DEBUG:
            return std::unique_ptr<Message>(new MsgDebug());


        // ---------------------------------------------------------------------
        // Miscellaneous Messages
        // ---------------------------------------------------------------------
        default:
            return nullptr;
    }
}


}  // End namespace


