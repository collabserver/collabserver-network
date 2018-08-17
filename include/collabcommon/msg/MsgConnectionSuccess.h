#pragma once

#include <msgpack.hpp>

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


/**
 * \brief
 * Response from Connection Request
 *
 * Server has successfully added a new user.
 * This message gives the created ID.
 */
class MsgConnectionSuccess : public Message {
    private:
        int _userID; // ID the server gave to the user just connected.

    public:
        bool serialize(std::stringstream& buffer) const override {
            msgpack::pack(buffer, _userID);
            return true;
        }

        bool unserialize(std::stringstream& buffer) override {
            const char* data    = buffer.str().data();
            const size_t size   = buffer.str().size();

            msgpack::unpacked r1;
            msgpack::unpack(r1, data, size);
            r1.get().convert(_userID);

            return true;
        }

        int getType() const override {
            return MessageFactory::MSG_CONNECTION_SUCCESS;
        }

    public:
        void setUserID(const int id) {
            _userID = id;
        }

        int userID() const {
            return _userID;
        }
};


} // End namespace


