#!/usr/bin/python3

import os

os.chdir("build")

cmake = "/home/pxy/download/cmake_3_30/cmake-3.30.5-linux-x86_64/bin/cmake"
os.system(f"{cmake} ..")
ret = os.system("make -j5")
if ret != 0:
    exit(ret)
os.chdir("..")
os.system("./release/Linux/bin/test")
