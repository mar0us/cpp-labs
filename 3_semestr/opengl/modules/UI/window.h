#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>

class GLFWwindow;

class Window
{
private:
    unsigned int width;
    unsigned int height; 
    std::string title_name;

    int init();
    void shutdown();
    GLFWwindow *window;
    
public:
    Window(unsigned int, unsigned int, std::string);
    ~Window();

    void on_update();
    unsigned int get_width() const { return this->width; };
    unsigned int get_height() const { return this->height; };
};


#endif