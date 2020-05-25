#!/usr/bin/env bash

#rm -rf ./build

if [ "$1" == "rebuild" ]; then
  CC=clang CXX=clang++ meson build --reconfigure
fi

cd build
ninja

./pong
