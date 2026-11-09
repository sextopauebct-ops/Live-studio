#include "live_studio/LiveStudioApp.h"

#include <iostream>

int main() {
    live_studio::LiveStudioApp app;

    if (!app.initialize()) {
        std::cerr << "Live Studio initialization failed." << std::endl;
        return 1;
    }

    app.settings().setConnectionTarget("192.168.1.10", 8080);
    app.settings().setStreamUrl("rtmp://ingest.example.com/live/stream");
    app.settings().setStreamProtocol("RTMP");
    app.settings().setCameraPosition(32, 32);
    app.settings().setCameraScale(100, 100);
    app.settings().setQuality(75);

    std::cout << "Live Studio starting" << std::endl;
    std::cout << "Status: " << app.statusText() << std::endl;
    std::cout << "Connection: " << app.connectionText() << std::endl;
    std::cout << "Camera: " << app.cameraText() << std::endl;

    const bool started = app.startTransmission();
    std::cout << "Transmission started: " << (started ? "yes" : "no") << std::endl;
    std::cout << "Stream: " << app.streamText() << std::endl;
    std::cout << "Status: " << app.statusText() << std::endl;

    app.stopTransmission();
    std::cout << "Transmission stopped." << std::endl;

    return 0;
}
