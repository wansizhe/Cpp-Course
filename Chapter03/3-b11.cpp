#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double ex = 0, x, xn = 1, j = 1;
	int n, k = 1;
	cout << "ÇëÊäÈëÖ¸Êýx£º";
	cin >> x;
	n = 1;
	while (xn / k >= 1e-6)
	{
		ex = ex + j;
		k = k * n;
		xn = xn * x;
		j = xn / k;
		n++;
	}
	cout << "e^x=" << setiosflags(ios::fixed) << setprecision(6) << ex << endl;
	return 0;
}