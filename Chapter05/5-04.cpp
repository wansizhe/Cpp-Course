#include<iostream>
using namespace std;
 
int main()
{
	int i;
	double t;
	double a[11] = { 1, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	cout << "������һ������";
	cin >> a[10];
	for (i = 9; i >= 0; i--)
		if (a[i + 1] < a[i])
		{
			t = a[i];
			a[i] = a[i + 1];
			a[i + 1] = t;
		}
	cout << "����������ԭ�����У�������ԭ������������Ϊ��" << endl;
	for (i = 0; i <= 10; i++)
		cout << a[i] << "  ";
	cout << endl;
	return 0;
}