#include <iostream>
#include <fstream>
#include <sstream>
#include "DLList.h"
#include "Cup.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    DLList List;
    void* S;
    Cup A;
    int m = 1;
    ifstream file("data.txt");
    string line;
    while(getline(file, line))
    {
        istringstream line_F(line);
        line_F >> A.volume >> A.height >> A.diameter >> A.material;
        S = Cup_init(A);
        List.AddNext(S);
    }
    file.close();
    while(m)
    {
        system("clear");
        cout << "--------------------------------------" << endl;
        cout << "|добавить элемент:                   |" << endl;
        cout << "|1 в начало                          |" << endl;
        cout << "|2 в конец                           |" << endl;
        cout << "|3 на к-тую позицию                  |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "|удалить элемент:                    |" << endl;
        cout << "|4 с начала                          |" << endl;
        cout << "|5 с конца                           |" << endl;
        cout << "|6 с к-той позиции                   |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "|7 сортировать по \"объем\"            |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "|8 очистить список                   |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "|9 загрузить данные из списка в файл |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "|10 показать список                  |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "|0 выход                             |" << endl;
        cout << "--------------------------------------" << endl;
        cin >> m;
        switch(m)
        {
        case 1:
        {
            system("clear");
            Cup_cin(A);
            S = Cup_init(A);
            List.AddFirst(S);
            Cup_out(List);
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 2:
        {
            system("clear");
            Cup_cin(A);
            S = Cup_init(A);
            List.AddLast(S);
            Cup_out(List);
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 3:
        {
            system("clear");
            int k;
            cout << "введите номер позиции от 1"<< " to " << List.Count + 1 << endl;
            cout << "k = "; cin >> k;
            k--;
            if(k >= 0 & k <= List.Count)
            {
            Cup_cin(A);
            S = Cup_init(A);
            if(k == 0)
            {
                List.AddFirst(S);
            }
            else
            {
                if(k == List.Count)
                {
                List.AddLast(S);
                }
                else
                {
                List.Move_k(k - 1);
                List.AddNext(S);
                }
            }
            Cup_out(List);
            }
            else cout << "ошибка" << endl;
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 4:
        {
            system("clear");
            if(List.DelFirst(S))
            {
            Cup_del(S);
            Cup_out(List);
            }
            else
            {
            cout << "ошибка" << endl;
            }
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 5:
        {
            system("clear");
            if(List.DelLast(S))
            {
            Cup_del(S);
            Cup_out(List);
            }
            else
            {
            cout << "ошибка" << endl;
            }
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 6:
        {
            system("clear");
            int k;
            if(!List.Count)
            {
            cout << "ошибка" << endl;
            cin.ignore(256,'\n');
            cin.get();
            break;
            }
            cout << "введите номер позиции от 1" << " to " << List.Count << endl;
            cout << "k = "; cin >> k;
            k--;
            if(k >= 0 & k <= List.Count)
            {
            if(k == 0)
            {
                List.DelFirst(S);
            }
            else
            {
                if(k == (List.Count - 1))
                {
                List.DelLast(S);
                }
                else
                {
                List.Move_k(k);
                List.Del(S);
                }
            }
            Cup_out(List);
            }
            else cout << "ошибка" << endl;
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 7:
        {
            system("clear");
            void* tmp;
            for(int i = 0; i < List.Count; i++)
            {
            List.MoveLast();
            for(int j = (List.Count - 1); j >= (i + 1); j--)
            {
                if(((Cup*) List.C->data)->volume < ((Cup*) List.C->prev->data)->volume)
                {
                tmp = List.C->data;
                List.C->data = List.C->prev->data;
                List.C->prev->data = tmp;
                }
                List.MovePrev();
            }
            }
            Cup_out(List);
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 8:
        {
            List.MoveFirst();
            while(List.Del(S))
            {
            Cup_del(S);
            }
            Cup_out(List);
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 9:
        {
            ofstream file("data.txt");
            List.MoveFirst();
            for(int i = 0; i < List.Count; i++)
            {
            A = *((Cup*) List.C->data);
            file << A.volume << " "  << A.height << " "<< A.diameter << " " << A.material << endl;
            List.MoveNext();
            }
            file.close();
            cout << "загрузка завершена!" << endl;
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        case 10:
        {
            system("clear");;
            Cup_out(List);
            cin.ignore(256,'\n');
            cin.get();
            break;
        }
        }
    }
    List.MoveFirst();
    while(List.Del(S))
    {
        Cup_del(S);
    }
    cin.ignore(256,'\n');
    cin.get();
    return 0;
}
