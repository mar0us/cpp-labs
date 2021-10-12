#include<stdio.h>
#include "modules/figure.h"



int main()
{
    Triangle triangle(2, 3, 4);
    Circle circle(4);

    double tri_sq = triangle.calc_square();
    double tri_pe = triangle.calc_perimeter();

    double cir_sq = circle.calc_square();
    double cir_pe = circle.calc_perimeter();

    double tri_vol = calc_volume(10, &triangle);
    double cir_vol = calc_volume(10, &circle);

    printf("площадь треугольника = %f\nпериметр треугольника = %f\n", tri_sq, tri_pe);
    printf("объем цилиндра полученного из этого треугольника = %f\n", tri_vol);

    printf("площадь круга = %f\nпериметр круга = %f\n", cir_sq, cir_pe);
    printf("объем цилиндра полученного из этого круга = %f\n", cir_vol);
    
    // double ff = fig.calc_square(1,2,3);

    // printf("площадь = %f", ff);
    // printf("периметр = %f\nплощадь = %f", fig.calc_perimeter(), fig.calc_square());

    return 0;
}


