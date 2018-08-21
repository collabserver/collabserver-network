#include "collabcommon/messaging/MessageList.h"

#include <sstream>
#include <msgpack.hpp>

#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


// -----------------------------------------------------------------------------
// MsgConnectionRequest
// -----------------------------------------------------------------------------

bool MsgConnectionRequest::serialize(std::stringstream& buffer) const {
    return true;
}

bool MsgConnectionRequest::unserialize(std::stringstream& buffer) {
    return true;
}

int MsgConnectionRequest::getType() const {
    return MessageFactory::MSG_CONNECTION_REQ;
}


// -----------------------------------------------------------------------------
// MsgConnectionSuccess
// -----------------------------------------------------------------------------

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


// -----------------------------------------------------------------------------
// MsgDebug
// -----------------------------------------------------------------------------

bool MsgDebug::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _content);
    return true;
}

bool MsgDebug::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();

    msgpack::unpacked r1;
    msgpack::unpack(r1, data, size);
    r1.get().convert(_content);

    return true;
}

int MsgDebug::getType() const {
    return MessageFactory::MSG_DEBUG;
}


// -----------------------------------------------------------------------------
// MsgError
// -----------------------------------------------------------------------------

bool MsgError::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _errorID);
    return true;
}

bool MsgError::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();

    msgpack::unpacked r1;
    msgpack::unpack(r1, data, size);
    r1.get().convert(_errorID);

    return true;
}

int MsgError::getType() const {
    return MessageFactory::MSG_ERROR;
}


} // End namespace


