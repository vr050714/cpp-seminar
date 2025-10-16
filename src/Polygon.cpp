#include "Polygon.h"
#include <cmath>

Polygon::Polygon(std::initializer_list<Point> points)
    : pts{points}
{}

float Polygon::circumfence() const {
    if (pts.size() < 2) {
        return 0.0f;
    }

    float total_length = 0.0f;

    // Calculate distance between consecutive points
    for (size_t i = 0; i < pts.size() - 1; ++i) {
        float dx = pts[i + 1].x - pts[i].x;
        float dy = pts[i + 1].y - pts[i].y;
        total_length += std::sqrt(dx * dx + dy * dy);
    }

    // Close the polygon: add distance from last point to first point
    float dx = pts[0].x - pts[pts.size() - 1].x;
    float dy = pts[0].y - pts[pts.size() - 1].y;
    total_length += std::sqrt(dx * dx + dy * dy);

    return total_length;
}

float Polygon::area() const {
    if (pts.size() < 3) {
        return 0.0f;
    }

    // Shoelace formula (surveyor's formula)
    float sum = 0.0f;
    for (size_t i = 0; i < pts.size(); ++i) {
        size_t next = (i + 1) % pts.size();
        sum += pts[i].x * pts[next].y - pts[next].x * pts[i].y;
    }

    return std::abs(sum) / 2.0f;
}
