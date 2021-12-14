// чтобы исходный файл подключался один раз
#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H


class Application
{
private:

public:
    Application();
    ~Application();


    virtual int start(unsigned int, unsigned int, const char*);
    virtual void on_update();
};

#endif