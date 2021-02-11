#include<iostream>
using namespace std;

unsigned long sum(int n)
{
	unsigned long x;
	if (n == 1)
		x = 1;
	else
		x = sum(n - 1) + n * n;
	return x;
}

int main()
{
	int n;
	cout << "请输入变量n的值：";
	cin >> n;
	cout << "1^2到n^2求和的值为：" << endl;
	cout << "sum=" << sum(n) << endl;
	return 0;
}