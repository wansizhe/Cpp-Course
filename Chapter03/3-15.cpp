#include<iostream>
using namespace std;

int main()
{
	cout << "����������������";
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
	cout << "���Լ��Ϊ��" << m << endl;
	n = a / m;
	cout << "��С������Ϊ��" << n << endl;
	return 0;
}

