#include "collabcommon/msg/MsgDebug.h"

#include <msgpack.hpp>

#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


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

void MsgDebug::setcontent(const std::string& str) {
    _content = str;
}

const std::string& MsgDebug::content() const {
    return _content;
}


} // End namespace


