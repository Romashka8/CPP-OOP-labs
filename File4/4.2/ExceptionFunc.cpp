#include "ExceptionFunc.h"

using namespace std;

void Angles(MyTriangle triangle) 
{
    if (isnan(triangle.a)) throw invalid_argument("a is NaN");
    if (isnan(triangle.b)) throw invalid_argument("b is NaN");
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
    catch (invalid_argument e)
    {
        cout << "Error!\n" << e.what() << endl;
    }
    return 0;
}
