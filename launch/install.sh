#!/bin/bash
if ! [ $(id -u) = 0 ]; then
    echo "Installation requires root privileges (sudo)"
    exit 1
fi

SOURCE="${BASH_SOURCE[0]}"
while [ -L "$SOURCE" ]; do
    DIR="$(cd -P "$( dirname "$SOURCE" )" && pwd)"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
SCRIPT_DIR="$(cd -P "$( dirname "$SOURCE" )" && pwd)"
cd "$SCRIPT_DIR" || exit 1

./_compilation.sh
if [[ ! -d "../source" && ! -d "../bin" ]]; then
    echo "The program is corrupted"
    exit 1
fi
echo "Installing..."
if [ -d "/usr/local/bin/cpputilities" ]; then
    rm -rf /usr/local/bin/cpputilities
fi
mkdir /usr/local/bin/cpputilities
cp -rf ../source /usr/local/bin/cpputilities
cp -rf ../bin /usr/local/bin/cpputilities
cp -f scr/sh/cpput /usr/bin
