#include<iostream>
using namespace std;

int f(int n)
{
	int x;
	if (n == 1)
		x = 0;
	else if (n == 2)
		x = 1;
	else
		x = f(n - 1) + f(n - 2);
	return x;
}

int main()
{
	int n;
	cout << "����������n��";
	cin >> n;
	cout << "Fibonacci���е�" << n << "��Ϊ��" << endl;
	cout << "F(" << n << ")=" << f(n) << endl;
	return 0;
}