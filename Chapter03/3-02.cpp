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
	cout << "�� �뾶r=1.5����h=3 ʱ���У�" << endl;
	cout << "Բ�ܳ� C=" << setiosflags(ios::fixed) << c << endl;
	cout << "Բ��� S=" << setiosflags(ios::fixed) << s << endl;
	cout << "Բ������ S=" << setiosflags(ios::fixed) << sq << endl;
	cout << "Բ����� V=" << setiosflags(ios::fixed) << vq << endl;
	cout << "Բ����� V=" << setiosflags(ios::fixed) << vz << endl;
	return 0;
}