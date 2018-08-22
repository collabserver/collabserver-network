#include "collabcommon/messaging/MessageList.h"

#include <sstream>
#include <msgpack.hpp>

namespace collab {


// -----------------------------------------------------------------------------
// Connection Messages
// -----------------------------------------------------------------------------

bool MsgConnectionRequest::serialize(std::stringstream& buffer) const {
    return true;
}

bool MsgConnectionRequest::unserialize(std::stringstream& buffer) {
    return true;
}

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

bool MsgDisconnectRequest::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _userID);
    return true;
}

bool MsgDisconnectRequest::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();

    msgpack::unpacked r1;
    msgpack::unpack(r1, data, size);
    r1.get().convert(_userID);

    return true;
}

bool MsgDisconnectSuccess::serialize(std::stringstream& buffer) const {
    return true;
}

bool MsgDisconnectSuccess::unserialize(std::stringstream& buffer) {
    return true;
}


// -----------------------------------------------------------------------------
// Data Messages
// -----------------------------------------------------------------------------

bool MsgCreaDataVolatileRequest::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _userID);
    msgpack::pack(buffer, _dataTypeID);
    return true;
}

bool MsgCreaDataVolatileRequest::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();
    std::size_t off     = 0;

    msgpack::unpacked r1;
    msgpack::unpacked r2;

    msgpack::unpack(r1, data, size, off);
    msgpack::unpack(r2, data, size, off);

    r1.get().convert(_userID);
    r2.get().convert(_dataTypeID);

    return true;
}

bool MsgCreaDataVolatileSuccess::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _dataID);
    return true;
}

bool MsgCreaDataVolatileSuccess::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();

    msgpack::unpacked r1;
    msgpack::unpack(r1, data, size);
    r1.get().convert(_dataID);

    return true;
}

bool MsgJoinDataRequest::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _userID);
    msgpack::pack(buffer, _dataID);
    return true;
}

bool MsgJoinDataRequest::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();
    std::size_t off     = 0;

    msgpack::unpacked r1;
    msgpack::unpacked r2;

    msgpack::unpack(r1, data, size, off);
    msgpack::unpack(r2, data, size, off);

    r1.get().convert(_userID);
    r2.get().convert(_dataID);

    return true;
}

bool MsgJoinDataSuccess::serialize(std::stringstream& buffer) const {
    return true;
}

bool MsgJoinDataSuccess::unserialize(std::stringstream& buffer) {
    return true;
}

bool MsgLeaveDataRequest::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _userID);
    msgpack::pack(buffer, _dataID);
    return true;
}

bool MsgLeaveDataRequest::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();
    std::size_t off     = 0;

    msgpack::unpacked r1;
    msgpack::unpacked r2;

    msgpack::unpack(r1, data, size, off);
    msgpack::unpack(r2, data, size, off);

    r1.get().convert(_userID);
    r2.get().convert(_dataID);

    return true;
}

bool MsgLeaveDataSuccess::serialize(std::stringstream& buffer) const {
    return true;
}

bool MsgLeaveDataSuccess::unserialize(std::stringstream& buffer) {
    return true;
}


// -----------------------------------------------------------------------------
// Various / Debug / Error Messages
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


} // End namespace


