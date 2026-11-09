#include "live_studio/LiveStudioApp.h"

namespace live_studio {

LiveStudioApp::LiveStudioApp() = default;

bool LiveStudioApp::initialize() {
    m_initialized = true;
    return true;
}

bool LiveStudioApp::startTransmission() {
    if (!m_initialized) {
        return false;
    }

    const bool cameraOk = m_camera.connectToSource(m_settings.connectionIp(), m_settings.connectionPort());
    const bool networkOk = m_network.connect(m_settings.connectionIp(), m_settings.connectionPort());
    const bool streamOk = m_streaming.start();

    m_transmitting = cameraOk && networkOk && streamOk;
    return m_transmitting;
}

bool LiveStudioApp::stopTransmission() {
    m_camera.disconnect();
    m_network.disconnect();
    m_streaming.stop();
    m_transmitting = false;
    return true;
}

void LiveStudioApp::update() {
    if (m_transmitting) {
        m_camera.updateConnectionState(true, true);
    }
}

std::string LiveStudioApp::statusText() const {
    if (!m_initialized) {
        return "Initializing";
    }
    return m_transmitting ? "Live Studio active" : "Ready";
}

std::string LiveStudioApp::connectionText() const {
    return m_network.statusText();
}

std::string LiveStudioApp::cameraText() const {
    return m_camera.previewStatus();
}

std::string LiveStudioApp::streamText() const {
    return m_streaming.statusText();
}

SettingsManager& LiveStudioApp::settings() { return m_settings; }
CameraManager& LiveStudioApp::camera() { return m_camera; }
NetworkManager& LiveStudioApp::network() { return m_network; }
StreamingManager& LiveStudioApp::streaming() { return m_streaming; }

} // namespace live_studio
