#pragma once

#include <string>
#include <memory> // std::unique_ptr
#include <cstdint>

namespace zmq { class context_t; class socket_t; }

namespace collab {


class MessageFactory;
class Message;


struct ZMQSocketConfig {
    int             zmqPattern;
    zmq::context_t* zmqContext;
    MessageFactory* factory;
};


/**
 * \brief
 * Abstraction of a ZeroMQ socket.
 */
class ZMQSocket {
    private:
        zmq::context_t*     _context;
        zmq::socket_t*      _socket;
        MessageFactory*     _factory;
        std::string         _address;
        uint16_t            _port;

    public:

        ZMQSocket(ZMQSocketConfig& config);
        ~ZMQSocket();

    public:

        // ---------------------------------------------------------------------
        // Connection / Binding
        // ---------------------------------------------------------------------

        /**
         * Set socket port/address and start to accept incoming connections.
         * Common bind address may be simply "*" for instance.
         *
         * \see http://api.zeromq.org/3-2:zmq-bind
         * \param address   Address to be bound with the socket.
         * \param port      Port accepting connections.
         */
        void bind(const char* address, const uint16_t port);

        /**
         * Stop accepting connections on this socket.
         * bind should have been called first.
         *
         * \see http://api.zeromq.org/3-2:zmq-unbind
         */
        void unbind();

        /**
         * Create outgoing connection from this socket.
         *
         * \see http://api.zeromq.org/3-2:zmq-connect
         * \param address   Address to connect.
         * \param port      Port to connect the distant address.
         */
        void connect(const char* address, const uint16_t port);

        /**
         * Disconnect this socket.
         *
         * \see http://api.zeromq.org/3-2:zmq-disconnect
         */
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
        void sendMessage(const Message& msg);

        /**
         * Wait until receive a message from this socket.
         * This is blocking until a message is received.
         *
         * \return Received message.
         */
        std::unique_ptr<Message> receiveMessage();
};


} // End namespace


