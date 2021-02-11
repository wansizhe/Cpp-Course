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
	cout << "第一天摘了 " << a << " 个桃子。";
	return 0;
}