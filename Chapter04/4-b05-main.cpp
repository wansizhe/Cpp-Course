#include<iostream>
using namespace std;

extern void liangshi(double, double, double);
extern void yishi(double, double, double);
extern void liangxu(double, double, double);
extern void yici(double, double);

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