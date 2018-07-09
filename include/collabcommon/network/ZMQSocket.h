#pragma once

#include <memory> // std::unique_ptr
#include <zmq.hpp>


namespace collab {

class MessageFactory;
class IMessage;

namespace network {


/**
 * ZeroMQ Socket.
 *
 * TODO Documentation
 */
class ZMQSocket {
    private:
        zmq::context_t*     _context;
        zmq::socket_t*      _socket;
        MessageFactory*     _factory;

    public:
        ZMQSocket(zmq::context_t& context, MessageFactory& factory);
        ~ZMQSocket();

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


}} // End namespace


