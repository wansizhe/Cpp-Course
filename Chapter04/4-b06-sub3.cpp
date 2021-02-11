#include<iostream>
using namespace std;

extern void liangxu(double a, double b, double c)
{
	cout << "x1=" << -b / (2 * a) << "+" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
	cout << "x2=" << -b / (2 * a) << "-" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
}