#include"circle.h"
#include<stdio.h>
#include<cmath>


Circle::Circle(double r):Figure()
{
    this->r = r;
    printf("генератор круга\n");
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
