#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <Shlwapi.h>
#pragma comment(lib,"shlwapi.lib")					//ע����õ�λ��
using namespace std;

struct number
{
	int num;
	int color;
	int cell;
	int get = 0;
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

/*�ж�����*/
int rownum(char row)
{
	switch (row)
	{
		case 'A':
		case 'a':
			return 1;
			break;
		case 'B':
		case 'b':
			return 2;
			break;
		case 'C':
		case 'c':
			return 3;
			break;
		case 'D':
		case 'd':
			return 4;
			break;
		case 'E':
		case 'e':
			return 5;
			break;
		case 'F':
		case 'f':
			return 6;
			break;
		case 'G':
		case 'g':
			return 7;
			break;
		case 'H':
		case 'h':
			return 8;
			break;
		case 'I':
		case 'i':
			return 9;
			break;
		default:
			return 10;
	}
}

/*�ж�����*/
int linenum(char line)
{
	switch (line)
	{
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
		default:
			return 10;
	}
}

/*�ж��������뷶Χ*/
bool r_l(int rl, int high = 9, int low = 1)
{
	bool error;
	if (rl > high || rl < low)
		error = true;
	else
		error = false;
	return error;
}

bool done(number shudu[10][10])
{
	int p = 0;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (shudu[i][j].num == 0)
				p++;
	if (p == 0)
		return true;
	else
		return false;
}

/*�жϱ�����д�Ƿ񷸹�*/
bool rightwrite(const int n, const int r,const int l,const int c, number shudu[10][10])
{
	for (int i = 1; i <= 9; i++)
		if (i != l&&n == shudu[r][i].num)
			return false;
	for (int i = 1; i <= 9; i++)
		if (i!=r&&n == shudu[i][l].num)
		    return false;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (c == shudu[i][j].cell&&!(i == r&&j == l))
				if( n == shudu[i][j].num)
					return false;
	return true;
}

/*��ӡһ��*/
void printone(HANDLE hout, number shudu, int l, int r,bool autos=0)
{
	if (autos)
	{
		if (shudu.num == 0)
			setcolor(hout, 15, 0);
		else
		    setcolor(hout, shudu.color, 0);
	}
	else
	{
		if (shudu.get == 0)
		{
			if (shudu.color == 0)
				setcolor(hout, 15, shudu.color);
			else
				setcolor(hout, shudu.color, 0);
		}
		else
			setcolor(hout, 14, 0);
	}


	gotoxy(hout, l, r);
	cout << "�q���r";
	gotoxy(hout, l, r + 1);
	cout << "��" << setw(2) << shudu.num << "��";
	gotoxy(hout, l, r + 2);
	cout << "�t���s";
}

/*��ӡ����*/
void printall(HANDLE hout, number shudu[10][10], int line, int row, bool autos = 0)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= line; j++)
		{
			printone(hout, shudu[i][j], 8 * (j - 1) + 2, 4 * (i - 1) + 1, autos);
		}
		cout << endl;
	}
}

void printb(HANDLE hout)
{
	setcolor(hout, 15, 0);
	gotoxy(hout, 0, 0);
	cout << "��";
	for (int i = 1; i <= 4 * 9 - 1; i++)
	{
		if (i % 12 == 0)
			cout << "��";
		else
			cout << "��";
	}
	cout << "��" << endl;
	for (int i = 1; i <= 4 * 9 - 1; i++)
	{
		if (i % 12 == 0)
		{
			cout << "��";
			for (int i = 1; i <= 4 * 9 - 1; i++)
			{
				if (i % 12 == 0)
					cout << "��";
				else
					cout << "��";
			}
			cout << "��";
			cout << endl;
		}
		else
		{
			cout << "��";
			for (int i = 1; i <= 4 * 9- 1; i++)
			{
				if (i % 12 == 0)
					cout << "��";
				else
					cout << "  ";
			}
			cout << "��";
			cout << endl;
		}
	}
	gotoxy(hout, 0, 4 *9);
	cout << "��";
	for (int i = 1; i <= 4 * 9 - 1; i++)
	{
		cout << "��";
	}
	cout << "��";
}

/*��ȡ�ļ���*/
void findFile(string dir, char list[][20], int n)
{
	WIN32_FIND_DATAA stFD;							//����ļ���Ϣ�Ľṹ��
	HANDLE h;
	string temp;

	temp = dir + "\\*";
	h = FindFirstFileA(temp.c_str(), &stFD);			//����Ŀ¼���

	while (FindNextFileA(h, &stFD))						//��ȡĿ¼�����ӦĿ¼���������ļ�
	{
		temp = dir + "\\" + stFD.cFileName;

		if (temp == dir + "\\..")										//��һ��·��
		{
			continue;
		}
		else if (PathIsDirectoryA(temp.c_str()))		//������Ŀ¼
		{
			findFile(temp, list, n + 1);												//�ݹ����
		}
		else
		{
			strcpy_s(list[n], stFD.cFileName);
			//��ӡ�ļ���
		}
		n++;
		if (n == 10)
			break;
	}

	return;
}

/*�Զ����*/
int showtime(HANDLE hout,number shudu[10][10])
{
	int i, j,zero=0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
			if (shudu[i][j].num == 0)
			{
				zero++;
				break;
			}
		if (zero != 0)
			break;
	}
	if (zero==0)
		return 1;
	else
	{
		for (int t = 1; t <= 9; t++)
		{
			if (rightwrite(t, i, j, shudu[i][j].cell, shudu))
			{
				shudu[i][j].num = t;
			    shudu[i][j].color = 3;
				printall(hout, shudu, j, i, 1);
				if (showtime(hout,shudu) == 1)
				{
					Sleep(50);
					return 1;
				}
			}
		}
		shudu[i][j].num = 0;
		shudu[i][j].color = 15;
		printall(hout, shudu, j, i, 1);
		Sleep(50);
		return -1;
	}
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //���λ��
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
								  //CONSOLE_SCREEN_BUFFER_INFO csbi;

	number sudoku[10][10];

	/*ѡ����Ŀ*/
	int choice;
	cout << "==============================" << endl;
	cout << "1������Ŀ1 �����ַ�����" << endl;
	cout << "2������Ŀ2 ����ͼ�ν���" << endl;
	cout << "3������Ŀ3 �����Զ����" << endl;
	cout << "==============================" << endl;
	cout << "��ѡ��";
	cin >> choice;
	system("cls");

	if (choice == 2)
	{
		/*��ȡ�ļ�*/
		char choose;
		ifstream infile;
		string dir;
		dir = "E:\\shudu";
		static char list[10][20];
		findFile(dir, list, 0);
		char txt[10][20];
		int i, fn;
		cout << "�X�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
		for (i = 0, fn = 0; i <=9; i++)
			if (strncmp("shudu", list[i], 5) == 0)
			{
				strcpy_s(txt[fn], list[i]);
				cout << "�U";
				cout << txt[fn] << endl;
				gotoxy(hout, 24, fn + 1);
				cout << "�U" << endl;
				fn++;
			}
		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
		int k=0;
		gotoxy(hout, 2, k + 1);
		setcolor(hout,9, 0);
		cout << txt[k];
		while (1)
		{
			choose = _getch();
			if (choose == 13)
			{
				infile.open(txt[k], ios::in);
				if (!infile.is_open())
				{
					gotoxy(hout, 0, fn + 3);
					setcolor(hout, 15, 0);
					cout << "���ļ�ʧ��" << endl;
					return -1;
				}
				break;
			}
			else
				if (isascii(choose))
				{
					gotoxy(hout, 2, k + 1);
					setcolor(hout, 15, 0);
					cout << txt[k];
					switch (choose)
					{
					case 72:
						if (k == 0)
							k = fn - 1;
						else
							k--;
						break;
					case 80:
						if (k == fn - 1)
							k = 0;
						else
							k++;
						break;
					default:
						continue;
					}
					gotoxy(hout, 2, k + 1);
					setcolor(hout, 9, 0);
					cout << txt[k];
				}
		}
		setcolor(hout, 15, 0);
		system("cls");
			/*���ִ�����ӡ*/
			/*������ȷ�������֣���0���㣺��3���������֣�����12��ͳһ����ɫ������15*/
			for (int i = 1; i <= 9; i++)
				for (int j = 1; j <= 9; j++)
				{
					infile >> sudoku[i][j].num;
					if (sudoku[i][j].num == 0)
						sudoku[i][j].color = 0;
					else
						sudoku[i][j].color = 3;

					if (i >= 1 && i <= 3 && j >= 1 && j <= 3)
						sudoku[i][j].cell = 1;
					else if (i >= 1 && i <= 3 && j >= 4 && j <= 6)
						sudoku[i][j].cell = 2;
					else if (i >= 1 && i <= 3 && j >= 7 && j <= 9)
						sudoku[i][j].cell = 3;
					else if (i >= 4 && i <= 6 && j >= 1 && j <= 3)
						sudoku[i][j].cell = 4;
					else if (i >= 4 && i <= 6 && j >= 4 && j <= 6)
						sudoku[i][j].cell = 5;
					else if (i >= 4 && i <= 6 && j >= 7 && j <= 9)
						sudoku[i][j].cell = 6;
					else if (i >= 7 && i <= 9 && j >= 1 && j <= 3)
						sudoku[i][j].cell = 7;
					else if (i >= 7 && i <= 9 && j >= 4 && j <= 6)
						sudoku[i][j].cell = 8;
					else if (i >= 7 && i <= 9 && j >= 7 && j <= 9)
						sudoku[i][j].cell = 9;
				}

			char cmd[80];
			sprintf(cmd, "mode con cols=%d lines=%d", 7 * 9 + 12, 5 * 9 - 1);
			system(cmd);

			printb(hout);
			printall(hout, sudoku, 9, 9);
			setcolor(hout, 15, 0);

			char arrow;
			int x = 1, y = 1;
			while (1)
			{
				int ds = 0, n = 0;

				showch(hout, 0, 4 * 9 + 1, 15, 0, ' ', 44);
				gotoxy(hout, 0, 4 * 9 + 1);

				arrow = _getch();
				sudoku[y][x].get = 0;
				if (arrow >= '1'&&arrow <= '9')
				{
					if (sudoku[y][x].num != 0)
						continue;
					else
					{
						sudoku[y][x].num = arrow - 48;
						if (rightwrite(sudoku[y][x].num, y, x, sudoku[y][x].cell, sudoku))
							sudoku[y][x].color = 3;
						else
							sudoku[y][x].color = 12;
						printone(hout, sudoku[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1);
					}
				}
				else
					if (isascii(arrow))
					{
						switch (arrow)
						{
						case 75:
							printone(hout, sudoku[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1);
							if (x == 1)
								x = 9;
							else
								x--;
							break;
						case 72:
							printone(hout, sudoku[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1);
							if (y == 1)
								y = 9;
							else
								y--;
							break;
						case 80:
							printone(hout, sudoku[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1);
							if (y == 9)
								y = 1;
							else
								y++;
							break;
						case 77:
							printone(hout, sudoku[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1);
							if (x == 9)
								x = 1;
							else
								x++;
							break;
						}
						sudoku[y][x].get = 1;
						printone(hout, sudoku[y][x], 8 * (x - 1) + 2, 4 * (y - 1) + 1);
					}
				if (done(sudoku))
					break;
			}

			int c = 0;
			for (int i = 1; i <= 9; i++)
				for (int j = 1; j <= 9; j++)
					if (sudoku[i][j].color != 0)
						c++;
			if (c == 0)
			{
				gotoxy(hout, 0, 13);
				setcolor(hout, 15, 12);
				cout << "�ɹ�";
			}
			else
			{
				gotoxy(hout, 0, 13);
				setcolor(hout, 15, 12);
				cout << "ʧ��";
			}

			gotoxy(hout, 0, 40);
			setcolor(hout, 15, 0);
			return 0;
		}
	
	else if (choice == 1)
	{
		/*��ȡ�ļ�*/
		char txt[15];
		cout << "���������ļ�����" << endl;
		cin >> txt;
		ifstream infile;
		infile.open(txt, ios::in);
		if (!infile.is_open())
		{
			cout << "���ļ�ʧ��" << endl;
			return -1;
		}

		/*���ִ�����ӡ*/
		/*������ȷ�������֣���0���㣺��3���������֣�����12��ͳһ����ɫ������15*/
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
			{
				infile >> sudoku[i][j].num;
				if (sudoku[i][j].num == 0)
					sudoku[i][j].color = 3;
				else
					sudoku[i][j].color = 0;

				if (i >= 1 && i <= 3 && j >= 1 && j <= 3)
					sudoku[i][j].cell = 1;
				else if (i >= 1 && i <= 3 && j >= 4 && j <= 6)
					sudoku[i][j].cell = 2;
				else if (i >= 1 && i <= 3 && j >= 7 && j <= 9)
					sudoku[i][j].cell = 3;
				else if (i >= 4 && i <= 6 && j >= 1 && j <= 3)
					sudoku[i][j].cell = 4;
				else if (i >= 4 && i <= 6 && j >= 4 && j <= 6)
					sudoku[i][j].cell = 5;
				else if (i >= 4 && i <= 6 && j >= 7 && j <= 9)
					sudoku[i][j].cell = 6;
				else if (i >= 7 && i <= 9 && j >= 1 && j <= 3)
					sudoku[i][j].cell = 7;
				else if (i >= 7 && i <= 9 && j >= 4 && j <= 6)
					sudoku[i][j].cell = 8;
				else if (i >= 7 && i <= 9 && j >= 7 && j <= 9)
					sudoku[i][j].cell = 9;
			}
		system("cls");
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				setcolor(hout, 15, sudoku[i][j].color);
				cout << sudoku[i][j].num << ' ';
			}
			cout << endl;
		}
		setcolor(hout, 15, 0);

		/*�������м�����*/
		char row, line, n;
		char op[4];
		while (1)
		{
			showch(hout, 0, 10, 15, 15, ' ', 25);
			showch(hout, 0, 11, 15, 15, ' ', 5);
			gotoxy(hout, 0, 10);
			setcolor(hout, 15, 0);
			cout << "���������к�����";
			gotoxy(hout, 0, 11);
			cin >> op;
			row = op[0];
			line = op[1];
			n = op[2];
			while (1)
			{
				/*�����벻�Ϸ���*/
				if (r_l(rownum(row)) || r_l(linenum(line)) || sudoku[rownum(row)][linenum(line)].num != 0)
				{
					showch(hout, 0, 10, 15, 15, ' ', 20);
					gotoxy(hout, 0, 10);
					setcolor(hout, 15, 0);
					cout << "����������������";
					showch(hout, 0, 11, 15, 15, ' ', 5);
					gotoxy(hout, 0, 11);
					setcolor(hout, 15, 0);
					cin >> row >> line >> n;
				}
				else
					break;
			}

			/*��ָ��λ��������*/
			/*������ȷ�������֣���0���㣺��3���������֣�����12��ͳһ����ɫ������15*/
			sudoku[rownum(row)][linenum(line)].num = n - 48;
			if (rightwrite(n - 48, rownum(row), linenum(line), sudoku[rownum(row)][linenum(line)].cell, sudoku))
				sudoku[rownum(row)][linenum(line)].color = 0;
			else
				sudoku[rownum(row)][linenum(line)].color = 12;
			showch(hout, 2 * linenum(line) - 2, rownum(row) - 1, 15, sudoku[rownum(row)][linenum(line)].color, n, 1);

			if (done(sudoku))
				break;
		}

		int c = 0;
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				if (sudoku[i][j].color != 0)
					c++;
		if (c == 0)
		{
			gotoxy(hout, 0, 13);
			setcolor(hout, 15, 12);
			cout << "�ɹ�";
		}
		else
		{
			gotoxy(hout, 0, 13);
			setcolor(hout, 15, 12);
			cout << "ʧ��";
		}

		gotoxy(hout, 0, 15);
		setcolor(hout, 15, 0);
		return 0;
	}

	else if (choice == 3)
	{
		/*��ȡ�ļ�*/
		char choose;
		ifstream infile;
		string dir;
		dir = "E:\\shudu";
		static char list[10][20];
		findFile(dir, list, 0);
		char txt[10][20];
		int i, fn;
		cout << "�X�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
		for (i = 0, fn = 0; i <= 9; i++)
			if (strncmp("shudu", list[i], 5) == 0)
			{
				strcpy_s(txt[fn], list[i]);
				cout << "�U";
				cout << txt[fn] << endl;
				gotoxy(hout, 24, fn + 1);
				cout << "�U" << endl;
				fn++;
			}
		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
		int k = 0;
		gotoxy(hout, 2, k + 1);
		setcolor(hout, 9, 0);
		cout << txt[k];
		while (1)
		{
			choose = _getch();
			if (choose == 13)
			{
				infile.open(txt[k], ios::in);
				if (!infile.is_open())
				{
					gotoxy(hout, 0, fn + 3);
					setcolor(hout, 15, 0);
					cout << "���ļ�ʧ��" << endl;
					return -1;
				}
				break;
			}
			else
				if (isascii(choose))
				{
					gotoxy(hout, 2, k + 1);
					setcolor(hout, 15, 0);
					cout << txt[k];
					switch (choose)
					{
					case 72:
						if (k == 0)
							k = fn - 1;
						else
							k--;
						break;
					case 80:
						if (k == fn - 1)
							k = 0;
						else
							k++;
						break;
					default:
						continue;
					}
					gotoxy(hout, 2, k + 1);
					setcolor(hout, 9, 0);
					cout << txt[k];
				}
		}
		setcolor(hout, 15, 0);
		system("cls");
		/*���ִ�����ӡ*/
		/*������ȷ�������֣���0���㣺��3���������֣�����12��ͳһ����ɫ������15*/
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
			{
				infile >> sudoku[i][j].num;
				if (sudoku[i][j].num == 0)
					sudoku[i][j].color = 0;
				else
					sudoku[i][j].color = 3;

				if (i >= 1 && i <= 3 && j >= 1 && j <= 3)
					sudoku[i][j].cell = 1;
				else if (i >= 1 && i <= 3 && j >= 4 && j <= 6)
					sudoku[i][j].cell = 2;
				else if (i >= 1 && i <= 3 && j >= 7 && j <= 9)
					sudoku[i][j].cell = 3;
				else if (i >= 4 && i <= 6 && j >= 1 && j <= 3)
					sudoku[i][j].cell = 4;
				else if (i >= 4 && i <= 6 && j >= 4 && j <= 6)
					sudoku[i][j].cell = 5;
				else if (i >= 4 && i <= 6 && j >= 7 && j <= 9)
					sudoku[i][j].cell = 6;
				else if (i >= 7 && i <= 9 && j >= 1 && j <= 3)
					sudoku[i][j].cell = 7;
				else if (i >= 7 && i <= 9 && j >= 4 && j <= 6)
					sudoku[i][j].cell = 8;
				else if (i >= 7 && i <= 9 && j >= 7 && j <= 9)
					sudoku[i][j].cell = 9;
			}

		char cmd[80];
		sprintf(cmd, "mode con cols=%d lines=%d", 7 * 9 + 12, 5 * 9 - 1);
		system(cmd);

		printb(hout);
		printall(hout, sudoku, 9, 9);
		setcolor(hout, 15, 0);
		cout << endl << "��������������Զ����";
		
		cin.ignore();
		getchar();
		showtime(hout, sudoku);

		gotoxy(hout, 0, 40);
		setcolor(hout, 15, 0);
		return 0;
	}
	
}