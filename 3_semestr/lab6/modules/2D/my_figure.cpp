#include"my_figure.h"
#include<cmath>

My_figure::My_figure(double r):Figure()
{
    this->r = r;
}

double My_figure::calc_perimeter()
{
    return this->r * (M_PI + 14); 
}

double My_figure::calc_square()
{
    return this->r * this->r * (sqrt(3) + 4 + M_PI/2);
}

Figure *My_figure::Clone()
{
    Figure *fig = new My_figure(this->r);
    return fig; 
}
