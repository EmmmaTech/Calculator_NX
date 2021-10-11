#!/usr/bin/env bash

# Set dir to project root
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

# Clean the main application build files
make clean

# Clean the overlay build files
pushd overlay
make clean
popd