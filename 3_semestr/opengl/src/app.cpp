#include <iostream>
#include <memory>
#include "../modules/UI/application.h"


class App : public Application
{
    virtual void on_update()
    {
        std::cout << "обновление кадра: " << frame++ << std::endl;
    }

    int frame = 0;
};

int main()
{


    
    auto app = std::make_unique<App>();
    int returnCode = app->start(1024, 900, "чота");
    // тоже самое что
    // App *app = new App();
    // int returnCode = app->start(700, 600, "test2"); 
    // delete app;

    return returnCode;
    
}