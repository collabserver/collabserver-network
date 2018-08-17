#pragma once

#include <msgpack.hpp>

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


class MsgRoomOperation : public Message {
    private:
        int roomID;
        int userID;

    public:
        bool serialize(std::stringstream& buffer) const override {
            // TODO
            return false;
        }

        bool unserialize(std::stringstream& buffer) override {
            // TODO
            return false;
        }

        int getType() const override {
            return MessageFactory::MSG_ROOM_OPERATION;
        }
};


} // End namespace


