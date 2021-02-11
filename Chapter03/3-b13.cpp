#include <iostream>
using namespace std;

int main()
{
    for (int a = 1; a <= 9; a++)
    {
        for (int b = 1; b <= a; b++)
        {
            cout << b << "x" << a << "=";
            if (a * b < 10)
                cout << " ";
            cout << a * b << "\t";
        }
        cout << endl;
    }
	return 0;
}