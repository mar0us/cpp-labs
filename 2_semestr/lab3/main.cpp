#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;

struct Node
{
    string name;
    int length;
    float weight;
    bool is_edible;
    Node* next;
};


Node* First = NULL;
Node* Current = NULL;
int Count = 0;

bool Create_list(string, int, float, bool);
bool Add_next(string, int, float, bool);
bool Remove(string&, int&, float&, bool&);
bool Print();
bool Move_first();
bool Move_next();
bool Read_file();
void strip(string&, std::vector<string>&);

int main()
{
    setlocale(LC_ALL, "Russian");
    int i;
    // for (i = 0; i < 10; i++)
            // Add_next(i);
    Print();
    string name;
    int length;
    float weight;
    bool is_edible;
    
    Move_first();
    while (Current != NULL)
    {
        if (Current->weight == 5)
        {
            Remove(name, length, weight, is_edible);
            std::cout<<"удалено";
        }
            
        else if(!Move_next())
            Current = NULL;
    }

    Read_file();
    
    Print();
    Move_first();

    
    return 0;
}

bool Create_list(string name, int length, float weight, bool is_edible)
{
    First = new Node;
    First->next = NULL;
    First->name = name;
    First->length = length;
    First->weight = weight;
    First->is_edible = is_edible;
    Current = First;
    Count++;
    return true;
}

bool Add_next(string name, int length, float weight, bool is_edible)
{
    if (First == NULL)
        return Create_list(name, length, weight, is_edible);
    Node* temp = Current->next;
    Current->next = new Node;
    Current->next->next = temp;
    Current = Current->next;
    Current->name = name;
    Current->length = length;
    Current->weight = weight;
    Current->is_edible = is_edible;
    Count++;
    return true;
}

bool Remove(string& name, int& length, float& weight, bool& is_edible)
{
    if (Current==NULL)
        return false;
    
    Node* temp;

    if (Current == First)
    {
        temp = First;
        First = First->next;
        name = temp->name;
        length = temp->length;
        weight = temp->weight;
        is_edible = temp->is_edible;
        delete temp;
        Count--;
        Current = First;
        return true;
    }

    if (Current->next == NULL)
    {
        name = Current->name;
        length = Current->length;
        weight = Current->weight;
        is_edible = Current->is_edible;
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
    name = Current->name;
    length = Current->length;
    weight = Current->weight;
    is_edible = Current->is_edible;
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
        std::cout<<std::endl<<"список:\n";
    if (First == NULL)
        return false;
    Node* temp = First;

    do
    {
        std::cout<<temp->name<<" "<<temp->length<<" "<<temp->weight<<" "<<temp->is_edible<<" "<<std::endl;
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
    bool is_edible;   
    string line;
    std::ifstream f;
    f.open("basket.txt");
    if (f.is_open())
    {
        while (getline(f, line))
        {
            std::vector<string> arr;
            strip(line, arr);
            // std::cout << typeid(arr[1]).name()   << std::endl;
            // float a = std::stof(arr[2]);
            
            if (arr[3] == "false")
                is_edible = false;
            else
                is_edible = true;
            Add_next(arr[0], std::stoi(arr[1]), std::stof(arr[2]), is_edible);

            // Add_next("ww", 5, 2.4, false);
            // std::cout<<"имя товара: "<<arr[0]<<" длина товара: "<<arr[1]<<" вес товара: "<<arr[2]<<" товар съедобен: "<<arr[3]<<std::endl;
            // std::cout<<strip(line)<<std::endl;
        }
        
    }
    f.close();
        
    
    return true;
}



void strip(string& str, std::vector<string>& arr)
{
    // std::vector<string> arr;
    // string str ("Привет; Как; Дела");
    string delim(" ");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while( ( next = str.find( delim, prev ) ) != string::npos ){
        //Отладка-start
        string tmp = str.substr( prev, next-prev );
        // std::cout << tmp << std::endl;
        //Отладка-end
        arr.push_back( str.substr( prev, next-prev ) );
        prev = next + delta;
    }
    //Отладка-start
    string tmp = str.substr( prev );
    // std::cout << tmp << std::endl;
    //Отладка-end
    arr.push_back( str.substr( prev ) );

    // std::cout<<arr[3]<<std::endl;

}