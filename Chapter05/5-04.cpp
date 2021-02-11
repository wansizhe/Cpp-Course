#include<iostream>
using namespace std;
 
int main()
{
	int i;
	double t;
	double a[11] = { 1, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	cout << "请输入一个数：";
	cin >> a[10];
	for (i = 9; i >= 0; i--)
		if (a[i + 1] < a[i])
		{
			t = a[i];
			a[i] = a[i + 1];
			a[i + 1] = t;
		}
	cout << "将该数插入原数集中，并按照原规律升序排列为：" << endl;
	for (i = 0; i <= 10; i++)
		cout << a[i] << "  ";
	cout << endl;
	return 0;
}