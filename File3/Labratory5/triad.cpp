#include "triad.h"

using namespace std;

Triad::Triad(int n1, int n2, int n3)
{
    number1 = n1;
    number2 = n2;
    number3 = n3;
}

int Triad::get_number1()
{
    return this->number1;
}

void Triad::set_number1(int new_val)
{
    this->number1 = new_val;
}

void Triad::increase_number1()
{
    this->number1++;
}

int Triad::get_number2()
{
    return this->number2;
}

void Triad::set_number2(int new_val)
{
    this->number2 = new_val;
}

void Triad::increase_number2()
{
    this->number2++;
}

int Triad::get_number3()
{
    return this->number3;
}

void Triad::set_number3(int new_val)
{
    this->number3 = new_val;
}

void Triad::increase_number3()
{
    this->number3++;
}

Triad Triad::operator++()
{
    this->number1 += 1;
    this->number2 += 1;
    this->number3 += 1;
    return *this;
}

Triad Triad::operator++(int)
{
    this->number1 += 1;
    this->number2 += 1;
    this->number3 += 1;
    return *this;
}

ostream& operator<<(ostream& stream, const Triad &a)
{
    return (stream << "(" << a.number1 << ":" << a.number2 << ":" << a.number3 << ")");
}

istream &operator>>(istream &stream, Triad &a)
{
    string flag;
    cout << "Enter number1(enter 'o' if do not want to change number1): ";
    stream >> flag;
    if (flag != "o") a.number1 = stoi(flag);
    cout << "Enter number2(enter 'o' if do not want to change number2): ";
    stream >> flag;
    if (flag != "o") a.number2 = stoi(flag);
    cout << "Enter number3(enter 'o' if do not want to change number3): ";
    stream >> flag;
    if (flag != "o") a.number3 = stoi(flag);
    return stream;
}
