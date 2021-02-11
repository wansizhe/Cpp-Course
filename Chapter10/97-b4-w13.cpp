#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include <Windows.h>
#include <conio.h>
using namespace std;

class hanzi
{
private:
	char hz[3];
	short high;
	short low;
	short zone;
	short bit;
	int dot[16][16] = { 0 };
public:
	hanzi()
	{
		hz[0]='\0';
		high = 0;
		low = 0;
		zone = 0;
		bit = 0;
	}
	hanzi(const char* c)
	{
		strcpy(hz, c);
		high = (int(hz[0]) & 0xff);
		low = (int(hz[1]) & 0xff);
		zone = high - 0xa0;
		bit = low - 0xa0;
	}
	hanzi& operator=(const char* c)
	{
		hz[0] = c[0];
		hz[1] = c[1];
		hz[3] = '\0';
		high = (int(hz[0]) & 0xff);
		low = (int(hz[1]) & 0xff);
		zone = high - 0xa0;
		bit = low - 0xa0;
		return *this;
	}
	int pos()
	{
		int n = 0;
		n = 94*32 *(zone - 1) + 32 * (bit - 1);
		return n;
	}
	void indot(short bin[16])
	{
		for (int i = 0; i < 16; i++)
		{
			for (int j = 7; j >= 0; j--)
			{
				if (((bin[i] >> j) & 1) == 0)
					dot[i][7 - j] = 0;
				else
					dot[i][7 - j] = 1;
			}
			for (int j = 15; j >= 8; j--)
			{
				if (((bin[i] >> j) & 1) == 0)
					dot[i][23 - j] = 0;
				else
					dot[i][23 - j] = 1;
			}
		}
	}
	void show(char f='N')
	{
		if (hz[0] != '\0')
		{
			cout << "汉  字：" << hz;
			if (f == 'Y' || f == 'y')
				cout << "（繁体）";
			else if (f == 'N' || f == 'n')
				cout << "（简体）";
			cout << endl << hex << setiosflags(ios::uppercase) << "GB2312：" << high << low << endl << dec << setw(2) << setfill('0') << "区位码：" << zone << setw(2) << setfill('0') << bit;
		}
	}
	friend void showonestd(HANDLE hout, hanzi hz, int x, int y);
	friend void showone1(HANDLE hout, hanzi hz, int x, int y);
	friend void showone2(HANDLE hout, hanzi hz, int x, int y);
	friend void showone3(HANDLE hout, hanzi hz, int x, int y);
	friend void showone4(HANDLE hout, hanzi hz, int x, int y);
	friend int show0(HANDLE hout,hanzi hz[], int row, int line,int);
	friend int show1(HANDLE hout, hanzi hz[], int row, int line,int word);
	friend int show6(HANDLE hout, hanzi hz[], const int hang, const int lie, int word);
};

class items
{
protected:
	string words;
	int num;
	int col;
public:
	items()
	{
		words = "\0";
		num = 0;
		col = 12;
	}
	void setwords(const char* c)
	{
		int n = strlen(c);
		num = 0;
		for (int i = 0; i < n;)
		{
			num++;
			if (c[i] < 0)
				i += 2;
			else if (c[i] > 0)
				i++;
		}
		words = c;
	}
	void setcol(int c)
	{
		if (c < 0)
			c = 12;
		else if (c>15)
			c = 12;
		col = c;
	}
	int getcol()
	{
		return col;
	}
	string getwords()
	{
		return words;
	}
	int getnum()
	{
		return num;
	}
};

typedef BOOL(WINAPI *PROCSETCONSOLEFONT)(HANDLE, DWORD);
/***************************************************************************
函数名称：
功    能：改变输出窗口的字体
输入参数：
返 回 值：
说    明：
***************************************************************************/
void setconsolefont(const HANDLE hout, const int font_no)
{
	HMODULE hKernel32 = GetModuleHandleA("kernel32");
	PROCSETCONSOLEFONT setConsoleFont = (PROCSETCONSOLEFONT)GetProcAddress(hKernel32, "SetConsoleFont");
	/* font_no width high
	0       3     5
	1       4     6
	2       5     8
	3       6     8
	4       8     8
	5       16    8
	6       5     12
	7       6     12
	8       7     12
	9       8     12
	10      16    12
	11      8     16
	12      12    16
	13      8     18
	14      10    18
	15      10    20 */
	setConsoleFont(hout, font_no);
	return;
}
/***************************************************************************
函数名称：
功    能：改变输出窗口的大小
输入参数：
返 回 值：
说    明：
***************************************************************************/
void setconsoleborder(const HANDLE hout, const int cols, const int lines)
{
	char cmd[80];

	system("cls");
	sprintf(cmd, "mode con cols=%d lines=%d", cols, lines);
	system(cmd);

	return;
}


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

void set(hanzi *hzstr,const char* chzs ,int hang,int lie,int word)
{
	int j = 0;
	for (int i = 0; i < word; i++)
	{
		if (chzs[j] < 0)
		{
			hzstr[i] = chzs + j;
			j += 2;
		}
		else if (chzs[j] >= 0x21 && chzs[j] <= 0x7e)
		{
			char temp[2];
			temp[0] = -93;
			temp[1] = chzs[j] - 128;
			hzstr[i] = temp;
			j++;
		}
	}
}

void showonestd(HANDLE hout, hanzi hz, int x, int y)
{
	int n = 0;
	
	int i, j;
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16;j++)
	    {
			gotoxy(hout, x + 2 * j, y + i);
			if (hz.dot[i][j] == 1)
			{
				cout << " *";
				hz.dot[i][j]++;
				//Sleep(1);
			}
			else
			{
				cout << "  ";
				hz.dot[i][j]--;
			}
		}
}

/*散点*/
void showone1(HANDLE hout, hanzi hz, int x, int y)
{
	hanzi thz = hz;
	for (int a = 0; a < 16; a++)
		for (int b = 0; b < 16; b++)
			thz.dot[a][b] = hz.dot[a][b];
	int n = 0;
	for (; n < 16*16; n++)
	{
		int i, j;
		for (;;)
		{
			i = rand() % 16;
			j = rand() % 16;
			if (thz.dot[i][j] == 0 || thz.dot[i][j] == 1)
				break;
		}
		gotoxy(hout, x + 2 * j, y + i);
		if (thz.dot[i][j] == 1)
		{
			cout << " *";
			thz.dot[i][j]++;
			Sleep(1);
		}
		else
		{
			cout << "  ";
			thz.dot[i][j]--;
		}
		//Sleep(1);
	}
}
/*左右*/
void showone2(HANDLE hout, hanzi hz, int x, int y)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			gotoxy(hout, x + 2 * i, y + j);
			if (hz.dot[j][i] == 0)
				cout << "  ";
			else
				cout << " *";
		}
		Sleep(5);
	}
}
/*上下*/
void showone3(HANDLE hout, hanzi hz, int x, int y)
{
	int n = 0;
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			gotoxy(hout, x + 2 * j, y + i);
			if (hz.dot[i][j] == 1)
			{
				cout << " *";
				hz.dot[i][j]++;
				//Sleep(1);
			}
			else
			{
				cout << "  ";
				hz.dot[i][j]--;
			}
		}
		Sleep(1);
	}
}
/*扩散*/
void showone4(HANDLE hout, hanzi hz, int x, int y)
{
	int n = 0;
	for (int a = 7; a >= 0; a--)
	{
		gotoxy(hout, x + 2 * a, y + a);
		for (int i = 0; i <= 15-2*a; i++)
		{
			if (hz.dot[a][a+i] == 1)
				cout << " *";
			else
				cout << "  ";
		}
		for (int i = 1; i < 15-2*a; i++)
		{
			gotoxy(hout, x + 2 * a , y + a+i);
			if (hz.dot[a+i][a] == 1)
				cout << " *";
			else
				cout << "  ";
			gotoxy(hout, x + 2 *(15 -  a) , y + a+i);
			if (hz.dot[a + i][(15 -  a)] == 1)
				cout << " *";
			else
				cout << "  ";
		}
		gotoxy(hout, x + 2 * a, y + 15-a);
		for (int i = 0; i <=15-2*a; i++)
		{
			if (hz.dot[(15 - a)][a+i] == 1)
				cout << " *";
			else
				cout << "  ";
		}
		Sleep(10);
	}
	//getchar();
}


/*基本*/
int show0(HANDLE hout,hanzi hz[], int hang, int lie,int word)
{
	int x = 0, y = 0, n = 0, max = hang*lie;
	gotoxy(hout, x, y);
	for (int a = 0; a < hang; a++)
	{
		for (int b = 0; b < lie; b++)
		{
			showonestd(hout, hz[n], 32 * b, 18 * a);
			n++;
			if (n == (word<max ? word : max))
				break;
		}
		if (n == (word<max ? word : max))
			break;
	}
	return 0;
}

/*全屏左右横幅*/
int show1(HANDLE hout, hanzi hz[], const int hang, const int lie,int word)
{
	int n = 0;
	int *x=new int[hang];
	int r;
	if (word%lie == 0)
		r = word / lie;
	else
		r = word / lie + 1;
	for (int l = 0; l < (word>lie?lie:word); l++)
	{
		for (int b = 0; b < 16; b++)
		{
			for (int h = 0; h < r; h++)
			{
				for (int a = 0; a < 16; a++)
				{
					int x = l * 32 + 2 * b, y = 18 * h + a;
					gotoxy(hout, x, y);
					if (hz[h*lie + l].dot[a][b] == 1)
						cout << " *";
					else
						cout << "  ";
				}
			}
			Sleep(10);
		}
	}
	
	delete x;
	return 1;
}

/*顺序单字散点*/
int show2(HANDLE hout, hanzi hz[], int hang, int lie,int word)
{
	int x = 0, y = 0, n = 0, max = hang*lie;
	gotoxy(hout, x, y);
	for (int a = 0; a < hang; a++)
	{
		for (int b = 0; b < lie; b++)
		{
			showone1(hout, hz[a*lie+b], 32 * b, 18 * a);
			n++;
			if (n == (word<max?word:max))
				break;
		}
		if (n == (word<max ? word : max))
			break;
	}
	return 2;
}

/*单行左右横幅*/
int show3(HANDLE hout, hanzi hz[], int hang, int lie, int word)
{
	int x = 0, y = 0, n = 0, max = hang*lie;
	gotoxy(hout, x, y);
	for (int a = 0; a < hang; a++)
	{
		for (int b = 0; b < lie; b++)
		{
			showone2(hout, hz[n], 32 * b, 18 * a);
			n++;
			if (n == (word<max ? word : max))
				break;
		}
		if (n == (word<max ? word : max))
			break;
	}
	return 3;
}

/*随机单字扩散*/
int show4(HANDLE hout, hanzi hz[], int hang, int lie, int word)
{
	int num = 0, h, l, max = hang*lie;
	int *n = new int[(word<max ? word : max)];
	for (int i = 0; i < (word<max ? word : max); i++)
		n[i] = 0;
	while (num < (word<max ? word : max))
	{
		h = rand() % hang;
		l = rand() % lie;
		if (h*lie + l >= (word < max ? word : max))
			continue;
		if (n[h*lie + l] == 0)
		{
			showone4(hout, hz[h*lie + l], 32 * l, 18 * h);
			num++;
			n[h*lie + l]++;
			Sleep(1);
		}
	}

	delete n;
	return 4;
}

/*单列上下横幅*/
int show5(HANDLE hout, hanzi hz[], int hang, int lie, int word)
{
	int x = 0, y = 0, n = 0, max = hang*lie;
	int r;
	if ((word < max ? word : max) % lie == 0)
		r = (word < max ? word : max) / lie;
	else
		r = (word < max ? word : max) / lie + 1;
	gotoxy(hout, x, y);
	for (int b = 0; b < lie; b++)
	{
		for (int a = 0; a < r; a++)
		{
			showone3(hout, hz[a*lie + b], 32 * b, 18 * a);
			//n++;
			//if (n == (word<max ? word : max))
				//break;
		}
		//if (n == (word<max ? word : max))
			//break;
	}
	return 5;
}

/*全屏上下横幅*/
int show6(HANDLE hout, hanzi hz[], const int hang, const int lie, int word)
{
	int n = 0;
	int *x = new int[hang];
	int r;
	if (word%lie == 0)
		r = word / lie;
	else
		r = word / lie + 1;
	for (int h = 0; h < r; h++)
	{
		for (int a = 0; a < 16; a++)
		{
			for(int l = 0; l < (word>lie ? lie : word); l++)
			{
				for (int b = 0; b < 16; b++)
				{
					int x = l * 32 + 2 * b, y = 18 * h + a;
					gotoxy(hout, x, y);
					if (hz[h*lie + l].dot[a][b] == 1)
						cout << " *";
					else
						cout << "  ";
				}
			}
			Sleep(10);
		}
	}

	delete x;
	return 6;
}

/*顺序单字扩散*/
int show7(HANDLE hout, hanzi hz[], int hang, int lie, int word)
{
	int x = 0, y = 0, n = 0, max = hang*lie;
	gotoxy(hout, x, y);
	for (int a = 0; a < hang; a++)
	{
		for (int b = 0; b < lie; b++)
		{
			showone4(hout, hz[a*lie + b], 32 * b, 18 * a);
			n++;
			if (n == (word<max ? word : max))
				break;
		}
		if (n == (word<max ? word : max))
			break;
	}
	return 2;
}

/*随机单字散点*/
int show8(HANDLE hout, hanzi hz[], int hang, int lie, int word)
{
	int num = 0, h, l, max = hang*lie;
	int *n = new int[(word<max ? word : max)];
	for (int i = 0; i < (word<max ? word : max); i++)
		n[i] = 0;
	while (num < (word<max ? word : max))
	{
		h = rand() % hang;
		l = rand() % lie;
		if (h*lie + l >= (word < max ? word : max))
			continue;
		if (n[h*lie + l] == 0)
		{
			showone1(hout, hz[h*lie + l], 32 * l, 18 * h);
			num++;
			n[h*lie + l]++;
			Sleep(1);
		}
	}

	delete n;
	return 4;
}

int main()
{
	const int total = 9;
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(unsigned int(time(0)));
	COORD coordScreen = { 0, 0 }; //光标位置
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	while (1)
	{
		system("cls");
		cout << "1、单字显示" << endl;
		cout << "2、模拟LED显示" << endl;
		cout << "0、退出" << endl;
		cout << "-----------------------" << endl;
		cout << "[请选择0-2]";
		char choice = _getch();

		if (choice == '1')
		{
			hanzi hz0;
			char temp[3] = "\0";
			system("cls");
			cout << "请输入汉字（Q退出）：";
			cin >> temp;
			if (temp[0] == 'q' || temp[0] == 'Q')
				continue;
			else
				hz0 = temp;
			cout << "是否需要繁体（Y/N）：";
			char fanti;
			cin >> fanti;

			ifstream fin;
			if (fanti == 'y' || fanti == 'Y')
			{
				fin.open("HZK16F", ios::in);
			}
			else if (fanti == 'n' || fanti == 'N')
			{
				fin.open("HZK16", ios::binary);
			}
			hz0.show(fanti);
			cout << endl;
			fin.seekg(hz0.pos(), ios::beg);
			short bin[16] = { 0 };
			fin.read((char*)&bin, 32);
			for (int i = 0; i < 16; i++)
				cout << hex <<setw(4)<<setfill('0')<< bin[i] << "  ";
			cout << endl << endl;
			GetConsoleScreenBufferInfo(hConsole, &csbi);
			int X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//获取当前坐标
			hz0.indot(bin);
			showone2(hout,hz0,X,Y);
			fin.close();
			getchar();
			getchar();
			//finF.close();
		}
		else if (choice == '2')
		{
			system("cls");
			ifstream fin;
			fin.open("led.conf", ios::in);
			string tline;
			int hangshu, lieshu, bcol, fcol, ping, tiao, texiao[total] = { 0 }, item = 0;
			while (!fin.eof())
			{
				fin >> tline;
				if (strstr(tline.c_str(), "行数") != NULL)
					hangshu = atoi(tline.c_str() + 5);
				if (strstr(tline.c_str(), "列数") != NULL)
					lieshu = atoi(tline.c_str() + 5);
				if (strstr(tline.c_str(), "背景色") != NULL)
					bcol = atoi(tline.c_str() + 7);
				if (strstr(tline.c_str(), "前景色") != NULL)
					fcol = atoi(tline.c_str() + 7);
				if (strstr(tline.c_str(), "特效") != NULL && (tline[6] == 'Y' || tline[6] == 'y') && atoi(tline.c_str() + 4)-1 < 4)
					texiao[atoi(tline.c_str() + 4)-1] = 1;
				if (strstr(tline.c_str(), "屏延时") != NULL)
					ping = atoi(tline.c_str() + 7);
				if (strstr(tline.c_str(), "条延时") != NULL)
					tiao = atoi(tline.c_str() + 7);
				if (strstr(tline.c_str(), "[content]") != NULL)
					break;
			}
			while (!fin.eof())
			{
				fin >> tline;
				if (strstr(tline.c_str(), "item") != NULL&&strstr(tline.c_str(), "color") == NULL)
					item++;
			}
			items* allwords = NULL;
			if (item > 0)
			{
				allwords = new items[item];
				fin.seekg(0, ios::beg);
				while (!fin.eof())
				{
					fin >> tline;
					if (strstr(tline.c_str(), "[content]") != NULL)
						break;
				}
				int t = 0;
				while (!fin.eof())
				{
					fin >> tline;
					if (strstr(tline.c_str(), "item") != NULL&&strstr(tline.c_str(), "color") == NULL)
					{
						if (atoi(tline.c_str() + 4) - 1 < item)
							allwords[atoi(tline.c_str() + 4) - 1].setwords(tline.c_str() + 6);
					}
					if (strstr(tline.c_str(), "item") != NULL&&strstr(tline.c_str(), "color") != NULL)
					{
						if (atoi(tline.c_str() + 4) - 1 < item)
							allwords[atoi(tline.c_str() + 4) - 1].setcol(atoi(tline.c_str() + 12));
					}
				}
			}
			else
			{
				allwords = new items[1];
				allwords->setwords("Welcome");
				item = 1;
			}
			fin.close();
			
			system("cls");
			if (hangshu < 1)
				hangshu = 1;
			else if (hangshu>5)
				hangshu = 5;
			if (lieshu < 8)
				lieshu = 8;
			else if (lieshu>10)
				lieshu = 10;
			if (bcol < 0)
				bcol = 0;
			else if (bcol>15)
				bcol = 15;
			if (fcol < 0)
				fcol = 0;
			else if (fcol>15)
				fcol = 15;
			setcolor(hout, bcol, fcol);
			/* 设置字体为 3*5 大小*/
			setconsolefont(hout, 0);
			/* 设置窗口大小 */
			setconsoleborder(hout, 32*lieshu, 18*hangshu+5);
			system("cls");
			//getchar();
			int itemcount = 0;
			fin.open("HZK16", ios::binary);
			while (itemcount < item)
			{
				int pagenum;
				pagenum = allwords[itemcount].getnum() / (hangshu*lieshu) + 1;
				int page = 0;
				setcolor(hout, bcol, allwords[itemcount].getcol());
				/*打印一页*/
				const int num = hangshu*lieshu;
				hanzi* hzs = new hanzi[pagenum*hangshu*lieshu];
				set(hzs, allwords[itemcount].getwords().c_str(), hangshu,lieshu, allwords[itemcount].getnum());
				for (int i = 0; i < allwords[itemcount].getnum(); i++)
				{
					fin.seekg(hzs[i].pos(), ios::beg);
					short bin[16] = { 0 };
					fin.read((char*)&bin, 32);
					//cout << endl;
					hzs[i].indot(bin);
				}

				for (page = 0; page < pagenum; page++)
				{
					int p = rand() % total;
					while (texiao[p] != 1)
					{
						p = rand() % (total-1);
					}
					system("cls");
					switch (p)
					{
					case 0:
						show1(hout, hzs+page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu? allwords[itemcount].getnum()-page*hangshu*lieshu : hangshu*lieshu));
						break;
					case 1:
						show2(hout, hzs + page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu ? allwords[itemcount].getnum() - page*hangshu*lieshu : hangshu*lieshu));
						break;
					case 2:
						show3(hout, hzs + page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu ? allwords[itemcount].getnum() - page*hangshu*lieshu : hangshu*lieshu));
						break;
					case 3:
						show4(hout, hzs + page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu ? allwords[itemcount].getnum() - page*hangshu*lieshu : hangshu*lieshu));
						break;
					case 4:
						show5(hout, hzs + page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu ? allwords[itemcount].getnum() - page*hangshu*lieshu : hangshu*lieshu));
						break;
					case 5:
						show6(hout, hzs + page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu ? allwords[itemcount].getnum() - page*hangshu*lieshu : hangshu*lieshu));
						break;
					case 6:
						show7(hout, hzs + page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu ? allwords[itemcount].getnum() - page*hangshu*lieshu : hangshu*lieshu));
						break;
					case 7:
						show8(hout, hzs + page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu ? allwords[itemcount].getnum() - page*hangshu*lieshu : hangshu*lieshu));
						break;
					default:
						show0(hout, hzs + page*hangshu*lieshu, hangshu, lieshu, (allwords[itemcount].getnum() - page*hangshu*lieshu<hangshu*lieshu ? allwords[itemcount].getnum() - page*hangshu*lieshu : hangshu*lieshu));
						break;
					}
					Sleep(ping*1000);
				}
				Sleep(tiao*1000);
				itemcount++;
				delete hzs;
			}
			getchar();
			fin.close();
			delete[] allwords;
			gotoxy(hout, 32 * lieshu, 18 * hangshu + 4);
			break;
		}
		else if (choice == '3')
		{
			const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

			/* 设置字体为 3*5 大小*/
			setconsolefont(hout, 0);
			/* 设置窗口大小 */
			setconsoleborder(hout, 200, 100);

			/* 随便输出一些内容（不可能看清） */
			cout << "abcdefghijklmnopqrstuvwxyz" << endl;
			cout << "今天天气真好" << endl;
			cout << "**************************" << endl;

			/* 等待按键 */
			_getch();

			/* 设置字体为 8*16 大小*/
			setconsolefont(hout, 11);
			/* 设置窗口大小 */
			setconsoleborder(hout, 80, 25);

			/* 随便输出一些内容 */
			cout << "abcdefghijklmnopqrstuvwxyz" << endl;
			cout << "今天天气真好" << endl;
			cout << "**************************" << endl;

			/* 等待按键 */
			_getch();

			return 0;
		}
		else if (choice == '0')
		{
			cout << endl << "已退出" << endl;
			break;
		}
	}
	return 0;
}