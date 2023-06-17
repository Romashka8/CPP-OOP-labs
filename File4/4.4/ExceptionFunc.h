#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct MyTriangle
{
    double a, b, c;
    double angle_a, angle_b;

    MyTriangle(double ua, double ub)
    {
        a = ua;
        b = ub;
    }
};

class MyTriangleException
{
    double a, b;

    public:
        string message;
        MyTriangleException(double ua, double ub, const string& s)
        {
            a = ua;
            b = ub;
            message = s;
        }
};
