# Data Structure in CPP
[![Build Status](https://travis-ci.com/kasper189/data-structure-cpp.svg?branch=master)](https://travis-ci.com/kasper189/data-structure-cpp)

The project aims at implementing a basic, not optimized version of data structures in cpp.
* [Linked List](https://en.wikipedia.org/wiki/Linked_list)

## Project dependencies
The project uses:
* [cmake](https://cmake.org) to build and test the project
* [Googletest](https://github.com/google/googletest) as Testing and Mocking Framework

Please ensure to install cmake before building the project, while Googletest will be automatically downloaded.

### Mac os cmake installation
* download the latest version of cmake for MacOS from the [originale repo](https://cmake.org/download/)
* install cmake on your laptop
* if you use the terminal, please

```bash
export PATH=$PATH:/Applications/CMake.app/Contents/bin/
```

### Build
```bash
mkdir -p build
cd build
cmake ..
make
```

### Run test
```bash
make test
```

A [script](scripts/run.sh) is available to build and run tests.
