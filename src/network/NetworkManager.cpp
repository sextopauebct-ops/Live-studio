#include "live_studio/Managers.h"

namespace live_studio {

bool NetworkManager::connect(const std::string& ip, uint16_t port) {
    (void)ip;
    (void)port;
    // A configured address is not proof of network connectivity.
    m_connected = false;
    return false;
}

bool NetworkManager::disconnect() {
    m_connected = false;
    return true;
}

bool NetworkManager::isConnected() const { return m_connected; }

std::string NetworkManager::statusText() const {
    return m_connected ? "Connected" : "Not connected (network probe pending)";
}

} // namespace live_studio
