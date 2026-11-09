#include "live_studio/Managers.h"

namespace live_studio {

StreamingManager::StreamingManager() = default;

bool StreamingManager::start() {
    if (m_streamUrl.empty()) {
        return false;
    }
    m_streaming = true;
    return true;
}

bool StreamingManager::stop() {
    m_streaming = false;
    return true;
}

bool StreamingManager::isStreaming() const { return m_streaming; }

std::string StreamingManager::statusText() const {
    return m_streaming ? "Streaming" : "Idle";
}

void StreamingManager::setStreamUrl(const std::string& url) { m_streamUrl = url; }
void StreamingManager::setProtocol(const std::string& protocol) { m_protocol = protocol; }

} // namespace live_studio
