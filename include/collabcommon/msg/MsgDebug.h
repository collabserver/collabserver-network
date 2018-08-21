#pragma once

#include <string>

#include "collabcommon/messaging/Message.h"

namespace collab {


/**
 * \brief
 * Message for debug purpose
 */
class MsgDebug : public Message {
    private:
        std::string _content;
    public:
        bool serialize(std::stringstream& buffer) const override;
        bool unserialize(std::stringstream& buffer) override;
        int getType() const override;

    public:
        void setcontent(const std::string& str);
        const std::string& content() const;
};


} // End namespace


