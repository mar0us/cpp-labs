#include <iostream>

using namespace std;
#ifndef A_h
#define A_h

// описываем структуру яблок
struct Apple
{
    string color;
    float weight;
    string country;
    float price;
};

// прототипы для работы со структурой

Apple* Init(Apple);
void Del(Apple*);
void A_Print(Apple*);
#endif