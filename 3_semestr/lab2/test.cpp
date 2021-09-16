#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Datetime
{
private:
    int second, minute, hour, day, month, year;

    bool _check_day(int, int);
    bool _check_month(int);

public:
    Datetime(){}
    Datetime(int second, int minute, int hour, int day, int month, int year): second(second), minute(minute), hour(hour), day(day), month(month), year(year){}

    void next_date();
    void previous_date();
    void print_date();
    void print_information(int);
    void print_information_no_next_month(int);    
};



class Read_file_date
{
private:
    int _get_count_lines();

    string path_file;
    string **_read_file(int);
    string **lines;

public:
    // Datetime **dates = new Datetime*[count_lines];
    int count_lines;
    Read_file_date(string path_file, Datetime **dates): path_file(path_file)
    {
        dates = new Datetime*[count_lines];
        count_lines = _get_count_lines();
        lines = _read_file(count_lines);

        for (int i = 0; i < 6; i++)
        {
            dates[i] = new Datetime(stoi(lines[i][0]), stoi(lines[i][1]), stoi(lines[i][2]), stoi(lines[i][3]), stoi(lines[i][4]), stoi(lines[i][5]));
        }
    }
};




int main()
{
    setlocale(LC_ALL, "Russian");
    
    string path_file = "data.txt";
    Datetime **dates;
    Read_file_date file(path_file, dates);

    for (int i = 0; i < file.count_lines; i++)
    {
        dates[i]->print_date();
    }
        

    

    return 0;
}


void Datetime::print_date()
{
    cout<<"текущая дата\n"
    <<day<<"."<<month<<"."<<year<<"\t"
    <<hour<<":"<<minute<<":"<<second<<endl;
}

bool Datetime::_check_day(int day, int month)
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


bool Datetime::_check_month(int month)
{
    if (month > 12 or month < 1)
        return false;
    return true;
}


void Datetime::next_date()
{
    if (_check_day(day+1, month))
        day++;
    else
    {
        day = 1;
        
        if (_check_month(month + 1))
        {
            month++;
        }else
        {
            month = 1;
            year++;
        }
    }
}

void Datetime::previous_date()
{
    int month_31day[7] = {1, 3, 5, 7, 8, 10, 12};


    if (_check_day(month, day - 1))
        day--;
    else
    {
        if (month - 1 == 2)
            day = 28;

        for (int i = 0; i < 7; i++)
        {
            if (month == 1)
                day = 31;
            else if (month -1 == month_31day[i])
                day = 31;
            else
                day = 30;
        }
        if (_check_month(month -1))
            month--;
        else
        {
            month = 12;
            year--;
        }
    }
}



int Read_file_date::_get_count_lines()
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

string **Read_file_date::_read_file(int count_lines)
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