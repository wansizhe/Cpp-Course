#include<iostream>
using namespace std;

int main()
{
	double a, b, c, p, s;
	cout << "��������������������a��b��c�ĳ���";
	cin >> a >> b >> c;
	p = (a + b + c) / 2;
	if (a + b > c && b + c > a && a + c > b)
	{
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "��������� s=" << s;
	}
	else
		cout << "���ܹ��������Σ�" << endl;
	return 0;
}