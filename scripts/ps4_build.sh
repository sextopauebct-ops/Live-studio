#!/usr/bin/env bash
set -euo pipefail
cmake -S . -B build -DPS4_TARGET=ON
