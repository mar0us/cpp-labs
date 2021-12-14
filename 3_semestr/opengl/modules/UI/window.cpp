#include "window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>



int Window::init()
{

}
void Window::shutdown()
{

}
Window::Window(unsigned int width, unsigned int height, std::string title_name)
{
    this->width = width;
    this->height = height;
    this->title_name = std::move(title_name);

    int result_code = this->init();
}
Window::~Window()
{

}

void Window::on_update()
{

}