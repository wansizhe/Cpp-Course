#include<iostream>
using namespace std;

int main()
{
	int a, i;
	a = 1;
	i = 9;
	while (i > 0)
	{
		a = 2 * (a + 1);
		i--;
	}
	cout << "��һ��ժ�� " << a << " �����ӡ�";
	return 0;
}