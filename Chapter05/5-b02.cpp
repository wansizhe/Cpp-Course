#include<iostream>
using namespace std;

int main()
{
	int light[101];
	int i, j;
	
	for (i = 1; i <= 100; i++)
		light[i] = 2;

	for (i = 1; i <= 100; i++)
		for (j = i; j <= 100; j++)
		{
			if (j % i == 0)
				light[j]++;
		}

	cout << "100次操作后，亮着的灯有：" << endl << endl;
	for (i = 1; i <= 100; i++)
	{
		if (light[i] % 2)
			cout << i << "号灯" << endl;
	}

	cout << endl;
	return 0;
}

