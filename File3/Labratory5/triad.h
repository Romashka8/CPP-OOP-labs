#include <iostream>
#include <string>

using namespace std;

class Triad
{
    int number1 = 0, number2 = 0, number3 = 0;

    public:
        Triad(int n1, int n2, int n3);

        // number1 methods
        int get_number1();
        void set_number1(int new_val);
        void increase_number1();
        // number2 methods
        int get_number2();
        void set_number2(int new_val);
        void increase_number2();
        // number3 methods
        int get_number3();
        void set_number3(int new_val);
        void increase_number3();

        // перезапись всего остального.
        Triad operator++();
        Triad operator++(int);
        // перезапись ввода/вывода.
        friend ostream& operator<<(ostream& stream, const Triad &a);
        friend istream& operator>>(istream& stream, Triad &a);
};
