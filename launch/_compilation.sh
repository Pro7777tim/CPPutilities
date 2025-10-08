#!/bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -L "$SOURCE" ]; do
    DIR="$(cd -P "$( dirname "$SOURCE" )" && pwd)"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
SCRIPT_DIR="$(cd -P "$( dirname "$SOURCE" )" && pwd)"
cd "$SCRIPT_DIR" || exit 1

if [ -e "../bin/main" ]; then
    echo "Starting recompilation..."
else
    echo "Starting compilation..."
fi
g++ ../source/main.cpp ../source/scr/cpp/math.cpp ../source/scr/cpp/time.cpp -o ../bin/main

