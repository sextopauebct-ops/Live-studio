#pragma once

#include <cstdint>
#include <string>

namespace live_studio {

class CameraManager {
public:
    bool start();
    bool stop();
    bool connectToSource(const std::string& ip, uint16_t port);
    bool disconnect();
    bool isConnected() const;
    std::string previewStatus() const;

private:
    bool m_connected = false;
};

class NetworkManager {
public:
    bool connect(const std::string& ip, uint16_t port);
    bool disconnect();
    bool isConnected() const;
    std::string statusText() const;

private:
    bool m_connected = false;
};

class StreamingManager {
public:
    bool start();
    bool stop();
    bool isStreaming() const;
    std::string statusText() const;
    void setStreamUrl(const std::string& url);

private:
    bool m_streaming = false;
    std::string m_streamUrl;
};

} // namespace live_studio
