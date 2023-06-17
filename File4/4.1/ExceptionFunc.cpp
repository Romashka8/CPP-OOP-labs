#include "ExceptionFunc.h"

using namespace std;

void Angles(MyTriangle triangle)
{
    if (isnan(triangle.a)) throw 1.0;
    if (isnan(triangle.b)) throw 1.0;
    triangle.c = sqrt(pow(triangle.a, 2) * pow(triangle.b, 2));
    triangle.angle_a = triangle.a / triangle.c;
    triangle.angle_b = triangle.b / triangle.c;
    cout << triangle.angle_a << " " << triangle.angle_b;
}

int main()
{
    double a = NAN, b = NAN;
    MyTriangle test(a, b);
    try
    {
        Angles(test);
    }
    catch (double)
    {
        cout << "Error!\n";
    }
    return 0;
}
