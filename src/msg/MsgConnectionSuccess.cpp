#include "collabcommon/msg/MsgConnectionSuccess.h"

#include <sstream>
#include <msgpack.hpp>

#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


bool MsgConnectionSuccess::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _userID);
    return true;
}

bool MsgConnectionSuccess::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();

    msgpack::unpacked r1;
    msgpack::unpack(r1, data, size);
    r1.get().convert(_userID);

    return true;
}

int MsgConnectionSuccess::getType() const {
    return MessageFactory::MSG_CONNECTION_SUCCESS;
}

void MsgConnectionSuccess::setUserID(const int id) {
    _userID = id;
}

int MsgConnectionSuccess::userID() const {
    return _userID;
}


} // End namespace


