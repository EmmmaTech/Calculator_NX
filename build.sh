#!/usr/bin/env bash

# Set dir to project root
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR

# Make the cnx_forwarder
pushd cnx_forwarder
make
popd

# Make the main application
make

# Make the overlay
pushd overlay
make
popd