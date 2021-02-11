#include<iostream>
using namespace std;

double p(unsigned int n, double x)
{
	double y;
	if (n == 0)
		y = 1;
	else if (n == 1)
		y = x;
	else
		y = ((2 * n - 1) * x * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
	return y;
}

int main()
{
	unsigned n;
	double x;
	cout << "请输入n，x：";
	cin >> n >> x;
	cout << n <<"阶勒让德多项式的值为： " << p(n, x) << endl;
	return 0;
}