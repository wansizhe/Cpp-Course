#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include <windows.h>
#include<io.h>
#include<stdio.h>
#include<string>
#include<cstring>
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
struct filename
{
	char fname[30];
	filename *next;
	char levelno[4] = "***";
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

/*打印选关列表*/
void printlist(HANDLE hout, int curX,int curY,filename *cur,char (*f)[4])
{
	int num = 0;
	cout << " 请选择关卡";
	curY++;
	gotoxy(hout, curX, curY );
	cout << "╔════╗";
	while (cur != NULL)
	{
		if (cur->levelno[0] != '*')
		{
			curY++;
			gotoxy(hout, curX, curY);
			strcpy(f[num], cur->levelno);
			cout << "║关卡" << f[num] << " ║";
			num++;
		}
		cur = cur->next;
	}
	curY++;
	gotoxy(hout, curX, curY);
	cout << "╚════╝" << "   共" << num << "关可选";
	//return num;
}

/*选关*/
int selectlevel(HANDLE hout, int curX, int curY,filename* cur,int filenum,char f[][4])
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
		else if (isascii(c) && c == 80&&n<filenum-1)
		{
			gotoxy(hout, curX , curY);
			cout << "关卡" << f[n];
			n++;
			curY++;
			setcolor(hout, 14, 0);
			gotoxy(hout, curX, curY);
			cout << "关卡"<<f[n];
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
		gotoxy(hout, curX, curY+1);
		cout << "║XX║";
		gotoxy(hout, curX, curY + 2);
		cout << "╚═╝";
	}
	else if (unit.floor == 1)
	{
		if (unit.box == 1&& unit.dest != 1)
		{
			setcolor(hout,2, 14);
			cout << "╔═╗";
			gotoxy(hout, curX, curY + 1);
			cout << "║★║";
			gotoxy(hout, curX, curY + 2);
			cout << "╚═╝";
		}
		else if (unit.dest == 1&& unit.box != 1)
		{
			setcolor(hout,11,10);
			cout << "╔═╗";
			gotoxy(hout, curX, curY + 1);
			cout << "║●║";
			gotoxy(hout, curX, curY + 2);
			cout << "╚═╝";
		}
		else if (unit.man == 1)
		{
			setcolor(hout,9,14);
			cout << "╔═╗";
			gotoxy(hout, curX, curY + 1);
			cout << "║♀║";
			gotoxy(hout, curX, curY + 2);
			cout << "╚═╝";
		}
		else if (unit.box == 1 && unit.dest == 1)
		{
			setcolor(hout, 14,12);
			cout << "╔═╗";
			gotoxy(hout, curX, curY + 1);
			cout << "║★║";
			gotoxy(hout, curX, curY + 2);
			cout << "╚═╝";
		}
		else
		{
			setcolor(hout,8,8);
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
	
	filename *first;
	graph map[16][16];
	first = new struct filename[1];
	char(*showlevel)[4];
	struct filename* nextone = first;

	/*获取文件名*/
	int filenum = 0;
	const char *to_search = ".\\关卡\\*.txt";
	long handle;
	struct _finddata_t fileinfo;
	handle = _findfirst(to_search, &fileinfo);
	if (handle == -1)
		return -1;
	strcpy(fileinfo.name, first->fname);
	while (!_findnext(handle, &fileinfo))
	{
		strcpy(nextone->fname, fileinfo.name);
		nextone->next = new struct filename[1];
		nextone = nextone->next;
	}
	_findclose(handle);
	nextone->next = NULL;
	nextone = first;
	while (nextone != NULL)
	{
		for (int i = 1; i <= 100; i++)
		{
			char tempname[30] = "Sokoban-Level-", tch1[4], tch2[5] = ".txt";
			if (i <= 9)
			{
				tch1[0] = '0';
				tch1[1] = '0';
				tch1[2] = char(48 + i);
				tch1[3] = '\0';
			}
			else if (i <= 99 && i >= 10)
			{
				tch1[0] = '0';
				tch1[1] = char(48 + (i / 10));
				tch1[2] = char(48 + (i % 10));
				tch1[3] = '\0';
			}
			else if (i >= 100 && i <= 999)
			{
				tch1[0] = char(48 + (i / 100));
				tch1[1] = char(48 + ((i % 100) / 10));
				tch1[2] = char(48 + ((i % 100) % 10));
				tch1[3] = '\0';
			}
			strcat(tempname, tch1);
			strcat(tempname, tch2);
			if (strcmp(tempname, nextone->fname) == 0)
			{
				strcpy(nextone->levelno, tch1);
				filenum++;
			}
		}
		nextone = nextone->next;
	}
	showlevel = new char[filenum][4];

	setcolor(hout, 15, 0);
	system("cls");
	system("mode con cols=80 lines=30"); // cols 为列 即宽 lines 为行 即高
	
	cout << "-----------------------" << endl;
	cout << "1. 显示关卡" << endl;
	cout << "0. 退出" << endl;
	cout << "-----------------------"<<endl;
	cout << "[请选择0-1]";
	char choice = _getch();

	if (choice == '0')
	{
		delete first;
		return 0;
	}

	else if (choice == '1')
	{
		system("cls");
		system("mode con cols=150 lines=150"); // cols 为列 即宽 lines 为行 即高
		
		/*打印选关列表*/
		int X, Y;
		gotoxy(hout, 120, 1);
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标

		printlist(hout, X, Y,first,showlevel);
		int toopen = selectlevel(hout, X, Y, first, filenum, showlevel);
		nextone = first;
		while (nextone != NULL)
		{
			if (nextone->levelno[0] != '*')
			{
				if (strncmp(showlevel[toopen], &(nextone->fname[14]), 3) == 0)
					break;
			}
			nextone = nextone->next;
		}
		ifstream fin;
		char path[40] = ".\\关卡\\";
		strcat(path, nextone->fname);
		fin.open(path, ios::in);
		if (!fin.is_open())
		{
			cout << "打开文件失败" << endl;
			delete[]showlevel;
			nextone = first;
			while (nextone != NULL)
			{
				filename *t = nextone->next;
				delete nextone;
				nextone = t;
			}
			return 0;
		}
		gotoxy(hout, 0, 0);
		string line;
		int i = -1;
		while (!fin.eof())
		{
			fin >> line;
			for(unsigned int j = 0; j < strlen(line.c_str()) && j<16; j++)
				if (line[j] != '9'&&line[j] != '0'&&line[j] != 'S'&&line[j] != 'R'&&line[j] != 'W'&&line[j] != 'B'&&line[j] != 'F')
				{
					cout << "数据有误" << endl;
					delete[]showlevel;
					nextone = first;
					while (nextone != NULL)
					{
						filename *t = nextone->next;
						delete nextone;
						nextone = t;
					}
					return 0;
				}
		}
		fin.close();

		fin.open(path, ios::in);
		if (!fin.is_open())
		{
			cout << "打开文件失败" << endl;
			delete[]showlevel;
			nextone = first;
			while (nextone != NULL)
			{
				filename *t = nextone->next;
				delete nextone;
				nextone = t;
			}
			return 0;
		}
		while (!fin.eof())
		{
			fin >> line;
			i++;
			for (unsigned int j = 0; j < strlen(line.c_str())&&j<16; j++)
			{
				switch (line[j])
				{
				case '9':
					map[i][j].dark = 1;
					map[i][j].exist = 1;
					break;
				case 'W':
					map[i][j].wall = 1;
					map[i][j].exist = 1;
					break;
				case 'B':
					map[i][j].box = 1;
					map[i][j].floor = 1;
					map[i][j].exist = 1;
					break;
				case 'F':
					map[i][j].dest = 1;
					map[i][j].floor = 1;
					break;
				case 'S':
					map[i][j].man = 1;
					map[i][j].floor = 1;
					map[i][j].exist = 1;
					break;
				case '0':
					map[i][j].floor = 1;
					map[i][j].exist = 1;
					break;
				case 'R':
					map[i][j].floor = 1;
					map[i][j].dest = 1;
					map[i][j].box = 1;
					map[i][j].exist = 1;
				default:
					break;
				}
			}
		}
		printall(hout, map);
		fin.close();
		getchar();
	}

	delete []showlevel;
	nextone = first;
	while (nextone != NULL)
	{
		filename *t = nextone->next;
		delete nextone;
		nextone = t;
	}

	return 0;
}