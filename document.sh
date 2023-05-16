#!/usr/bin/env bash
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

$SCRIPT_DIR/packages/simple-documentation-library/document.py event-handler 1.1.1 "Simple event handler library" source documentation