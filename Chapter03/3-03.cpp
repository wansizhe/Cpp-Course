#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double c, f;
	cout << "������һ�� �����¶� ��ֵ" << endl;
	cin >>f;
	c = (f - 32) * double(5) / double(9);
	cout << setprecision(2);
	cout <<"ת��Ϊ�����¶�Ϊ��" << endl;
	cout << setiosflags(ios::fixed) << c << "��  ��С�������2λ��" << endl;
	return 0;
}