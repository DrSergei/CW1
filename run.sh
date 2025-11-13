#! /bin/sh

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=On -GNinja ..
ninja

echo "Run parallel sort"
./src/par 100000000

echo "Run sequential sort"
./src/seq 100000000

echo "Run tests"
./src/tests
