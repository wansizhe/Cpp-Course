#include<iostream>
using namespace std;

int main()
{
	char str[100];
	int a[10] = { 0 }, n = 0, u = 0, k;

	cin >> str;

	for (k = 0; ; k++)
	{
		if (*(str + k) >= '0' && *(str + k) <= '9')
		{
			n++;
			continue;
		}
		else if (n)
		{
			for (int j = 1; j <= n; j++)
			{
				int t = int(*(str + k - j)) - 48;
				for (int i = 1; i <= j - 1; i++)
					t *= 10;
				*(a + u) += t;
			}
			n = 0;
			u++;
		}
		if (*(str + k)==0)
			break;
	}

	cout << endl << "共" << u << "个整数：" << endl;
	for (int i = 0; i < u; i++)
		cout << *(a + i) << ' ';
	cout << endl;
	return 0;
}