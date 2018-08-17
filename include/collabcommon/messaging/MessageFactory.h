#pragma once

#include <memory> // std::unique_ptr

#include "collabcommon/utils/Singleton.h"
#include "collabcommon/messaging/Message.h"

namespace collab {


/**
 * \brief
 * Factory for CollabServer messages.
 *
 * Each message has a special ID.
 * Factory may return the specific message implementation from its ID.
 */
class MessageFactory : private Singleton<MessageFactory> {
    // -------------------------------------------------------------------------
    // Message types
    // -------------------------------------------------------------------------
    public:
        enum Type : int {
            MSG_CONNECTION_REQ,         // User connect to server (Request)
            MSG_CONNECTION_SUCCESS,     // Server accept user connection

            MSG_ROOM_OPERATION,         // Msg with an operation in a room

            MSG_ERROR,                  // Any error msg (Using error ID)
            MSG_DEBUG,                  // Simple msg for debug and test

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


