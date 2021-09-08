#include<iostream>

using namespace std;

struct datetime
{
    int second, minute, hour, day, month, year;
};

void get_date(datetime*, int, int, int, int, int, int);
bool check_date(int, int);
void print_date(datetime*);
void next_date(datetime*);

int main()
{
    setlocale(LC_ALL, "Russian");

    datetime time;

    get_date(&time, 3, 5, 2, 32, 10, 1998);

    print_date(&time);
    return 0;
}


bool check_date(int month, int day)
{
    int month_31day[7] = {1, 3, 5, 7, 8, 10, 12};
    
    if (month == 2)
        if (day > 28)
            return false;
    
    for (int i = 0; i < 7; i++)
    {
        if (month == month_31day[i])
            
    }
    
}

void get_date(datetime* date, int second, int minute, int hour, int day, int month, int year)
{
    if (second < 0 or second > 60)
    {
        cout<< "неверный формат секунд, автоматически выставилось 0"<<endl;
        date->second = 0;
    }else
        date->second = second;

    if (minute < 0 or minute > 60)
    {
        cout<< "неверный формат минут, автоматически выставилось 0"<<endl;
        date->minute = 0;
    }else
        date->minute = minute;
       
    if (hour < 0 or hour > 24)
    {
        cout<< "неверный формат часов, автоматически выставилось 0"<<endl;
        date->hour = 0;
    }else
        date->hour = hour;

    if (day < 1 or day > 31)
    {
        cout<< "неверный формат дней, автоматически выставилось 1"<<endl;
        date->day = 1;
    }else
        date->day = day;
        
    if (month < 0 or month > 12)
    {
        cout<< "неверный формат месяцев, автоматически выставилось 1"<<endl;
        date->month = 1;
    }else
        date->month = month;

    if (year < 0)
    {
        cout<< "неверный формат года, автоматически выставилось "<<endl;
        date->year = 0;
    }else
        date->year = year;
}

void print_date(datetime* date)
{
    cout<<"текущие время и дата:"<<endl;
    cout<<"секунда: "<< date->second <<endl;
    cout<<"минута: "<< date->minute <<endl;
    cout<<"час: "<< date->hour <<endl;
    cout<<"день: "<< date->day <<endl;
    cout<<"месяц: "<< date->month <<endl;
    cout<<"год: "<< date->year <<endl;
}

void next_date(datetime* date)
{
    date->day++;
    if (date->day > 31)
}