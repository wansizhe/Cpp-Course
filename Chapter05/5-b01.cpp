#include<iostream>
#include<iomanip>
using namespace std;

int fac(int x)
{
	int f = 1;
	if (x == 0)
		f = 1;
	else
		f = fac(x - 1)*x;
	return f;
}

int c(int a, int b)
{
	int c;
	c = fac(a) / (fac(b) * fac(a - b));
	return c;
}

int main()
{
	int a, b, i;
	int yh[10][10];
	for (a = 0; a <= 9; a++)
		for (b = 0; b <= 9; b++)
		{
			if (a >= b)
				yh[a][b] = c(a, b);
			else
				yh[a][b] = 0;
		}
	cout << "杨辉三角 — 等腰三角形打印（前10行）：" << endl << endl;
	for (a = 0; a <= 9; a++)
	{
		for (i = 9 - a; i >= 0; i--)
			cout << "   ";
		for (b = 0; b <= 9; b++)
		{
			if (yh[a][b])
				cout << setw(3) << yh[a][b] << "   ";
		}
		cout << endl << endl;
	}

	return 0;
}