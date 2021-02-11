#include<iostream>
using namespace std;

int main()
{
	double m = 1e-5;
	double y, z;
	unsigned int a, b, c, d, e, f, g, h, i, j, k, l;
	cout << "请输入一个0.00～1000000000.00的数（小数点后最多两位）" << endl;
	cin >> y;
	y = y + m;
	a = int(y / 1000000000);
	y = y - 1.0 * 1000000000 * a;
	b = y / 100000000;
	y = y - 1.0 * 100000000 * b;
	c = y / 10000000;
	y = y - 1.0  *10000000 * c;
	d = y / 1000000;
	y = y - 1.0  *1000000 * d;
	e = y / 100000;
	y = y - 1.0 * 100000 * e;
	f = y / 10000;
	y = y - 1.0  *10000 * f;
	g = y / 1000;
	y = y - 1.0 * 1000 * g;
	h = y / 100;
	y = y - 1.0 * 100 * h;
	i = y / 10;
	y = y - 1.0  *10 * i;
	j = y / 1;
	z = y - j;
	cout << "十亿位：" << a << endl;
	cout << "亿位：" << b << endl;
	cout << "千万位：" << c << endl;
	cout << "百万位：" << d << endl;
	cout << "十万位：" << e << endl;
	cout << "万位：" << f << endl;
	cout << "千位：" << g << endl;
	cout << "百位：" << h << endl;
	cout << "十位：" << i << endl;
	cout << "个位：" << j << endl;
	k = z / 0.1;
	z = z - 0.1 * k;
	l = z / 0.01;
	cout << "十分位：" << k << endl;
	cout << "百分位：" << l << endl;
	return 0;
}

