#include "collabcommon/network/ZMQSocket.h"

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/messaging/IMessage.h"

namespace collab {
namespace network {


ZMQSocket::ZMQSocket(zmq::context_t& context, MessageFactory& factory) {
    _context = &context;
    _factory = &factory;
    _socket = new zmq::socket_t(*_context, ZMQ_REP); // TODO tmp
}

ZMQSocket::~ZMQSocket() {
    delete _socket;
}

// Internal use. Get size of stream
static size_t _calculStreamSize(std::stringstream & stream) {
    // TODO: There might be a better way to do that!
    stream.seekg(0, std::ios::end);
    const size_t size = stream.tellg();
    stream.seekg(0);
    return size;
}

void ZMQSocket::sendMessage(const IMessage& msg) {
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

std::unique_ptr<IMessage> ZMQSocket::receiveMessage() {
    zmq::message_t request_msg;
    _socket->recv(&request_msg);

    char*           msg     = static_cast<char*>(request_msg.data());
    const int       size    = request_msg.size();
    const int       msgType = static_cast<int>(msg[0]);
    const char*     msgData = msg + 1;
    const size_t    msgSize = size - 1;

    MessageTypes    type    = static_cast<MessageTypes>(msgType);
    std::unique_ptr<IMessage> m = _factory->newMessage(type);
    assert(m != nullptr);
    if(m == nullptr) {
        return nullptr;
    }

    std::stringstream stream;
    stream.str(std::string(msgData, msgSize));
    m->unserialize(stream);
    return m;
}


}} // End namespace


