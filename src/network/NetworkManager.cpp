#include "live_studio/Managers.h"

#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <poll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace live_studio {

bool NetworkManager::connect(const std::string& ip, uint16_t port) {
    m_connected = false;
    m_lastError.clear();

    if (port == 0) {
        m_lastError = "Port must be between 1 and 65535";
        return false;
    }

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    if (::inet_pton(AF_INET, ip.c_str(), &address.sin_addr) != 1) {
        m_lastError = "Invalid IPv4 address";
        return false;
    }

    const int fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        m_lastError = std::string("socket failed: ") + std::strerror(errno);
        return false;
    }

    const int originalFlags = ::fcntl(fd, F_GETFL, 0);
    if (originalFlags < 0 || ::fcntl(fd, F_SETFL, originalFlags | O_NONBLOCK) < 0) {
        m_lastError = std::string("fcntl failed: ") + std::strerror(errno);
        ::close(fd);
        return false;
    }

    int result = ::connect(fd, reinterpret_cast<sockaddr*>(&address), sizeof(address));
    if (result < 0 && errno != EINPROGRESS) {
        m_lastError = std::string("connect failed: ") + std::strerror(errno);
        ::close(fd);
        return false;
    }

    if (result < 0) {
        pollfd pollState{};
        pollState.fd = fd;
        pollState.events = POLLOUT;
        result = ::poll(&pollState, 1, 1500);
        if (result <= 0) {
            m_lastError = result == 0 ? "Connection timed out" :
                std::string("poll failed: ") + std::strerror(errno);
            ::close(fd);
            return false;
        }

        int socketError = 0;
        socklen_t errorLength = sizeof(socketError);
        if (::getsockopt(fd, SOL_SOCKET, SO_ERROR, &socketError, &errorLength) < 0 || socketError != 0) {
            const int error = socketError != 0 ? socketError : errno;
            m_lastError = std::string("connect failed: ") + std::strerror(error);
            ::close(fd);
            return false;
        }
    }

    ::close(fd);
    m_connected = true;
    return true;
}

bool NetworkManager::disconnect() {
    m_connected = false;
    m_lastError.clear();
    return true;
}

bool NetworkManager::isConnected() const { return m_connected; }

std::string NetworkManager::statusText() const {
    if (m_connected) return "TCP endpoint reachable";
    if (!m_lastError.empty()) return std::string("Not connected: ") + m_lastError;
    return "Not connected (probe not run)";
}

} // namespace live_studio
