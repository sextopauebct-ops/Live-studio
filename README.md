# LIVE STUDIO

Live Studio is an early PS4 homebrew prototype. The repository currently contains a portable C++ state/configuration model and host-side tests—not a PS4 application or streaming client.

## Current status
- Host build and state tests: implemented in CMake/CI.
- Host IPv4 TCP reachability probe: implemented and tested against a local test server. This checks only whether a TCP endpoint accepts a connection; it does not prove that the endpoint is an iPhone camera stream.
- Camera network protocol and video decoding: not implemented.
- PS4 UI/rendering integration: not implemented.
- Game-wide overlay: not a universal PS4 homebrew capability; do not assume it works.
- RTMP encoding/output and audio capture: not implemented.
- PS4 ELF/SELF/PKG pipeline: prepared as a packaging workflow, but not verified here because the OpenOrbis toolchain and PS4 packaging utilities are not installed in this environment.

## Build and test on a computer
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
./build/LiveStudio_host
```

## PS4 packaging flow (requires OpenOrbis)
```bash
export ORBIS_SDK=/path/to/OpenOrbis
cmake -S . -B build-ps4 -DPS4_TARGET=ON -DORBIS_SDK="$ORBIS_SDK"
cmake --build build-ps4
./scripts/build_pkg.sh
```

This script expects:
- a valid PS4 ELF in `build-ps4/LiveStudio.elf`
- `make_fself` and `make_pkg` available in PATH
- a valid `config/live-studio.gp4` file for the target package metadata

It does not claim that a .pkg file has already been generated in this environment. The final installation package must be produced on a machine with the OpenOrbis packaging toolchain installed.
