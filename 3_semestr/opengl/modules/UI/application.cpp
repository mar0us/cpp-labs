#include "application.h"
#include <iostream>
#include <memory>

#include "../logging/log.h"
#include "window.h"

Application::Application()
{
    logging::info("запуск приложения");
    // Window win(20, 20, "wsf");
}

Application::~Application()
{
    logging::info("закрытие приложения");
}

int Application::start(unsigned int window_width, unsigned int window_height, const char* title_name)
{
    this->window = std::make_unique<Window>(window_width, window_height, title_name);

    while (true)
    {
        this->window->on_update();
        this->on_update();
    }
    

    return 0;
}

void Application::on_update()
{

}