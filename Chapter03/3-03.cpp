#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double c, f;
	cout << "请输入一个 华氏温度 数值" << endl;
	cin >>f;
	c = (f - 32) * double(5) / double(9);
	cout << setprecision(2);
	cout <<"转化为摄氏温度为：" << endl;
	cout << setiosflags(ios::fixed) << c << "℃  （小数点后保留2位）" << endl;
	return 0;
}