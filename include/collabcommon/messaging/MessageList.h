#pragma once

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


// -----------------------------------------------------------------------------
// Connection Messages
// -----------------------------------------------------------------------------

class MsgConnectionRequest : public Message {
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override {
            return MessageFactory::MSG_CONNECTION_REQUEST;
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

class MsgDisconnectRequest : public Message {
    private:
        int _userID; // ID the server gave to the user just connected.
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        void setUserID(const int id) { _userID = id; }
        int getUserID() const { return _userID; }
        int getType() const override {
            return MessageFactory::MSG_DISCONNECT_REQUEST;
        }
};

class MsgDisconnectSuccess : public Message {
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override {
            return MessageFactory::MSG_DISCONNECT_SUCCESS;
        }
};


// -----------------------------------------------------------------------------
// Data Messages
// -----------------------------------------------------------------------------

class MsgCreaDataVolatileRequest : public Message {
    private:
        int _userID;
        int _dataTypeID;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        void setUserID(const int id) { _userID = id; }
        void setDataTypeID(const int id) { _dataTypeID = id; }
        int getUserID() const { return _userID; }
        int getDataTypeID() const { return _dataTypeID; }
        int getType() const override {
            return MessageFactory::MSG_CREA_DATA_VOLATILE_REQUEST;
        }
};

class MsgCreaDataVolatileSuccess : public Message {
    private:
        int _dataID;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        void setDataID(const int id) { _dataID = id; }
        int getDataID() const { return _dataID; }
        int getType() const override {
            return MessageFactory::MSG_CREA_DATA_VOLATILE_SUCCESS;
        }
};

class MsgJoinDataRequest : public Message {
    private:
        int _userID;
        int _dataID;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        void setUserID(const int id) { _userID = id; }
        void setDataID(const int id) { _dataID = id; }
        int getUserID() const { return _userID; }
        int getDataID() const { return _dataID; }
        int getType() const override {
            return MessageFactory::MSG_JOIN_DATA_REQUEST;
        }
};

class MsgJoinDataSuccess : public Message {
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override {
            return MessageFactory::MSG_JOIN_DATA_SUCCESS;
        }
};

class MsgLeaveDataRequest : public Message {
    private:
        int _userID;
        int _dataID;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        void setUserID(const int id) { _userID = id; }
        void setDataID(const int id) { _dataID = id; }
        int getUserID() const { return _userID; }
        int getDataID() const { return _dataID; }
        int getType() const override {
            return MessageFactory::MSG_LEAVE_DATA_REQUEST;
        }
};

class MsgLeaveDataSuccess : public Message {
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override {
            return MessageFactory::MSG_LEAVE_DATA_SUCCESS;
        }
};


// -----------------------------------------------------------------------------
// Various / Debug / Error Messages
// -----------------------------------------------------------------------------

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


