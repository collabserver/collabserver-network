#include "collabcommon/messaging/MessageFactory.h"

#include <cassert>

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageList.h"

namespace collab {


Message* MessageFactory::newMessage(const int type) const {
    switch(type) {
        case MSG_CONNECTION_REQ:
            return new MsgConnectionRequest();
        case MSG_CONNECTION_SUCCESS:
            return new MsgConnectionSuccess();
        case MSG_ERROR:
            return new MsgError();
        case MSG_DEBUG:
            return new MsgDebug();


        // ---------------------------------------------------------------------
        // Miscellaneous Messages
        // ---------------------------------------------------------------------
        default:
            return nullptr;
    }
}

void MessageFactory::freeMessage(Message* msg) const {
    assert(msg != nullptr);
    if(msg != nullptr) {
        delete msg;
    }
}


}  // End namespace


