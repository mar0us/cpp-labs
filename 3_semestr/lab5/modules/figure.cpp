#include "figure.h"
#include<stdio.h>
#include<cmath>

Figure::Figure()
{
    printf("вызов конструктора фигуры\n");
}

Figure::~Figure()
{
    printf("вызов деструктора фигуры\n");
}


Triangle::Triangle(double a, double b, double c):Figure()
{
    this->a = a;
    this->b = b;
    this->c = c;
    printf("вызов конструктора треугольника\n");
}

Triangle::~Triangle()
{
    printf("вызов деструктора треугольника\n");
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


Circle::Circle(double r):Figure()
{
    this->r = r;
    printf("вызов конструктора круга\n");
}

Circle::~Circle()
{
    printf("вызов деструктора круга\n");
}

double Circle::calc_perimeter()
{
    return 2 * M_PI * this->r;
}

double Circle::calc_square()
{
    return M_PI * this->r * this->r;
}


double calc_volume(double h, Figure *fig)
{
    return h * fig->calc_square();
}


// Cylinder::Cylinder(double h, Figure* fig)
// {
//     this->h = h;
//     this->fig = fig->Clone();
// }

// double Cylinder::calc_volume()
// {
//     return this->h * fig->calc_square();
// }