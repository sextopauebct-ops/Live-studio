# Live Studio Makefile

BUILD_DIR ?= build
.PHONY: all host test clean

all: host
host:
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)
test: host
	ctest --test-dir $(BUILD_DIR) --output-on-failure
clean:
	rm -rf $(BUILD_DIR)
