#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, RMB1;
	double RMB, RMB2, f, g, h, i, j, k;
	cout << "������������Ǯ����Ӧ��[0.01,100.00)֮�䣬��λС������";
	cin >> RMB;
	RMB1 = int(RMB);
	RMB2 = RMB - RMB1;
	a = RMB1 / 50;
	RMB1 = RMB1 - 50 * a;
	b = RMB1 / 20;
	RMB1 = RMB1 - 20 * b;
	c = RMB1 / 10;
	RMB1 = RMB1 - 10 * c;
	d = RMB1 / 5;
	RMB1 = RMB1 - 5 * d;
	e = RMB1 / 1;

	f = RMB2 / 0.5;
	f = int(f);
	RMB2 = RMB2 - 0.5 * f;
	g = RMB2 / 0.1;
	g = int(g);
	RMB2 = RMB2 - 0.1 * g;
	h = RMB2 / 0.05;
	h = int(h);
	RMB2 = RMB2 - 0.05 * h;
	i = RMB2 / 0.02;
	i = int(i);
	RMB2 = RMB2 - 0.02 * i;
	j = RMB2 / 0.01;
	j = int(j);
	k = a + b + c + d + e + f + g + h + i + j;
	cout << "����Ϊ" << k << endl;
	if (a != 0)
		cout << " 50Ԫ x " << a << endl;
	if (b != 0)
		cout << " 20Ԫ x " << b << endl;
	if (c != 0)
		cout << " 10Ԫ x " << c << endl;
	if (d != 0)
		cout << "  5Ԫ x " << d << endl;
	if (e != 0)
		cout << "  1Ԫ x " << e << endl;
	if (f != 0)
		cout << "  5�� x " << f << endl;
	if (g != 0)
		cout << "  1�� x " << g << endl;
	if (h != 0)
		cout << "  5�� x " << h << endl;
	if (i != 0)
		cout << "  2�� x " << i << endl;
	if (j != 0)
		cout << "  1�� x " << j << endl;
	return 0;
}