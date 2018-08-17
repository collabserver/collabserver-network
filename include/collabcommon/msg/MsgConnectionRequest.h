#pragma once

#include <msgpack.hpp>

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


/**
 * \brief
 * User request connection to the server
 *
 * This add a new user in the server (If possible).
 * Server will respond with connection success, which gives to the user its ID.
 */
class MsgConnectionRequest : public Message {
    public:
        bool serialize(std::stringstream& buffer) const override {
            return true;
        }

        bool unserialize(std::stringstream& buffer) override {
            return true;
        }

        int getType() const override {
            return MessageFactory::MSG_CONNECTION_REQ;
        }
};


} // End namespace


