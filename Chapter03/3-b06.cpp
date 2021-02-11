#include<iostream>
using namespace std;

int main()
{
	double x1, x2, x3, y1, y2, y3, s, a, b, c, p;
	cout << "请依次输入a，b，c三点的横、纵坐标：" << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if ((y1 - y2) / (x1 - x2) == (y2 - y3) / (x2 - x3))
		cout << "不能构成三角形" << endl;
	else if((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3 ) || (x1 == x3 && y1 == y3))
		cout << "不能构成三角形" << endl;
	else
	{
		a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
		c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		p = (a + b + c) / 2;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "三角形面积 s=" << s << endl;
	}
	return 0;
}