add_executable(poly2)

target_sources(poly2 PRIVATE main.cpp)

target_compile_options(poly2
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)

target_link_libraries(poly2 PRIVATE geometry)

# Set RPATH so the executable can find the library
set_target_properties(poly2 PROPERTIES
    INSTALL_RPATH "$ORIGIN:$ORIGIN/../lib"
)

install(TARGETS poly2
    RUNTIME DESTINATION bin
)
