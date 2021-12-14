cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME Figures.bin)
set(SOURCE_MAIN src/app.cpp)


# Debug
# Release
set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)

project(${PROJECT_NAME}
    LANGUAGES CXX C
)

set(CMAKE_C_COMPILER "/usr/local/gcc-11.1.0/bin/gcc-11.2")
set(CMAKE_CXX_COMPILER "/usr/local/gcc-11.1.0/bin/g++-11.2")

add_executable(${PROJECT_NAME} ${SOURCE_MAIN})


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)



# линковка библиотек
add_subdirectory(modules)
target_link_libraries(${PROJECT_NAME} PUBLIC module_figure)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)