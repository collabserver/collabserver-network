#pragma once

#include <memory> // std::unique_ptr

#include "collabcommon/utils/Singleton.h"

namespace collab {


class Message;


/**
 * Factory for messages.
 * Each message has a special ID.
 * Factory may return the specific message implementation from its ID.
 */
class MessageFactory : private Singleton<MessageFactory> {
    // -------------------------------------------------------------------------
    // Message types
    // -------------------------------------------------------------------------
    public:
        enum Type : int {
            MSG_DEBUG,              // Simple msg for debug and test
            MSG_ROOM_OPERATION,     // Msg with an operation in a room


            // Internal use (TO KEEP LAST).
            // Has the total number of defined messages
            _COUNTER
        };


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------

    private:
        friend Singleton<MessageFactory>;
    public:
        using Singleton<MessageFactory>::getInstance;
    protected:
        MessageFactory() = default;
        ~MessageFactory() = default;


    // -------------------------------------------------------------------------
    // Factory methods
    // -------------------------------------------------------------------------

    public:

        /**
         * Create a new concrete message from its ID.
         * If ID is not valid, nullptr is returned.
         *
         * \param type  ID of the message type to create.
         * \return      Smart pointer to the new created Message.
         */
        std::unique_ptr<Message> newMessage(const int type) const;
};


} // End namespace


