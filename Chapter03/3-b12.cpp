#include<iostream>
using namespace std;

int main()
{
	double a, b, c, m, n, p;
	m = 0;
	n = 1;
	for (; fabs(n - m) >= 1e-6;)
	{
		p = (m + n) / 2;
		a = 2 * m * m * m - 9 * m * m + 12 * m - 3;
		b = 2 * n * n * n - 9 * n * n + 12 * n - 3;
		c = 2 * p * p * p - 9 * p * p + 12 * p - 3;
		if (fabs(c) < 1e-6)
		{
			m = c;
			break;
		}
		if (a * c < 0)
		{
			n = p;
			continue;
		}
		if (b * c < 0)
		{
			m = p;
			continue;
		}
	}
	cout << "方程 2x^3-9x^2+12x-3=0 在(0,1)上的零点为：" << endl << "x=" << m << endl;
	return 0;
}