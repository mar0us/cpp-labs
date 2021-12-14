#include "application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
 
#include <iostream>
 

Application::Application()
{

}

Application::~Application()
{

}

int Application::start(unsigned int window_width, unsigned int window_height, const char* title_name)
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(window_width, window_height, title_name, NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    
    while (!glfwWindowShouldClose(window))
    {
        // glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();

        this->on_update();
    }

    glfwTerminate();
    return 0;
}

void Application::on_update()
{

}