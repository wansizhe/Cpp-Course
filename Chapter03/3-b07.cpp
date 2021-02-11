#include<iostream>
using namespace std;

int main()
{
	double a, b, c, x1, x2, t, m, n;
	cout << "请依次输入一元二次方程的二次项系数a，一次项系数b，常数项c：" << endl;
	cin >> a >> b >> c;
	t = b * b - 4 * a * c;
	if (a == 0)
		cout << "不是一元二次方程" << endl;
    else if (t > 0)
	{
		x1 = (-b + sqrt(t)) / (2 * a);
		x2 = (-b - sqrt(t)) / (2 * a);
		cout << "存在两个不等的实根：" << endl << "x1=" << x1 << endl << "x2=" << x2 << endl;
	}
    else if (t == 0)
	{
		x1 = (-b + sqrt(t)) / (2 * a);
		x2 = (-b - sqrt(t)) / (2 * a);
		cout << "存在两个相等的实根：" << endl << "x1=x2=" << x1 << endl;
	}
	else if (t < 0)
	{
		m = -b / (2 * a);
		n = sqrt(-t) / (2 * a);
		cout << "存在两个虚根：" << endl;
		if (a >= 0)
		{
			cout << "x1=" << m << "+" << n << "i" << endl;
			cout << "x2=" << m << "-" << n << "i" << endl;
		}
		else
		{
			n = -n;
			cout << "x1=" << m << "+" << n << "i" << endl;
			cout << "x1=" << m << "-" << n << "i" << endl;
		}
	}
	return 0;
}