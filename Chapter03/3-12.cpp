#include<iostream>
using namespace std;

int main()
{
	int x, a, b, c, d, e,y;
	cout << "������һ����������λ����������";
	cin >> x;
	a = x / 10000;
	x %= 10000;
	b = x / 1000;
	x %= 1000;
	c = x / 100;
	x %= 100;
	d = x / 10;
	e = x % 10;
	if (a != 0)
	{
		cout << "����Ϊ5λ������" << endl;
		cout << "�Ӹ�λ����λÿһλ���ֱַ�Ϊ��" << a << " " << b << " " << c << " " << d << " " << e << endl;
		cout << "�������Ϊ��" << e << d << c << b << a;
	}
	else if (b != 0)
	{
		cout << "����Ϊ4λ������" << endl;
		cout << "�Ӹ�λ����λÿһλ���ֱַ�Ϊ��" << b << " " << c << " " << d << " " << e << endl;
		cout << "�������Ϊ��" << e << d << c << b ;
	}
	else if (c != 0)
	{
		cout << "����Ϊ3λ������" << endl;
		cout << "�Ӹ�λ����λÿһλ���ֱַ�Ϊ��"  << c << " " << d << " " << e << endl;
		cout << "�������Ϊ��" << e << d << c ;

	}
	else if (d != 0)
	{
		cout << "����Ϊ2λ������" << endl;
		cout << "�Ӹ�λ����λÿһλ���ֱַ�Ϊ��" << d << " " << e << endl;
		cout << "�������Ϊ��" << e << d;
	}
	else
	{
		cout << "����Ϊ1λ������" << endl;
		cout << "�Ӹ�λ����λÿһλ���ֱַ�Ϊ��" << e << endl;
		cout << "�������Ϊ��" << e ;
	}
	cout << endl;
	return 0;
}