#include <iostream>
#include <fstream>
#include <string>

struct Node
{
    
    int data;
    Node* next;
};


Node* First = NULL;
Node* Current = NULL;
int Count = 0;

bool Create_list(int);
bool Add_next(int);
bool Remove(int&);
bool Print();
bool Move_first();
bool Move_next();
bool Read_file();

int main()
{
    setlocale(LC_ALL, "Russian");
    int i;
    for (i = 0; i < 10; i++)
            Add_next(i);
    Print();
    
    
    Move_first();
    while (Current != NULL)
    {
        if (Current->data  == 5)
            Remove(i);
        else if(!Move_next())
            Current = NULL;
    }
    
    Print();
    Move_first();

    Read_file();
    
    return 0;
}

bool Create_list(int data)
{
    First = new Node;
    First->next = NULL;
    First->data = data;
    Current = First;
    Count++;
    return true;
}

bool Add_next(int data)
{
    if (First == NULL)
        return Create_list(data);
    Node* temp = Current->next;
    Current->next = new Node;
    Current->next->next = temp;
    Current = Current->next;
    Current->data = data;
    Count++;
    return true;
}

bool Remove(int& data)
{
    if (Current==NULL)
        return false;
    
    Node* temp;

    if (Current == First)
    {
        temp = First;
        First = First->next;
        data = temp->data;
        delete temp;
        Count--;
        Current = First;
        return true;
    }

    if (Current->next == NULL)
    {
        data = Current->data;
        temp = First;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
        Count--;
        Current = temp;
        return true;
    }

    temp = First;
    data = Current->data;
    do
    {
        if (temp->next == Current)
        {
            temp->next = Current->next;
            delete Current;
            Current = temp;
            Count--;
            return true;
        }
        temp = temp->next;
    }while(temp->next != NULL);
    return false;
}

bool Print()
{
    if (Count == 0)
        std::cout<<std::endl<<"список пустой"<<std::endl;
    else
        std::cout<<std::endl<<"список:\t";
    if (First == NULL)
        return false;
    Node* temp = First;

    do
    {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != NULL);
    std::cout<<std::endl<<"количество = "<<Count<<std::endl;
    return true;
}


bool Move_first()
{
    if (First == NULL)
        return false;
    Current = First;
    return true;
}

bool Move_next()
{
    if (First == NULL)
        return false;
    if (Current == NULL)
    {
        Current = First;
        return true;
    }
    if (Current->next == NULL)
        return false;
    Current = Current->next;
    return true;
}

bool Read_file()
{
    std::ofstream f;
    f.open("data.txt");
    if (f.is_open())
        f<<"hello";
    
    return true;
}