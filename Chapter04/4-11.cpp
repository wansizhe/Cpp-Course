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
	cout << "���������n��ֵ��";
	cin >> n;
	cout << "1^2��n^2��͵�ֵΪ��" << endl;
	cout << "sum=" << sum(n) << endl;
	return 0;
}