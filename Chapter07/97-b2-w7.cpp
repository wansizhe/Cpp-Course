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
struct step
{
	step *past;
	char stepinfo;
	graph curmap[16][16];
	step *next;
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
void printlist(HANDLE hout, int curX, int curY, filename *cur, char(*f)[100])
{
	int num = 0;
	cout << " 请选择关卡";
	curY++;
	gotoxy(hout, curX, curY);
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
int selectlevel(HANDLE hout, int curX, int curY, filename* cur, int filenum, char f[][100])
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
		else if (unit.dest == 1 && unit.box != 1 && unit.man != 1)
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

/*操作*/
int play(HANDLE hout, graph cur[16][16], char ctrl, char choice,int stepn,step* curstep=NULL)
{
	int manr, manl;
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			if (cur[i][j].man == 1)
			{
				manr = i;
				manl = j;
			}
	if (choice == '2')
	{
		switch (ctrl)
		{
		case 72/*up*/:
			if (manr - 1 > 0 && cur[manr - 1][manl].exist == 1 && cur[manr - 1][manl].box != 1 && cur[manr - 1][manl].wall != 1 && cur[manr - 1][manl].dark != 1 && cur[manr - 1][manl].floor == 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manr--;
				cur[manr][manl].man = 1;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				stepn++;
			}
			else if (manr - 1 > 0 && cur[manr - 1][manl].exist == 1 && cur[manr - 1][manl].wall != 1 && cur[manr - 1][manl].dark != 1 && cur[manr - 1][manl].floor == 1 && cur[manr - 1][manl].box == 1 && cur[manr - 2][manl].wall != 1 && cur[manr - 2][manl].dark != 1 && manr - 2>0 && cur[manr - 2][manl].exist == 1 && cur[manr - 2][manl].box != 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manr--;
				cur[manr][manl].man = 1;
				cur[manr][manl].box = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				cur[manr - 1][manl].box = 1;
				printone(hout, 6 * manl, 3 * (manr - 1), cur[manr - 1][manl]);
				stepn++;
			}
			if(curstep!=NULL)
			    curstep->stepinfo = 'U';
			break;
		case 77/*right*/:
			//cout << "r";
			if (manl + 1 < 16 && cur[manr][manl + 1].exist == 1 && cur[manr][manl + 1].box != 1 && cur[manr][manl + 1].wall != 1 && cur[manr][manl + 1].dark != 1 && cur[manr][manl + 1].floor == 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manl++;
				cur[manr][manl].man = 1;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				stepn++;
			}
			else if (manl + 1 < 16 && cur[manr][manl + 1].exist == 1 && cur[manr][manl + 1].wall != 1 && cur[manr][manl + 1].dark != 1 && cur[manr][manl + 1].floor == 1 && cur[manr][manl + 1].box == 1 && cur[manr][manl + 2].wall != 1 && cur[manr][manl + 2].dark != 1 && manl + 2<16 && cur[manr][manl + 2].exist == 1 && cur[manr][manl + 2].box != 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manl++;
				cur[manr][manl].man = 1;
				cur[manr][manl].box = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				cur[manr][manl + 1].box = 1;
				printone(hout, 6 * (manl + 1), 3 * manr, cur[manr][manl + 1]);
				stepn++;
			}
			if (curstep != NULL)
				curstep->stepinfo = 'R';
			break;
		case 75/*left*/:
			//cout << "l";
			if (manl - 1 >0 && cur[manr][manl - 1].exist == 1 && cur[manr][manl - 1].box != 1 && cur[manr][manl - 1].wall != 1 && cur[manr][manl - 1].dark != 1 && cur[manr][manl - 1].floor == 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manl--;
				cur[manr][manl].man = 1;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				stepn++;
			}
			else if (manl - 1 > 0 && cur[manr][manl - 1].exist == 1 && cur[manr][manl - 1].wall != 1 && cur[manr][manl - 1].dark != 1 && cur[manr][manl - 1].floor == 1 && cur[manr][manl - 1].box == 1 && cur[manr][manl - 2].wall != 1 && cur[manr][manl - 2].dark != 1 && manl - 2>0 && cur[manr][manl - 2].exist == 1 && cur[manr][manl - 2].box != 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manl--;
				cur[manr][manl].man = 1;
				cur[manr][manl].box = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				cur[manr][manl - 1].box = 1;
				printone(hout, 6 * (manl - 1), 3 * manr, cur[manr][manl - 1]);
				stepn++;
			}
			if (curstep != NULL)
				curstep->stepinfo = 'L';
			break;
		case 80/*down*/:
			//cout << "d";
			if (manr + 1 < 16 && cur[manr + 1][manl].exist == 1 && cur[manr + 1][manl].box != 1 && cur[manr + 1][manl].wall != 1 && cur[manr + 1][manl].dark != 1 && cur[manr + 1][manl].floor == 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manr++;
				cur[manr][manl].man = 1;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				stepn++;
			}
			else if (manr + 1<16 && cur[manr + 1][manl].exist == 1 && cur[manr + 1][manl].wall != 1 && cur[manr + 1][manl].dark != 1 && cur[manr + 1][manl].floor == 1 && cur[manr + 1][manl].box == 1 && cur[manr + 2][manl].wall != 1 && cur[manr + 2][manl].dark != 1 && manr + 2<16 && cur[manr + 2][manl].exist == 1 && cur[manr + 2][manl].box != 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manr++;
				cur[manr][manl].man = 1;
				cur[manr][manl].box = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				cur[manr + 1][manl].box = 1;
				printone(hout, 6 * manl, 3 * (manr + 1), cur[manr + 1][manl]);
				stepn++;
			}
			if (curstep != NULL)
				curstep->stepinfo = 'D';
			break;
		default:
			//cout << "n";
			break;
		}

	}

	if (choice == '3')
	{
		switch (ctrl)
		{
		case 'U':
		case 'u':
			//cout << ctrl;
			if (manr - 1 > 0 && cur[manr - 1][manl].exist == 1 && cur[manr - 1][manl].box != 1 && cur[manr - 1][manl].wall != 1 && cur[manr - 1][manl].dark != 1 && cur[manr - 1][manl].floor == 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manr--;
				cur[manr][manl].man = 1;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				stepn++;
			}
			else if (manr - 1 > 0 && cur[manr - 1][manl].exist == 1 && cur[manr - 1][manl].wall != 1 && cur[manr - 1][manl].dark != 1 && cur[manr - 1][manl].floor == 1 && cur[manr - 1][manl].box == 1 && cur[manr - 2][manl].wall != 1 && cur[manr - 2][manl].dark != 1 && manr - 2>0 && cur[manr - 2][manl].exist == 1 && cur[manr - 2][manl].box != 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manr--;
				cur[manr][manl].man = 1;
				cur[manr][manl].box = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				cur[manr - 1][manl].box = 1;
				printone(hout, 6 * manl, 3 * (manr - 1), cur[manr - 1][manl]);
				stepn++;
			}
			break;
		case 'R':
		case 'r':
			//cout << ctrl;
			if (manl + 1 < 16 && cur[manr][manl + 1].exist == 1 && cur[manr][manl + 1].box != 1 && cur[manr][manl + 1].wall != 1 && cur[manr][manl + 1].dark != 1 && cur[manr][manl + 1].floor == 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manl++;
				cur[manr][manl].man = 1;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				stepn++;
			}
			else if (manl + 1 < 16 && cur[manr][manl + 1].exist == 1 && cur[manr][manl + 1].wall != 1 && cur[manr][manl + 1].dark != 1 && cur[manr][manl + 1].floor == 1 && cur[manr][manl + 1].box == 1 && cur[manr][manl + 2].wall != 1 && cur[manr][manl + 2].dark != 1 && manl + 2<16 && cur[manr][manl + 2].exist == 1 && cur[manr][manl + 2].box != 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manl++;
				cur[manr][manl].man = 1;
				cur[manr][manl].box = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				cur[manr][manl + 1].box = 1;
				printone(hout, 6 * (manl + 1), 3 * manr, cur[manr][manl + 1]);
				stepn++;
			}
			break;
		case 'L':
		case 'l':
			//cout << ctrl;
			if (manl - 1 >0 && cur[manr][manl - 1].exist == 1 && cur[manr][manl - 1].box != 1 && cur[manr][manl - 1].wall != 1 && cur[manr][manl - 1].dark != 1 && cur[manr][manl - 1].floor == 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manl--;
				cur[manr][manl].man = 1;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				stepn++;
			}
			else if (manl - 1 > 0 && cur[manr][manl - 1].exist == 1 && cur[manr][manl - 1].wall != 1 && cur[manr][manl - 1].dark != 1 && cur[manr][manl - 1].floor == 1 && cur[manr][manl - 1].box == 1 && cur[manr][manl - 2].wall != 1 && cur[manr][manl - 2].dark != 1 && manl - 2>0 && cur[manr][manl - 2].exist == 1 && cur[manr][manl - 2].box != 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manl--;
				cur[manr][manl].man = 1;
				cur[manr][manl].box = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				cur[manr][manl - 1].box = 1;
				printone(hout, 6 * (manl - 1), 3 * manr, cur[manr][manl - 1]);
				stepn++;
			}
			break;
		case 'D':
		case 'd':
			//cout << ctrl;
			if (manr + 1 < 16 && cur[manr + 1][manl].exist == 1 && cur[manr + 1][manl].box != 1 && cur[manr + 1][manl].wall != 1 && cur[manr + 1][manl].dark != 1 && cur[manr + 1][manl].floor == 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manr++;
				cur[manr][manl].man = 1;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				stepn++;
			}
			else if (manr + 1<16 && cur[manr + 1][manl].exist == 1 && cur[manr + 1][manl].wall != 1 && cur[manr + 1][manl].dark != 1 && cur[manr + 1][manl].floor == 1 && cur[manr + 1][manl].box == 1 && cur[manr + 2][manl].wall != 1 && cur[manr + 2][manl].dark != 1 && manr + 2<16 && cur[manr + 2][manl].exist == 1 && cur[manr + 2][manl].box != 1)
			{
				cur[manr][manl].man = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				manr++;
				cur[manr][manl].man = 1;
				cur[manr][manl].box = 0;
				printone(hout, 6 * manl, 3 * manr, cur[manr][manl]);
				cur[manr + 1][manl].box = 1;
				printone(hout, 6 * manl, 3 * (manr + 1), cur[manr + 1][manl]);
				stepn++;
			}
			break;
		default:
			break;
		}
	}

	return stepn;
}

bool win(graph cur[16][16])
{
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
		{
			if (cur[i][j].exist == 1)
				if (cur[i][j].dest == 1 && cur[i][j].box != 1)
					return false;
		}
	return true;
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //光标位置
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	filename *first;
	first = new struct filename[1];
	char(*showlevel)[100];
	struct filename* nextone = first;


	/*获取文件名*/
	int filenum = 0;
	const char *to_search = ".\\关卡\\*.txt";
	long handle;
	struct _finddata_t fileinfo;
	handle = _findfirst(to_search, &fileinfo);
	if (handle == -1)
	{
		cout << "无数据文件" << endl;
		return -1;
	}
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
	showlevel = new char[filenum][100];

	while (1)
	{
		int stepn = 0, best=-1;
		graph map[16][16];
		char score[40] = ".\\关卡\\";
		char path[40] = ".\\关卡\\";
		char ans[40];
		char temp[10];
		setcolor(hout, 15, 0);
		system("cls");
		system("mode con cols=80 lines=30"); // cols 为列 即宽 lines 为行 即高

		cout << "-----------------------" << endl;
		cout << "1. 显示关卡" << endl;
		cout << "2. 开始游戏" << endl;
		cout << "3. 自动演示" << endl;
		cout << "0. 退出" << endl;
		cout << "-----------------------" << endl;
		cout << "[请选择0-3]";
		char choice = _getch();

		if (choice == '0')
		{
			break;
		}

		else if (choice == '1' || choice == '2' || choice == '3')
		{
			system("cls");
			system("mode con cols=150 lines=150"); // cols 为列 即宽 lines 为行 即高

												   /*打印选关列表*/
			int X, Y;
			gotoxy(hout, 120, 1);
			GetConsoleScreenBufferInfo(hConsole, &csbi);
			X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标

			printlist(hout, X, Y, first, showlevel);
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
			strcat(path, nextone->fname);
			fin.open(path, ios::in);
			if (!fin.is_open())
			{
				cout << "打开文件失败" << endl;
				getchar();
				continue;
			}
			gotoxy(hout, 0, 0);
			string line;
			bool error = false;
			int i = -1;
			while (!fin.eof())
			{
				fin >> line;
				for (unsigned int j = 0; j < strlen(line.c_str()) && j<16; j++)
					if (line[j] != '9'&&line[j] != '0'&&line[j] != 'S'&&line[j] != 's'&&line[j] != 'R'&&line[j] != 'r'&&line[j] != 'W'&&line[j] != 'w'&&line[j] != 'B'&&line[j] != 'b'&&line[j] != 'F'&&line[j] != 'f')
					{
						cout << "数据有误" << endl;
						error = true;
						break;
					}
				if (error)
					break;
			}
			fin.close();
			if (error)
			{
				getchar();
				continue;
			}

			ifstream ibs;
			ofstream obs;
			strcpy(score, path);
			strcpy(temp, score + 24);
			strcpy(score + 24, "-score");
			strcat(score, temp);

			ofstream oans;
			strcpy(ans, path);
			strcpy(ans + 24, "-ans");
			strcat(ans, temp);

			fin.open(path, ios::in);
			if (!fin.is_open())
			{
				cout << "打开文件失败" << endl;
				getchar();
				continue;
			}
			while (!fin.eof())
			{
				fin >> line;
				i++;
				if (i >= 16)
					break;
				for (unsigned int j = 0; j < strlen(line.c_str()) && j<16; j++)
				{
					switch (line[j])
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
						map[i][j].exist = 1;
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
			fin.close();
			graph cur[16][16];
			for (int i = 0; i < 16; i++)
				for (int j = 0; j < 16; j++)
					cur[i][j] = map[i][j];
			char ctrl;
			if (choice == '1')
			{
				getchar();
				continue;
			}

			else if (choice == '2')
			{
				step* firststep, *curstep;
				
				while (1)
				{
					ctrl = _getch();
					

					if (ctrl == 'R' || ctrl == 'r')
					{
						stepn = 0;
						
						for (int i = 0; i < 16; i++)
							for (int j = 0; j < 16; j++)
								cur[i][j] = map[i][j];
						printall(hout, map);
						curstep = firststep->next;
						delete firststep;
						while (curstep != NULL)
						{
							step * t;
							t = curstep->next;
							delete curstep;
							curstep = t;
						}
					}
					else if (ctrl == 'q' || ctrl == 'Q')
					{
						
						if (stepn >= 1)
						{
							curstep = firststep->next;
							delete firststep;
							while (curstep != NULL)
							{
								step * t;
								t = curstep->next;
								delete curstep;
								curstep = t;
							}
						}
						break;
					}
					else if (ctrl == 8)
					{
						if (curstep->past != NULL)
						{
							stepn++;
							gotoxy(hout, 143, 4);
							cout << stepn;

							step *p = curstep->past;
							delete curstep;
							curstep = p;
							curstep->next = NULL;

							printall(hout, curstep->curmap);
							for (int a = 0; a < 16; a++)
								for (int b = 0; b < 16; b++)
									cur[a][b] = curstep->curmap[a][b];
						}
						else if (curstep->past == NULL)
						{
							printall(hout, map);
							for (int a = 0; a < 16; a++)
								for (int b = 0; b < 16; b++)
									cur[a][b] = map[a][b];
						}
						
					}
					else if (ctrl == 's' || ctrl == 'S')
					{
						
						oans.open(ans, ios::out);
						oans << firststep->stepinfo;
						step *outa = firststep->next;
						while (outa->next != NULL)
						{
							oans << outa->stepinfo;
							outa = outa->next;
						}
						oans.close();
					}
					else
					{
						
						if (!isascii(ctrl))
						{
							char _ctrl = _getch();
							if (stepn == 0)
							{
								firststep = new step[1];
								firststep->past = NULL;
								curstep = firststep;
							}
							else if (stepn >= 1)
							{
								curstep->next = new step[1];
								curstep->next->past = curstep;
								curstep = curstep->next;
							}
							curstep->next = NULL;

							
							stepn=play(hout, cur, _ctrl, choice, stepn,curstep);
							for (int a = 0; a < 16; a++)
								for (int b = 0; b < 16; b++)
									curstep->curmap[a][b] = cur[a][b];
							gotoxy(hout, 143, 4);
							cout << stepn;
							if (win(cur))
							{
								gotoxy(hout, 133, 3);
								cout << "恭喜，成功！" << endl;
								gotoxy(hout, 133, 4);
								cout << "本局步数：" << stepn;
								gotoxy(hout, 133, 5);
								cout << "历史最佳：";
								ibs.open(score, ios::in);
								if (ibs.is_open()&&!ibs.eof())
								{
									ibs >> best;
								}
								cout << best;
								ibs.close();
								//cout << best;
								if ((stepn < best&&best>0) || best == -1)
								{
									gotoxy(hout, 133, 6);
									cout << "新纪录！";
									obs.open(score, ios::out);
									obs << stepn;
									obs.close();
								}
								break;
							}
						}
						else
							continue;
					}
				}
				if (ctrl == 'q' || ctrl == 'Q')
					continue;
				if (win(cur))
					getchar();
			}

			else if (choice == '3')
			{
				bool error = false;
				stepn = 0;
				fin.open(ans, ios::in);
				if (!fin.is_open())
				{
					gotoxy(hout, 133, 3);
					cout << "答案文件不存在" << endl;
					getchar();
					continue;
				}
				while (!fin.eof())
				{
					char ch;
					fin.get(ch);
					if (!(ch == 'D' || ch == 'R' || ch == 'L' || ch == 'U' || ch == 'u' || ch == 'r' || ch == 'l' || ch == 'd'||ch==10))
					{
						gotoxy(hout, 133,7 );
						cout << "数据有误" << endl;
						error = true;
						break;
					}
				}
				fin.close();
				if (error)
				{
					getchar();
					continue;
				}
				fin.open(ans, ios::in);
				if (!fin.is_open())
				{
					gotoxy(hout, 133, 3);
					cout << "答案文件不存在" << endl;
					getchar();
					continue;
				}
				gotoxy(hout, 0, filenum + 5);
				getchar();
				error = false;
				while (!fin.eof())
				{
					Sleep(100);
					char ch;
					fin.get(ch);
					if (ch == 'D' || ch == 'R' || ch == 'L' || ch == 'U' || ch == 'u' || ch == 'r' || ch == 'l' || ch == 'd')
					{
						if (play(hout, cur, ch, choice, stepn) != 1&&!win(cur))
						{
							error = true;
							break;
						}
					}
				}
				if (error)
				{
					gotoxy(hout, 133, 7);
					cout << "数据有误" << endl;
					getchar();
					fin.close();
					continue;
				}
				gotoxy(hout, 133, 3);
				cout <<"演示完成" << endl;
				fin.close();
				getchar();
			}

		}
	
	}
 
	gotoxy(hout, 0, filenum + 5);
	
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