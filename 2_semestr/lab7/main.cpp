#include <iostream>
#include <fstream>
#include <stack>
#include <climits>

using namespace std;

// прототипы

int** Read(string, int&, int&);
void Delete(int**&, int);
int* dijkstra(int**, int, int);
void dijkstra_route(int**, int, int, int, int*, stack <int>&);

int main()
{
    setlocale(LC_ALL, "Russian");
    // создаем файл для выходных данных
    ofstream out;
    out.open("out.txt");

    int n, m;
    stack <int> route;

    int** A = Read("data.txt", n, m);

    // проверяем входной файл на валидность
    if(A == NULL | n != m)
    {
        cout << "Ошибка";
        out << "Ошибка";
        return 0;
    }

    int s;
    cout << "Стартовая вершина: "; cin >> s;
    s--;
    int* d = dijkstra(A, n, s);
    // выводим полученый маршрут расстояний в файл и консоль
    for(int i = 0; i < n; i++)
    {
        cout << s + 1 << " -> " << i + 1 << " = " << d[i] << endl;
        out << s + 1 << " -> " << i + 1 << " = " << d[i] << endl;
    }

    int end;
    cout << "Конечная вершина: "; cin >> end;
    end--;

    dijkstra_route(A, n, s, end, d, route);

    cout << "Маршрут: " << endl;
    out << "Маршрут: " << endl;
    // выводим машрут в консоль и файл
    while(!route.empty())
    {
        cout << " -> " << route.top();
        out << " -> " << route.top();
        route.pop();
    }
    cout << endl;
    out << endl;
    out.close();
    Delete(A, n);
    delete[] d;
    return 0;
}

// функция считывания данных из файла
int** Read(string file_name, int& n, int& m)
{
    // открываем файл
    ifstream in(file_name);
    if(in.is_open())
    {
        int count = 0;
        int temp;

        // считаем количество символов в файле
        while(!in.eof())
        {
            in >> temp;
            count++;
        }

        in.seekg(0, ios::beg);
        in.clear();

        int count_space = 0;
        char symbol;

        while(!in.eof())
        {
            // считаем количество пробелов в строке
            in.get(symbol);
            if(symbol == ' ') count_space++;
            if(symbol == '\n') break;
        }

        in.seekg(0, ios::beg);
        in.clear();

        // вычисляем вершину графа
        n = count / (count_space + 1);
        m = count_space + 1;

        int **x = new int*[n];
        
        // записываем в двумерный массив верншины графа, где это номер начальной вершины, а m номер конечной вершины
        for(int i = 0; i < n; i++) x[i] = new int[m];
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    in >> x[i][j];
                }
            }
        in.close();
        return x;
    }
    in.close();
    return NULL;
}

// реализация функции очистки памяти
void Delete(int**& x, int n)
{
    for (int i = 0; i < n; i++) delete[] x[i];
    delete[] x;
}

// реализация алгоритма дейкстры
int* dijkstra(int** A, int n, int s)
{
    const int inf = INT_MAX;
    int* d = new int[n];
    bool* v = new bool[n];
    int index, u;
    
    // заполняем массивы начальными данными
    for(int i = 0; i < n; i++)
    {
        d[i] = inf;
        v[i] = false;
    }

    d[s] = 0;
    // идем от начальной вершины к первой вершине запоминаем расстояние идем ко второй вершине запоминаем расстояние и тд. пока не дойдем до конца, затем выбираем
    // вершину с наименьшим расстоянием до исходной вершины и идем от нее к следующей так до конца, на выходе получаем кратчайший маршрут в виде длин
    for(int count = 0; count < n - 1; count++)
    {
        int min = inf;
        for(int i = 0; i < n; i++)
            if(!v[i] && d[i] <= min)
            {
                min = d[i];
                index = i;
            }
        u = index;
        v[u] = true;
        for(int i = 0; i < n; i++)
            if(!v[i] && A[u][i] && d[u] != inf && d[u] + A[u][i] < d[i]) 
                d[i] = d[u] + A[u][i];
    }
    delete[] v;
    return d;
}

// реализация функции составления маршрута
void dijkstra_route(int** A, int n, int s, int end, int* d, stack <int>& route)
{
    route.push(end + 1);
    int weight = d[end];
    // проходим по файлу и сравниваем значения в нем с значениями в массиве маршрута если совпадают запоминаем вершину, на выходе получаем путь
    while (end != s)
    {
        for (int i = 0; i < n; i++)
            if (A[i][end] != 0)
            {
                int temp = weight - A[i][end];
                if (temp == d[i])
                {
                    weight = temp;
                    end = i;
                    route.push(i + 1);
                }
            }
    }
}
