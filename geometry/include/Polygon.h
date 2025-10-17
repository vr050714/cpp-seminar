#ifndef POLYGON_H
#define POLYGON_H

#include <initializer_list>
#include <memory>

// Important: we don't want to disclose implementation adding more includes there, because this
// header will be included in client code.

struct Point { float x, y; };

class Polygon {
public:
    explicit Polygon(std::initializer_list<Point> points);

    // templated factory method allows creating an object from any collection
    // implements two-phase construction
    template<typename Iterator>
    static Polygon from_collection(Iterator begin, Iterator end) {
        Polygon tmp;
        for (auto it = begin; it != end; ++it) {
            tmp.add_point(*it);
        }
        return tmp;
    }

    // now either rule of 3 or 5 must be satisfied, since we defined the default constructor
    // before that the constructors and operators were defined automatically
    Polygon(const Polygon&);
    Polygon& operator=(const Polygon&);
    ~Polygon();

    float circumfence() const;
    float area() const;

private:
    struct PolygonImpl; // forward declaration
    std::unique_ptr<PolygonImpl> impl; // independent of implementation details

    // default constructor and the method are required for two-phase construction
    Polygon();
    void add_point(const Point&);
};

#endif // POLYGON_H
