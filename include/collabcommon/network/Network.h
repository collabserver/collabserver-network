#pragma once

#include <zmq.hpp>

namespace collab {
namespace network {


static zmq::context_t g_context(1);


bool initNetwork();
void shutdownNetwork();
bool isNetworkInit();


}} // End namespaces


