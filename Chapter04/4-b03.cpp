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
	cout << "请输入一个十进制正整数和一个不小于2的整数基数：";
	cin >> num >> base;
	x = is_power(num, base);
	cout << "返回结果：" << x << endl;
	if (x == 1)
		cout << num << "是基数" << base << "的幂。";
	if(x==0)
		cout << num << "不是基数" << base << "的幂。";
	cout << endl;
	return 0;
}