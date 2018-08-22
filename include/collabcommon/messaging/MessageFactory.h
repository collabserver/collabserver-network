#pragma once

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

            MSG_CREA_DATA_VOLATILE_REQ, // Create new volatile data room

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
         * \warning
         * Message must be free manually
         *
         * \param type  ID of the message type to create.
         * \return      Smart pointer to the new created Message.
         */
        Message* newMessage(const int type) const;

        /**
         * Free the message previously created by the factory.
         *
         * \param msg Message to free
         */
        void freeMessage(Message* msg) const;
};


} // End namespace


