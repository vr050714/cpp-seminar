#ifndef POLYGON_H
#define POLYGON_H

#include <initializer_list>
#include <memory>

struct Point { float x, y; };

class Polygon {
public:
    explicit Polygon(std::initializer_list<Point> points);
    ~Polygon();

    float circumfence() const;
    float area() const;

private:
    struct PolygonImpl; // forward declaration
    std::unique_ptr<PolygonImpl> impl; // independent of implementation details
};

#endif // POLYGON_H
