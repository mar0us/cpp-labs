// модуль для меню
#include <iostream>
#include "Cup.h"
using namespace std;
void* Cup_init(Cup B)
{
    Cup* A = new Cup;
    A->volume = B.volume;
    A->height = B.height;
    A->diameter = B.diameter;
    A->material = B.material;
    void* S = (void*) A;
    return S;
}
void Cup_del(void* S)
{
    delete (Cup*) S;
}
// вывод информации о стеке
void Cup_out(DLList List)
{
    Cup A;
    List.MoveFirst();
    system("clear");
    if(!List.Count)
    {
        cout << "список пустой" << endl;
        return;
    }
    for(int i = 0; i < List.Count; i++)
    {
        A = *((Cup*) List.C->data);
        cout << "---------------------------------------" << endl;
        cout << "|объем = " << A.volume << endl;
        cout << "|высота = " << A.height << endl;
        cout << "|диаметр = " << A.diameter << endl;
        cout << "|материал = " << A.material << endl;
        cout << "---------------------------------------" << endl;
        List.MoveNext();
    }
}
// ввод элемента стека
void Cup_cin(Cup& A)
{
    cout << "введите ваши данные:" << endl;
    cout << "объем = "; cin >> A.volume;
    cout << "высота = "; cin >> A.height;
    cout << "диаметр = "; cin >> A.diameter;
    cout << "материал = "; cin >> A.material;
}