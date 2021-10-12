#ifndef FIGURE_H
#define FIGURE_H

// класс наследник
// класс цилиндр

class Figure
{
private:

public:
    Figure();
    ~Figure();
    virtual double calc_square(){ return 0; }
    virtual double calc_perimeter(){ return 0; }
};


class Triangle : public Figure
{
private:
    double a, b, c;
public:
    Triangle(double, double, double);
    ~Triangle();
    virtual double calc_perimeter();
    virtual double calc_square();
};


class Circle : public Figure
{
private:
    double r;
public:
    Circle(double);
    ~Circle();
    virtual double calc_perimeter();
    virtual double calc_square();
};


double calc_volume(double, Figure*);



#endif