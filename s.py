#!/usr/bin/python3

import os

os.chdir("build")

cmake = "/home/pxy/download/cmake_3_30/cmake-3.30.5-linux-x86_64/bin/cmake"
os.system(f"{cmake} ..")
os.system("make -j5")
os.chdir("..")
os.system("./release/Linux/bin/test")
