#include <iostream>
#include "Polygon.h"

/// What if:
/// 1. ~We are going to use ths class in different places, should it be compiled multiple times?~
/// 2. We are going to change implementation
///    - keep coordinates in two separate arrays for better performance
///    - use Eigen library for vectorization
/// 3. We are going to distribue the library with python wrapper

int main() {
    Polygon a { {0, 0}, {1, 0}, {1, 1}, {0, 1} };
    std::cout << "a.circumfence(): " << a.circumfence() << "\n";
    std::cout << "a.area(): " << a.area() << "\n";
    return 0;
}