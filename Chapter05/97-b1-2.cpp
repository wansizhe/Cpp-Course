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

/*��ӡ����*/
void print(HANDLE hout, char q,int n)
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

int main()
{
	system("mode con cols=100 lines=30"); // cols Ϊ�� ���� lines Ϊ�� ����
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	int n;
	cout << "���������(1-10) ";
	cin >> n;
	while (n < 1 || n>10)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "���������(1-10) ";
		cin >> n;
	}
	cout << "���������(A-C) ";
	cin >> qidian;
	while (qidian != 65 && qidian != 97 && qidian != 66 && qidian != 98 && qidian != 67 && qidian != 99)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "���������(A-C) ";
		cin >> qidian;
	}
	if (qidian / 10 != 6)
		qidian -= 32;

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
		Sleep(speed);
		showch(hout, 51, i, 14, 0, ch, 1);
		Sleep(speed);
		showch(hout, 84, i, 14, 0, ch, 1);
		Sleep(speed);
	}

	print(hout, qidian, n);


	gotoxy(hout, 0, 22);
	setcolor(hout, 15, 0);
	cout << endl;
	return 0;
}