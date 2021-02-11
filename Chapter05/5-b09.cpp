#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int shudu[10][10], sd[10][10];
	int i, j, k;
	ifstream fin, infile;
	fin.open("shudu.txt", ios::in);
	infile.open("shudu.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	if (!infile.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}


	/*输入1*/
	for (i = 1; i <= 3; i++)
		for (j = 1; j <= 3; j++)
			fin >> shudu[i][j];
	for (i = 1; i <= 3; i++)
		for (j = 4; j <= 6; j++)
			fin >> shudu[i][j];
	for (i = 1; i <= 3; i++)
		for (j = 7; j <= 9; j++)
			fin >> shudu[i][j];

	for (i = 4; i <= 6; i++)
		for (j = 1; j <= 3; j++)
			fin >> shudu[i][j];
	for (i = 4; i <= 6; i++)
		for (j = 4; j <= 6; j++)
			fin >> shudu[i][j];
	for (i = 4; i <= 6; i++)
		for (j = 7; j <= 9; j++)
			fin >> shudu[i][j];

	for (i = 7; i <= 9; i++)
		for (j = 1; j <= 3; j++)
			fin >> shudu[i][j];
	for (i = 7; i <= 9; i++)
		for (j = 4; j <= 6; j++)
			fin >> shudu[i][j];
	for (i = 7; i <= 9; i++)
		for (j = 7; j <= 9; j++)
			fin >> shudu[i][j];

	/*输入2*/
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
			infile >> sd[i][j];

	//fin.close();

	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
			cout << sd[i][j] << " ";
		cout<<endl;
	}
	cout << endl;

	/*判断小九宫格*/
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			for (k = j + 1; k <= 9;k++)
				if (shudu[i][j] - shudu[i][k] == 0)
				{
					cout << "不是数独的解" << endl;
					return 0;
				}
		}

	/*判断行列*/
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			for (k = j + 1; k <= 9;k++)
				if (sd[i][j] - sd[i][k] == 0)
				{
					cout << "不是数独的解" << endl;
					return 0;
				}
		}

	for (j = 1; j <= 9; j++)
		for (i = 1; i <= 9; i++)
		{
			for (k = i + 1; k <= 9; k++)
				if (sd[i][j] - sd[k][j] == 0)
				{
					cout << "不是数独的解" << endl;
					return 0;
				}
		}

	cout << "是数独的解" << endl;

	return 0;


}