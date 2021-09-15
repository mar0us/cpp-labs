#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class datetime
{
    private:
    int second, minute, hour, day, month, year;

    void next_date(datetime*);
    void previous_date(datetime*);
    void print_date(datetime);
    void print_information(datetime*, int);
    void print_information_no_next_month(datetime*, int);

    void get_date(datetime*, int, int, int, int, int, int);
    bool check_day(int, int);
    bool check_month(int, int);
};


int get_count_lines(string);
string **read_file(string, int);


int main()
{
    setlocale(LC_ALL, "Russian");

    string path_file = "data.txt";
    int count_lines = get_count_lines(path_file);
    string **lines = read_file(path_file, count_lines);
    datetime *dates = new datetime[count_lines];
    
    for (int i = 0; i < count_lines; i++)
    {
        get_date(&dates[i], stoi(lines[i][0]), stoi(lines[i][1]), stoi(lines[i][2]), stoi(lines[i][3]), stoi(lines[i][4]), stoi(lines[i][5]));
    }
    
    for (int i = 0; i < count_lines; i++)
    {
        dates[i].print_information(&dates[i], i+1);
        // dates[i].print_information(&dates[i], i+1);
    }

    cout<<"даты которые не попадут на след. месяц"<<endl;
    for (int i = 0; i < count_lines; i++)
    {
        if (check_day(dates[i].month, dates[i].day+1))
            dates[i].print_information_no_next_month(&dates[i], i+1);
    }

    

    for (int i = 0; i < count_lines; i++)
    {
        delete [] lines[i];
    }
    delete [] lines;
    
    return 0;
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
        cout<< "неверный формат года, автоматически выставилось 2000"<<endl;
        date->year = 2000;
    }else
        date->year = year;
}

void datetime::print_date(datetime date)
{
    cout<<"----------------------"<<endl;
    cout<<"текущие время и дата:"<<endl;
    cout<<"секунда: "<< date.second <<endl;
    cout<<"минута: "<< date.minute <<endl;
    cout<<"час: "<< date.hour <<endl;
    cout<<"день: "<< date.day <<endl;
    cout<<"месяц: "<< date.month <<endl;
    cout<<"год: "<< date.year <<endl;
    cout<<"----------------------"<<endl<<endl;
}

void datetime::print_information(datetime *date, int n)
{
    cout<<"№ "<<n<<"; дата: "<<date->day<<"."<<date->month<<"."<<date->year<<";\t";
    date->next_date(date);
    cout<<"след. дата: "<<date->day<<"."<<date->month<<"."<<date->year<<";\t";
    date->previous_date(date);
    date->previous_date(date);
    cout<<"пред. дата: "<<date->day<<"."<<date->month<<"."<<date->year<<endl;
    date->next_date(date);
}

void datetime::print_information_no_next_month(datetime *date, int n)
{
    cout<<"№ "<<n<<"; дата: "<<date->day<<"."<<date->month<<"."<<date->year<<";\t";
    date->next_date(date);
    cout<<"след. дата: "<<date->day<<"."<<date->month<<"."<<date->year<<endl;
    date->previous_date(date);
}

bool check_day(int month, int day)
{
    int month_31day[7] = {1, 3, 5, 7, 8, 10, 12};

    if (day <1)
        return false;

    if (month == 2)
        if (day > 28)
            return false;
    
    for (int i = 0; i < 7; i++)
    {
        if (month == month_31day[i])
        {
            if (day > 31)
                return false;
        }else
            if (day > 30)
                return false;   
    }
    return true;
}

bool check_month(int month)
{
    if (month > 12 or month < 1)
        return false;
    return true;
}

void datetime::next_date(datetime* date)
{
    if (check_day(date->month, date->day + 1))
        date->day++;
    else
    {
        date->day = 1;
        
        if (check_month(date->month + 1))
        {
            date->month++;
        }else
        {
            date->month = 1;
            date->year++;
        }
    }
}

void datetime::previous_date(datetime* date)
{
    int month_31day[7] = {1, 3, 5, 7, 8, 10, 12};


    if (check_day(date->month, date->day - 1))
        date->day--;
    else
    {
        if (date->month - 1 == 2)
            date->day = 28;

        for (int i = 0; i < 7; i++)
        {
            if (date->month == 1)
                date->day = 31;
            else if (date->month -1 == month_31day[i])
                date->day = 31;
            else
                date->day = 30;
        }
        if (check_month(date->month -1))
            date->month--;
        else
        {
            date->month = 12;
            date->year--;
        }
    }
}


int get_count_lines(string path_file)
{
    ifstream f(path_file);
    string s;
    int count = 0;
    while (getline(f, s))
    {
        count++;
    }
    
    return count;
}

string **read_file(string path_file, int count_lines)
{
    ifstream f(path_file);
    string line;

    string **lines = new string*[count_lines];
    for (int i = 0; i < count_lines; i++)
    {
        lines[i] = new string[6];
    }

    int j = 0;
    while (getline(f, line))
    {
        string buf;
        stringstream x;
        x << line;

        for (int i = 0; i < 6; i++)
        {
            x >> buf;
            lines[j][i] = buf;
        }
        j++;        
    }


    f.close();
    return lines;
}