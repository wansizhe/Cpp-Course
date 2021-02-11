#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	const double pi = 3.14159;
	double r, h, c, s, sq, vq, vz;
	r = 1.5;
	h = 3;
	c = 2 * pi * r;
	s = pi * r * r;
	sq = 4 * pi * r * r;
	vq = pi * r * r * r * double(4) / double(3);
	vz = s * h;
	cout << setprecision(2);
	cout << "当 半径r=1.5，高h=3 时，有：" << endl;
	cout << "圆周长 C=" << setiosflags(ios::fixed) << c << endl;
	cout << "圆面积 S=" << setiosflags(ios::fixed) << s << endl;
	cout << "圆球表面积 S=" << setiosflags(ios::fixed) << sq << endl;
	cout << "圆球体积 V=" << setiosflags(ios::fixed) << vq << endl;
	cout << "圆柱体积 V=" << setiosflags(ios::fixed) << vz << endl;
	return 0;
}