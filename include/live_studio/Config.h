#pragma once

#include <string>
#include <cstdint>

namespace live_studio {

struct CameraConfig {
    bool enabled = true;
    int width = 1280;
    int height = 720;
    int x = 32;
    int y = 32;
    int scaleX = 100;
    int scaleY = 100;
    int quality = 75;
};

struct ConnectionConfig {
    bool connected = false;
    bool cameraConnected = false;
    std::string ip = "192.168.1.10";
    uint16_t port = 8080;
    std::string lastError;
};

struct StreamingConfig {
    bool enabled = false;
    std::string ingestUrl = "rtmp://ingest.example.com/live/stream";
    std::string protocol = "RTMP";
    bool autoReconnect = true;
};

} // namespace live_studio
