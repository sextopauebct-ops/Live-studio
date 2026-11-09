#include "live_studio/Managers.h"

namespace live_studio {

bool StreamingManager::start() {
    // RTMP encoding/transport has not been implemented; do not claim a live stream.
    m_streaming = false;
    return false;
}

bool StreamingManager::stop() {
    m_streaming = false;
    return true;
}

bool StreamingManager::isStreaming() const { return m_streaming; }

std::string StreamingManager::statusText() const {
    return m_streaming ? "Streaming" : "Idle (streaming backend pending)";
}

void StreamingManager::setStreamUrl(const std::string& url) { m_streamUrl = url; }

} // namespace live_studio
