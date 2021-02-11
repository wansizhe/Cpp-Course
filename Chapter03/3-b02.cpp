#include<iostream>
using namespace std;

int main()
{
	int x, a, b, c, d, e;
	cout << "请输入一个1～30000的整数" << endl;
	cin >> x;
	a = x / 10000;
	x = x % 10000;
	b = x / 1000;
	x = x % 1000;
	c = x / 100;
	x = x % 100;
	d = x / 10;
	e = x % 10;
	cout << "万位：" << a << endl;
	cout << "千位：" << b << endl;
	cout << "百位：" << c << endl;
	cout << "十位：" << d << endl;
	cout << "个位：" << e << endl;
	return 0;
}
