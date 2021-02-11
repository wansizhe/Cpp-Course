#include<iostream>
using namespace std;

int main()
{
	cout << "请输入两个整数：";
	int m, n, a, t;
	cin >> m >> n;
	if (m > n)
	{
		t = m;
		m = n;
		n = t;
	}
    a = m * n;
    while (n % m != 0)
	{
		t = n % m;
		n = m;
		m = t;
	}
	cout << "最大公约数为：" << m << endl;
	n = a / m;
	cout << "最小公倍数为：" << n << endl;
	return 0;
}

