# Data Structure in CPP
[![Build Status](https://travis-ci.com/kasper189/data-structure-cpp.svg?branch=master)](https://travis-ci.com/kasper189/data-structure-cpp)

The project aims at implementing a basic, not optimized version of data structures in cpp.
* [Linked List](https://en.wikipedia.org/wiki/Linked_list)
* [Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
* [Binary Heap](https://en.wikipedia.org/wiki/Binary_heap)

## Project dependencies
The project uses:
* [cmake](https://cmake.org) to build and test the project
* [Googletest](https://github.com/google/googletest) as Testing and Mocking Framework
* [Valgrind](http://valgrind.org) as analysis tool

Please ensure to install cmake before building the project, while Googletest will be automatically downloaded.

## Mac os dependencies installation

### CMake
* download the latest version of cmake for MacOS from the [originale repo](https://cmake.org/download/)
* install cmake on your laptop
* if you use the terminal, please

```bash
export PATH=$PATH:/Applications/CMake.app/Contents/bin/
```

### Valgrind
```bash
brew install valgrind
```

## Build
```bash
mkdir -p build
cd build
cmake ..
make
```

## Run test
```bash
make test
```

## Run test with valgrind
```bash
ctest -D ExperimentalMemCheck
```

A [script](scripts/run.sh) is available to build and run tests.

## LICENCE

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for non-commercial applications, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

