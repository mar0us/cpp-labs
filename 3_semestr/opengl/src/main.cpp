#include<stdio.h>
#include "../modules/2D/figure.h"
#include "../modules/2D/triangle.h"
#include "../modules/2D/circle.h"
#include "../modules/2D/my_figure.h"
#include "../modules/3D/cylinder.h"
#include "../modules/UI/application.h"



int main()
{
    Triangle triangle(2, 3, 4);
    Circle circle(4);
    // Cylinder tri_cyl(5, &triangle);
    // Circle_cylinder cir_cyl(5, &circle);
    // Circle_cylinder cir_cyl(5);


    double tri_sq = triangle.calc_square();
    double tri_pe = triangle.calc_perimeter();

    double cir_sq = circle.calc_square();
    double cir_pe = circle.calc_perimeter();

    // double tri_vol = tri_cyl.calc_volume();
    // double cir_vol = cir_cyl.calc_volume();



    printf("площадь треугольника = %f\nпериметр треугольника = %f\n", tri_sq, tri_pe);
    // printf("объем цилиндра полученного из этого треугольника = %f\n", tri_vol);

    printf("площадь круга = %f\nпериметр круга = %f\n", cir_sq, cir_pe);
    // printf("объем цилиндра полученного из этого круга = %f\n", cir_vol);


    Application app;

    app.start(500, 500, "test");

    return 0;
}


