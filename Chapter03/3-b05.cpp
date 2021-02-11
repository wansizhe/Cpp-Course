#include<iostream>
using namespace std;

int main()
{
	double a, b, c, p, s;
	cout << "请依次输入三角形三边a，b，c的长：";
	cin >> a >> b >> c;
	p = (a + b + c) / 2;
	if (a + b > c && b + c > a && a + c > b)
	{
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "三角形面积 s=" << s;
	}
	else
		cout << "不能构成三角形！" << endl;
	return 0;
}