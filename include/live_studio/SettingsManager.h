#pragma once

#include <cstdint>
#include <string>

namespace live_studio {

class SettingsManager {
public:
    SettingsManager();
    void setCameraEnabled(bool enabled);
    void setResolution(int width, int height);
    void setCameraPosition(int x, int y);
    void setCameraScale(int scaleX, int scaleY);
    void setQuality(int quality);
    void setStreamUrl(const std::string& url);
    void setStreamProtocol(const std::string& protocol);
    void setConnectionTarget(const std::string& ip, uint16_t port);
    void setAutoReconnect(bool enabled);

    bool cameraEnabled() const;
    int width() const;
    int height() const;
    int positionX() const;
    int positionY() const;
    int scaleX() const;
    int scaleY() const;
    int quality() const;
    std::string streamUrl() const;
    std::string streamProtocol() const;
    std::string connectionIp() const;
    uint16_t connectionPort() const;
    bool autoReconnect() const;

private:
    bool m_cameraEnabled = true;
    int m_width = 1280;
    int m_height = 720;
    int m_x = 32;
    int m_y = 32;
    int m_scaleX = 100;
    int m_scaleY = 100;
    int m_quality = 75;
    std::string m_streamUrl;
    std::string m_streamProtocol = "RTMP";
    std::string m_ip = "192.168.1.10";
    uint16_t m_port = 8080;
    bool m_autoReconnect = true;
};

} // namespace live_studio
