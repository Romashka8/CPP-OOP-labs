#include "triad.h"

class Time : public Triad
{
    int hours, minutes, seconds;
    public:
        Time(int n1, int n2, int n3);

        // hours
        void increase_number1();
        // minutes
        void increase_number2();
        // seconds
        void increase_number3();

        // перезапись инкремента.
        // здесь это операции увеличения и секунд, и минут.
        Time operator++();
        Time operator++(int);
        // ввод и вывод.
        friend ostream& operator<<(ostream& stream, const Time &a);
        friend istream& operator>>(istream& stream, Time &a);
};
