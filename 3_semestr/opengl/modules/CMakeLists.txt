cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME module_figure)
project(${PROJECT_NAME})

# add_library(figure_modules STATIC include/glad/glad.h src/glad.c)
# add_library(figure_modules STATIC modules/2D/figure.cpp modules/2D/circle.cpp modules/2D/triangle.cpp modules/2D/my_figure.cpp modules/3D/cylinder.cpp modules/UI/ui_console.cpp)
add_library(${PROJECT_NAME} STATIC
    2D/figure.cpp
    2D/circle.cpp
    2D/triangle.cpp
    2D/my_figure.cpp

    3D/cylinder.cpp

    UI/application.cpp
    UI/window.cpp

    logging/log.cpp
)
# target_include_directories(${PROJECT_NAME} PUBLIC 2D/ 3D/)