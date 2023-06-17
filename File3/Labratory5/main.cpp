#include "time.h"

using namespace std;

int main()
{
	Time timer(0, 0, 0);
    Triad test(0, 0, 0);
	for (int i = 0; i <= 60; i++)
	{
		timer++;
	}
	cout << timer << "\n";
	cout << "Minute has left!\n";
    // демонстрация принцыпа подстановки.
    test = timer;
    cout << test << endl;
	return 0;
}
