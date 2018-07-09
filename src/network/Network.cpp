#include "collabcommon/network/Network.h"

namespace collab {
namespace network {


static bool _isNetworkInit = false;


bool initializeNetwork() {
    if(_isNetworkInit) {
        return false;
    }
    _isNetworkInit = true;
    return true;;
}

void shutdownNetwork() {
    _isNetworkInit = false;
}

bool isNetworkInitialized() {
    return _isNetworkInit;
}


}} // End namespaces


