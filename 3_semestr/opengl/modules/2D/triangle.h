#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"figure.h"

class Triangle : public Figure
{
private:
    double a, b, c;
public:
    Triangle(double, double, double);
    ~Triangle(){}
    virtual double calc_perimeter();
    virtual double calc_square();
    virtual Figure* Clone();
};

#endif