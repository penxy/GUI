#!/bin/bash

cmake="/home/pxy/download/cmake_3_30/cmake-3.30.5-linux-x86_64/bin/cmake"
$cmake -S . -B build && \
make -C build -j6 && ./release/Linux/bin/test --qss=$PWD/Qss