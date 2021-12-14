#pragma once
#ifndef MY_FIGURE_H
#define MY_FIGURE_H

#include"figure.h"

class My_figure : public Figure
{
private:
    double r;
public:
    My_figure(double);
    ~My_figure(){}
    virtual double calc_square();
    virtual double calc_perimeter();
    virtual Figure* Clone();
};


#endif