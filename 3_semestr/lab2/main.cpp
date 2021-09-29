#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Datetime
{
private:
    

    bool _check_day(int, int);
    bool _check_month(int);

public:
    int second, minute, hour, day, month, year;
    Datetime(int day, int month, int year, int hour, int minute, int second): day(day), month(month), year(year), hour(hour), minute(minute), second(second)
    {
        if (day > 31 or day < 1)
            this->day = 1;

        if (month < 1 or month > 12)
            this->month = 1;
        
        if (year < 1)
            this->year = 1;
            
        if (hour < 0 or hour > 12)
            this->hour = 1;

        if (minute < 0 or minute > 60)
            this->minute = 1;

        if (second < 0 or second > 60)
            this->second = 1;
    }

    void next_date();
    void previous_date();
    void print_date();
    void print_information(int);
    void print_information_no_next_month(int);    
};

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

void Datetime::print_date()
{
    // cout<<"текущая дата\n"
    
    cout<<day<<"."<<month<<"."<<year<<"\t"
    <<hour<<":"<<minute<<":"<<second;
}


class Data_reader
{
private:
    string **_read_file(int);
    int _get_count_lines();

    string path_file = "data.txt";

public:
    // Datetime **dates = new Datetime*[count_lines];
    int count_lines;
    Data_reader()
    {
        count_lines = _get_count_lines();
    }

    Datetime **get_value()
    {
        string **lines;
        Datetime **dates;
        dates = new Datetime*[count_lines];
        lines = _read_file(count_lines);
        
        for (int i = 0; i < count_lines; i++)
        {
            dates[i] = new Datetime(stoi(lines[i][0]), stoi(lines[i][1]), stoi(lines[i][2]), stoi(lines[i][3]), stoi(lines[i][4]), stoi(lines[i][5]));
        }

        return dates;     
    }

    // ~Data_reader()
    // {
    //     cout<<"деструктор файла\n";
    //     // for (int i = 0; i < count_lines; i++)
    //     // {
    //     //     delete [] lines[i];    
    //     // }
    //     // delete [] lines;

        
    // }
};

int Data_reader::_get_count_lines()
{
    ifstream f(path_file);
    string s;
    int count = 0;
    while (getline(f, s))
    {
        count++;
    }
    f.close();
    return count;
}

string **Data_reader::_read_file(int count_lines)
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

class UI
{
private:
    int n = 0;

    void _print_all(Datetime **dates, Data_reader data)
    {
        // system("clear");
        for (int i = 0; i < data.count_lines; i++)
        {
            cout<<i+1<<". ";
            dates[i]->print_date();
            cout<<"\tслед. дата:\t";
            dates[i]->next_date();
            dates[i]->print_date();
            cout<<"\tпред. дата:\t";
            dates[i]->previous_date();
            dates[i]->print_date();
            cout<<endl;
        }
    }
    

    void _print_not_next_month(Datetime **dates, Data_reader data)
    {
        for (int i = 0; i < data.count_lines; i++)
        {
            int month = dates[i]->month;
            dates[i]->next_date();
            if (dates[i]->month != month)
            {
                dates[i]->previous_date();
                continue;   
            }


            dates[i]->previous_date();
            cout<<i+1<<". ";
            dates[i]->print_date();
            cout<<"\tслед. дата:\t";
            dates[i]->next_date();
            dates[i]->print_date();
            cout<<"\tпред. дата:\t";
            dates[i]->previous_date();
            dates[i]->print_date();
            cout<<endl;
        }
    }

public:
    UI()
    {
        cout<<"выберите действие"<<endl
        <<"1 - вывести информацию о всех датах"<<endl
        <<"2 - вывести информацию о датах, след. дата которых не попадает на след. месяц"<<endl;
        cin>>n;
        // n = 2;
        // _print_all(dates, data);
    }

    void print(Datetime **dates, Data_reader data)
    {
        switch (n)
        {
        case 1:
            _print_all(dates, data);
            break;
        case 2:
            _print_not_next_month(dates, data);
        }
    }

};

class App
{
private:
    // void _print_information();
    // void _print_inf_var3();

    Datetime **dates;
    Data_reader data;
    

public:
    void run()
    {
        
        dates = data.get_value();
        UI ui;
        ui.print(dates, data);
    }

    ~App()
    {
        cout<<"деструктор приложения\n";
        for (int i = 0; i < data.count_lines; i++)
        {
            delete [] dates[i];
        }
        delete [] dates;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    App app;
    app.run();
    return 0;
}



