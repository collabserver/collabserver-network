#pragma once

#include <cstring> // size_t


namespace collab {

class MessageFactory;


/**
 * Component that listen for message comming over the network.
 * Message are handled by a message router.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageReceiver {
    private:
        bool m_isRunning;
        MessageFactory& m_messageFactory;

    public:
        MessageReceiver();
        ~MessageReceiver();

    public:
        /**
         * Start listening.
         *
         * \note
         * This function block until this component is stopped
         * from another thread.
         */
        void start();

        /**
         * Stop listening.
         */
        void stop();
};


} // End namespace
