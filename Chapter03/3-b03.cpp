#include<iostream>
using namespace std;

int main()
{
	double m = 1e-5;
	double y, z;
	unsigned int a, b, c, d, e, f, g, h, i, j, k, l;
	cout << "������һ��0.00��1000000000.00������С����������λ��" << endl;
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
	cout << "ʮ��λ��" << a << endl;
	cout << "��λ��" << b << endl;
	cout << "ǧ��λ��" << c << endl;
	cout << "����λ��" << d << endl;
	cout << "ʮ��λ��" << e << endl;
	cout << "��λ��" << f << endl;
	cout << "ǧλ��" << g << endl;
	cout << "��λ��" << h << endl;
	cout << "ʮλ��" << i << endl;
	cout << "��λ��" << j << endl;
	k = z / 0.1;
	z = z - 0.1 * k;
	l = z / 0.01;
	cout << "ʮ��λ��" << k << endl;
	cout << "�ٷ�λ��" << l << endl;
	return 0;
}

