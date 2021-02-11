#include<iostream>
using namespace std;

int main()
{
	int x, a, b, c, d, e,y;
	cout << "请输入一个不多于五位的正整数：";
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
		cout << "该数为5位正整数" << endl;
		cout << "从高位到低位每一位数字分别为：" << a << " " << b << " " << c << " " << d << " " << e << endl;
		cout << "倒序输出为：" << e << d << c << b << a;
	}
	else if (b != 0)
	{
		cout << "该数为4位正整数" << endl;
		cout << "从高位到低位每一位数字分别为：" << b << " " << c << " " << d << " " << e << endl;
		cout << "倒序输出为：" << e << d << c << b ;
	}
	else if (c != 0)
	{
		cout << "该数为3位正整数" << endl;
		cout << "从高位到低位每一位数字分别为："  << c << " " << d << " " << e << endl;
		cout << "倒序输出为：" << e << d << c ;

	}
	else if (d != 0)
	{
		cout << "该数为2位正整数" << endl;
		cout << "从高位到低位每一位数字分别为：" << d << " " << e << endl;
		cout << "倒序输出为：" << e << d;
	}
	else
	{
		cout << "该数为1位正整数" << endl;
		cout << "从高位到低位每一位数字分别为：" << e << endl;
		cout << "倒序输出为：" << e ;
	}
	cout << endl;
	return 0;
}