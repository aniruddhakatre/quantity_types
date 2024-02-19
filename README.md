# Quantity Types

This library implements strongly typed physical quantities along with a variety of operators that operate on the quantities. The concept and the basis for implementation is from the __Unit Independent Types Subsystem__ presented in the [Naval Research Laboratory's](https://www.nrl.navy.mil) publication on [GeoLib](https://apps.dtic.mil/sti/trecms/pdf/AD1170763.pdf). The library modifies and extends the design presented in GeoLib in several ways.

The benefit of using this library is that it allows you to use and manipulate various physical quantities without tracking the corresponding units for each quantity.

## Build Instructions

To build the code in this repository, execute the following commands at the terminal.

```cpp
mkdir build install
cmake -B build -DCMAKE_INSTALL_PREFIX=install
cmake --build build --target install --parallel $(nproc)
```

These commands will build the unit tests and install all the header files for `QuantityTypes` and its dependencies along with the unit tests to the `install` directory.

To disable building unit tests, modify the `cmake -B ...` command above as follows. Disabling unit tests will result in just the installation of the header files.

```cpp
cmake -B build -DCMAKE_INSTALL_PREFIX=install -DBUILD_TESTS=OFF
```

**NOTE**: The header files for `QuantityTypes` depend on the `NamedType` headers also installed by the build process.