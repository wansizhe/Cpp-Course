#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <windows.h>
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

int main()
{
	system("mode con cols=100 lines=30"); // cols Ϊ�� ���� lines Ϊ�� ����
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	const int time = 300;

	gotoxy(hout, 5, 18);
	setcolor(hout, 1, 0);
	cout << "                        ";
	Sleep(time);

	gotoxy(hout, 38, 18);
	setcolor(hout, 1, 0);
	cout << "                        ";
	Sleep(time);

	gotoxy(hout, 71, 18);
	setcolor(hout, 1, 0);
	cout << "                        ";
	Sleep(time);
	
	char ch = ' ';
	for (int i = 17; i >= 5; i--)
	{
		showch(hout, 17, i, 1, 0, ch, 1);
		Sleep(time);
		showch(hout, 50, i, 1, 0, ch, 1);
		Sleep(time);
		showch(hout, 83, i, 1, 0, ch, 1);
		Sleep(time);
	}


	
	gotoxy(hout, 0, 22);
	setcolor(hout, 15, 0);
	cout << endl;
	return 0;
}