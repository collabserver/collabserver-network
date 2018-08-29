#include "collabcommon/messaging/MessageList.h"

#include <cassert>
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

bool MsgCreaDataRequest::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _userID);
    return true;
}

bool MsgCreaDataRequest::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();
    std::size_t off     = 0;

    msgpack::unpacked r1;
    msgpack::unpack(r1, data, size, off);
    r1.get().convert(_userID);

    return true;
}

bool MsgCreaDataSuccess::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _dataID);
    return true;
}

bool MsgCreaDataSuccess::unserialize(std::stringstream& buffer) {
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
    return true;
}

bool MsgLeaveDataRequest::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();
    std::size_t off     = 0;

    msgpack::unpacked r1;

    msgpack::unpack(r1, data, size, off);

    r1.get().convert(_userID);

    return true;
}

bool MsgLeaveDataSuccess::serialize(std::stringstream& buffer) const {
    return true;
}

bool MsgLeaveDataSuccess::unserialize(std::stringstream& buffer) {
    return true;
}


// -----------------------------------------------------------------------------
// Room
// -----------------------------------------------------------------------------

bool MsgRoomOperation::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _roomID);
    msgpack::pack(buffer, _userID);

    // TODO
    //assert(_operation != nullptr);
    //_operation->serialize(buffer);

    return true;
}

bool MsgRoomOperation::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();
    std::size_t off     = 0;

    msgpack::unpacked r1;
    msgpack::unpacked r2;

    msgpack::unpack(r1, data, size, off);
    msgpack::unpack(r2, data, size, off);

    r1.get().convert(_roomID);
    r2.get().convert(_userID);

    // TODO Set the new buffer that has only the operation buffer

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

bool MsgUgly::serialize(std::stringstream& buffer) const {
    msgpack::pack(buffer, _response);
    return true;
}

bool MsgUgly::unserialize(std::stringstream& buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();

    msgpack::unpacked r1;
    msgpack::unpack(r1, data, size);
    r1.get().convert(_response);

    return true;
}

bool MsgEmpty::serialize(std::stringstream& buffer) const {
    return true;
}

bool MsgEmpty::unserialize(std::stringstream& buffer) {
    return true;
}


} // End namespace


