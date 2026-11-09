#!/usr/bin/env bash
set -euo pipefail

: "${ORBIS_SDK:?Set ORBIS_SDK to the OpenOrbis root directory before building the PS4 package. Example: export ORBIS_SDK=/opt/orbis}"

BUILD_DIR="${BUILD_DIR:-build-ps4}"
APP_NAME="${APP_NAME:-LiveStudio}"
ELF_PATH="${ELF_PATH:-${BUILD_DIR}/${APP_NAME}.elf}"
SELF_PATH="${SELF_PATH:-${BUILD_DIR}/${APP_NAME}.self}"
PKG_OUT="${PKG_OUT:-${BUILD_DIR}/LiveStudio.pkg}"
GP4_PATH="${GP4_PATH:-config/live-studio.gp4}"

if [ ! -f "${ELF_PATH}" ]; then
  echo "No ELF found at ${ELF_PATH}. Build the PS4 target before packaging."
  exit 1
fi

if ! command -v make_fself >/dev/null 2>&1; then
  echo "make_fself was not found in PATH. Install OpenOrbis packaging utilities and ensure they are on PATH."
  exit 1
fi

if ! command -v make_pkg >/dev/null 2>&1; then
  echo "make_pkg was not found in PATH. Install OpenOrbis packaging utilities and ensure they are on PATH."
  exit 1
fi

mkdir -p "${BUILD_DIR}"
make_fself "${ELF_PATH}" "${SELF_PATH}"
make_pkg "${GP4_PATH}" "${PKG_OUT}"

echo "Package generated: ${PKG_OUT}"
