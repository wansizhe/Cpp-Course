#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <windows.h>
using namespace std;

char qidian, zhongdian, fuzhu;
int num, a, b, c, i, j, k, s=1;
const int lie = 17;
int color[11], leftp[11], wide[11], noa[10], nob[10], noc[10];

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
	int p, h, w, fcol = 0, bcol = 2, nn = n;
	char ch = ' ';
	switch (q)
	{
	case 'A':
		p = 18;
		a = n;
		b = 0;
		c = 0;
		for (int t = 0; t <= n - 1; t++)
		{
			noa[t] = nn;
			nn--;
		}
		break;
	case 'B':
		p = 51;
		b = n;
		a = 0;
		c = 0;
		for (int t = 0; t <= n - 1; t++)
		{
			nob[t] = nn;
			nn--;
		}
		break;
	case 'C':
		p = 84;
		a = 0;
		b = 0;
		c = n;
		for (int t = 0; t <= n - 1; t++)
		{
			noc[t] = nn;
			nn--;
		}
		break;
	}
	w = 3 + 2 * n;
	p = p - (w - 1) / 2;
	int i = n;
	leftp[i] = p;
	wide[i] = w;
	color[i] = bcol;
	i--;
	for (h = 17; h >= 17 - n + 1; h--)
	{
		showch(hout, p, h, bcol, fcol, ch, w);
		w -= 2;
		wide[i] = w;
		bcol++;
		color[i] = bcol;
		p++;
		leftp[i] = p;
		i--;
		Sleep(50);
	}
}

/*搬运*/
void carry(HANDLE hout, char q, char z,int n)
{
	int p, pp, p0, h0;
	int from, to;
	char ch = ' ';
	switch (q)
	{
		case 'A':
			p = 18;
			from = a;
			break;
		case 'B':
			p = 51;
			from = b;
			break;
		case 'C':
			p = 84;
			from = c;
			break;
		}
		switch (z)
		{
		case 'A':
			pp = 18;
			to = a;
			break;
		case 'B':
			pp = 51;
			to = b;
			break;
		case 'C':
			pp = 84;
			to = c;
			break;
	}
	p0 = leftp[n];

	/*上移*/
	for (h0 = 18 - from; h0 >= 5; h0--)
	{
		Sleep(60);
		showch(hout, p0, h0, 15, 0, ch, wide[n]);
		showch(hout, p, h0, 14, 0, ch, 1);
		showch(hout, p0, h0 - 1, color[n], 0, ch, wide[n]);
	}
	for (; h0 >= 3; h0--)
	{
		Sleep(60);
		showch(hout, p0, h0, 15, 0, ch, wide[n]);
		showch(hout, p0, h0 - 1, color[n], 0, ch, wide[n]);
	}
	/*平移*/
	if (pp > p)
	{
		for (; p0 <= pp - (wide[n] + 1) / 2; p0++)
		{
			Sleep(40);
			showch(hout, p0, h0, 15, 0, ch, wide[n]);
			showch(hout, p0 + 1, h0, color[n], 0, ch, wide[n]);
		}
	}
	else
	{
		for (; p0 >= pp - (wide[n] - 3) / 2; p0--)
		{
			Sleep(40);
			showch(hout, p0, h0, 15, 0, ch, wide[n]);
			showch(hout, p0 - 1, h0, color[n], 0, ch, wide[n]);
		};
	}
	/*下移*/

	for (; h0 < 5; h0++)
	{
		Sleep(40);
		showch(hout, p0, h0, 15, 0, ch, wide[n]);
		showch(hout, p0, h0 + 1, color[n], 0, ch, wide[n]);
	}
	for (; h0 <(17 - to); h0++)
	{
		Sleep(40);
		showch(hout, p0, h0, 15, 0, ch, wide[n]);
		showch(hout, pp, h0, 14, 0, ch, 1);
		showch(hout, p0, h0 + 1, color[n], 0, ch, wide[n]);
	}
	leftp[n] = p0;
}

void move(char qi, char zhong)
{
	int  i = 1, j = 1, k = 1, temp;
	s++;
	if (noa[9] > 0)
		i = 9;
	else
	{
		for (i = 0; i < 9; i++)
			if (noa[i] == 0)
				break;
		i--;
	}
	if (nob[9] > 0)
		j = 9;
	else
	{
		for (j = 0; j < 9; j++)
			if (nob[j] == 0)
				break;
		j--;
	}
	if (noc[9] > 0)
		k = 9;
	else
	{
		for (k = 0; k < 9; k++)
			if (noc[k] == 0)
				break;
		k--;
	}
	switch (qi)
	{
		case 'A':
			temp = noa[i];
			noa[i] = 0;
			a--;
			break;
		case 'B':
			temp = nob[j];
			nob[j] = 0;
			b--;
			break;
		case 'C':
			temp = noc[k];
			noc[k] = 0;
			c--;
			break;
	}

	if (noa[0] == 0)
		i = 0;
	else
	{
		for (i = 9; i > 0; i--)
			if (noa[i] != 0)
				break;
		i++;
	}
	if (nob[0] == 0)
		j = 0;
	else
	{
		for (j = 9; j > 0; j--)
			if (nob[j] != 0)
				break;
		j++;
	}
	if (noc[0] == 0)
		k = 0;
	else
	{
		for (k = 9; k > 0; k--)
			if (noc[k] != 0)
				break;
		k++;
	}
	switch (zhong)
	{
		case 'A':
			noa[i] = temp;
			a++;
			break;
		case 'B':
			nob[j] = temp;
			b++;
			break;
		case 'C':
			noc[k] = temp;
			c++;
			break;
	}
}

int main()
{
	system("mode con cols=100 lines=30"); // cols 为列 即宽 lines 为行 即高
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	cout << "请输入层数(1-10) ";
	cin >> num;
	while (num < 1 || num>10)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入层数(1-10) ";
		cin >> num;
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

	if (qidian * zhongdian == 4290)
		fuzhu = 'C';
	else if (qidian * zhongdian == 4355)
		fuzhu = 'B';
	else if (qidian * zhongdian == 4422)
		fuzhu = 'A';

	system("cls");

	gotoxy(hout, 5, 18);
	setcolor(hout, 14, 0);
	cout << "                           ";
	Sleep(10);

	gotoxy(hout, 38, 18);
	setcolor(hout, 14, 0);
	cout << "                           ";
	Sleep(10);

	gotoxy(hout, 71, 18);
	setcolor(hout, 14, 0);
	cout << "                           ";
	Sleep(10);

	char ch = ' ';
	for (int i = 17; i >= 5; i--)
	{
		showch(hout, 18, i, 14, 0, ch, 1);
		Sleep(50);
		showch(hout, 51, i, 14, 0, ch, 1);
		Sleep(50);
		showch(hout, 84, i, 14, 0, ch, 1);
		Sleep(50);
	}

	print(hout, qidian, num);
	char fin = zhongdian;
	while (1)
	{
		int v = 0, u,f=0,g=num;
		setcolor(hout, 15, 0);
		gotoxy(hout, 0, 21);
		cout << "当前第 " << s << " 步";
		gotoxy(hout, 0, 22);
		cout << "  ";
		gotoxy(hout, 0, 22);
		cin >> qidian >> zhongdian;
		while ((zhongdian != 65 && zhongdian != 97 && zhongdian != 66 && zhongdian != 98 && zhongdian != 67 && zhongdian != 99)|| (qidian != 65 && qidian != 97 && qidian != 66 && qidian != 98 && qidian != 67 && qidian != 99))
		{
			gotoxy(hout, 0, 22);
			cout << "  ";
			gotoxy(hout, 0, 22);
			cin >> qidian >> zhongdian;
		}
		if (qidian / 10 != 6)
			qidian -= 32;
		if (zhongdian / 10 != 6)
			zhongdian -= 32;
		
		switch (qidian)
		{
			case 'A':
				if (a == 0)
					continue;
				else
					u = noa[a - 1];
				break;
			case 'B':
				if (b == 0)
					continue;
				else
					u = nob[b - 1];
				break;
			case 'C':
				if (c == 0)
					continue;
				else
					u = noc[c - 1];
				break;
		}
		switch (zhongdian)
		{
			case 'A':
				if (a != 0)
					v = noa[a - 1];
				break;
			case 'B':
				if (b != 0)
					v = nob[b-1];
				break;
			case 'C':
				if(c!=0)
					v = noc[c-1];
				break;
		}
		switch (fin)
		{
			case 'A':
				for (int e = 0; e <= num; e++)
				{
					if (noa[e] == g)
						f++;
					g--;
				}
				break;
			case 'B':
				for (int e = 0; e <= num; e++)
				{
					if (nob[e] == g)
						f++;
					g--;
				}
				break;
			case 'C':
				for (int e = 0; e <= num; e++)
				{
					if (noc[e] == g)
						f++;
					g--;
				}
				break;
		}
	   if (v != 0 && wide[u] > wide[v])
			continue;
		carry(hout, qidian, zhongdian,u);
		if (f == num)
			break;
		move(qidian, zhongdian);
	}

	gotoxy(hout, 0, 21);
	setcolor(hout, 15, 0);
	cout <<"恭喜！您已递归！    共计"<<s<<"步"<<endl;
	return 0;
}

