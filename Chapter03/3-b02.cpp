#include<iostream>
using namespace std;

int main()
{
	int x, a, b, c, d, e;
	cout << "������һ��1��30000������" << endl;
	cin >> x;
	a = x / 10000;
	x = x % 10000;
	b = x / 1000;
	x = x % 1000;
	c = x / 100;
	x = x % 100;
	d = x / 10;
	e = x % 10;
	cout << "��λ��" << a << endl;
	cout << "ǧλ��" << b << endl;
	cout << "��λ��" << c << endl;
	cout << "ʮλ��" << d << endl;
	cout << "��λ��" << e << endl;
	return 0;
}
