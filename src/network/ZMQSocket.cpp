#include "collabcommon/network/ZMQSocket.h"

#include <cassert>
#include <sstream>
#include <zmq.hpp>

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/messaging/Message.h"
#include "collabcommon/network/Network.h"

namespace collab {


// -----------------------------------------------------------------------------
// Init
// -----------------------------------------------------------------------------

ZMQSocket::ZMQSocket(ZMQSocketConfig& config) {
    _context = config.zmqContext;
    _factory = config.factory;
    assert(_context != nullptr);
    assert(_factory != nullptr);
    _socket = new zmq::socket_t(*_context, config.zmqPattern);
    assert(_socket != nullptr);
}

ZMQSocket::~ZMQSocket() {
    delete _socket;
}


// -----------------------------------------------------------------------------
// Connection / Binding
// -----------------------------------------------------------------------------

void ZMQSocket::bind(const char* address, const uint16_t port) {
    std::stringstream endpoint;
    endpoint << "tcp://" << address << ":" << port;
    _socket->bind(endpoint.str());
    _address = address;
    _port = port;
}

void ZMQSocket::unbind() {
    std::stringstream endpoint;
    endpoint << "tcp://" << _address << ":" << _port;
    std::string endpoint_copy = endpoint.str();
    zmq_unbind(_socket, endpoint_copy.c_str()); // TODO TMP
    _address = "";
    _port = 0;
}

void ZMQSocket::connect(const char* address, const uint16_t port) {
    std::stringstream endpoint;
    endpoint << "tcp://" << address << ":" << port;
    _socket->connect(endpoint.str());
    _address = address;
    _port = port;
}

void ZMQSocket::disconnect() {
    std::stringstream endpoint;
    endpoint << "tcp://" << _address << ":" << _port;
    std::string endpoint_copy = endpoint.str();
    zmq_disconnect(_socket, endpoint_copy.c_str());
    _address = "";
    _port = 0;
}


// -----------------------------------------------------------------------------
// Message methods
// -----------------------------------------------------------------------------

// Internal use: calculate size of stream
static size_t _calculStreamSize(std::stringstream & stream) {
    // TODO: There might be a way better way to do that!
    stream.seekg(0, std::ios::end);
    const size_t size = stream.tellg();
    stream.seekg(0);
    return size;
}

void ZMQSocket::sendMessage(const Message& msg) {
    std::stringstream buffer;
    msg.serialize(buffer);

    const size_t msgSize = _calculStreamSize(buffer);
    const int    msgType = static_cast<int>(msg.getType());

    zmq::message_t request(msgSize + 1); // +1 for the msg type byte

    char* ptrBufferStart = static_cast<char*>(request.data()) + 1;

    memcpy(request.data(), &msgType, 1);
    memcpy(ptrBufferStart, buffer.str().c_str(), msgSize); 

    _socket->send(request);
}

std::unique_ptr<Message> ZMQSocket::receiveMessage() {
    zmq::message_t request_msg;
    _socket->recv(&request_msg);

    char*           msg     = static_cast<char*>(request_msg.data());
    const int       size    = request_msg.size();
    const int       msgType = static_cast<int>(msg[0]);
    const char*     msgData = msg + 1;
    const size_t    msgSize = size - 1;

    std::unique_ptr<Message> m = _factory->newMessage(msgType);
    assert(m != nullptr);
    if(m == nullptr) {
        return nullptr;
    }

    std::stringstream stream;
    stream.str(std::string(msgData, msgSize));
    m->unserialize(stream);
    return m;
}


} // End namespace


