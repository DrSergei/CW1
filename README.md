# CW1

## Setup

Install packages and clone repo.

```sh
sudo apt install cmake ninja build-essential
git clone ...
git submodule update --init --recursive
```

## Run

Just execute `run.sh` from the root of repo.

```sh
./run.sh
```

## Example

Execution trace example on my laptop: WSL2, AMD Ryzen 7 8845HS.

```sh
sergei@DrSergei:~/CW1$ ./run.sh
-- PARLAY VERSION 2.3.3
-- ---------------------------- General configuration -----------------------------
-- CMake Generator:                Ninja
-- Compiler:                       GNU 13.3.0
-- Build type:                     Release
-- CMAKE_CXX_FLAGS:                
-- CMAKE_CXX_FLAGS_DEBUG:          -g
-- CMAKE_CXX_FLAGS_RELEASE:        -O3 -DNDEBUG
-- CMAKE_CXX_FLAGS_RELWITHDEBINFO: -O2 -g -DNDEBUG -fno-omit-frame-pointer
-- CMAKE_EXE_LINKER_FLAGS          
-- CMAKE_INSTALL_PREFIX:           /usr/local
-- -------------------------------- Library options ------------------------------
-- Using Parlay scheduler. Switch with -DPARLAY_{CILKPLUS,OPENCILK,OPENMP,TBB}=On
-- Elastic parallelism enabled. Disable with -DPARLAY_ELASTIC_PARALLELISM=Off
-- ------------------------------- Static Analysis --------------------------------
-- cppcheck:                     Disabled (enable with -DENABLE_CPPCHECK=On)
-- clang-tidy:                   Disabled (enable with -DENABLE_CLANG_TIDY=On)
-- include-what-you-use:         Disabled (enable with -DENABLE_IWYU=On)
-- ---------------------------------- Unit Tests ----------------------------------
-- testing: Disabled (enable with -DPARLAY_TEST=On)
-- ---------------------------------- Benchmarks ----------------------------------
-- benchmarks: Disabled (enable with -DPARLAY_BENCHMARK=On)
-- ----------------------------------- Examples -----------------------------------
-- examples: Disabled (enable with -DPARLAY_EXAMPLES=On)
-- example data: Off (add -DPARLAY_EXAMPLE_DATA=On to download)
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sergei/CW1/build
ninja: no work to do.
Run parallel sort
Average time: 4.0559
Run sequential sort
Average time: 12.3733
Run tests
Tests success
sergei@DrSergei:~/CW1$ 
```
