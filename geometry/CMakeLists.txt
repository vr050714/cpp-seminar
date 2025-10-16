add_library(geometry SHARED)

target_sources(geometry PRIVATE src/Polygon.cpp)

target_include_directories(geometry
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(geometry
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)

install(TARGETS geometry
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
