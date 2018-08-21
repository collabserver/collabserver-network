#pragma once

#include "collabcommon/messaging/Message.h"

namespace collab {


class MsgError : public Message {
    private:
        int _errorID;

    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override;

    public:
        void setErrorID(const int id);
        int errorID() const;
};


} // End namespace


