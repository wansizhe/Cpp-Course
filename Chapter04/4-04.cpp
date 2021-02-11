#include<iostream>
using namespace std;

int fac(int n)
{
	int x;
	if (n == 0 || n == 1)
		x = 1;
	else
		x = n * fac(n - 1);
	return x;
}

int main()
{
	int a, b, c;
	cout << "请输入a，b，c：";
	cin >> a >> b >> c;
	cout << a << "!+" << b << "!+" << c << "!=";
	cout << fac(a) + fac(b) + fac(c);
	cout << endl;
	return 0;
}