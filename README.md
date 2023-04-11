# Poster: Framework for Semi-Private Function Evaluation with Application to Secure Insurance Rate Calculation

By *Daniel Günther, Ágnes Kiss, Lukas Scheidel, and Thomas Schneider* in [26. ACM Conference on Computer and Communications Security (CCS'19) Posters/Demos](https://www.sigsac.org/ccs/CCS2019/). Paper available [here](https://encrypto.de/papers/GKSS19.pdf).

### Requirements

* A **Linux distribution** of your choice (developed and tested on Ubuntu).
* **Required packages:**
  * [`g++`](https://packages.debian.org/testing/g++) (version >=8)
    or another compiler and standard library implementing C++17 including the filesystem library
  * [`make`](https://packages.debian.org/testing/make)
  * [`cmake`](https://packages.debian.org/testing/cmake)
  * [`libgmp-dev`](https://packages.debian.org/testing/libgmp-dev)
  * [`libssl-dev`](https://packages.debian.org/testing/libssl-dev)
  * [`libboost-all-dev`](https://packages.debian.org/testing/libboost-all-dev) (version >= 1.66)
  * [`flex`](https://packages.debian.org/testing/flex)
  * [`bison`](https://packages.debian.org/testing/bison)
  * [`python3`](https://packages.debian.org/testing/python3)

  Install these packages with your favorite package manager, e.g, `sudo apt-get install <package-name>`.

* Optional packages: `doxygen` and `graphviz` to create your own [Doxygen](http://www.doxygen.org) documentation of the code.

#### Building the Framework

##### Short Version

```shell
git clone --recursive https://github.com/danguenther/spfe-framework
cd spfe-framework
mkdir build
cd build
cmake ..
make
make -C ..
```

##### Detailed Guide

###### External Depedencies

This frameworkdepends on the following libraries:

* [boost](https://www.boost.org/)
* [googletest](https://github.com/google/googletest) (optional)

These are referenced using the Git submodules in the `extern/`
directory. During the configure phase of the build (calling `cmake
..`) CMake searches your system for these libraries.

* If they are already installed at a standard location, e.g., at `/usr` or
  `/usr/local`, CMake should find these automatically.
* In case they are installed at a nonstandard location, e.g., at `~/some/path/`,
  you can point CMake to their location via the
  [`CMAKE_PREFIX_PATH`](https://cmake.org/cmake/help/latest/variable/CMAKE_PREFIX_PATH.html)
  option:
    ```
    cmake .. -DCMAKE_PREFIX_PATH=~/some/path/
    ```

###### Build Options

You can choose the build type, e.g. `Release` or `Debug` using
[`CMAKE_BUILD_TYPE`](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html):
```
cmake .. -DCMAKE_BUILD_TYPE=Release
# or
cmake .. -DCMAKE_BUILD_TYPE=Debug
```
`Release` will enable optimizations whereas `Debug` includes debug symbols.

To choose a different compiler, use the `CXX` environment variable:
```
CXX=/usr/bin/clang++ cmake ..
```
