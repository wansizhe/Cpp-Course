#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <windows.h>
#include<io.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct line
{
	line* past;
	char words[101] = "\0";
	line* next;
};
class filename
{
public:
	char *fname;
	char abbr[10] = "***";
	filename* next;
	filename(const char *name)
	{
		fname = new char[strlen(name) + 1];
		strcpy(fname, name);
		for (unsigned int i = 0; i < strlen(name)-4 && i < 9;)
		{
			if (((name[i] >> 7) & 1) == 1&& ((name[i+1] >> 7) & 1) == 1&&i<8)
			{
				abbr[i] = name[i];
				abbr[i + 1] = name[i + 1];
				i = i + 2;
			}
			else if (((name[i] >> 7) & 1) == 0)
			{
				abbr[i] = name[i];
				i++;
			}
			else if (((name[i] >> 7) & 1) == 1 && ((name[i + 1] >> 7) & 1) == 1 && i >= 8)
			{
				abbr[i] = '\0';
				i++;
			}
		}
	}
	~filename()
	{
		delete fname;
	}
};
struct line2
{
	char ch[100];
	line2* next;
};

/* 将光标移动到指定位置 */
void gotoxy(HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* 在指定位置，用指定颜色，显示一个字符 */
void showch(HANDLE hout, const int X, const int Y, const int bg_color, const int fg_color, const char ch, const int n)
{
	int i;
	gotoxy(hout, X, Y);

	/* 循环n次，打印字符ch */
	for (i = 0; i<n; i++)
		putchar(ch);
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

/*打印文本文件名列表*/
void printlist(HANDLE hout, int curX, int curY, filename *cur)
{
	int num = 0;
	cout << " 请选择文本";
	curY++;
	gotoxy(hout, curX, curY);
	cout << "╔═════╗";
	while (cur != NULL)
	{
		curY++;
		gotoxy(hout, curX, curY);
		cout << "║";
		cout <<setw(10)<<setiosflags(ios::left)<< cur->abbr;
		cout << "║";
		num++;
		cur = cur->next;
	}
	curY++;
	gotoxy(hout, curX, curY);
	cout << "╚═════╝" << "   共" << num << "个文本可选";
}

/*选文本*/
int selecttxt(HANDLE hout, int curX, int curY, filename* cur, int filenum)
{
	char(*fa)[10] = new char[filenum][10];
	filename *p = cur;
	int n = 0;
	while (p != NULL)
	{
		strcpy(fa[n], p->abbr);
		p = p->next;
		n++;
	}
	n = 0;
	curX++;
	curX++;
	curY++;
	curY++;
	gotoxy(hout, curX, curY);
	setcolor(hout, 14, 0);
	cout << setw(10) << setiosflags(ios::left) << fa[n];
	setcolor(hout, 15, 0);
	while (1)
	{
		char c = _getch();
		if (c == 13)
			break;
		else if (c == -32)
		{
			char c0 = _getch();
			if (c0 == 72 && n > 0)
			{
				gotoxy(hout, curX, curY);
				cout << setw(10) << setiosflags(ios::left) << fa[n];
				n--;
				curY--;
				setcolor(hout, 14, 0);
				gotoxy(hout, curX, curY);
				cout << setw(10) << setiosflags(ios::left) << fa[n];
				setcolor(hout, 15, 0);
			}
			else if (c0 == 80 && n<filenum - 1)
			{
				gotoxy(hout, curX, curY);
				cout << setw(10) << setiosflags(ios::left) << fa[n];
				n++;
				curY++;
				setcolor(hout, 14, 0);
				gotoxy(hout, curX, curY);
				cout << setw(10) << setiosflags(ios::left) << fa[n];
				setcolor(hout, 15, 0);
			}
			else
				continue;
		}
		else if (c == 'q' || c == 'Q')
		{
			delete[]fa;
			return -1;
		}
		else
			continue;
	}
	delete[] fa;
	return n;
}

/*打印文本*/
void printclear(HANDLE hout)
{
	int lnum = 1;
	gotoxy(hout, 8, 4);
	showch(hout, 8, 4, 15, 0, ' ', 100);
	while (1)
	{
		gotoxy(hout, 8, 4 + lnum);
		showch(hout, 8, 4 + lnum, 15, 0, ' ', 100);
		lnum++;
		if (lnum == 32)
			break;
	}
}

void printwords(HANDLE hout, line* beg)
{
	printclear(hout);
	line* curline = beg;
	int lnum = 0;
	while (curline != NULL&&lnum<32)
	{
		gotoxy(hout, 8, 4 + lnum);
		cout << curline->words;
		curline = curline->next;
		lnum++;
	}
}

/*计算长度*/
int longtxt(line*head)
{
	int num = 0;
	while (head != NULL)
	{
		num += strlen(head->words);
		head = head->next;
	}
	return num;
}

int curlong(line* head, const line*cur)
{
	int num = 0;
	while (head != NULL)
	{
		num += strlen(head->words);
		if (head == cur)
			break;
		head = head->next;
	}
	return num;
}

/*跳转进度*/
line* gotobs(line *head,int b)
{
	int num = 0;
	while (head != NULL)
	{
		num += strlen(head->words);
		if (num >= b)
			break;
		head = head->next;
	}
	return head;
}

/*寻找、更新阅读历史*/
int find_to_read(FILE* fp,const char *f)
{
	char cur[100] = "\0";
	int pos = 0;
	int get = 0;
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (strstr(cur, f) != NULL)
			get++;
	}
	if (get == 0)
		return 0;
	
	rewind(fp);
	while (!feof(fp))
	{
		char cur[100];
		fgets(cur, 99, fp);
		if (strstr(cur, f) != NULL)
			break;
	}
	char t[100];
	get = 0;
	long fpast = ftell(fp);
	while (!feof(fp))
	{
		fgets(t, 99, fp);
		if (ftell(fp) == fpast)
			return 0;
		if (t[0] == '[')
			return 0;
		if (t[0] == '\n')
			continue;
		else
			break;
	}
	return atoi(t);
}

int update_history(FILE* fp, const char *f, int pos)
{
	char cur[100];
	char *to_up = new char[strlen(f) + 3];
	strcpy(to_up, "[");
	strcat(to_up, f);
	strcat(to_up, "]");
	int get = 0;
	rewind(fp);
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (strstr(cur, to_up) != NULL)
			get++;
	}
	if (get == 0)
	{
		fseek(fp, 0, SEEK_END);
		fprintf(fp, "%s", to_up);
		fprintf(fp, "%c", '\n');
		fprintf(fp, "%d", pos);
		delete to_up;
		return 1;
	}
	rewind(fp);
	line2 *fhead = new line2[1];
	line2 *curline = fhead;
	while (!feof(fp))
	{
		char curl[100];
		fgets(curl, 99, fp);
		//cout << ftell(fp) << "  " << cur;
		strcpy(curline->ch, curl);
		//cout << ftell(fp) << "  " << curline->ch;
		curline->next = new line2[1];
		curline = curline->next;
		curline->ch[0] = '\0';
		curline->next = NULL;
		curl[0] = 0;
	}
	get = 0;
	rewind(fp);
	curline = fhead;
	while (curline != NULL)
	{
		if (get != 0)
			break;
		if (strstr(curline->ch, to_up) != NULL)
			get++;
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	fprintf(fp, "%d", pos);
	fputc('\n', fp);
	while (curline != NULL)
	{
		if (curline->ch[0] == '[')
			break;
		else
			curline = curline->next;
	}

	while (curline != NULL)
	{
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	
	curline = fhead;
	while (curline != NULL)
	{
		line2 *t = curline->next;
		delete curline;
		curline = t;
	}
	delete to_up;
	return 1;
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //光标位置
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int X, Y;
	system("mode con cols=155 lines=45"); // cols 为列 即宽 lines 为行 即高

	/*构建文件名链表*/
	int filenum = 0;
	filename *first;
	filename* cur;
	const char *to_search = ".\\book\\*.txt";
	long handle;
	struct _finddata_t fileinfo;
	handle = _findfirst(to_search, &fileinfo);
	if (handle == -1)
	{
		cout << "无数据文件" << endl;
		return -1;
	}
	first = new filename(fileinfo.name);
	filenum++;
	first->next = NULL;
	cur = first;
	while (!_findnext(handle, &fileinfo))
	{
		cur->next = new filename(fileinfo.name);
		filenum++;
		cur = cur->next;
		cur->next =NULL;
	}
	_findclose(handle);
	gotoxy(hout, 120, 3);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标
	cur = first;

	while (1)
	{
		system("cls");
		gotoxy(hout, 120, 3);
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标
		cur = first;
		printlist(hout, X, Y, cur);
		int to_open = selecttxt(hout, X, Y, cur, filenum);
		if (to_open == -1)
			break;
		char *to_read = NULL;
		cur = first;
		for (int i = 0; cur != NULL; i++)
		{
			if (i == to_open)
			{
				to_read = cur->fname;
				break;
			}
			cur = cur->next;
		}
		gotoxy(hout, 0, 0);

		/*打开文本并传入链表*/
		char ch;
		FILE* fin;
		char path[100] = ".\\book\\";
		strcat(path, to_read);
		fin = fopen(path, "r");
		if (fin == NULL)
		{
			cout << "打开失败" << endl;
			getchar();
			continue;
		}
		line *head, *curline;
		int start = 0;
		
		head = new line;
		head->past = NULL;
		head->next = NULL;
		int endline = 1;
		int cn = 0;
		for (int i = 0; i < 100;)
			{
				if (endline == 1)
				{
					head->words[0] = ' ';
					head->words[1] = ' ';
					head->words[2] = ' ';
					head->words[3] = ' ';
					i = 4;
					endline = 0;
					continue;
				}
				ch = fgetc(fin);
				if ((ch == ' ' || ch == '\t')&&start==0)
					continue;
				else if (ch == '\n'&&start==0)
					continue;
				else if (ch == '\n'&&start==1)
				{
					head->words[i] = '\0';
					endline = 1;
					break;
				}
				else if (((ch >> 7) & 1) == 1 && i < 99)
				{
					start = 1;
					cn++;
					head->words[i] = ch;
					i++;
				}
				else if (i == 99)
				{
					if (((ch >> 7) & 1) == 1 && cn % 2 == 1)
					{
						start = 1;
						head->words[i] = ch;
						head->words[100] = '\0';
					}
					else if (((ch >> 7) & 1) != 1)
					{
						start = 1;
						head->words[i] = ch;
						head->words[100] = '\0';
					}
					else if (((ch >> 7) & 1) == 1 && cn % 2 == 0)
					{
						start = 1;
						fseek(fin, -1, SEEK_CUR);
						head->words[i] = '\0';
						head->words[100] = '\0';
					}
					i++;
				}
				else
				{
					head->words[i] = ch;
					i++;
				}
			}

		curline = head;
		while (1)
		{
			start = 0;
			curline->next = new line;
			curline->next->past = curline;
			curline = curline->next;
			curline->next = NULL;
			cn = 0;
			for (int i = 0; i < 100;)
			{
				if (feof(fin))
				{
					curline->words[i] = '\0';
					break;
				}
				if (endline == 1)
				{
					curline->words[0] = ' ';
					curline->words[1] = ' ';
					curline->words[2] = ' ';
					curline->words[3] = ' ';
					i = 4;
					endline = 0;
					continue;
				}
				ch = fgetc(fin);
				if ((ch == ' ' || ch == '\t') && start == 0)
					continue;
				else if (ch == '\n'&&start == 0)
					continue;
				else if (ch == '\n'&&start == 1)
				{
					curline->words[i] = '\0';
					endline = 1;
					start = 0;
					break;
				}
				else if (((ch >> 7) & 1) == 1 && i < 99)
				{
					start = 1;
					cn++;
					curline->words[i] = ch;
					i++;
				}
				else if (i == 99)
				{
					if (((ch >> 7) & 1) == 1 && cn % 2 == 1)
					{
						start = 1;
						curline->words[i] = ch;
						curline->words[100] = '\0';
					}
					else if (((ch >> 7) & 1) != 1)
					{
						start = 1;
						curline->words[i] = ch;
						curline->words[100] = '\0';
					}
					else if (((ch >> 7) & 1) == 1 && cn % 2 == 0)
					{
						start = 1;
						fseek(fin, -1, SEEK_CUR);
						curline->words[i] = '\0';
						curline->words[100] = '\0';
					}
					i++;
				}
				else
				{
					curline->words[i] = ch;
					i++;
				}
			}
			if (feof(fin))
				break;
		}

		/*打印文本框*/
		gotoxy(hout, 6, 3);
		cout << "╔";
		for (int i = 0; i < 50; i++)
			cout << "═";
		cout << "╗";
		for (int i = 0; i < 32; i++)
		{
			gotoxy(hout, 6, 4 + i);
			cout << "║";
			for (int j = 0; j < 50; j++)
				cout << "  ";
			cout << "║";
		}
		gotoxy(hout, 6, 36);
		cout << "╚";
		for (int i = 0; i < 50; i++)
			cout << "═";
		cout << "╝";
		gotoxy(hout, 7, 2);
		cout << "当前阅读：" << to_read << "          进度：";
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标
		gotoxy(hout, 7, 37);
		cout << "PgUp/PgDn翻页      上下箭头移动一行      S/s跳转进度      N/n结束本次阅读      Q/q退出      ";

		int lnum = 1;
		line* beg_l;
		beg_l = head;
		curline = head;
		int b = longtxt(head);
		int pos = 0;
		FILE *history;
		history = fopen(".\\book\\position.saving", "r");
		if (history == NULL)
			pos = 0;
		else
		{
			pos = find_to_read(history, to_read);
			fclose(history);
		}
		gotoxy(hout, 90, 2);
		if (pos > b || pos < 0)
			pos = 0;
		cout << "上次阅读到"<<pos<<"字节";
		if (pos != 0)
			beg_l = gotobs(head, pos);
		printwords(hout, beg_l);
		gotoxy(hout, X, Y);
		int a = curlong(head, beg_l);
		float p0 = float(a) /float( b);
		cout <<setiosflags(ios::fixed)<<setprecision(2)<<p0*100<< '%';

		/*开始阅读*/
		int q = 0;
		while (1)/////////////////////////////////////////////////////////
		{
			showch(hout, 7, 38, 15, 0, ' ', 100);
			gotoxy(hout, 7, 38);
			char ctrl = _getch();
			if (ctrl == 'Q' || ctrl == 'q')
			{
				q = 1;
				break;
			}
			else if (ctrl == 'N' || ctrl == 'n')
			{
				break;
			}
			else if (ctrl == -32)
			{
				char ctrl2 = _getch();
				if (ctrl2 == 72&&beg_l->past!=NULL)
				{
					beg_l = beg_l->past;
					printwords(hout, beg_l);
				}
				else if (ctrl2 == 80&&beg_l->next!=NULL)
				{
					beg_l = beg_l->next;
					printwords(hout, beg_l);
				}
				else if (ctrl2 == 73)
				{
					int k = 1;
					curline = beg_l;
					while (curline->past != NULL)
					{
						curline = curline->past;
						k++;
						if (k == 32)
							break;
					}
					beg_l = curline;
					printwords(hout, beg_l);
				}
				else if (ctrl2 == 81)
				{
					int k = 1;
					curline = beg_l;
					while (curline->next != NULL)
					{
						curline = curline->next;
						k++;
						if (k == 32)
							break;
					}
					beg_l = curline;
					printwords(hout, beg_l);
				}
				gotoxy(hout, X, Y);
				a = curlong(head, beg_l);
				cout << setiosflags(ios::fixed) << setprecision(2) <<100*( float(a)/float(b))<< '%';
			}
			else if (ctrl == 's' || ctrl == 'S')
			{
				cout << "请输入跳转进度： _______%";
				gotoxy(hout, 24, 38);
				float p;
				cin >> p;
				if (p > 100 || p < 0)
					continue;
				beg_l = gotobs(head, int(b*(p / 100)));
				curline = beg_l;
				printwords(hout, beg_l);
				gotoxy(hout, X, Y);
				a = curlong(head, beg_l);
				cout << setiosflags(ios::fixed) << setprecision(2) <<100*( float(a) / float(b) )<< '%';
			}
			else
				continue;
		}
		history = fopen(".\\book\\position.saving", "r+");
		if (history == NULL)
			pos = 0;
		pos = curlong(head, beg_l);
		update_history(history, to_read, pos);
		fclose(history);
		cout << "本次阅读到" << pos << "字节，已保存";
		getchar();
		getchar();

		curline = head;
		while (curline != NULL)
		{
			line* t = curline->next;
			delete curline;
			curline = t;
		}
		if (q == 1)
			break;
	}

	system("cls");
	cout << "已退出" << endl;
	cur = first;
	while (cur != NULL)
	{
		filename *t = cur->next;
		delete cur;
		cur = t;
	}

	return 0;
}
