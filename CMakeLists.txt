cmake_minimum_required(VERSION 3.28)

project(cppseminar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(poly2)

target_sources(poly2
    PRIVATE
        src/main.cpp
        src/Polygon.cpp
)

target_compile_options(poly2
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)
