#!/usr/bin/env bash
mkdir ./build
cd ./build
cmake ..
make all
cd ./bin
./challenge < ../../creditCookie.txt