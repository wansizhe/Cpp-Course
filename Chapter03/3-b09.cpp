#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, RMB1;
	double RMB, RMB2, f, g, h, i, j, k;
	cout << "请输入所找零钱数（应在[0.01,100.00)之间，两位小数）：";
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
	cout << "总量为" << k << endl;
	if (a != 0)
		cout << " 50元 x " << a << endl;
	if (b != 0)
		cout << " 20元 x " << b << endl;
	if (c != 0)
		cout << " 10元 x " << c << endl;
	if (d != 0)
		cout << "  5元 x " << d << endl;
	if (e != 0)
		cout << "  1元 x " << e << endl;
	if (f != 0)
		cout << "  5角 x " << f << endl;
	if (g != 0)
		cout << "  1角 x " << g << endl;
	if (h != 0)
		cout << "  5分 x " << h << endl;
	if (i != 0)
		cout << "  2分 x " << i << endl;
	if (j != 0)
		cout << "  1分 x " << j << endl;
	return 0;
}