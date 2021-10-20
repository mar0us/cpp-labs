#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// описание структуры продуктов
struct product_group
{
    int quantity;
    double price;
};

// принцип работы такой же как в предыдущем скрипте, создаем функции удаления, добавления, вывода информации
struct MyQueue
{
    struct Node
    {
        product_group data;
        Node* next;
    };
    Node* First = NULL;
    int Count = 0;
    // цена товара
    double full_cost = 0;
    // доход от продаж
    double income = 0;
    bool Push(product_group);
    bool Pop(product_group&);
    void Info();
};

bool MyQueue::Push(product_group dt)
{
    if(!First)
    {
        First = new Node;
        First -> next = NULL;
        First -> data = dt;
        Count = 1;
        // увеличиваем общую стоимость товаров
        full_cost += dt.price * dt.quantity;
    }
    else
    {
        Node *temp;
        temp = First;
        while(temp -> next != NULL) 
            temp = temp -> next;
        temp -> next = new Node;
        temp -> next -> data = dt;
        temp -> next -> next = NULL;
        Count++;
        full_cost += dt.price * dt.quantity;
    }
    return true;
}

bool MyQueue::Pop(product_group& dt)
{
    if(!First) return false;
    Node* temp = First -> next;
    dt = First -> data;
    delete First;
    First = temp;
    Count--;
    return true;
}

void MyQueue::Info()
{
    if(!First) cout << "Склад пуст" << endl;
    else
    {
        cout << endl << "Информация о складе: " << endl;
        cout << "\tРазмер склада = " << Count << endl;
        cout << "\tПервая величина = " << First -> data.quantity << endl;
        cout << "\tПервая цена = " << First -> data.price << endl << endl;
    }
}

// проверка есть ли товар который нужно продать в стеке, если есть вернуть истину иначе ложь
bool check(MyQueue Q, product_group dt_x)
{
    product_group dt;
    MyQueue::Node *a;
    a = Q.First;
    int k = 0;
    while(a -> data.price <= dt_x.price & k != Q.Count)
    {
        dt.price = a -> data.price;
        dt.quantity = a -> data.quantity;
        if(dt_x.quantity <= dt.quantity)
        {
            dt_x.quantity = 0;
        }
        else
        {
            dt_x.quantity -= dt.quantity;
        }
        if(dt_x.quantity == 0)
        {
            return true;
        }
        else
        {
            if(k < Q.Count)
            {
                k++;
                a = a -> next;
            }
        else 
            return false;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    MyQueue Q;
    product_group dt;
    product_group dt_x;
    ifstream file("data.txt");
    string line;
    while(getline(file, line))
    {
        istringstream line_F(line);
        line_F >> dt.quantity >> dt.price;
        Q.Push(dt);
    }
    file.close();
    int m = 1;
    while(m)
    {
        Q.Info();
        cout << "1. Добавление товара" << endl;
        cout << "2. Продажа товаров" << endl;
        cout << "3. Отчет" << endl;
        cout << "0. Выход" << endl;
        cin >> m;
        switch (m)
        {
        case 1:
        {
            system("clear");
            cout << "Введите цену и количество товаров:" << endl;
            cout << "Количество = "; cin >> dt.quantity;
            cout << "Цена = "; cin >> dt.price;
            Q.Push(dt);
            system("clear");
            break;
        }
        case 2:
        {
            system("clear");
            cout << "Введите цену и количество товаров:" << endl;
            cout << "Количество = "; cin >> dt_x.quantity;
            cout << "Цена = "; cin >> dt_x.price;
            dt = Q.First -> data;
            if(check(Q, dt_x))
            {
            while(dt_x.quantity)
            {
                if(dt_x.quantity <= dt.quantity)
                {
                Q.income += dt_x.quantity * (dt_x.price - dt.price);
                Q.full_cost -= dt.price * dt_x.quantity;
                dt.quantity -= dt_x.quantity;
                dt_x.quantity = 0;
                Q.First -> data.quantity = dt.quantity;
                }
                else
                {
                Q.income += dt.quantity * (dt_x.price - dt.price);
                Q.full_cost -= dt.price * dt.quantity;
                dt_x.quantity -= dt.quantity;
                dt.quantity = 0;
                }
                if(dt.quantity == 0)
                {
                Q.Pop(dt);
                dt = Q.First -> data;
                }
            }
            cout << "Продажа завершена" << endl;
            }
            else cout << "Продажа не была совершена" << endl;
            cin.ignore(256,'\n');
            cin.get();
            system("clear");
            break;
        }
        case 3:
        {
            system("clear");
            cout << "Количество единиц = " << Q.Count << endl;
            cout << "Цена товара = " << Q.full_cost << endl;
            cout << "Доход от продажи = " << Q.income << endl;
            cin.ignore(256,'\n');
            cin.get();
            system("clear");
            break;
        }
        }
    }
}