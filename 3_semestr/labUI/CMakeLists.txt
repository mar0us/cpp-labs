cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_COMPILER "/usr/local/gcc-11.1.0/bin/gcc-11.2")
set(CMAKE_CXX_COMPILER "/usr/local/gcc-11.1.0/bin/g++-11.2")


enable_language(CXX)

project(Figure_calc)

# set(SOURCE_MAIN library.cpp)
set(SOURCE_LIB modules/2D/figure.cpp modules/2D/circle.cpp modules/2D/triangle.cpp modules/2D/my_figure.cpp modules/3D/cylinder.cpp modules/UI/ui_console.cpp)
set(SOURCE_M library.cpp)

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(figures_lib SHARED ${SOURCE_LIB})
add_library(lib SHARED ${SOURCE_M})
target_link_directories(figures_lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/modules/2d
        ${PROJECT_SOURCE_DIR}/modules/3d
)
# add_executable(library.o ${SOURCE_MAIN})

# target_link_libraries(library.o libs)  
target_link_libraries(lib figures_lib)