#ifndef POLYGON_H
#define POLYGON_H

#include <initializer_list>
#include <vector> // <-- will be included everywhere

struct Point { float x, y; };

class Polygon {
public:
    explicit Polygon(std::initializer_list<Point> points);

    float circumfence() const;
    float area() const;

private:
    std::vector<Point> pts; // <-- details of implementation will be in client code
};

#endif // POLYGON_H
