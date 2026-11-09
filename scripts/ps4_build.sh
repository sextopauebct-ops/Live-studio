#!/usr/bin/env bash
set -euo pipefail

cmake -S . -B build -DPS4_TARGET=OFF
cmake --build build
./build/LiveStudio_host
