#pragma once

#include <msgpack.hpp>

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


class MsgError : public Message {
    private:
        int _errorID;

    public:
        bool serialize(std::stringstream& buffer) const override {
            msgpack::pack(buffer, _errorID);
            return true;
        }

        bool unserialize(std::stringstream& buffer) override {
            const char* data    = buffer.str().data();
            const size_t size   = buffer.str().size();

            msgpack::unpacked r1;
            msgpack::unpack(r1, data, size);
            r1.get().convert(_errorID);

            return true;
        }

        int getType() const override {
            return MessageFactory::MSG_ERROR;
        }

    public:
        void setErrorID(const int id) {
            _errorID = id;
        }

        int errorID() const {
            return _errorID;
        }
};


} // End namespace



