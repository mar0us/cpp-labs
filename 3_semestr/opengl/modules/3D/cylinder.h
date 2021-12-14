#pragma once
#ifndef CYLINDER_H
#define CYLINDER_H
#include"../2D/figure.h"

class Cylinder
{
protected:
    // virtual Figure *create_figure(Figure*) { return nullptr; }

private:
    double h;
    Figure *fig;
    // Figure *get_figure(Figure*);

public:
    Cylinder(double, Figure*);
    ~Cylinder();
    double calc_volume();
};



class Circle_cylinder : public Cylinder
{
public:
    Circle_cylinder(double h, Figure *fig);
    ~Circle_cylinder();
protected:
    static Figure *create_figure(Figure*);

};





#endif