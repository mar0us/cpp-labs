#include"cylinder.h"
#include<stdio.h>


Cylinder::Cylinder(double h, Figure* fig)
{
    this->h = h;
    this->fig = fig->Clone();
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