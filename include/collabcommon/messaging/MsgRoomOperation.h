#pragma once

#include <string>

#include "Message.h"
#include "MessageFactory.h"

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
            return MessageFactory::MSG_DEBUG;
        }
};


} // End namespace


