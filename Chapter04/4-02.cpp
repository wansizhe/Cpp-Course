#include<iostream>
using namespace std;

void liangshi(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b*b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b*b - 4 * a * c)) / (2 * a);
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void yishi(double a, double b, double c)
{
	double x;
	x = -b / (2 * a);
	cout << "x1=x2=" << x << endl;
}

void liangxu(double a, double b, double c)
{
	cout << "x1=" << -b / (2 * a) << "+" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
	cout << "x2=" << -b / (2 * a) << "-" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
}

void yici(double b, double c)
{
	cout << "x=" << -c / b << endl;
}

int main()
{
	double a, b, c, delta;
	cout << "请依次输入二次项系数、一次项系数、常数项：" << endl;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (a == 0)
		yici(b, c);
	else if (delta > 0)
		liangshi(a, b, c);
	else if (delta == 0)
		yishi(a, b, c);
	else
		liangxu(a, b, c);
	return 0;
}