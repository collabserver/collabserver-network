#pragma once

#include "collabcommon/messaging/Message.h"

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
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override;

    public:
        void setUserID(const int id);
        int userID() const;
};


} // End namespace


