## Description

Demonstrate PIMPL idiom.

## TODO

- [X] initialize project
- [X] start creating classes
- [X] transform to PIMPL
- [X] extract classes to a shared library
- [ ] create python wrapper for the library

## How to build

```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=dist
cmake --build build
cmake --install build
```
