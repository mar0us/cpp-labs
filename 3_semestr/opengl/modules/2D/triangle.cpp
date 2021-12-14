#include"triangle.h"
#include<stdio.h>
#include<cmath>

Triangle::Triangle(double a, double b, double c):Figure()
{
    this->a = a;
    this->b = b;
    this->c = c;
    printf("это генератор треугольника\n");
}

double Triangle::calc_perimeter()
{
    return this->a + this->b + this->c;
}

double Triangle::calc_square()
{
    double p = this->calc_perimeter()/2;
    double s = sqrt(p * (p - this->a) * (p - this->b) * (p - this->c));
    return s;
}

Figure *Triangle::Clone()
{
    Triangle *tri = new Triangle(this->a, this->b, this->c);
    // return &Triangle(this->a, this->b, this->c);
    return tri;
}