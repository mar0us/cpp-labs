cmake_minimum_required(VERSION 3.8)

# set(CMAKE_C_COMPILER "/usr/local/gcc-11.1.0/bin/gcc-11.2")
# set(CMAKE_CXX_COMPILER "/usr/local/gcc-11.2.0/bin/g++-11.2")
# set(CMAKE_AUTOMOC ON)

enable_language(CXX)

project(Figure_calc)

set(SOURCE_MAIN main.cpp)
set(SOURCE_LIB modules/figure.cpp)

add_library(figure_lib STATIC ${SOURCE_LIB})
add_executable(main.o ${SOURCE_MAIN})

target_link_libraries(main.o figure_lib)