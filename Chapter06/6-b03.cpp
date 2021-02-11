#include<iostream>
using namespace std;

void merge(int *la, int *lb, int *lc)
{
	int i = 0, j = 0, k = 1;
	while (1)
	{
		if (*(la + i) > 0 && *(lb + j) > 0)
		{
			if (*(la + i) < *(lb + j))
			{
				if (*(lc + k - 1) != *(lb + j))
				{
					*(lc + k) = *(lb + j);
					k++;
				}
				j++;
			}
			else if (*(la + i) > *(lb + j))
			{
				if (*(lc + k - 1) != *(la + i))
				{
					*(lc + k) = *(la + i);
					k++;
				}
				i++;
			}
			else if (*(la + i) == *(lb + j))
			{
				if (*(lc + k - 1) != *(lb + j))
				{
					*(lc + k) = *(la + i);
					k++;
				}
				i++;
				j++;
			}
		}
		else if (*(la + i) > 0 && *(lb + j) <= 0)
		{
			if (*(lc + k - 1) != *(la + i))
			{
				*(lc + k) = *(la + i);
				k++;
			}
			i++;
		}
		else if (*(la + i) <= 0 && *(lb + j) > 0)
		{
			if (*(lc + k - 1) != *(lb + j))
			{
				*(lc + k) = *(lb + j);
				k++;
			}
			j++;
		}
		else if (*(la + i) <= 0 && *(lb + j) <= 0)
			break;
	}
	*(lc + k) = -1;
}

int main()
{
	int a[] = { 8, 8, 6, 4, 2, 1, -1 }, b[] = { 9, 8, 7, 5, 5, 3, 1, -1 }, c[21] = { 0 };
	merge(a, b, c);
	int i = 1;
	while (i <= 20)
	{
		if(*(c + i) > 0)
		    cout << *(c + i) << ' ';
		i++;
	}
	cout << endl;
	return 0;
}