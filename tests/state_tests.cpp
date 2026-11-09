#include "live_studio/LiveStudioApp.h"

#include <cassert>

int main() {
    live_studio::LiveStudioApp app;
    assert(app.statusText() == "Initializing");
    assert(app.initialize());
    assert(app.statusText() == "Ready (prototype)");
    assert(!app.startTransmission());
    assert(!app.streaming().isStreaming());

    app.settings().setQuality(120);
    assert(app.settings().quality() == 100);
    app.settings().setResolution(1, 9000);
    assert(app.settings().width() == 160);
    assert(app.settings().height() == 2160);
    return 0;
}
