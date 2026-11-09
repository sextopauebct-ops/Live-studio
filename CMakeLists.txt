cmake_minimum_required(VERSION 3.16)
project(LiveStudio VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIVE_STUDIO_SOURCES
    src/app/LiveStudioApp.cpp
    src/camera/CameraManager.cpp
    src/network/NetworkManager.cpp
    src/settings/SettingsManager.cpp
    src/streaming/StreamingManager.cpp
)

add_library(live_studio_core STATIC ${LIVE_STUDIO_SOURCES})
target_include_directories(live_studio_core PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(LiveStudio_host src/main.cpp)
target_link_libraries(LiveStudio_host PRIVATE live_studio_core)

enable_testing()
add_executable(LiveStudio_state_tests tests/state_tests.cpp)
target_link_libraries(LiveStudio_state_tests PRIVATE live_studio_core)
add_test(NAME LiveStudio_state_tests COMMAND LiveStudio_state_tests)

option(PS4_TARGET "Build for PS4/OpenOrbis (not yet implemented)" OFF)
if(PS4_TARGET)
    message(FATAL_ERROR "PS4 target is not yet a verified build. Toolchain integration/package metadata must be implemented and tested before enabling this option.")
endif()
