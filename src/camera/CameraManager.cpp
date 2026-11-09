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

StreamingManager::StreamingManager() = default;

bool StreamingManager::start() {
    if (m_streamUrl.empty()) {
        return false;
    }
    m_streaming = true;
    return true;
}

bool StreamingManager::stop() {
    m_streaming = false;
    return true;
}

bool StreamingManager::isStreaming() const { return m_streaming; }

std::string StreamingManager::statusText() const {
    return m_streaming ? "Streaming" : "Idle";
}

void StreamingManager::setStreamUrl(const std::string& url) { m_streamUrl = url; }
void StreamingManager::setProtocol(const std::string& protocol) { m_protocol = protocol; }

} // namespace live_studio
