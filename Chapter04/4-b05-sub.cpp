#include<iostream>
using namespace std;

extern void liangshi(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

extern void yishi(double a, double b, double c)
{
	double x;
	x = -b / (2 * a);
	cout << "x1=x2=" << x << endl;
}

extern void liangxu(double a, double b, double c)
{
	cout << "x1=" << -b / (2 * a) << "+" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
	cout << "x2=" << -b / (2 * a) << "-" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
}

extern void yici(double b, double c)
{
	cout << "x=" << -c / b << endl;
}