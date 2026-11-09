#include "live_studio/Managers.h"

namespace live_studio {

bool CameraManager::start() {
    // Camera transport and video decoding are not implemented yet.
    m_connected = false;
    return false;
}

bool CameraManager::stop() {
    m_connected = false;
    return true;
}

bool CameraManager::connectToSource(const std::string& ip, uint16_t port) {
    (void)ip;
    (void)port;
    // Do not report a camera connection until a real transport succeeds.
    m_connected = false;
    return false;
}

bool CameraManager::disconnect() {
    m_connected = false;
    return true;
}

bool CameraManager::isConnected() const { return m_connected; }

std::string CameraManager::previewStatus() const {
    return m_connected ? "Connected (preview unavailable)" : "Not connected (transport pending)";
}

} // namespace live_studio
