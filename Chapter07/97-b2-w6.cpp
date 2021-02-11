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

/* ������ƶ���ָ��λ�� */
void gotoxy(HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* ����ָ������ɫ

��ɫ��ȡֵ�ɱ���ɫ+ǰ��ɫ��ɣ���16��
fg_color��0-7    ��   ��   ��   ��   ��   ��   ��   ��
8-15 ���� ���� ���� ���� ���� ���� ���� ����
bg_color��0-7    ��   ��   ��   ��   ��   ��   ��   ��
8-15 ���� ���� ���� ���� ���� ���� ���� ����
���յ���ɫΪ ����ɫ*16+ǰ��ɫ */
void setcolor(HANDLE hout, const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(hout, bg_color * 16 + fg_color);
}

/* ��ָ��λ�ã���ָ����ɫ����ʾһ���ַ� */
void showch(HANDLE hout, const int X, const int Y, const int bg_color, const int fg_color, const char ch, const int n)
{
	int i;
	gotoxy(hout, X, Y);
	setcolor(hout, bg_color, fg_color);

	/* ѭ��n�Σ���ӡ�ַ�ch */
	for (i = 0; i<n; i++)
		putchar(ch);
}

/*��ӡѡ���б�*/
void printlist(HANDLE hout, int curX,int curY,filename *cur,char (*f)[4])
{
	int num = 0;
	cout << " ��ѡ��ؿ�";
	curY++;
	gotoxy(hout, curX, curY );
	cout << "�X�T�T�T�T�[";
	while (cur != NULL)
	{
		if (cur->levelno[0] != '*')
		{
			curY++;
			gotoxy(hout, curX, curY);
			strcpy(f[num], cur->levelno);
			cout << "�U�ؿ�" << f[num] << " �U";
			num++;
		}
		cur = cur->next;
	}
	curY++;
	gotoxy(hout, curX, curY);
	cout << "�^�T�T�T�T�a" << "   ��" << num << "�ؿ�ѡ";
	//return num;
}

/*ѡ��*/
int selectlevel(HANDLE hout, int curX, int curY,filename* cur,int filenum,char f[][4])
{
	int n = 0;
	curX++;
	curX++;
	curY++;
	curY++;
	gotoxy(hout, curX, curY);
	setcolor(hout, 14, 0);
	cout << "�ؿ�" << f[n];
	setcolor(hout, 15, 0);
	while (1)
	{
		char c = _getch();
		if (c == 13)
			break;
		else if (isascii(c) && c == 72 && n > 0)
		{
			gotoxy(hout, curX, curY);
			cout << "�ؿ�" << f[n];
			n--;
			curY--;
			setcolor(hout, 14, 0);
			gotoxy(hout, curX, curY);
			cout << "�ؿ�" << f[n];
			setcolor(hout, 15, 0);
		}
		else if (isascii(c) && c == 80&&n<filenum-1)
		{
			gotoxy(hout, curX , curY);
			cout << "�ؿ�" << f[n];
			n++;
			curY++;
			setcolor(hout, 14, 0);
			gotoxy(hout, curX, curY);
			cout << "�ؿ�"<<f[n];
			setcolor(hout, 15, 0);
		}
		else
			continue;
	}
	return n;
}

/*��ӡ����*/
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
		cout << "�X�T�[";
		gotoxy(hout, curX, curY+1);
		cout << "�UXX�U";
		gotoxy(hout, curX, curY + 2);
		cout << "�^�T�a";
	}
	else if (unit.floor == 1)
	{
		if (unit.box == 1&& unit.dest != 1)
		{
			setcolor(hout,2, 14);
			cout << "�X�T�[";
			gotoxy(hout, curX, curY + 1);
			cout << "�U��U";
			gotoxy(hout, curX, curY + 2);
			cout << "�^�T�a";
		}
		else if (unit.dest == 1&& unit.box != 1)
		{
			setcolor(hout,11,10);
			cout << "�X�T�[";
			gotoxy(hout, curX, curY + 1);
			cout << "�U��U";
			gotoxy(hout, curX, curY + 2);
			cout << "�^�T�a";
		}
		else if (unit.man == 1)
		{
			setcolor(hout,9,14);
			cout << "�X�T�[";
			gotoxy(hout, curX, curY + 1);
			cout << "�U��U";
			gotoxy(hout, curX, curY + 2);
			cout << "�^�T�a";
		}
		else if (unit.box == 1 && unit.dest == 1)
		{
			setcolor(hout, 14,12);
			cout << "�X�T�[";
			gotoxy(hout, curX, curY + 1);
			cout << "�U��U";
			gotoxy(hout, curX, curY + 2);
			cout << "�^�T�a";
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
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //���λ��
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	filename *first;
	graph map[16][16];
	first = new struct filename[1];
	char(*showlevel)[4];
	struct filename* nextone = first;

	/*��ȡ�ļ���*/
	int filenum = 0;
	const char *to_search = ".\\�ؿ�\\*.txt";
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
	system("mode con cols=80 lines=30"); // cols Ϊ�� ���� lines Ϊ�� ����
	
	cout << "-----------------------" << endl;
	cout << "1. ��ʾ�ؿ�" << endl;
	cout << "0. �˳�" << endl;
	cout << "-----------------------"<<endl;
	cout << "[��ѡ��0-1]";
	char choice = _getch();

	if (choice == '0')
	{
		delete first;
		return 0;
	}

	else if (choice == '1')
	{
		system("cls");
		system("mode con cols=150 lines=150"); // cols Ϊ�� ���� lines Ϊ�� ����
		
		/*��ӡѡ���б�*/
		int X, Y;
		gotoxy(hout, 120, 1);
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//��ȡ��ǰ����

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
		char path[40] = ".\\�ؿ�\\";
		strcat(path, nextone->fname);
		fin.open(path, ios::in);
		if (!fin.is_open())
		{
			cout << "���ļ�ʧ��" << endl;
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
					cout << "��������" << endl;
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
			cout << "���ļ�ʧ��" << endl;
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