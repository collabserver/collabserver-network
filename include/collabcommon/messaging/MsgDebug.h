#pragma once

#include <string>

#include "Message.h"
#include "MessageFactory.h"

namespace collab {


class MsgDebug : public Message {
    private:
        std::string _content; // Simple random content.

    public:
        bool serialize(std::stringstream& buffer) const override {
            // TODO This is temporary. Use msgpack instead
            buffer.str(_content);
            return false;
        }

        bool unserialize(std::stringstream& buffer) override {
            // TODO This is temporary. Use msgpack instead
            _content = buffer.str();
            return false;
        }

        int getType() const override {
            return MessageFactory::MSG_DEBUG;
        }
};


} // End namespace


