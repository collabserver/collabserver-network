#include "collabcommon/network/Network.h"

namespace collab {
namespace network {


static bool _isNetworkInit = false;


bool initializeNetwork() {
    return false;
}

void shutdownNetwork() {
}

bool isNetworkInitialized() {
    return _isNetworkInit;
}


}} // End namespaces


