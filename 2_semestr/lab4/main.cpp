#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// создаем структуру, ноутбука с полями память, оперативная память, модель и цвет
struct laptop
{
    int memory;
    int RAM;
    string model;
    string color;
};

// создаем стек
struct MyQueue
{
    struct Node
    {
        char* data;
        int nnn;
        Node* next;
    };
    Node* First = NULL;
    int Count = 0;
    bool Push(char*, int n);
    bool Pop(char*&, int& n);
};

// функция добавления в стек
bool MyQueue::Push(char* data, int n)
{
    if(!First)
    {
        First = new Node;
        First -> next = NULL;
        First -> data = new char[n];
        // проходим символам строки и записываем полученные данные в стек
        for(int i = 0; i < n; i++) 
            (First -> data)[i] = data[i];
        Count = 1;
        First -> nnn = n;
    }
    else
    {
        Node *temp;
        temp = First;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = new Node;
        temp -> next -> data = new char[n];
        for(int i = 0; i < n; i++) (temp -> next -> data)[i] = data[i];
        temp -> next -> nnn = n;
        temp -> next -> next = NULL;
        Count++;
    }
    return true;
}
// функция удаления из стека
bool MyQueue::Pop(char*& data, int& n)
{
    if(!First) return false;
    Node* temp = First -> next;
    n = First -> nnn;
    data = new char[n];
    for(int i = 0; i < First -> nnn; i++) 
        data[i] = (First -> data)[i];
    delete[] (First -> data);
    delete First;
    First = temp;
    Count--;
    return true;
}
// функция получения товара из бинарного файла
void GetSeria(char*& data, int &n, laptop A)
{
    // выясняем количество символов в модели и цвете
    size_t s1 = A.model.size();
    size_t s2 = A.color.size();
    int n1 = sizeof(int);
    int n2 = sizeof(int);
    int n3_size = sizeof(size_t);
    int n3 = s1;
    int n4_size = sizeof(size_t);
    int n4 = s2;

    // записываем все полученные данные в строку
    n = n1 + n2 + n3_size + n3 + n4_size + n4;
    data = new char [n];

    char* d1 = reinterpret_cast<char*> (&A.memory);
    char* d2 = reinterpret_cast<char*> (&A.RAM);
    char* d3_size = reinterpret_cast<char*> (&s1);
    char* d3 = const_cast<char*> (A.model.c_str());
    char* d4_size = reinterpret_cast<char*> (&s2);
    char* d4 = const_cast<char*> (A.color.c_str());

    for(int i = 0; i < n1; i++)
        data[i] = d1[i];
    for(int i = 0; i < n2; i++) 
        data[i + n1] = d2[i];
    for(int i = 0; i < n3_size; i++) 
        data[i + n1 + n2] = d3_size[i];
    for(int i = 0; i < n3; i++) 
        data[i + n1 + n2 + n3_size] = d3[i];
    for(int i = 0; i < n4_size; i++) 
        data[i + n1 + n2 + n3_size + n3] = d4_size[i];
    for(int i = 0; i < n4; i++) 
        data[i + n1 + n2 + n3_size + n3 + n4_size] = d4[i];
}

void GetDeSeria(char* data, int n, laptop& A)
{
    int n1, n2, n3_size, n3, n4_size, n4;

    n1 = sizeof(int);
    n2 = sizeof(int);
    n3_size = sizeof(size_t);
    
    size_t p1 = *reinterpret_cast<size_t*> (data + n1 + n2);
    n3 = p1;

    string s1(data + n1 + n2 + n3_size, p1);
    n4_size = sizeof(size_t);

    size_t p2 = *reinterpret_cast<size_t*> (data + n1 + n2 + n3_size + n3);
    n4 = p2;

    string s2(data + n1 + n2 + n3_size + n3 + n4_size, p2);

    A.memory = *reinterpret_cast<int*> (data);
    A.RAM = *reinterpret_cast<int*> (data + n1);
    A.model = s1;
    A.color = s2;
}

// получение информации из бинарного файла
bool InputBinaryFile(MyQueue &Q)
{
    fstream f_in("out.dat", ios::in | ios::binary);
    if(!f_in)
    {
        return false;
    }
    laptop A;
    int n = 0;
    while(!f_in.eof())
    {
        if(f_in.read((char*) &n, sizeof(int)))
        {
        char* data = new char[n];
        f_in.read(data, n);
        GetDeSeria(data, n, A);
        delete[] data;
        GetSeria(data, n, A);
        Q.Push(data, n);
        }
    }
    f_in.close();
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // создаем стек
    MyQueue Q;
    char* data;
    int n = 0;
    int m = 1;
    laptop A;
    // считываем данные из файла
    InputBinaryFile(Q);
    // меню на основе switch
    while(m)
    {
        cout << "1. добавить товар в очередь" << endl;
        cout << "2. вытащить товар" << endl;
        cout << "3. показать и очистить очередь" << endl;
        cout << "0. выход" << endl;
        cin >> m;
        switch(m)
        {
            case 1:
            {
                system("clear");
                cout << "Введите характеристики продукта:" << endl;
                cout << "память = "; cin >> A.memory;
                cout << "оперативная память = "; cin >> A.RAM;
                cout << "модель = "; cin >> A.model;
                cout << "цвет = "; cin >> A.color;
                // добавляем элемент в стек
                GetSeria(data, n, A);
                Q.Push(data, n);
                system("clear");
                break;
            }
            case 2:
            {
                // проверяем есть ли элемент в стеке если есть удаляем, если нет выводим соответствующее сообщение
                system("clear");
                laptop A_x;
                bool metka = false;
                cout << "Введите характеристики продукта:" << endl;
                cout << "память = "; cin >> A_x.memory;
                cout << "оперативная память = "; cin >> A_x.RAM;
                cout << "модель = "; cin >> A_x.model;
                cout << "цвет = "; cin >> A_x.color;
                int Y = Q.Count;
                for(int i = 0; i < Y; i++)
                {
                    Q.Pop(data, n);
                    GetDeSeria(data, n, A);
                    delete[] data;
                    if(A.memory != A_x.memory || A.RAM != A_x.RAM || A.model != A_x.model || A.color != A_x.color)
                    {
                        GetSeria(data, n, A);
                        Q.Push(data, n);
                        delete[] data;
                    }
                    else
                    {
                        metka = true;
                        break;
                    }
                }
                if(!metka) cout << "продукт не найден" << endl;
                cin.ignore(256,'\n');
                cin.get();
                system("clear");
                break;
            }
            case 3:
            {
                // пройтись по всем элементам стека вывести информацию и очистить стек
                while(Q.Count)
                {
                    Q.Pop(data, n);
                    GetDeSeria(data, n, A);
                    delete[] data;
                    cout << "память = " << A.memory << endl;
                    cout << "оперативная память = " << A.RAM << endl;
                    cout << "модель = " << A.model << endl;
                    cout << "цвет = " << A.color << endl << endl;
                }
                cin.ignore(256,'\n');
                cin.get();
                system("clear");
                break;
            }
        }
    }

    while(Q.Count)
    {
        Q.Pop(data, n);
        delete[] data;
    }
}