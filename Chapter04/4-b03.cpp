#include<iostream>
using namespace std;

int is_power(int num, int base)
{
	int x;
	if (num >= base)
	{
		if (num % base != 0)
			x = 0;
		else if (num / base == 1)
			x = 1;
		else
		{
			num = num / base;
			x = is_power(num, base);
		}
	}
	else
	{
		if (num == 1)
			x = 1;
		else
			x = 0;
	}
	return x;
}

int main()
{
	int num, base, x;
	cout << "������һ��ʮ������������һ����С��2������������";
	cin >> num >> base;
	x = is_power(num, base);
	cout << "���ؽ����" << x << endl;
	if (x == 1)
		cout << num << "�ǻ���" << base << "���ݡ�";
	if(x==0)
		cout << num << "���ǻ���" << base << "���ݡ�";
	cout << endl;
	return 0;
}