#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << "a+b=" << a + b;
	return 0;  //没有开头的预处理指令，未定义c，未初始化ab，cout后箭头方向反了，缺少return0
}
