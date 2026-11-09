#include "live_studio/Managers.h"

#include <cassert>
#include <cstdint>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    live_studio::NetworkManager manager;
    assert(!manager.connect("not-an-ip", 8080));
    assert(!manager.isConnected());

    const int server = ::socket(AF_INET, SOCK_STREAM, 0);
    assert(server >= 0);
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    address.sin_port = 0;
    assert(::bind(server, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == 0);
    assert(::listen(server, 1) == 0);
    socklen_t addressLength = sizeof(address);
    assert(::getsockname(server, reinterpret_cast<sockaddr*>(&address), &addressLength) == 0);
    const uint16_t port = ntohs(address.sin_port);

    std::thread acceptThread([server] {
        const int client = ::accept(server, nullptr, nullptr);
        if (client >= 0) ::close(client);
        ::close(server);
    });

    assert(manager.connect("127.0.0.1", port));
    assert(manager.isConnected());
    assert(manager.statusText() == "TCP endpoint reachable");
    assert(manager.disconnect());
    acceptThread.join();
    return 0;
}
