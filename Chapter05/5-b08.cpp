#include<iostream>
using namespace std;

int main()
{
	int i, l, j = 0, k , line;
	double x[9], y[9];
	double a, b, m, n, u, v, c;
	cout << "请输入边数" << endl;
	cin >> l;
	cout << "请按时针顺序依次输入各点的横纵坐标" << endl;
	for (i = 1; i <= l; i++)
	{
		cin >> x[i];
		cin >> y[i];
	}
	x[0] = x[l];
	y[0] = y[l];
	x[l + 1] = x[1];
	y[l + 1] = y[1];

	line = l;
	for (i = 1; i <= l; i++)
	{
		a = x[i - 1];
		b = y[i - 1];
		u = x[i];
		v = y[i];
		m = x[i + 1];
		n = y[i + 1];
		if ((v - b) / (u - a) == (n - v)/ (m - u))
			line--;
	}

	if (line != l)
	{
		switch (line)
		{
			case 0:
			case 1:
			case 2:
				cout << "error";
				break;
			case 3:
				cout << "三角形";
				break;
			case 4:
				cout << "四边形";
				break;
			case 5:
				cout << "五边形";
				break;
			case 6:
				cout << "六边形";
				break;
		}
		cout << endl;
		return 0;
	}

	else
	{
		for (i = 1; i <= l; i++)
		{
			c = 0;
			if (x[i] - x[i + 1] != 0)
			{
				a = (y[i] - y[i + 1]) / (x[i] - x[i + 1]);
				b = y[i] - a * x[i];
				for (k = 1; k <= l; k++)
				{
					if (y[k] - (a * x[k] + b) > 0)
						c++;
				}
			}
			else
			{
				for (k = 1; k <= l; k++)
				{
					if (x[i] - x[k]>0)
						c++;
				}
			}
			if (c != 0 && c != l - 2)
			{
				cout << "凹" << endl;
				return 0;
			}
		}
	}
	
	    cout << "凸" << endl;
		double s = 0;
		for (int e = 1; e <= line; e++)
		    s = s + (x[e] * y[e + 1] - x[e + 1] * y[e]);

		s = s / 2;

		cout << "面积为：" << s << endl;

	cout << endl;
	return 0;
}