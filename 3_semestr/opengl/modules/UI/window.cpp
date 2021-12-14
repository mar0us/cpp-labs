#include "window.h"
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../logging/log.h"

using std::string;
using std::to_string;

static bool GLFW_initialized = false;

Window::Window(unsigned int width, unsigned int height, std::string title_name)
{
    this->width = width;
    this->height = height;
    this->title_name = std::move(title_name);

    int result_code = this->init();
}
Window::~Window()
{
    this->shutdown();
}

int Window::init()
{
    string mess = "было создано окно с разрешением: " + to_string(width) + "x" + to_string(height);
    logging::info(mess.c_str());

    // GLFWwindow* window;

    if (!GLFW_initialized)
    {
        if (!glfwInit())
        {
            logging::critical("не удалось инициализировать glfw");
            return -1;
        }
        GLFW_initialized = true;
    }

    this->window = glfwCreateWindow(this->width, this->height, this->title_name.c_str(), nullptr, nullptr);
    
    if (!this->window)
    {
        logging::critical( (string("не удалось создать окно программы") + string(this->title_name)).c_str());
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(this->window);

    // если не удалось инициализировать glad завершить программу
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        logging::critical("не удалось инициализировать GLAD");
        return -1;
    }

    return 0;

    
}
void Window::shutdown()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

void Window::on_update()
{
    glClearColor(0, 0, 0.3, 0);

    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    // while (!glfwWindowShouldClose(this->window))
    // {

    //     // this->on_update();
    // }

}