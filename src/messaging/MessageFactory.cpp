#include "collabcommon/messaging/MessageFactory.h"

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageList.h"

namespace collab {


std::unique_ptr<Message> MessageFactory::newMessage(const int type) const {
    switch(type) {
        case MSG_DEBUG:
            return std::unique_ptr<Message>(new MsgDebug());
        case MSG_ERROR:
            return std::unique_ptr<Message>(new MsgError());
        case MSG_CONNECTION_REQ:
            return std::unique_ptr<Message>(new MsgConnectionRequest());
        case MSG_CONNECTION_SUCCESS:
            return std::unique_ptr<Message>(new MsgConnectionSuccess());


        // ---------------------------------------------------------------------
        // Miscellaneous Messages
        // ---------------------------------------------------------------------
        default:

            return nullptr;
    }
}


}  // End namespace


