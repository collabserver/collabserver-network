#include "collabcommon/network/Network.h"

#include <zmq.hpp>

namespace collab {
namespace network {


bool initNetwork() {
    if(isNetworkInit()) {
        return false;
    }
    g_context = new zmq::context_t(1);
    return true;;
}

void shutdownNetwork() {
    if(isNetworkInit()) {
        delete g_context;
    }
}

bool isNetworkInit() {
    return g_context != nullptr;
}


}} // End namespaces


