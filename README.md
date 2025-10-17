## Description

Demonstrate PIMPL idiom.

## TODO

- [X] initialize project
- [X] start creating classes
- [X] transform to PIMPL
- [X] extract classes to a shared library
- [X] create python wrapper for the library

## How to build

```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=dist
cmake --build build
cmake --install build
```

## Testing python wrapper

```python
from pygeometry import Point, Polygon
p = Polygon([Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)])
print(f"p.circumfence(): {p.circumfence()}")
print(f"p.area(): {p.area()}")
```
