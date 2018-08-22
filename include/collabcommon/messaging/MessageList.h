#pragma once

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


class MsgConnectionRequest : public Message {
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override {
            return MessageFactory::MSG_CONNECTION_REQ;
        }
};

class MsgConnectionSuccess : public Message {
    private:
        int _userID; // ID the server gave to the user just connected.
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        void setUserID(const int id) { _userID = id; }
        int getUserID() const { return _userID; }
        int getType() const override {
            return MessageFactory::MSG_CONNECTION_SUCCESS;
        }
};

class MsgDebug : public Message {
    private:
        std::string _content;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        void setContent(const std::string& str) { _content = str; }
        const std::string& getContent() const { return _content; }
        int getType() const override {
            return MessageFactory::MSG_DEBUG;
        }
};

class MsgError : public Message {
    private:
        int _errorID;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        void setErrorID(const int id) { _errorID = id; }
        int getErrorID() const { return _errorID; }
        int getType() const override {
            return MessageFactory::MSG_ERROR;
        }
};


} // End namespace


