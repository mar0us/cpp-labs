#include <iostream>
#include "A.h"

using namespace std;

// функция инициализации структуры
Apple* Init(Apple A)
{
    Apple* B = new Apple;
    *B = A;
    return B;
}
// функция очистки памяти
void Del(Apple* A)
{
    delete A;

}
// функция вывода информации о структуре
void A_Print(Apple* A)
{
    cout << "____________________" << endl;
    cout << "цвет: " << A->color << endl;
    cout << "вес: " << A->weight << endl;
    cout << "страна: " << A->country << endl;
    cout << "цена: " << A->price << endl;
    cout << "____________________" << endl;
}