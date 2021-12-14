// чтобы исходный файл подключался один раз
#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
class Application
{
private:
    
public:
    Application();
    ~Application();
    std::unique_ptr<class Window> window;

    virtual int start(unsigned int, unsigned int, const char*);
    virtual void on_update();
};

#endif