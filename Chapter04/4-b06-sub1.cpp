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