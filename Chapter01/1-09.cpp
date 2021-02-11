#include<iostream>
using namespace std;

int add(int x, int y);

int main()
{
	int a, b,c;
	cin >> a >> b;
	c = add(a, b);
	cout << "a+b=" << c << endl;
	return 0;
}

int add(int x, int y)
{
	int z;
	z = x + y;
	return (z);//未声明函数add，未定义c，未初始化ab，未定义z，第十二行最后不应有问号
}