# C++ seminar

## Plan

### Idioms

- [x] RAII
- [x] Copy-and-swap idiom
- [x] Pimpl idiom
- [x] CRTP
- [ ] inplace lambda
- [ ] "Virtual constructor"
- [ ] External polymorphism (type erasure + bridge + ADL)

### Templates

- [ ] Type traits
- [ ] SFINAE (std::enable_if, std::void_t + constexpr)
- [ ] Template metaprogramming (???)
- [ ] Template template parameters (a.k.a metafunctions)
- [ ] Variadic templates
- [ ] Templated constructor, deduction guides
- [ ] Concepts (???)

## Links

- [Modernes C++](https://www.modernescpp.com/index.php/table-of-content/)
- [Fluent C++](https://www.fluentcpp.com/)
- [UB Book](https://github.com/Nekrolm/ubbook)
- [Hacking C++](https://hackingcpp.com/index.html)
- [C++20 idioms for parameter packs](https://www.scs.stanford.edu/~dm/blog/param-pack.html)
- [C++ Patterns](https://cpppatterns.com/)
- [modern-cpp-features](https://github.com/AnthonyCalandra/modern-cpp-features)
- [C++23 Deducing this](https://devblogs.microsoft.com/cppblog/cpp23-deducing-this)
- [cppiceberg](https://victorpoughon.github.io/cppiceberg/)

## Demonstrate PIMPL idiom

- [X] initialize project
- [X] start creating classes
- [X] transform to PIMPL
- [X] extract classes to a shared library
- [X] create python wrapper for the library

## How to build

```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=dist -G "Ninja"
cmake --build build
cmake --install build
```

## Testing python wrapper

```python
from pygeometry import Point, Polygon
p = Polygon([Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)])
print(f"p.circumference(): {p.circumference()}")
print(f"p.area(): {p.area()}")
```
