#pragma once

#include "live_studio/SettingsManager.h"
#include "live_studio/Managers.h"

namespace live_studio {

class LiveStudioApp {
public:
    LiveStudioApp();

    bool initialize();
    bool startTransmission();
    bool stopTransmission();
    void update();
    std::string statusText() const;
    std::string connectionText() const;
    std::string cameraText() const;
    std::string streamText() const;

    SettingsManager& settings();
    CameraManager& camera();
    NetworkManager& network();
    StreamingManager& streaming();

private:
    SettingsManager m_settings;
    CameraManager m_camera;
    NetworkManager m_network;
    StreamingManager m_streaming;
    bool m_initialized = false;
    bool m_transmitting = false;
};

} // namespace live_studio
