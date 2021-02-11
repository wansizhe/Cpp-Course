#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <windows.h>
#include<iomanip>
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
void printone(HANDLE hout, int t, int l, int r)
{
	if (t >= 1 && t <= 6)
		setcolor(hout, t, 0);
	else
		setcolor(hout, t + 2, 0);
	gotoxy(hout, l, r);
	cout << "╭─╮";
	gotoxy(hout, l, r + 1);
	cout << "│" << setw(2) << t << "┃";
	gotoxy(hout, l, r + 2);
	cout << "╰━╯";
}

/*打印所有*/
void printall(HANDLE hout, int getX[][22], int line, int row)
{
	setcolor(hout, 15, 0);
	gotoxy(hout, 0, 0);
	cout << "┍";
	Sleep(10);
	for (int i = 1; i <= 4 * line-1; i++)
	{
		if (i % 4 == 0)
			cout << "┯";
		else
		    cout << "━";
		Sleep(10);
	}
	cout << "┑" << endl;
	Sleep(10);
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
				Sleep(10);
			}
			cout << "┥";
			Sleep(10);
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
				Sleep(10);
			}
			cout << "│";
			Sleep(10);
			cout << endl;
		}
	}
	gotoxy(hout, 0, 4 * row );
	cout << "┕";
	Sleep(100);
	for (int i = 1; i <= 4 * line-1; i++)
	{
		if (i % 4 == 0)
			cout << "┷";
		else
			cout << "━";
		Sleep(10);
	}
	cout << "┙";
	Sleep(100);

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= line; j++)
		{
			printone(hout, getX[i][j], 8 * (j - 1) + 2, 4 * (i - 1) + 1);
			Sleep(50);
		}
		cout << endl;
	}
}


int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //光标位置
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(unsigned int(time(0)));

	int row, line, X, Y, getX[22][22] = { 0 };

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
	sprintf(cmd, "mode con cols=%d lines=%d", 7 * line + 12, 5 * row-1);
	system(cmd);

	/*初始化*/
	initialize(row, line, getX);
	printall(hout, getX, line, row);


	setcolor(hout, 15, 0);
	cout << endl << endl << endl;
	return 0;
}