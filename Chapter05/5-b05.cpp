#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main()
{
	int i, j, num;
	double k;
	ifstream fin;
	fin.open("score.dat", ios::in);
	double grade[1001];

	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	for (i = 1; i <= 1000; i++)
	{
		fin >> grade[i];
		if (grade[i] < 0)
		{
			i--;
			break;
		}
	}
	num = i;

	for (i = 1; i <= num-1; i++)
		for (j = 1; j <= num - i; j++)
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
	for (i = 1; i <= num; i++)
	{
		cout << setw(3) << i << "   ";
		cout << setw(3) << grade[i] << "    " << setw(3) << k << endl;
		if (grade[i + 1] == grade[i])
			j++;
		else
		{
			k += j;
			j = 1;
		}
		/*if (i % 100 == 0)
			getchar();*/
	}

	cout << endl;
	return 0;
}