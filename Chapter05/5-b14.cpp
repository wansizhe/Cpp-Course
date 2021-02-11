#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

/* ������ƶ���ָ��λ�� */
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* ��ָ��λ�ô���ӡһ��ָ�����ַ� */
void showch(HANDLE hout, int X, int Y, char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}


int main()
{
	const int MAX_X = 9;	//����*��ɵı߿�Ŀ��
	const int MAX_Y = 25;	//����*��ɵı߿�ĸ߶�
	
	char boom[10][26] = { 0 };
	int k = 0;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
							
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand(unsigned int(time(0)));

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	ע�⣺������bug���������ѭ�����ɵ�XY����ǡ����ȫ��ͬ������ĸ�����᲻��20������˵��������Ҫ�����bug�� */
	int a, b;
	while(1)
	{
		a = rand() % MAX_X;
		b = rand() % MAX_Y;
		if (boom[a][b] != '*')
		{
			k++;
			boom[a][b] = '*';
		}
		if (k == 50)
			break;
	}

	int x,  y , p=0;
	for (x = 0; x <= 9; x++)
		for (y = 0; y <= 25; y++)
		{
			if (x - 1 >= 0 && x - 1 <= 9 && y - 1 >= 0 && y - 1 <= 25 && boom[x - 1][y - 1] == '*')
				p++;
			if (x >= 0 && x <= 9 && y - 1 >= 0 && y - 1 <= 25 && boom[x][y - 1] == '*')
				p++;
			if (x + 1 >= 0 && x + 1 <= 9 && y - 1 >= 0 && y - 1 <= 25 && boom[x + 1][y - 1] == '*')
				p++;
			if (x - 1 >= 0 && x - 1 <= 9 && y >= 0 && y <= 25 && boom[x - 1][y] == '*')
				p++;
			if (x + 1 >= 0 && x + 1  <= 9 && y >= 0 && y <= 25 && boom[x + 1][y] == '*')
				p++;
			if (x - 1 >= 0 && x - 1 <= 9 && y + 1 >= 0 && y + 1 <= 25 && boom[x - 1][y + 1] == '*')
				p++;
			if (x >= 0 && x <= 9 && y + 1 >= 0 && y + 1 <= 25 && boom[x][y + 1] == '*')
				p++;
			if (x + 1 >= 0 && x + 1 <= 9 && y + 1 >= 0 && y + 1 <= 25 && boom[x + 1][y + 1] == '*')
				p++;
			
			if (boom[x][y] != '*')
				switch (p)
				{
				case 0:
					boom[x][y] = '0';
					break;
				case 1:
					boom[x][y] = '1';
					break;
				case 2:
					boom[x][y] = '2';
					break;
				case 3:
					boom[x][y] = '3';
					break;
				case 4:
					boom[x][y] = '4';
					break;
				case 5:
					boom[x][y] = '5';
					break;
				case 6:
					boom[x][y] = '6';
					break;
				case 7:
					boom[x][y] = '7';
					break;
				case 8:
					boom[x][y] = '8';
					break;
				}
			
			p = 0;
		}

	int m, n;
	for (m = 0; m <= 9; m++)
	{
		for (n = 0; n <= 25; n++)
			cout << boom[m][n] << ' ';
		cout << endl;
	}


	gotoxy(hout, 0, 23);
	return 0;
}