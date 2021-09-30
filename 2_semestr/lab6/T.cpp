#include <iostream>
#include <algorithm>
#include <vector>
#include "A.h"
#include "T.h"

using namespace std;

// функция сортировки строк, если сортировка завершилась верно возвращает true
bool sort_str(string a, string b)
{
    vector <string> v = {a, b};
    sort(v.begin(), v.end());
    if(v[0] == a) return true;
    else return false;
}

// функция сортировки по цене
void Add_price(Tree*& T, Apple* data)
{
    if(!T)
    {
        T = new Tree;
        T->data = data;
        T->left = NULL;
        T->right = NULL;
        return;
    }
    //если цена слева меньше цены справа то добавляем в дерево на левую позицию левую цену и наоборот 
    if(data->price < T->data->price) Add_price(T->left, data);
         else Add_price(T->right, data);
}

// функция сортировки по цвету
void Add_color(Tree*& T, Apple* data)
{
    if(!T)
    {
        T = new Tree;
        T->data = data;
        T->left = NULL;
        T->right = NULL;
        return;
    }
    // аналогично тому что происходит при сортировке по цене
    if(sort_str(data->color, T->data->color)) Add_color(T->left, data);
    else Add_color(T->right, data);
}

// функция вывода отсортированного дерева в нормальном виде 
void Print(Tree* T)
{
    if(!T) return;
    Print(T->left);
    A_Print(T->data);
    Print(T->right);
}

// функция очистки памяти
void Delete(Tree*& T)
{
    if(T)
    {
        if(T->left) Delete (T->left);
        if(T->right) Delete(T->right);
        Del(T->data);
        delete T;
        T = NULL;
  }
}

// функция вывода яблок по цене ниже указаной пользователем
void Print_price(Tree* T, float price)
{
    if(!T) return;
    Print_price(T->left, price);
    if(T->data->price < price) A_Print(T->data);
    Print_price(T->right, price);
}

// функция вывода яблок цвет которых начинается с определенной буквы
void Print_color(Tree* T, char a)
{
    if(!T) return;
    Print_color(T->left, a);
    if(T->data->color[0] == a) A_Print(T->data);
    Print_color(T->right, a);
}