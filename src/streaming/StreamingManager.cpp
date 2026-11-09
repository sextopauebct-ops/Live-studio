#include "live_studio/Managers.h"

namespace live_studio {

NetworkManager::NetworkManager() = default;

bool NetworkManager::connect(const std::string& ip, uint16_t port) {
    m_ip = ip;
    m_port = port;
    m_connected = true;
    return true;
}

bool NetworkManager::disconnect() {
    m_connected = false;
    return true;
}

bool NetworkManager::isConnected() const { return m_connected; }

std::string NetworkManager::statusText() const {
    return m_connected ? "Connected" : "Disconnected";
}

} // namespace live_studio
