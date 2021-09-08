#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

struct phone
{
    string Model;
    int RAM;
    int Memory;
    int Battery;
};

struct MyStack
{
    struct Node
    {
        phone data;
        Node *prev;
    };
    Node *Top = NULL;
    int Count = 0;
    bool Push(phone);
    bool Pop(phone&);
    void Info();
};

bool MyStack::Push(phone dt)
{
    if(!Top)
    {
        Top = new Node;
        Top -> prev = NULL;
        Count = 1;
    }
    else
    {
        Node *temp;
        temp = new Node;
        temp -> prev = Top;
        Top = temp;
        Count++;
    }
    Top -> data = dt;
    return true;
}

bool MyStack::Pop(phone& dt)
{
    if(!Top) return false;
    Node *temp = Top -> prev;
    dt = Top -> data;
    delete Top;
    Top = temp;
    Count--;
    return true;
}

void MyStack::Info()
{
    if(!Top) cout << "Stack is empty" << endl;
    else
    {
        cout << endl << "информация о стэке: " << endl;
        cout << "\tразмер стэка = " << Count << endl;
        cout <<"\tверхняя модель = " << Top -> data.Model << endl;
        cout <<"\tверхняя оперативная память = " << Top -> data.RAM << endl;
        cout <<"\tверхняя память = " << Top -> data.Memory << endl;
        cout <<"\tверхняя емкость батареии = " << Top -> data.Battery << endl << endl;
    }
}

void print(MyStack &S, MyStack &V)
{
    phone dt;
    while(S.Count)
    {
        S.Pop(dt);
        cout <<"\tмодель = " << dt.Model << endl;
        cout <<"\tоперативная память = " << dt.RAM << endl;
        cout <<"\tпамять = " << dt.Memory << endl;
        cout <<"\tемкость батареи = " << dt.Battery << endl << endl;
        V.Push(dt);
    }
    while(V.Count)
    {
        V.Pop(dt);
        S.Push(dt);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    MyStack S;
    MyStack V;
    phone dt;
    ifstream file("phone.txt");
    string line;
    while(getline(file, line))
    {
        istringstream line_F(line);
        line_F >> dt.Model >> dt.RAM >> dt.Memory >> dt.Battery;
        S.Push(dt);
    }
    file.close();
    int m = 1;
    while(m)
    {
        S.Info();
        cout << "1. добавить телефон в корзину" << endl;
        cout << "2. вытащить телефон из корзины" << endl;
        cout << "3. очистить корзину" << endl;
        cout << "4. показать содержимое корзины" << endl;
        cout << "0. выход" << endl;
        cin >> m;
        switch(m)
        {
        case 1:
        {
            system("clear");
            cout << "введите характеристики телефона:" << endl;
            cout << "модель = "; cin >> dt.Model;
            cout << "оперативная память = "; cin >> dt.RAM;
            cout << "память = "; cin >> dt.Memory;
            cout << "емкость батареи = "; cin >> dt.Battery;
            S.Push(dt);
            system("clear");
            break;
        }
        case 2:
        {
            system("clear");
            phone dt_x;
            bool metka = false;
            cout << "введите характеристики телефона:" << endl;
            cout << "модель = "; cin >> dt_x.Model;
            cout << "оперативная память = "; cin >> dt_x.RAM;
            cout << "память = "; cin >> dt_x.Memory;
            cout << "емкость батареи = "; cin >> dt_x.Battery;
            while(S.Count)
            {
            S.Pop(dt);
            if(dt.Model != dt_x.Model || dt.RAM != dt_x.RAM || dt.Memory != dt_x.Memory || dt.Battery != dt_x.Battery)
            {
                V.Push(dt);
            }
            else
            {
                metka = true;
                break;
            }
            }
            if(!metka) cout << "телефон не найден" << endl;
            while(V.Count)
            {
            V.Pop(dt);
            S.Push(dt);
            }
            cin.ignore(256,'\n');
            cin.get();
            system("clear");
            break;
        }
        case 3:
        {
            system("clear");
            while(S.Count)
            {
            S.Pop(dt);
            }
            break;
        }
        case 4:
        {
            system("clear");
            print(S,V);

            cin.ignore(256,'\n');
            cin.get();
            system("clear");
            break;
        }
        }
    }
}