#ifndef CYLINDER_H
#define CYLINDER_H
#include"../2D/figure.h"

class Cylinder
{
private:
    double h;
    Figure *fig;

public:
    Cylinder(double, Figure*);
    ~Cylinder();
    double calc_volume();
};

#endif