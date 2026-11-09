cmake_minimum_required(VERSION 3.16)
project(LiveStudio VERSION 1.0.0 LANGUAGES CXX)

option(PS4_TARGET "Build for PS4/OpenOrbis" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/include)

if(PS4_TARGET)
    if(NOT DEFINED ORBIS_SDK)
        message(FATAL_ERROR "ORBIS_SDK must be set when PS4_TARGET=ON")
    endif()

    add_compile_definitions(__ORBIS__)
    include_directories(${ORBIS_SDK}/include)

    add_executable(LiveStudio
        src/main.cpp
        src/app/LiveStudioApp.cpp
        src/camera/CameraManager.cpp
        src/network/NetworkManager.cpp
        src/settings/SettingsManager.cpp
        src/streaming/StreamingManager.cpp
    )

    target_include_directories(LiveStudio PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(LiveStudio PRIVATE
        -lSceSystemService
        -lScePad
        -lSceVideoOut
        -lSceNet
    )
else()
    add_executable(LiveStudio_host
        src/main.cpp
        src/app/LiveStudioApp.cpp
        src/camera/CameraManager.cpp
        src/network/NetworkManager.cpp
        src/settings/SettingsManager.cpp
        src/streaming/StreamingManager.cpp
    )

    target_include_directories(LiveStudio_host PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_compile_definitions(LiveStudio_host PRIVATE LIVE_STUDIO_HOST_BUILD)
endif()
