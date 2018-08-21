#pragma once

#include "collabcommon/messaging/Message.h"


namespace collab {


class MsgConnectionRequest : public Message {
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override;
};

class MsgConnectionSuccess : public Message {
    private:
        int _userID; // ID the server gave to the user just connected.
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override;
        void setUserID(const int id) { _userID = id; }
        int userID() const { return _userID; }
};

class MsgDebug : public Message {
    private:
        std::string _content;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override;
        void setcontent(const std::string& str) { _content = str; }
        const std::string& content() const { return _content; }
};

class MsgError : public Message {
    private:
        int _errorID;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override;
        void setErrorID(const int id) { _errorID = id; }
        int errorID() const { return _errorID; }
};


} // End namespace


