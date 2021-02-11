#include<iostream>
using namespace std;

int main()
{
	int i, j, k, l;
	i = 2;
	while (i <= 1000)
	{
		j = 1;
		l = 0;
		while (j < i)
		{
			k = i % j;
			if (k == 0)
				l = l + j;
			j++;
		}
		if (l == i)
		{
			cout << i << ",its factors are 1";
			for (j = 2; j < i; j++)
			{
				k = i % j;
				if (k == 0)
					cout << "," << j;
			}
			cout << endl;
		}
		i++;
	}
	return 0;
}