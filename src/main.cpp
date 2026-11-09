#include "live_studio/LiveStudioApp.h"

#include <iostream>

int main() {
    live_studio::LiveStudioApp app;
    if (!app.initialize()) {
        std::cerr << "Live Studio initialization failed\n";
        return 1;
    }

    std::cout << "====================================\n"
              << " LIVE STUDIO | prototype dashboard\n"
              << "====================================\n"
              << "Status:     " << app.statusText() << '\n'
              << "Network:    " << app.connectionText() << '\n'
              << "iPhone:     " << app.cameraText() << '\n'
              << "Broadcast:  " << app.streamText() << "\n\n"
              << "This build is a host-side model only. Camera transport, video preview,\n"
              << "PS4 rendering, and live streaming are not implemented yet.\n";
    return 0;
}
