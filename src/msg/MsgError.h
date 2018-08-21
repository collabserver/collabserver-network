#include "collabcommon/msg/MsgError.h"

#include <msgpack.hpp>

#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


bool MsgError::serialize(std::stringstream& buffer) const override {
    msgpack::pack(buffer, _errorID);
    return true;
}

bool MsgError::unserialize(std::stringstream& buffer) override {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();

    msgpack::unpacked r1;
    msgpack::unpack(r1, data, size);
    r1.get().convert(_errorID);

    return true;
}

int MsgError::getType() const override {
    return MessageFactory::MSG_ERROR;
}

void MsgError::setErrorID(const int id) {
    _errorID = id;
}

int MsgError::errorID() const {
    return _errorID;
}


} // End namespace


