#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
private:

public:
    Figure();
    ~Figure(){}
    virtual double calc_square(){ return 0; }
    virtual double calc_perimeter(){ return 0; }
    virtual Figure *Clone() { return nullptr; };
};

#endif