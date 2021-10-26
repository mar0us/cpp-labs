#include"circle.h"
#include"../UI/ui_console.h"
#include<stdio.h>
#include<cmath>




Circle::Circle(double r):Figure()
{
    this->r = r;
    // printf("генератор круга\n");
    // debug_message.print_constructor("круг");
}

Circle::~Circle()
{
    // debug_message.print_destructor("круг");
}

double Circle::calc_perimeter()
{
    return 2 * M_PI * this->r;
}

double Circle::calc_square()
{
    return M_PI * this->r * this->r;
}

Figure *Circle::Clone()
{
    Circle *cir = new Circle(this->r);
    return cir;
}
