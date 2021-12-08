#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

// создаем структуру телефона, модель, оперативная память, память и батарея
struct phone
{
    string Model;
    int RAM;
    int Memory;
    int Battery;
};

// создаем стек, внутри которого создаем узел
struct MyStack
{
    struct Node
    {
        phone data;
        Node *prev;
    };
    // верхний элемент стека
    Node *Top = NULL;
    // количество элементов в стеке
    int Count = 0;
    // функция добавления элемента в стека
    bool Push(phone);
    // функция вытаскивания элемента из стека
    bool Pop(phone&);
    // функция вывода информации о стеке
    void Info();
};

// описываем функцию добавления элемента в стек
bool MyStack::Push(phone dt)
{
    // если верхнего элемента нет, создаем стек с 1 элементом
    if(!Top)
    {
        Top = new Node;
        Top -> prev = NULL;
        Count = 1;
    }
    // иначе добавляем новый элемент в начало стека
    else
    {
        Node *temp;
        temp = new Node;
        temp -> prev = Top;
        Top = temp;
        Count++;
    }
    Top -> data = dt;
    // если добавление прошло успешно возвращаем true
    return true;
}

// описываем функцию извлечение элемента из стека
bool MyStack::Pop(phone& dt)
{
    // если список пустой вернуть false
    if(!Top) return false;
    // иначе сохранить предыдущие элементы в буфер, удалить элемент и сместить предыдущие элементы, затем уменьшить количество элементов
    Node *temp = Top -> prev;
    dt = Top -> data;
    delete Top;
    Top = temp;
    Count--;
    return true;
}

// описание функции вывода информации о стеке
void MyStack::Info()
{
    if(!Top) cout << "стэк пустой" << endl;
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

// описание функции вывода информации о элементах стека
void print(MyStack &S, MyStack &V)
{
    phone dt;
    while(S.Count)
    {
        // проходим по всем элементам, выбираем первый выводим информацию о нем, удаляем, затем добавляем его в буфер для восстановления порядка
        S.Pop(dt);
        cout <<"\tмодель = " << dt.Model << endl;
        cout <<"\tоперативная память = " << dt.RAM << endl;
        cout <<"\tпамять = " << dt.Memory << endl;
        cout <<"\tемкость батареи = " << dt.Battery << endl << endl;
        V.Push(dt);
    }
    // восстанавливаем порядок эллементов
    while(V.Count)
    {
        V.Pop(dt);
        S.Push(dt);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // создаем 2 стека, исходный и буферный
    MyStack S;
    MyStack V;
    phone dt;
    // считываем данные из файла
    ifstream file("phone.txt");
    string line;
    // считываем строку
    while(getline(file, line))
    {
        istringstream line_F(line);
        // считываем каждое новое слово
        line_F >> dt.Model >> dt.RAM >> dt.Memory >> dt.Battery;
        // добавляем элемент в стек
        S.Push(dt);
    }
    file.close();
    // создаем меню с помощью switch
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
                // так как я компилирую код из под linux чтобы очистить консоль использую clear, а не cls
                system("clear");
                cout << "введите характеристики телефона:" << endl;
                cout << "модель = "; cin >> dt.Model;
                cout << "оперативная память = "; cin >> dt.RAM;
                cout << "память = "; cin >> dt.Memory;
                cout << "емкость батареи = "; cin >> dt.Battery;
                // добавляем элемент с заданными параметрами в стек
                S.Push(dt);
                system("clear");
                break;
            }
            case 2:
            {
                system("clear");
                phone dt_x;
                // метка которая при значении ложь говорит что элемент не найден
                bool metka = false;
                cout << "введите характеристики телефона:" << endl;
                cout << "модель = "; cin >> dt_x.Model;
                cout << "оперативная память = "; cin >> dt_x.RAM;
                cout << "память = "; cin >> dt_x.Memory;
                cout << "емкость батареи = "; cin >> dt_x.Battery;
                // перебираем элементы стека
                while(S.Count)
                {
                    // ищем соответствие, если соответствие не найдено, удаляем элемент из стека и добавляем элемент в буферный стек чтобы потом сохранить порядок
                    S.Pop(dt);
                    if(dt.Model != dt_x.Model || dt.RAM != dt_x.RAM || dt.Memory != dt_x.Memory || dt.Battery != dt_x.Battery)
                    {
                        V.Push(dt);
                    }
                    // как только соответствие найдено выходим из цикла
                    else
                    {
                        metka = true;
                        break;
                    }
                }
                if(!metka) cout << "телефон не найден" << endl;
                // восстанавливаем порядок элементов
                while(V.Count)
                {
                    V.Pop(dt);
                    S.Push(dt);
                }
                // чтобы подождать пока пользователь введет символ используем cin.get
                cin.ignore(256,'\n');
                cin.get();
                system("clear");
                break;
            }
            case 3:
            {
                // проходим по всем стеку и удаляем элементы
                system("clear");
                while(S.Count)
                {
                    S.Pop(dt);
                }
                break;
            }
            case 4:
            {
                // вывод информации о элементах стека
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