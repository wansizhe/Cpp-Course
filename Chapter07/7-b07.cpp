#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>
#include<iomanip>
using namespace std;

void means1(short room[], const char *name[], int n, int m)
{
	short t;
	int q , p,s=0;
	int *bname;
	bname = new int[n];
	for (int i = 0; i < n; i++)
		bname[i] = 0;
	for (int i = 0; room[i] != 0x0000; i++)
	{
		t = room[i];
		q = 0;
		for (int j = 1; j <= 16; j++)
		{
			if ((t & 0x8000) == 0x8000)
			{
				q++;
				if (q == 1)
					cout << "| /    |";
				if(s<n)
				    while (1)
					{
						p = rand() % n;
						if (bname[p] == 0)
						{
							cout << setw(6) << setiosflags(ios::left) << name[p] << "|";
							bname[p] = 1;
							s+=1;
							break;
						}
					}
				else
					cout << " /    |";
			}
			else
				if (q != 0)
					cout << " /    |";
			t <<= 1;
		}
		cout << endl;
	}
	delete bname;
}

void means2(short room[], const char *name[], int n, int m)
{
	int *bname, row=0;
	int (*seat)[16];
	bname = new int[n];
	for (int i = 0; i < n; i++)
		bname[i] = 0;
	for (int i = 0; room[i] != 0x0000; i++)
		row++;
	seat = new int[row][16];
	short t;
	int r, l, p, s=0;
	for (int i = 0; i < row; i++)
	{
		t = room[i];
		for (int j = 0; j < 16; j++)
		{
			if ((t & 0x8000) == 0)
				seat[i][j] = 0;
			else
				seat[i][j] = 1;
			t <<= 1;
		}
	}
	for (int i = 1; s < n; i++)
	{
		r = rand() % row;
		l = rand() % 16;
		if (seat[r][l] == 1)
		{
			seat[r][l] = 2;
			s++;
		}
	}
	int line;
	for (int j = 0; j < 16; j++)
	{
		int get = 0;
		for (int i = 0; i < row; i++)
			if (seat[i][j] != 0)
			{
				line = j;
				get = 1;
				break;
			}
		if (get == 1)
			break;
	}
	for (int i = 0; i < row; i++)
	{
		s = 0;
		for (int j = line; j < 16; j++)
		{
			if (s == 0)
			{
				cout << "| /    |";
				s++;
			}
			if (seat[i][j] == 2)
			{
				while (1)
				{
					p = rand() % n;
					if (bname[p] == 0)
					{
						cout << setw(6) << setiosflags(ios::left) << name[p] << "|";
						bname[p] = 1;
						break;
					}
				}
			}
			else 
				cout << " /    |";
		}
		cout << endl;
	}
	delete bname;
	delete []seat;
}


int main()
{
	int c;
	short room[] = { 0x4444,0x4444 ,0x4444,0x0000};
	const char *name[] = { "AA","BB","CC","DD","EE","FF",NULL };
	int n=0, m=0;
	for (int i = 0; room[i] != 0x0000; i++)
	{
		short t = room[i];
		for (int j = 1; j <= 16; j++)
		{
			if ((t & 1) == 1)
				m++;
			t >>= 1;
		}
	}
	for (int i = 0; name[i] != NULL; i++)
		n++;
	if (n > m)
		return 0;
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(unsigned int(time(0)));

	cout << "========================" << endl;
	cout << "1、方法一" << endl;
	cout << "2、方法二" << endl;
	cout << "========================" << endl;
	cout << "请选择：";
	cin >> c;
	system("cls");
	char cmd[80];
	sprintf(cmd, "mode con cols=%d lines=%d", 120, 80);
	system(cmd);

	if(c==1)
	    means1(room, name, n, m);
	else if(c==2)
		means2(room, name, n, m);

	return 0;

}