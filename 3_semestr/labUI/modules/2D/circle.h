#ifndef CIRCLE_H
#define CIRCLE_H

#include"figure.h"

class Circle : public Figure
{
private:
    double r;
public:
    Circle(double);
    ~Circle();
    virtual double calc_perimeter();
    virtual double calc_square();
    virtual Figure* Clone();
};


#endif