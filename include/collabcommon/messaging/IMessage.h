#pragma once

#include <sstream>

#include "MessageTypes.h"

namespace collab {


/**
 * Interface for network Messages.
 */
class IMessage {
    protected:
        IMessage() = default;
    public:
        virtual ~IMessage() = default;


    public:

        /**
         * Serialize the message in internal packed format.
         *
         * \param buffer Where to place serialized data.
         * \return True if successfully serialized, otherwise, return false.
         */
        virtual bool serialize(std::stringstream & buffer) const = 0;

        /**
         * Unserialize the message from its internal packed format.
         *
         * \param buffer Where to place unserialized data.
         * \return True if successfully unserialized, otherwise, return false.
         */
        virtual bool unserialize(std::stringstream & buffer) = 0;

        /**
         * Apply the event registered for this message.
         * This is usually the function to call whenever message is received.
         */
        virtual void apply() = 0;

        /**
         * Get the message type ID. (From enum).
         *
         * \return Type of the message.
         */
        virtual MessageTypes getType() const = 0;
};


} // End namespace


