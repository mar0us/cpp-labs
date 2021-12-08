#include<stdio.h>


template<typename T1>
class List
{
public:
    List();
    ~List();
    void push(T1);
    void push(T1, int);
    int get_size() { return this->size; }

    T1& operator[](const int);
    T1 delete_elem(const int);
    // T1& set(const int index);

private:
    template<typename T2>
    class Node
    {
    public:
        Node *pNext;
        T2 data;

        Node(T2 data = T2(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int size = 0;
    Node<T1> *head;
};

template<typename T1>
List<T1>::List()
{
    this->size = 0;
    this->head = nullptr;
}

template<typename T1>
List<T1>::~List()
{

}


template<typename T1> 
void List<T1>::push(T1 data)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T1>(data);
    }
    else
    {
        Node<T1> *current = this->head;
        while (current->pNext != nullptr)
        {
            // current->pNext = current->pNext;
            current = current->pNext;
        }
        current->pNext = new Node<T1>(data);
    }
    this->size++;
}

template<typename T1> 
T1 &List<T1>::operator[](int index)
{
    int current_index = 0;  
    Node<T1> *current = this->head;
    while (current != nullptr)
    {
        if (current_index == index)
        {
            return current->data;
        }
        current = current->pNext;
        current_index++;
    }
    // T1 a = T1();
    // return ;
}

template<typename T1> 
T1 List<T1>::delete_elem(int index)
{
    if (index == 0)
    {
        T1 buf = this->head->data;
        this->head = this->head->pNext;
        // printf("%d\n", this->head->data);
        this->size--;
        return buf;

    }


    int current_index = 0;
    Node<T1> *current = this->head;

    while (current != nullptr)
    {
        if (current_index+1 == index)
        {
            Node<T1> *next = current->pNext;
            current->pNext = next->pNext;

            // delete next; next = nullptr;
            this->size--;
            return next->data;
            // current->pNext = current->pNext;

            // current = current->pNext;
            // delete current; current = nullptr;
        }
        current = current->pNext;
        current_index++;
        // printf("%d\n", current_index);
    }
}

template<typename T1> 
void List<T1>::push(T1 data, int index)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T1>(data);
    }
    else if (index == 0)
    {
        Node<T1> *current = this->head;
        this->head = new Node<T1>(data);
        this->head->pNext = current;
    }
    else
    {
        bool is_added = false;
        int current_index = 0;
        Node<T1> *current = this->head;
        while (current->pNext != nullptr)
        {
            if (current_index+1 == index)
            {
                Node<T1> *next = current->pNext;
                current->pNext = new Node<T1>(data);
                current = current->pNext;
                current->pNext = next;
                is_added = true;
                break;
            }
            // current->pNext = current->pNext;
            current = current->pNext;
            current_index++;
        }

        if (!is_added)
        {
            current->pNext = new Node<T1>(data);
        }
        // current->pNext = new Node<T1>(data);
    }
    this->size++;
}


// template<class T1> 
// T1 &List<T1>::set(int index)
// {
//     int current_index = 0;  
//     Node<T1> *current = this->head;
//     while (current != nullptr)
//     {
//         if (current_index == index)
//         {
//             return current->data;
//         }
//         current = current->pNext;
//         current_index++;
//     }
// }


int main()
{
    // int i = int();

    List<int> lst;
    int i_del = 1;
    lst.push(1);
    lst.push(2);
    lst.push(3);
    lst.push(6);
    // lst[2] = 5;
    // printf("элемент = %d\n", lst[1]);

    for (int i = 0; i < lst.get_size(); i++)
    {
        printf("%d ", lst[i]);
    }
    printf("длина = %d\n", lst.get_size());
    
    lst.push(10, 0);
    printf("%d ", lst[1]);
    // printf("%d\n", lst.delete_elem(1));
    printf("длина = %d\n", lst.get_size());
    for (int i = 0; i < lst.get_size(); i++)
    {
        printf("%d ", lst[i]);
    }
    printf("длина = %d\n", lst.get_size());


    // printf("элемент который нужно удалить i[%d] = %d\n", i_del, lst.delete_elem(i_del));
    // lst.delete_elem(i_del);
    // printf("элемент = %d\n", lst[1]);
    // lst.set(2) = 5;
    // printf("hello world %d\n", lst.get_size());
    // printf("элемент = %d\n", lst[2]);

    return 0;
}