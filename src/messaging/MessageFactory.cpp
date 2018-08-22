#include "collabcommon/messaging/MessageFactory.h"

#include <cassert>

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageList.h"

namespace collab {


Message* MessageFactory::newMessage(const int type) const {
    switch(type) {
        // Connection
        case MSG_CONNECTION_REQUEST:
            return new MsgConnectionRequest();
        case MSG_CONNECTION_SUCCESS:
            return new MsgConnectionSuccess();
        case MSG_DISCONNECT_REQUEST:
            return new MsgDisconnectRequest();
        case MSG_DISCONNECT_SUCCESS:
            return new MsgDisconnectSuccess();

        // Data
        case MSG_CREA_DATA_VOLATILE_REQUEST:
            return new MsgCreaDataVolatileRequest();
        case MSG_CREA_DATA_VOLATILE_SUCCESS:
            return new MsgCreaDataVolatileSuccess();
        case MSG_JOIN_DATA_REQUEST:
            return new MsgJoinDataRequest();
        case MSG_JOIN_DATA_SUCCESS:
            return new MsgJoinDataSuccess();
        case MSG_LEAVE_DATA_REQUEST:
            return new MsgLeaveDataRequest();
        case MSG_LEAVE_DATA_SUCCESS:
            return new MsgLeaveDataSuccess();

        // Various
        case MSG_ERROR:
            return new MsgError();
        case MSG_DEBUG:
            return new MsgDebug();

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


