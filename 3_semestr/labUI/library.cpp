#include <stdio.h>

extern "C"
{

   
    #include "modules/2D/figure.h"
    #include "modules/2D/triangle.h"
    #include "modules/2D/circle.h"
    #include "modules/2D/my_figure.h"
    #include "modules/3D/cylinder.h"


    int test(int a)
    {
        Circle cir(4);

        printf("%f\n", cir.calc_perimeter());
        // return test_circle(a);
        return cir.calc_square();
    }
}