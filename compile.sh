#!/usr/bin/env bash

cd ..
rm -rf ./build
mkdir build

CC=gcc CXX=g++ meson build --reconfigure

cd build
ninja


