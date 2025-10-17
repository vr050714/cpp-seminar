set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(pygeometry pygeometry.cpp)

target_link_libraries(pygeometry PRIVATE geometry)

set_target_properties(pygeometry PROPERTIES
    INSTALL_RPATH "$ORIGIN"
)

install(TARGETS pygeometry DESTINATION lib)
