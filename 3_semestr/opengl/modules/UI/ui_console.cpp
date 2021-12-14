#include"ui_console.h"
#include<stdio.h>

// UI_console::UI_console(bool display_mes)
// {
//     this->display_mes = display_mes;
// }

// void UI_console::print_constructor(std::string name_constructor)
// {
//     if (this->display_mes)
//     {
//         printf("вызов конструктора \"%s\"\n", name_constructor);
//     }
// }

// void UI_console::print_destructor(std::string name_constructor)
// {
//     if (this->display_mes)
//     {
//         printf("вызов деструктора \"%s\"\n", name_constructor);
//     }
// }

void print_constructor(std::string name_constructor)
{
    // if (display_mes)
    {
        printf("вызов конструктора \"%s\"\n", name_constructor);
    }
}

void print_destructor(std::string name_constructor)
{
    // if (display_mes)
    {
        printf("вызов деструктора \"%s\"\n", name_constructor);
    }
}

