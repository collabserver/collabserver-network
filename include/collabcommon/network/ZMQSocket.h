#pragma once

#include <string>
#include <memory> // std::unique_ptr
#include <cstdint>

namespace zmq { class context_t; class socket_t; }

namespace collab {


class MessageFactory;
class IMessage;


struct ZMQSocketConfig {
    int             zmqPattern;
    zmq::context_t* zmqContext;
    MessageFactory* factory;
};


/**
 * ZeroMQ Socket.
 * TODO Documentation
 */
class ZMQSocket {
    private:
        zmq::context_t*     _context;
        zmq::socket_t*      _socket;
        MessageFactory*     _factory;
        std::string         _hostname;
        uint16_t            _port;

    public:

        ZMQSocket(ZMQSocketConfig& config);
        ~ZMQSocket();

    public:

        // ---------------------------------------------------------------------
        // Connection / Binding
        // ---------------------------------------------------------------------

        void bind(const char* hostname, const uint16_t port);

        void unbind();

        void connect(const char* hostname, const uint16_t port);

        void disconnect();


        // ---------------------------------------------------------------------
        // Message methods
        // ---------------------------------------------------------------------

        /**
         * Send a message on this socket transport.
         * Block until message is sent.
         *
         * \param msg The message to send.
         */
        void sendMessage(const IMessage& msg);

        /**
         * Wait until receive a message from this socket.
         * This is blocking.
         */
        std::unique_ptr<IMessage> receiveMessage();
};


} // End namespace


