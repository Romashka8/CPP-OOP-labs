#include "time.h"

using namespace std;

Time::Time(int n1, int n2, int n3) : Triad (0, 0, 0)
{
    if (n1 >= 0 && n2 >= 0 && n3 >= 0)
    {
        this->set_number1(n1);
        this->set_number1(n2);
        this->set_number1(n3);
        return;
    }
    cout << "Incorrect values were gotten! Default values were setted!";
}

void Time::increase_number1(){ this->set_number1(this->get_number1() + 1); }

void Time::increase_number2()
{
    if (this->get_number2() != 60)
    {
        this->set_number2(this->get_number2() + 1);
        return;    
    }
    this->increase_number1();
    this->set_number2(0);
}

void Time::increase_number3()
{
    if (this->get_number3() != 60)
    {
        this->set_number3(this->get_number3() + 1);
        return;
    }
    this->increase_number2();
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

ostream &operator<<(ostream &stream, Time &a)
{
    stream << "[";
    if (a.get_number1() < 10) stream << "0";
    stream << a.get_number1() << ":";
    if (a.get_number2() < 10) stream << "0";
    stream << a.get_number2() << ":";
    if (a.get_number3() < 10) stream << "0";
    stream << a.get_number3() << "]";
    return stream;
}

istream &operator>>(istream &stream, Time &a)
{
    string flag;
    cout << "Enter number1(enter 'o' if do not want to change number1): ";
    stream >> flag;
    if (flag != "o")
    {
        if (stoi(flag) >= 0) a.set_number1(stoi(flag));
        else cout << "Incorrect values! Hours has not changed!";
    }
    cout << "Enter number2(enter 'o' if do not want to change number2): ";
    stream >> flag;
    if (flag != "o")
    {
        if (stoi(flag) < 60 && stoi(flag) >= 0) a.set_number2(stoi(flag));
        else cout << "Incorrect values! Minutes has not changed!";
    }
    cout << "Enter number3(enter 'o' if do not want to change number3): ";
    stream >> flag;
    if (flag != "o")
    { 
        if (stoi(flag) < 60 && stoi(flag) >= 0) a.set_number3(stoi(flag));
        else cout << "Incorrect values! Seconds has not changed!";
    }
    return stream;
}
