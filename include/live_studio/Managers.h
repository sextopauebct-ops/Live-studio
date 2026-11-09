#pragma once

#include <string>

namespace live_studio {

class CameraManager {
public:
    CameraManager();

    bool start();
    bool stop();
    bool connectToSource(const std::string& ip, uint16_t port);
    bool disconnect();
    bool isConnected() const;
    std::string previewStatus() const;
    void updateConnectionState(bool connected, bool cameraConnected);

private:
    bool m_connected = false;
    bool m_cameraConnected = false;
    std::string m_ip;
    uint16_t m_port = 0;
};

class NetworkManager {
public:
    NetworkManager();

    bool connect(const std::string& ip, uint16_t port);
    bool disconnect();
    bool isConnected() const;
    std::string statusText() const;

private:
    bool m_connected = false;
    std::string m_ip;
    uint16_t m_port = 0;
};

class StreamingManager {
public:
    StreamingManager();

    bool start();
    bool stop();
    bool isStreaming() const;
    std::string statusText() const;
    void setStreamUrl(const std::string& url);
    void setProtocol(const std::string& protocol);

private:
    bool m_streaming = false;
    std::string m_streamUrl;
    std::string m_protocol = "RTMP";
};

} // namespace live_studio
