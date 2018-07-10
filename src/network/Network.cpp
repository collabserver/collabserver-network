#include "collabcommon/network/Network.h"

namespace collab {
namespace network {


static bool _isInit = false;


bool initNetwork() {
    if(isNetworkInit()) {
        return false;
    }
    _isInit = true;
    return true;;
}

void shutdownNetwork() {
    if(isNetworkInit()) {
        _isInit = false;
    }
}

bool isNetworkInit() {
    return _isInit;
}


}} // End namespaces


