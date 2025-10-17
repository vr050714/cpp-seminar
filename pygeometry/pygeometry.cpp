#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Polygon.h"

namespace py = pybind11;

PYBIND11_MODULE(pygeometry, m) {
    m.doc() = "Python bindings for geometry library";

    // Bind Point struct
    py::class_<Point>(m, "Point")
        .def(py::init<float, float>())
        .def_readwrite("x", &Point::x)
        .def_readwrite("y", &Point::y)
        .def("__repr__",
            [](const Point &p) {
                return "Point(x=" + std::to_string(p.x) + ", y=" + std::to_string(p.y) + ")";
            });

    // Bind Polygon class
    py::class_<Polygon>(m, "Polygon")
        .def(py::init([](std::vector<Point> points) {
            return Polygon::from_collection(points.begin(), points.end());
        }))
        .def("circumfence", &Polygon::circumfence, "Calculate the circumference of the polygon")
        .def("area", &Polygon::area, "Calculate the area of the polygon")
        .def("__repr__", [](const Polygon&) { return "<Polygon>"; });
}
