#include <iostream>

using namespace std;

class Pair
{
    public:
        unsigned int first = 0;
        float second = 0;

        void init(int f, float s);
        void read();
        void display();
        float cost();
};

void Pair::init(int f, float s)
{
    if (f > 0 && s > 0)
    {
        first = f;
        second = s;
    }
    else
    {
        cout << "Object was created with default values! You've entered a wrong data!\n";
        first = 1;
        second = 1;
    }
}

void Pair::read()
{
    int f;
    float s;
    cout << "First: ";
    cin >> f;
    cout << "Second: ";
    cin >> s;
    Pair::init(f, s);
}

void Pair::display()
{
    cout << "first = " << first << "\nsecond = " << second << "\ncost - " << Pair::cost() << "\n";
}

float Pair::cost()
{
    return first * second;
}

int main()
{
    Pair tests[3];
    for (int i = 0; i < 2; i++)
    {
        tests[i].read();
        tests[i].display();
    }
    tests[2].init(5, 5);
    tests[2].display();
    return 0;
}


