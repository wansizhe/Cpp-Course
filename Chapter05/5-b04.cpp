#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i, j;
	double k;
	double grade[51] = { 0, 43, 73, 86, 36,	96,	47,	36,	61,	46,
						99, 69, 81, 62, 97, 74,	24,	67,	62,	42,
						81,	14, 57, 20, 42, 53,	32,	37,	32, 16,
						76, 82, 27,	66,	56,	50,	26,	71,	07,	32,
						90,	79,	78, 53, 12,	56,	85,	99,	26,	96, 99};

	for (i = 1; i <= 49; i++)
		for (j = 1; j <= 50 - i; j++)
			if (grade[j] < grade[j + 1])
			{
				k = grade[j + 1];
				grade[j + 1] = grade[j];
				grade[j] = k;
			}

	k = 1; 
	j = 1;
	cout << "序号" << " ";
	cout << "分数" << "  ";
	cout << "名次" << endl;
	for (i = 1; i <= 50; i++)
		{
			cout << setw(2) << i << "   ";
			cout << setw(3) << grade[i] << "    " << setw(2) << k << endl;
			if (grade[i + 1] == grade[i])
				j++;
			else
			{
				k += j;
				j = 1;
			}
		}

		cout << endl;
		return 0;
}