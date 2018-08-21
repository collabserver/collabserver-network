#pragma once

#include "collabcommon/messaging/Message.h"

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
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override;
};


} // End namespace


