#include "live_studio/SettingsManager.h"
#include <iostream>

namespace live_studio {

SettingsManager::SettingsManager() = default;

void SettingsManager::setCameraEnabled(bool enabled) { m_cameraEnabled = enabled; }
void SettingsManager::setResolution(int width, int height) { m_width = width; m_height = height; }
void SettingsManager::setCameraPosition(int x, int y) { m_x = x; m_y = y; }
void SettingsManager::setCameraScale(int scaleX, int scaleY) { m_scaleX = scaleX; m_scaleY = scaleY; }
void SettingsManager::setQuality(int quality) { m_quality = quality; }
void SettingsManager::setStreamUrl(const std::string& url) { m_streamUrl = url; }
void SettingsManager::setStreamProtocol(const std::string& protocol) { m_streamProtocol = protocol; }
void SettingsManager::setConnectionTarget(const std::string& ip, uint16_t port) { m_ip = ip; m_port = port; }
void SettingsManager::setAutoReconnect(bool enabled) { m_autoReconnect = enabled; }

bool SettingsManager::cameraEnabled() const { return m_cameraEnabled; }
int SettingsManager::width() const { return m_width; }
int SettingsManager::height() const { return m_height; }
int SettingsManager::positionX() const { return m_x; }
int SettingsManager::positionY() const { return m_y; }
int SettingsManager::scaleX() const { return m_scaleX; }
int SettingsManager::scaleY() const { return m_scaleY; }
int SettingsManager::quality() const { return m_quality; }
std::string SettingsManager::streamUrl() const { return m_streamUrl; }
std::string SettingsManager::streamProtocol() const { return m_streamProtocol; }
std::string SettingsManager::connectionIp() const { return m_ip; }
uint16_t SettingsManager::connectionPort() const { return m_port; }
bool SettingsManager::autoReconnect() const { return m_autoReconnect; }

} // namespace live_studio
