#include <iostream>
#include <fstream>
#include <sstream>
#include "A.h"
#include "T.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Apple A;
    Tree* T = NULL;
    int m = 1;

    // консольный интерфейс взаимодействия с пользователем
    while(m)
    {
        // открываем файл для считывания данных
        ifstream file("data.txt");
        string line;
        system("clear");

        // вывод меню
        cout << "___________________________________________________" << endl;
        cout << "1. сортировать по цвету" << endl;
        cout << "2. сортировать по цене" << endl;
        cout << "3. показать яблоки по цене ниже указанной" << endl;
        cout << "4. показать яблоки цвет которых начинается с указаной буквы" << endl;
        cout << "0. выход" << endl;
        cout << "___________________________________________________" << endl;
        cin >> m;

        switch(m)
        {
            case 1:
            {
                // считываем данные из файла с помощью потока
                while(getline(file, line))
                {
                    istringstream line_F(line);
                    line_F >> A.color >> A.weight >> A.country >> A.price;
                    // выполняем сортировку
                    Add_color(T, Init(A));
                }

                system("clear");
                Print(T);
                
                cin.ignore(256,'\n');
                cin.get();
                break;
            }
            // для остальных типов происходят такие же действия
            case 2:
            {
                while(getline(file, line))
                {
                    istringstream line_F(line);
                    line_F >> A.color >> A.weight >> A.country >> A.price;
                    Add_price(T, Init(A));
                }

                system("clear");
                Print(T);
                
                cin.ignore(256,'\n');
                cin.get();
                break;
            }
            case 3:
            {
                float price;
                cout << "Price = "; 
                cin >> price;

                while(getline(file, line))
                {
                    istringstream line_F(line);
                    line_F >> A.color >> A.weight >> A.country >> A.price;
                    Add_price(T, Init(A));
                }

                system("clear");
                Print_price(T, price);
                
                cin.ignore(256,'\n');
                cin.get();
                break;
            }
            case 4:
            {
                char a;
                cout << "Буква = "; cin >> a;

                while(getline(file, line))
                {
                    istringstream line_F(line);
                    line_F >> A.color >> A.weight >> A.country >> A.price;
                    Add_color(T, Init(A));
                }

                system("clear");
                Print_color(T, a);
                
                cin.ignore(256,'\n');
                cin.get();
                break;
            }
        }
        Delete(T);
        file.close();
    }
    return 0;
}