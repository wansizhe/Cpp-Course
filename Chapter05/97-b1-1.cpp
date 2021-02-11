#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <windows.h>
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

int main()
{
	system("mode con cols=100 lines=30"); // cols 为列 即宽 lines 为行 即高
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	const int time = 300;

	gotoxy(hout, 5, 18);
	setcolor(hout, 1, 0);
	cout << "                        ";
	Sleep(time);

	gotoxy(hout, 38, 18);
	setcolor(hout, 1, 0);
	cout << "                        ";
	Sleep(time);

	gotoxy(hout, 71, 18);
	setcolor(hout, 1, 0);
	cout << "                        ";
	Sleep(time);
	
	char ch = ' ';
	for (int i = 17; i >= 5; i--)
	{
		showch(hout, 17, i, 1, 0, ch, 1);
		Sleep(time);
		showch(hout, 50, i, 1, 0, ch, 1);
		Sleep(time);
		showch(hout, 83, i, 1, 0, ch, 1);
		Sleep(time);
	}


	
	gotoxy(hout, 0, 22);
	setcolor(hout, 15, 0);
	cout << endl;
	return 0;
}