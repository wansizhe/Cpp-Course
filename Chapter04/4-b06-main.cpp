#include<iostream>
#include"4-b6.h"
using namespace std;

int main()
{
	double a, b, c, delta;
	cout << "���������������ϵ����һ����ϵ���������" << endl;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (a == 0)
		yici(b, c);
	else if (delta > 0)
		liangshi(a, b, c);
	else if (delta == 0)
		yishi(a, b, c);
	else
		liangxu(a, b, c);
	return 0;
}