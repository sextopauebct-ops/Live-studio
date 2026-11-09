# LIVE STUDIO

Live Studio is a PS4 homebrew prototype focused on live gameplay streaming with an iPhone camera source.

Project status:
- Repository audited and initialized.
- Project foundation created.
- Host-side validation build is implemented.
- PS4/OpenOrbis build structure is prepared.
- A real .pkg generation still requires the official OpenOrbis Toolchain and PS4 packaging tools in a compatible environment.

Architecture notes:
- A direct overlay over arbitrary PS4 game content is not universally supported by the platform and should not be assumed.
- The feasible architecture is a stand-alone homebrew app that accepts an iPhone camera feed over the local network and displays it inside the app, while preparing the pipeline for streaming ingest via RTMP or an intermediary gateway.

Quick build (host validation):
```bash
cmake -S . -B build
cmake --build build
./build/LiveStudio_host
```

PS4 build:
```bash
export ORBIS_SDK=/path/to/OpenOrbis
cmake -S . -B build-ps4 -DPS4_TARGET=ON -DORBIS_SDK="$ORBIS_SDK"
cmake --build build-ps4
```

Package generation:
- Requires OpenOrbis make_fself and make_pkg.
- The final .pkg must be generated in a PS4-capable build environment.

