#include<iostream>
using namespace std;

double a, b, c, delta, x1, x2, x;

void liangshi()
{
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void yishi()
{
	x = -b / (2 * a);
	cout << "x1=x2=" << x << endl;
}

void liangxu()
{
	cout << "x1=" << -b / (2 * a) << "+" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
	cout << "x2=" << -b / (2 * a) << "-" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
}

void yici()
{
	cout << "x=" << -c / b << endl;
}

int main()
{
	cout << "请依次输入二次项系数、一次项系数、常数项：" << endl;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (a == 0)
		yici();
	else if (delta > 0)
		liangshi();
	else if (delta == 0)
		yishi();
	else
		liangxu();
	return 0;
}