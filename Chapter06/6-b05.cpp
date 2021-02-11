#include<iostream>
using namespace std;

int dec(char *p)
{
	int n, d=0;
	for (n = 0; *(p + n); n++)
		;
	for (int i = 0; i <= n - 1; i++)
	{
		int t=1;
		for (int j = 1; j <= i; j++)
			t *= 2;
		d += (int(*(p + n - 1 - i)) - 48) * t;
	}
	return d;
}

int main()
{
	char str[33];
	cout << "二进制：";
	cin >> str;
	cout << "十进制：" << dec(str);
	cout << endl;
	return 0;
}