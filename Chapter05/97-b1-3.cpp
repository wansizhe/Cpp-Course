#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <windows.h>
using namespace std;

char qidian, zhongdian, fuzhu;
const int hanga = 62;
const int hangb = 80;
const int hangc = 98;
const int lie = 17;
const int speed = 300;

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

/*打印盘子*/
void print(HANDLE hout, char q, int n)
{
	int p, h, w, fcol = 0, bcol = 2;
	char ch = ' ';
	switch (q)
	{
		case 'A':
			p = 18;
			break;
		case 'B':
			p = 51;
			break;
		case 'C':
			p = 84;
			break;
		default:
			break;
	}
	w = 3 + 2 * n;
	p = p - (w - 1) / 2;
	for (h = 17; h >= 17 - n + 1; h--)
	{
		showch(hout, p, h, bcol, fcol, ch, w);
		w -= 2;
		bcol++;
		p++;
		Sleep(speed);
	}
}

/*搬运*/
void carry(HANDLE hout, char q,char z,int n)
{
	int p,pp, h, w, fcol = 0, bcol = 2,p0,h0;
	char ch = ' ';
	switch (q)
	{
		case 'A':
			p = 18;
			break;
		case 'B':
			p = 51;
			break;
		case 'C':
			p = 84;
			break;
		default:
			break;
	}
	switch (z)
	{
		case 'A':
			pp = 18;
			break;
		case 'B':
			pp = 51;
			break;
		case 'C':
			pp = 84;
			break;
		default:
			break;
	}
	w = 3 + 2 * n;
	p0 = p - (w - 1) / 2-1;
	for (h = 17; h >= 17 - n + 1; h--)
	{
		w -= 2;
		bcol++;
		p0++;
	}
	bcol--;
	h++;
	w += 2;
	h0 = h;
	/*上移*/
	for (; h0 >= 5;h0--)
	{
		Sleep(100);
		showch(hout, p0, h0, 15, 0, ch, w);
		showch(hout, p, h0, 14, 0, ch, 1);
		showch(hout, p0, h0 - 1, bcol, 0, ch, w);
	}
	for (; h0 >= 3; h0--)
	{
		Sleep(100);
		showch(hout, p0, h0, 15, 0, ch, w);
		showch(hout, p0, h0 - 1, bcol, 0, ch, w);
	}
	/*平移*/
	if (pp > p)
	{
		for (; p0 <= pp - (w + 1) / 2; p0++)
		{
			Sleep(50);
			showch(hout, p0, h0, 15, 0, ch, w);
			showch(hout, p0+1, h0, bcol, 0, ch, w);
		}
	}
	else
	{
		for (; p0 >= pp - (w + 1) / 2; p0--)
		{
			Sleep(50);
			showch(hout, p0, h0, 15, 0, ch, w);
			showch(hout, p0 - 1, h0, bcol, 0, ch, w);
		};
	}
	/*下移*/

	for (; h0 <= 5; h0++)
	{
		Sleep(100);
		showch(hout, p0, h0, 15, 0, ch, w);
		showch(hout, p0, h0 + 1, bcol, 0, ch, w);
	}
	for (; h0 < 17; h0++)
	{
		Sleep(100);
		showch(hout, p0, h0, 15, 0, ch, w);
		showch(hout, pp, h0, 14, 0, ch, 1);
		showch(hout, p0, h0 + 1, bcol, 0, ch, w);
	}
}


int main()
{
	system("mode con cols=100 lines=30"); // cols 为列 即宽 lines 为行 即高
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	int n;
	cout << "请输入层数(1-10) ";
	cin >> n;
	while (n < 1 || n > 10)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入层数(1-10) ";
		cin >> n;
	}
	cout << "请输入起点(A-C) ";
	cin >> qidian;
	while (qidian != 65 && qidian != 97 && qidian != 66 && qidian != 98 && qidian != 67 && qidian != 99)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入起点(A-C) ";
		cin >> qidian;
	}
	cout << "请输入终点(A-C) ";
	cin >> zhongdian;
	while (zhongdian != 65 && zhongdian != 97 && zhongdian != 66 && zhongdian != 98 && zhongdian != 67 && zhongdian != 99)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入终点(A-C) ";
		cin >> zhongdian;
	}
	if (qidian / 10 != 6)
		qidian -= 32;
	if (zhongdian / 10 != 6)
		zhongdian -= 32;

	system("cls");

	gotoxy(hout, 5, 18);
	setcolor(hout, 14, 0);
	cout << "                           ";
	Sleep(speed);

	gotoxy(hout, 38, 18);
	setcolor(hout, 14, 0);
	cout << "                           ";
	Sleep(speed);

	gotoxy(hout, 71, 18);
	setcolor(hout, 14, 0);
	cout << "                           ";
	Sleep(speed);

	char ch = ' ';
	for (int i = 17; i >= 5; i--)
	{
		showch(hout, 18, i, 14, 0, ch, 1);
		//Sleep(speed);
		showch(hout, 51, i, 14, 0, ch, 1);
		//Sleep(speed);
		showch(hout, 84, i, 14, 0, ch, 1);
		//Sleep(speed);
	}

	print(hout, qidian, n);
	
	carry(hout, qidian, zhongdian, n);


	gotoxy(hout, 0, 22);
	setcolor(hout, 15, 0);
	cout << endl;
	return 0;
}