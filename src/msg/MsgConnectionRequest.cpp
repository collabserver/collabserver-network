#include "collabcommon/msg/MsgConnectionRequest.h"

#include <msgpack.hpp>
#include <sstream>

#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


bool MsgConnectionRequest::serialize(std::stringstream& buffer) const {
    return true;
}

bool MsgConnectionRequest::unserialize(std::stringstream& buffer) {
    return true;
}

int MsgConnectionRequest::getType() const {
    return MessageFactory::MSG_CONNECTION_REQ;
}


} // End namespace


