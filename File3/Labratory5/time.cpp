#include "time.h"

using namespace std;

Time::Time(int n1, int n2, int n3) : Triad (n1, n2, n3)
{
    if (n1 >= 0 && n2 >= 0 && n3 >= 0)
    {
        hours = n1;
        minutes = n2;
        seconds = n3;
        return;
    }
    cout << "Incorrect values were gotten! Default values were setted!";
    hours = 0;
    minutes = 0;
    seconds = 0;
}

void Time::increase_number1()
{
    this->hours += 1;
    this->set_number1(this->hours);
}

void Time::increase_number2()
{
    if (this->minutes != 60)
    {
        this->minutes += 1;
        this->set_number2(this->minutes);
        return;    
    }
    this->increase_number1();
    this->minutes = 0;
    this->set_number2(0);
}

void Time::increase_number3()
{
    if (this->seconds != 60)
    {
        this->seconds += 1;
        this->set_number3(this->seconds);
        return;
    }
    this->increase_number2();
    this->seconds = 0;
    this->set_number3(0);
}

Time Time::operator++()
{
    this->increase_number3();
    return *this;
}

Time Time::operator++(int)
{
    this->increase_number3();
    return *this;
}

ostream &operator<<(ostream &stream, const Time &a)
{
    stream << "[";
    if (a.hours < 10) stream << "0";
    stream << a.hours << ":";
    if (a.minutes < 10) stream << "0";
    stream << a.minutes << ":";
    if (a.seconds < 10) stream << "0";
    stream << a.seconds << "]";
    return stream;
    // return (stream << "[" << a.hours << ":" << a.minutes << ":" << a.seconds << "]");
}

istream &operator>>(istream &stream, Time &a)
{
    string flag;
    cout << "Enter number1(enter 'o' if do not want to change number1): ";
    stream >> flag;
    if (flag != "o")
    {
        if (stoi(flag) >= 0) a.hours = stoi(flag);
        else cout << "Incorrect values! Hours has not changed!";
    }
    cout << "Enter number2(enter 'o' if do not want to change number2): ";
    stream >> flag;
    if (flag != "o")
    {
        if (stoi(flag) < 60 && stoi(flag) >= 0) a.minutes = stoi(flag);
        else cout << "Incorrect values! Minutes has not changed!";
    }
    cout << "Enter number3(enter 'o' if do not want to change number3): ";
    stream >> flag;
    if (flag != "o")
    { 
        if (stoi(flag) < 60 && stoi(flag) >= 0) a.seconds = stoi(flag);
        else cout << "Incorrect values! Seconds has not changed!";
    }
    return stream;
}
