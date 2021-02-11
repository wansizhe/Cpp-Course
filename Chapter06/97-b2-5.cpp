#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <windows.h>
#include<iomanip>
using namespace std;

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

/*�ж��������뷶Χ*/
bool r_l(int rl, int high = 8, int low = 5)
{
	bool error;
	if (rl > high || rl < low)
		error = true;
	else
		error = false;
	return error;
}

/*��ʼ��*/
void initialize(int row, int line, int getX[][22])
{
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
		{
			getX[i][j] = rand();
			while (getX[i][j] <= 0 || getX[i][j] >= 4)
				getX[i][j] = rand();
		}
}

/*��ӡһ��*/
void printone(HANDLE hout, int t, int l, int r)
{
	if (t >= 1 && t <= 6)
		setcolor(hout, t, 0);
	else
		setcolor(hout, t + 2, 0);
	gotoxy(hout, l, r);
	cout << "�q���r";
	gotoxy(hout, l, r + 1);
	cout << "��" << setw(2) << t << "��";
	gotoxy(hout, l, r + 2);
	cout << "�t���s";
}

/*��ӡ����*/
void printall(HANDLE hout, int getX[][22], int line, int row)
{
	setcolor(hout, 15, 0);
	gotoxy(hout, 0, 0);
	cout << "��";
	Sleep(10);
	for (int i = 1; i <= 4 * line-1; i++)
	{
		if (i % 4 == 0)
			cout << "��";
		else
		    cout << "��";
		Sleep(10);
	}
	cout << "��" << endl;
	Sleep(10);
	for (int i = 1; i <= 4 * row - 1; i++)
	{
		if (i % 4 == 0)
		{
			cout << "��";
			for (int i = 1; i <= 4 * line - 1; i++)
			{
				if (i % 4 == 0)
					cout << "��";
				else
				    cout << "��";
				Sleep(10);
			}
			cout << "��";
			Sleep(10);
			cout << endl;
		}
		else
		{
			cout << "��";
			for (int i = 1; i <= 4 * line - 1; i++)
			{
				if (i % 4 == 0)
					cout << "��";
				else
					cout << "  ";
				Sleep(10);
			}
			cout << "��";
			Sleep(10);
			cout << endl;
		}
	}
	gotoxy(hout, 0, 4 * row );
	cout << "��";
	Sleep(100);
	for (int i = 1; i <= 4 * line-1; i++)
	{
		if (i % 4 == 0)
			cout << "��";
		else
			cout << "��";
		Sleep(10);
	}
	cout << "��";
	Sleep(100);

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= line; j++)
		{
			printone(hout, getX[i][j], 8 * (j - 1) + 2, 4 * (i - 1) + 1);
			Sleep(50);
		}
		cout << endl;
	}
}


int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //���λ��
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand(unsigned int(time(0)));

	int row, line, X, Y, getX[22][22] = { 0 };

	/*�������в��ж��Ƿ�Ϸ�*/
	cout << "������������5-8����";
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//��ȡ��ǰ����
	cin >> row;
	while (r_l(row))
	{
		cout << "����������������롣";
		showch(hout, X, Y, 15, 0, ' ', 2);
		gotoxy(hout, X, Y);
		cin >> row;
	}
	showch(hout, 0, Y + 1, 15, 0, ' ', 25);
	gotoxy(hout, 0, Y + 1);
	cout << "������������5-8����";
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//��ȡ��ǰ����
	cin >> line;
	while (r_l(line))
	{
		cout << "����������������롣";
		showch(hout, X, Y, 15, 0, ' ', 2);
		gotoxy(hout, X, Y);
		cin >> line;
	}
	showch(hout, 0, Y + 1, 15, 0, ' ', 25);
	cout << endl;

	/*���ô���*/
	system("cls");
	char cmd[80];
	sprintf(cmd, "mode con cols=%d lines=%d", 7 * line + 12, 5 * row-1);
	system(cmd);

	/*��ʼ��*/
	initialize(row, line, getX);
	printall(hout, getX, line, row);


	setcolor(hout, 15, 0);
	cout << endl << endl << endl;
	return 0;
}