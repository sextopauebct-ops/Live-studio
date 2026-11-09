#include "live_studio/Managers.h"

namespace live_studio {

CameraManager::CameraManager() = default;

bool CameraManager::start() {
    m_connected = true;
    return true;
}

bool CameraManager::stop() {
    m_connected = false;
    m_cameraConnected = false;
    return true;
}

bool CameraManager::connectToSource(const std::string& ip, uint16_t port) {
    m_ip = ip;
    m_port = port;
    m_connected = true;
    m_cameraConnected = true;
    return true;
}

bool CameraManager::disconnect() {
    m_connected = false;
    m_cameraConnected = false;
    return true;
}

bool CameraManager::isConnected() const { return m_connected && m_cameraConnected; }

std::string CameraManager::previewStatus() const {
    return m_cameraConnected ? "Camera online" : "Camera offline";
}

void CameraManager::updateConnectionState(bool connected, bool cameraConnected) {
    m_connected = connected;
    m_cameraConnected = cameraConnected;
}

} // namespace live_studio
