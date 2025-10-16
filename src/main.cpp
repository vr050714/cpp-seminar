#include <iostream>
#include <vector>
#include <cmath>

struct Point { float x, y; };

class Polygon {
public:
    explicit Polygon(std::initializer_list<Point> points)
        : pts{points}
    {}

    float circumfence() const {
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

    float area() const {
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

private:
    std::vector<Point> pts;
};

/// What if:
/// 1. We are going to use ths class in different places, should it be compiled multiple times?
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