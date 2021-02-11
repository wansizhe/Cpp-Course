#include<iostream>
using namespace std;

void merge(int *la, int *lb, int *lc)
{
	int i = 0, j = 0, k = 0;
	while (*(la+i) > 0 || *(lb+j) > 0)
	{
		if (*(la + i) > 0 && *(lb + j) > 0)
		{
			if (*(la + i) > *(lb + j))
			{
				*(lc + k) = *(lb + j);
				j++;
			}
			else
			{
				*(lc + k) = *(la + i);
				i++;
			}
		}
		else if (*(la + i) > 0 && *(lb + j) <= 0)
		{
			*(lc + k) = *(la + i);
			i++;
		}
		else if (*(la + i) <= 0 && *(lb + j) > 0)
		{
			*(lc + k) = *(lb + j);
			j++;
		}
		else if (*(la + i) <= 0 && *(lb + j) <= 0)
			break;
		k++;
	}
	*(lc + k) = -1;
}

int main()
{
    int a[] = { 2, 4, 6, 8, -1 }, b[] = { 1, 3, 5, 7, 9, -1 }, c[20];
	merge(a, b, c);
	int i = 0;
	while (*(c + i) > 0)
	{
		cout << *(c + i) << ' ';
		i++;
	}
	cout << endl;
	return 0;
}