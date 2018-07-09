#pragma once

namespace zmq { class context_t; }

namespace collab {
namespace network {


static zmq::context_t* g_context = nullptr;


bool initNetwork();
void shutdownNetwork();
bool isNetworkInit();


}} // End namespaces


