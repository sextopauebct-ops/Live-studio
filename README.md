# LIVE STUDIO

Live Studio is an early PS4 homebrew prototype. The repository currently contains a portable C++ state/configuration model and host-side tests—not a PS4 application or streaming client.

## Current status
- Host build and state tests: implemented in CMake/CI.
- Camera network protocol and video decoding: not implemented.
- PS4 UI/rendering integration: not implemented.
- Game-wide overlay: not a universal PS4 homebrew capability; do not assume it works.
- RTMP encoding/output and audio capture: not implemented.
- PS4 ELF/SELF/PKG pipeline: not yet verified; no installable PKG is produced by this project at this stage.

## Build and test on a computer
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
./build/LiveStudio_host
```

The host dashboard deliberately reports that camera/network/streaming backends are pending. It does not claim a connection or transmission that has not taken place.

## Planned architecture
An initial camera proof-of-concept should use a simple LAN transport (for example MJPEG over HTTP) from an iPhone camera app/page to a receiver, after validating decoder and socket support on the target. For a stable broadcast to Twitch/YouTube, use a separately tested gateway/encoder; do not assume PS4 game framebuffer capture, global overlay, hardware encode APIs, or RTMP support are available to homebrew.

The PS4 target must be enabled only after a known OpenOrbis sample is compiled and packaged with pinned, verified tool versions and metadata. No PS4 hardware/Firmware 13.52/GoldHEN test is claimed.
