#!/bin/bash
# To rebuild, change to "true", and "false" to use the ready binary
devmode=false
#--------------------------

SOURCE="${BASH_SOURCE[0]}"
while [ -L "$SOURCE" ]; do
    DIR="$(cd -P "$( dirname "$SOURCE" )" && pwd)"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
SCRIPT_DIR="$(cd -P "$( dirname "$SOURCE" )" && pwd)"
cd "$SCRIPT_DIR" || exit 1

if [ -e "../bin/main" ]; then
    if $devmode; then
        ./_compilation.sh
        ./_start.sh
    else
        ./_start.sh
    fi
else
    ./_compilation.sh
    ./_start.sh
fi
