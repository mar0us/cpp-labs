#include"cylinder.h"
#include<stdio.h>
#include"../2D/circle.h"



Cylinder::Cylinder(double h, Figure* fig)
{
    this->h = h;
    // this->fig = fig->Clone();
    this->fig = create_figure(fig);
}

Cylinder::~Cylinder()
{
    delete fig; fig = nullptr;
    printf("деструктор цилиндра\n");
}

double Cylinder::calc_volume()
{
    return this->h * fig->calc_square();
}


// Circle_cylinder::Circle_cylinder(double h, Figure* fig):Cylinder(h, fig)
// {

// }

Figure *Circle_cylinder::create_figure(Figure* fig)
{
    Circle *cir = (Circle*)fig;
    // Circle *cir = new Circle();
    printf("радиус окружности переданной в цилиндр = %f\n", cir->r);
    return cir;
}