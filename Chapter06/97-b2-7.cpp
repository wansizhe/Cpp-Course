#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <windows.h>
#include<iomanip>
#include <conio.h>
#include <time.h>
#include<stdio.h>
using namespace std;

/* 将光标移动到指定位置 */
void gotoxy(HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* 设置指定的颜色

颜色的取值由背景色+前景色组成，各16种
fg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
bg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
最终的颜色为 背景色*16+前景色 */
void setcolor(HANDLE hout, const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(hout, bg_color * 16 + fg_color);
}

/* 在指定位置，用指定颜色，显示一个字符 */
void showch(HANDLE hout, const int X, const int Y, const int bg_color, const int fg_color, const char ch, const int n)
{
	int i;
	gotoxy(hout, X, Y);
	setcolor(hout, bg_color, fg_color);

	/* 循环n次，打印字符ch */
	for (i = 0; i<n; i++)
		putchar(ch);
}

/*判断行列输入范围*/
bool r_l(int rl, int high = 8, int low = 5)
{
	bool error;
	if (rl > high || rl < low)
		error = true;
	else
		error = false;
	return error;
}

/*初始化*/
void initialize(int row, int line, int getX[][22])
{
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
		{
			getX[i][j] = rand();
			while (getX[i][j] <= 0 || getX[i][j] >= 4)
				getX[i][j] = rand();
		}
}

/*打印一个*/
void printone(HANDLE hout, int t, int l, int r, int bb,bool center=false)
{
	if (t == 0)
		setcolor(hout, 15, 15);
	else if (bb == 1 && center)
		setcolor(hout, 14, 13);
	else if (bb == 1 && !center)
		setcolor(hout, 14, 0);
	else
	{
		if (t >= 1 && t <= 6)
			setcolor(hout, t, 0);
		else
			setcolor(hout, t + 2, 0);
	}
	gotoxy(hout,l,r);
	cout << "╭─╮";
	gotoxy(hout, l, r + 1);
	cout << "│" << setw(2) << t << "┃";
	gotoxy(hout, l, r + 2);
	cout << "╰━╯";
}

/*打印所有*/
void printall(HANDLE hout, int getX[][22], int line, int row,int bgetx[][22])
{
	setcolor(hout, 15, 0);
	gotoxy(hout, 0, 0);
	cout << "┍";
	//Sleep(10);
	for (int i = 1; i <= 4 * line - 1; i++)
	{
		if (i % 4 == 0)
			cout << "┯";
		else
			cout << "━";
		//Sleep(10);
	}
	cout << "┑" << endl;
	//Sleep(10);
	for (int i = 1; i <= 4 * row - 1; i++)
	{
		if (i % 4 == 0)
		{
			cout << "┝";
			for (int i = 1; i <= 4 * line - 1; i++)
			{
				if (i % 4 == 0)
					cout << "┿";
				else
					cout << "━";
				//Sleep(10);
			}
			cout << "┥";
			//Sleep(10);
			cout << endl;
		}
		else
		{
			cout << "│";
			for (int i = 1; i <= 4 * line - 1; i++)
			{
				if (i % 4 == 0)
					cout << "│";
				else
					cout << "  ";
				//Sleep(10);
			}
			cout << "│";
			//Sleep(10);
			cout << endl;
		}
	}
	gotoxy(hout, 0, 4 * row);
	cout << "┕";
	//Sleep(10);
	for (int i = 1; i <= 4 * line - 1; i++)
	{
		if (i % 4 == 0)
			cout << "┷";
		else
			cout << "━";
		//Sleep(10);
	}
	cout << "┙";
	//Sleep(10);

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= line; j++)
		{
			printone(hout, getX[i][j], 8 * (j - 1) + 2, 4 * (i - 1) + 1, bgetx[i][j]);
			//Sleep(10);
		}
		cout << endl;
	}
}

/*判断连续*/
void continuous(int r, int l, int bgetx[][22], int getX[][22])
{
	bgetx[r][l] = 1;
	if (getX[r - 1][l] == getX[r][l] && bgetx[r - 1][l] == 0)
	{
		bgetx[r - 1][l] = 1;
		continuous(r - 1, l, bgetx, getX);
	}
	if (getX[r + 1][l] == getX[r][l] && bgetx[r + 1][l] == 0)
	{
		bgetx[r + 1][l] = 1;
		continuous(r + 1, l, bgetx, getX);
	}
	if (getX[r][l - 1] == getX[r][l] && bgetx[r][l - 1] == 0)
	{
		bgetx[r][l - 1] = 1;
		continuous(r, l - 1, bgetx, getX);
	}if (getX[r][l + 1] == getX[r][l] && bgetx[r][l + 1] == 0)
	{
		bgetx[r][l + 1] = 1;
		continuous(r, l + 1, bgetx, getX);
	}
}

/*合并相同数*/
void merge(int r, int l, int row, int line, int bgetx[][22], int getX[][22], int *ds, int *s)
{
	int num = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			if ((i != r || j != l) && bgetx[i][j] == 1)
			{
				getX[i][j] = 0;
				num++;
			}
	*ds = getX[r][l] * 3 * (num + 1);
	*s += *ds;
	getX[r][l]++;
	bgetx[r][l] = 0;
}

/*下落*/
void drop(int row, int line, int bgetx[][22], int getX[][22])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int j = 1; j <= line; j++)
	{
		int t;
		while (1)
		{
			int n = 0;
			for (int i = row; i >= 1; i--)
				if (getX[i][j] == 0 && getX[i - 1][j] != 0)
				{
					t = getX[i][j];
					getX[i][j] = getX[i - 1][j];
					bgetx[i][j] = 0;
					getX[i - 1][j] = t;
					bgetx[i - 1][j] = 1;
					n++;

					for (int k = 0; 4 * (i - 2) + 1 + k <= 4 *( i-1) + 1; k++)
					{
						
						gotoxy(hout, 8 * (j - 1) + 2, 4 * (i - 2) + k);
						setcolor(hout, 15, 15);
						cout << "      ";
						gotoxy(hout, 8 * (j - 1) + 2, 4 * (i - 1));
						setcolor(hout, 15, 0);
						cout << "━━━";
						gotoxy(hout, 8 * (j - 1) + 2, 4 * (i - 2));
						setcolor(hout, 15, 0);
						cout << "━━━";
						printone(hout, getX[i][j], 8 * (j - 1) + 2, 4 * (i - 2) + 1+k, 0);
						Sleep(50);
					}


				}
			if (n == 0)
				break;
		}
	}
}

/*确定最大值*/
int the_max(int getX[][22], int row, int line)
{
	int max = getX[1][1];
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			if (getX[i][j]>max)
				max = getX[i][j];
	return max;
}

/*讨论随机数概率*/
int probability(int m)
{
	int n = rand() % 100;
	switch (m)
	{
	case 3:
		if (n <= 33)
			return 1;
		else if (n >= 67)
			return 2;
		else
			return 3;
	case 4:
		if (n < 30)
			return 1;
		else if (n >= 30 && n < 60)
			return 2;
		else if (n >= 60 && n < 90)
			return 3;
		else
			return 4;
	case 5:
		if (n < 25)
			return 1;
		else if (n >= 25 && n < 50)
			return 2;
		else if (n >= 50 && n < 75)
			return 3;
		else if (n >= 75 && n < 90)
			return 4;
		else
			return 5;
	case 6:
		if (n < 20)
			return 1;
		else if (n >= 20 && n < 40)
			return 2;
		else if (n >= 40 && n < 60)
			return 3;
		else if (n >= 60 && n < 80)
			return 4;
		else if (n >= 80 && n < 95)
			return 5;
		else
			return 6;
	default:
		if (n < 5)
			return m;
		else if (n >= 5 && n < 10)
			return m - 1;
		else if (n >= 10 && n < 20)
			return m - 2;
		else
			return (rand() % (m - 2)) + 1;
	}
}

/*再生*/
void regenerate(int row, int line, int getX[][22])
{
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			if (getX[i][j] == 0)
				getX[i][j] = probability(the_max(getX, row, line));
}



int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //光标位置
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(unsigned int(time(0)));

	int row, line, X, Y, getX[22][22] = { 0 }, bgetx[22][22] = { 0 }, score = 0;

	/*输入行列并判断是否合法*/
	cout << "请输入行数（5-8）：";
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标
	cin >> row;
	while (r_l(row))
	{
		cout << "输入错误，请重新输入。";
		showch(hout, X, Y, 15, 0, ' ', 2);
		gotoxy(hout, X, Y);
		cin >> row;
	}
	showch(hout, 0, Y + 1, 15, 0, ' ', 25);
	gotoxy(hout, 0, Y + 1);
	cout << "请输入列数（5-8）：";
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标
	cin >> line;
	while (r_l(line))
	{
		cout << "输入错误，请重新输入。";
		showch(hout, X, Y, 15, 0, ' ', 2);
		gotoxy(hout, X, Y);
		cin >> line;
	}
	showch(hout, 0, Y + 1, 15, 0, ' ', 25);
	cout << endl;

	/*设置窗口*/
	system("cls");
	char cmd[80];
	sprintf(cmd, "mode con cols=%d lines=%d", 7 * line + 12, 5 * row - 1);
	system(cmd);

	/*初始化*/
	initialize(row, line, getX);
	printall(hout, getX, line, row,bgetx);

	/*箭头选择*/
	char arrow;
	int x = 1, y = 1, step = 1;
	bool uncont = true, unmerg = true, undrop = true, unrege = true;
	printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1,1);
	while (step<=1)
	{
		int ds = 0, n = 0;
		arrow = _getch();
		if (arrow == 13)
		{
			/*连续标记*/
			if (uncont)
			{
				continuous(y, x, bgetx, getX);
				for (int i = 1; i <= row; i++)
					for (int j = 1; j <= line; j++)
						if (bgetx[i][j] == 1)
							printone(hout, getX[i][j], 8 * (j - 1) + 2, 4 * (i - 1) + 1, bgetx[i][j]);
				printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1, bgetx[y][x], true);
				for (int a = 1; a <= row; a++)
					for (int b = 1; b <= line; b++)
						if (bgetx[a][b] == 1)
							n++;
				if (n <= 1)
					continue;
				else
				    uncont = false;
			}
			/*连续合并*/
			else if (unmerg)
			{
				merge(y, x, row, line, bgetx, getX, &ds, &score);
				for (int i = 1; i <= row; i++)
					for (int j = 1; j <= line; j++)
						if (bgetx[i][j] == 1)
							printone(hout, getX[i][j], 8 * (j - 1) + 2, 4 * (i - 1) + 1, bgetx[i][j]);
				/*合并闪烁*/
				for (int i = 1; i <= 10; i++)
				{
					Sleep(50);
					if (i % 2 == 1)
						printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1, bgetx[y][x], true);
					else
						printone(hout, 0, 8 * (x - 1) + 2, 4 * (y - 1) + 1, bgetx[y][x], true);
				}
				printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1, 0);
				unmerg = false;
				/*得分*/
				setcolor(hout, 15, 0);
				gotoxy(hout, 0, 4 * row + 1);
				cout << "本次得分：" << ds << "   总得分：" << score << "   合成目标：10";
			}
			/*下落*/
			else if (undrop)
			{
				drop(row, line, bgetx, getX);
				
				undrop = false;
			}
			/*再生*/
			else if (unrege)
			{
				regenerate(row, line, getX);
				for (int i = 1; i <= row; i++)
					for (int j = 1; j <= line; j++)
						if (bgetx[i][j] == 1)
						{
							printone(hout, getX[i][j], 8 * (j - 1) + 2, 4 * (i - 1) + 1, 0);
							bgetx[i][j] = 0;
							Sleep(50);
						}
				step++;
				uncont = true;
				unmerg = true;
				undrop = true;
				unrege = true;
			}
		}
		else if (isascii(arrow))
		{
			uncont = true;
			for (int i = 1; i <= row; i++)
				for (int j = 1; j <= line; j++)
					if (bgetx[i][j] == 1)
						printone(hout, getX[i][j], 8 * (j - 1) + 2, 4 * (i - 1) + 1, 0);
			for (int a = 1; a <= row; a++)
				for (int b = 1; b <= line; b++)
					bgetx[a][b] = 0;
			switch (arrow)
			{
			case 75:
				printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1, false);
				if (x == 1)
					x = line;
				else
					x--;
				break;
			case 72:
				printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1, false);
				if (y == 1)
					y = row;
				else
					y--;
				break;
			case 80:
				printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1, false);
				if (y == row)
					y = 1;
				else
					y++;
				break;
			case 77:
				printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1, false);
				if (x == line)
					x = 1;
				else
					x++;
				break;
			}
			printone(hout, getX[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1, true);
		}
	}


	setcolor(hout, 15, 0);
	gotoxy(hout, 0, 4 * row + 2);
	cout << endl;
	return 0;
}