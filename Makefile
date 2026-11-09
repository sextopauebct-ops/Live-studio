# Makefile for Live Studio

.DEFAULT_GOAL := host

BUILD_DIR ?= build
PS4_BUILD_DIR ?= build-ps4

.PHONY: host ps4 clean

host:
	cmake -S . -B $(BUILD_DIR) -DPS4_TARGET=OFF
	cmake --build $(BUILD_DIR)

ps4:
	@if [ -z "$(ORBIS_SDK)" ]; then \
		echo "ORBIS_SDK is not set. Example: export ORBIS_SDK=/path/to/OpenOrbis"; \
		exit 1; \
	fi
	cmake -S . -B $(PS4_BUILD_DIR) -DPS4_TARGET=ON -DORBIS_SDK="$(ORBIS_SDK)"
	cmake --build $(PS4_BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(PS4_BUILD_DIR)
