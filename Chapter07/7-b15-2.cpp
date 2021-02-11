#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<fstream>
#include<string>
#include<cstring>
#include <windows.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

struct graph
{
	int wall = 0;
	int man = 0;
	int dark = 0;
	int box = 0;
	int floor = 0;
	int dest = 0;
	int exist = 0;
};

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

/*打印选关列表*/
void printlist(HANDLE hout, int curX, int curY, char f[][4], int fnum)
{
	int n = 0;
	cout << " 请选择关卡";
	curY++;
	gotoxy(hout, curX, curY);
	cout << "╔════╗";
	while (n<fnum)
	{
		curY++;
		gotoxy(hout, curX, curY);
		cout << "║关卡" << f[n] << " ║";
		n++;
	}
	curY++;
	gotoxy(hout, curX, curY);
	cout << "╚════╝";
}

/*选关*/
int selectlevel(HANDLE hout, int curX, int curY, int filenum, char f[][4])
{
	int n = 0;
	curX++;
	curX++;
	curY++;
	curY++;
	gotoxy(hout, curX, curY);
	setcolor(hout, 14, 0);
	cout << "关卡" << f[n];
	setcolor(hout, 15, 0);
	while (1)
	{
		char c = _getch();
		if (c == 13)
			break;
		else if (isascii(c) && c == 72 && n > 0)
		{
			gotoxy(hout, curX, curY);
			cout << "关卡" << f[n];
			n--;
			curY--;
			setcolor(hout, 14, 0);
			gotoxy(hout, curX, curY);
			cout << "关卡" << f[n];
			setcolor(hout, 15, 0);
		}
		else if (isascii(c) && c == 80 && n<filenum - 1)
		{
			gotoxy(hout, curX, curY);
			cout << "关卡" << f[n];
			n++;
			curY++;
			setcolor(hout, 14, 0);
			gotoxy(hout, curX, curY);
			cout << "关卡" << f[n];
			setcolor(hout, 15, 0);
		}
		else
			continue;
	}
	return n;
}

/*打印界面*/
void printone(HANDLE hout, int curX, int curY, graph unit)
{
	gotoxy(hout, curX, curY);
	if (unit.dark == 1)
	{
		setcolor(hout, 0, 0);
		for (int i = 0; i < 3; i++)
		{
			gotoxy(hout, curX, curY + i);
			cout << "      ";
		}
	}
	else if (unit.wall == 1)
	{
		setcolor(hout, 4, 0);
		cout << "╔═╗";
		gotoxy(hout, curX, curY + 1);
		cout << "║XX║";
		gotoxy(hout, curX, curY + 2);
		cout << "╚═╝";
	}
	else if (unit.floor == 1)
	{
		if (unit.box == 1 && unit.dest != 1)
		{
			setcolor(hout, 2, 14);
			cout << "╔═╗";
			gotoxy(hout, curX, curY + 1);
			cout << "║★║";
			gotoxy(hout, curX, curY + 2);
			cout << "╚═╝";
		}
		else if (unit.dest == 1 && unit.box != 1)
		{
			setcolor(hout, 11, 10);
			cout << "╔═╗";
			gotoxy(hout, curX, curY + 1);
			cout << "║●║";
			gotoxy(hout, curX, curY + 2);
			cout << "╚═╝";
		}
		else if (unit.man == 1)
		{
			setcolor(hout, 9, 14);
			cout << "╔═╗";
			gotoxy(hout, curX, curY + 1);
			cout << "║♀║";
			gotoxy(hout, curX, curY + 2);
			cout << "╚═╝";
		}
		else if (unit.box == 1 && unit.dest == 1)
		{
			setcolor(hout, 14, 12);
			cout << "╔═╗";
			gotoxy(hout, curX, curY + 1);
			cout << "║★║";
			gotoxy(hout, curX, curY + 2);
			cout << "╚═╝";
		}
		else
		{
			setcolor(hout, 8, 8);
			for (int i = 0; i < 3; i++)
			{
				gotoxy(hout, curX, curY + i);
				cout << "      ";
			}
		}
	}
	setcolor(hout, 15, 0);
}

void printall(HANDLE hout, graph map[16][16])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			printone(hout, 6 * j, 3 * i, map[i][j]);
		}
	}
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //光标位置
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	graph map[16][16];
	system("mode con cols=150 lines=150"); // cols 为列 即宽 lines 为行 即高
	FILE* fin;
	fin=fopen("Sokoban-Level.txt", "r");
	if (fin==NULL)
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	int levelnum = 0;
	//cout << '1' << endl;
	while (!feof(fin))
	{
		char line [50];
		fgets(line, 49, fin);
		if (line[0] == '['&&strlen(line) == 12 && strncmp(line, "[Level-", 7) == 0 && line[strlen(line) - 2] == ']')
		{
			levelnum++;
		}
	}
	fclose(fin);

	char(*lname)[4];
	lname = new char[levelnum][4];
	int n = 0, b = levelnum - 1;
	fin = fopen("Sokoban-Level.txt", "r");
	if (fin == NULL)
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	cout << '5' << endl;
	while (!feof(fin))
	{
		char line[50];
		fgets(line, 49, fin);
		if (line[0] == '['&&strlen(line) == 12 && strncmp(line, "[Level-", 7) == 0 && line[strlen(line) - 2] == ']')
		{
			if (line[7] >= '0'&&line[7] <= '9'&&line[8] >= '0'&&line[8] <= '9'&&line[9] >= '0'&&line[9] <= '9')
			{
				strncpy(lname[n], line + 7, 3);
				lname[n][3] = '\0';
				n++;
			}
			else
			{
				strncpy(lname[b], line + 7, 3);
				lname[b][3] = '\0';
				b--;
			}
		}
	}
	fclose(fin);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (atoi(lname[i])>atoi(lname[j]))
			{
				char temp[4];
				strcpy(temp, lname[i]);
				strcpy(lname[i], lname[j]);
				strcpy(lname[j], temp);
			}
		}
	}

	int X, Y;
	int p = 0;
	gotoxy(hout, 120, 1);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标
	printlist(hout, X, Y, lname, levelnum);
	int to_open = selectlevel(hout, X, Y, levelnum, lname);
	gotoxy(hout, 0, 0);
	char level_to_open[12] = "[Level-";
	strcat(level_to_open, lname[to_open]);
	level_to_open[10] = ']';
	level_to_open[11] = '\0';
	cout << level_to_open << endl;

	fin=fopen("Sokoban-Level.txt", "r");
	if (fin==NULL)
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	while (!feof(fin))
	{
		char line[50];
		fgets(line, 49, fin);
		if (strncmp(level_to_open, line, 11) == 0)
			p++;
	}
	fclose(fin);


	int d = 0;
	fin = fopen("Sokoban-Level.txt", "r");
	if (fin == NULL)
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	while (!feof(fin))
	{
		char line[50];
		fgets(line, 49, fin);
		if (strncmp(level_to_open, line, 11) == 0)
			d++;
		if (d == p)
			break;
	}
	while (!feof(fin))
	{
		char ch = fgetc(fin);
		if (ch == '[')
			break;
		if (!(ch == '9' || ch == '0' || ch == 'S' || ch == 's' || ch == 'R' || ch == 'r' || ch == 'W' || ch == 'w' || ch == 'B' || ch == 'b' || ch == 'F' || ch == 'f'||ch==10))
			{
				cout << "数据有误" << endl;
				fclose(fin);
				delete[]lname;
				return 0;
			}
	}
	fclose(fin);
	d = 0;
	fin = fopen("Sokoban-Level.txt", "r");
	if (fin == NULL)
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	while (!feof(fin))
	{
		char line[50];
		fgets(line, 49, fin);
		if (strncmp(level_to_open, line, 11) == 0)
			d++;
		if (d == p)
			break;
	}
	int i = -1;
	int j = -1;
	while (!feof(fin))
	{
		char ch = fgetc(fin);
		if (ch == '[')
			break;
		else
		{
			if (ch == 10)
			{
				i++;
				j = -1;
				continue;
			}
			if (i >= 16)
				break;
			j++;
			if(j<16)
			    switch (ch)
				{
				case '9':
					map[i][j].dark = 1;
					map[i][j].exist = 1;
					break;
				case 'W':
				case 'w':
					map[i][j].wall = 1;
					map[i][j].exist = 1;
					break;
				case 'B':
				case 'b':
					map[i][j].box = 1;
					map[i][j].floor = 1;
					map[i][j].exist = 1;
					break;
				case 'F':
				case 'f':
					map[i][j].dest = 1;
					map[i][j].floor = 1;
					break;
				case 'S':
				case 's':
					map[i][j].man = 1;
					map[i][j].floor = 1;
					map[i][j].exist = 1;
					break;
				case '0':
					map[i][j].floor = 1;
					map[i][j].exist = 1;
					break;
				case 'R':
				case 'r':
					map[i][j].floor = 1;
					map[i][j].dest = 1;
					map[i][j].box = 1;
					map[i][j].exist = 1;
					break;
				default:
					break;
				}
		}
	}
	printall(hout, map);
	fclose(fin);
	delete[]lname;
	return 0;
}