#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

/* 将光标移动到指定位置 */
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* 在指定位置处打印一个指定的字符 */
void showch(HANDLE hout, int X, int Y, char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}


int main()
{
	const int MAX_X = 9;	//定义*组成的边框的宽度
	const int MAX_Y = 25;	//定义*组成的边框的高度
	
	char boom[10][26] = { 0 };
	int k = 0;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
							
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(unsigned int(time(0)));

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	rand()函数的功能：随机生成一个在 0-32767 之间的整数
	注意：程序有bug，如果两次循环生成的XY坐标恰好完全相同，则字母数量会不足20个（仅说明，不需要解决此bug） */
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