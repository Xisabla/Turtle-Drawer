#!/usr/bin/env bash

SCRIPT_DIR=$(dirname "$(realpath $0)")

APP_PATH="$(dirname "$(dirname "$SCRIPT_DIR")")"/bin/app

INPUT_FILE_PATH="$SCRIPT_DIR"/instructions.txt

"$APP_PATH" "$INPUT_FILE_PATH"