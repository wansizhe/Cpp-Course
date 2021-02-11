#include <iostream>
#include <ctime>
#include<iomanip>
#include <cmath>
#include <cstdio>
#include <windows.h>
using namespace std;

/*���չ�ʽ����ÿ�µ�һ�������ڼ�*/
int zeller(int year, int month)
{
	int w, c, y, m, d, week, day = 1;
	switch (month)
	{
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			m = month;
			break;
		case 1:
		case 2:
			m = 12 + month;
			year--;
			break;
	}
	c = year / 100;
	y = year % 100;
	d = day;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0)
		for (; w < 0;)
			w += 7;
	week = w % 7;
	return week;
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

/*��ӡͷ��*/
void head(int n)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	cout <<endl<< endl ;
	setcolor(hout, 15, 0);
	cout << "             " << setw(2)<<setiosflags(ios::right)<<n << "��               " << "               " <<  setw(2)<< setiosflags(ios::right) << n+1<< "��               " << "               " << setw(2) <<setiosflags(ios::right)<< n+2 << "��               " << endl;
	cout << "  Mon Tue Wed Thu Fri ";
	setcolor(hout, 15, 12);
	cout << "Sat Sun";
	setcolor(hout, 15, 0);
	cout << "       Mon Tue Wed Thu Fri ";
	setcolor(hout, 15, 12);
	cout << "Sat Sun";
	setcolor(hout, 15, 0);
	cout << "       Mon Tue Wed Thu Fri ";
	setcolor(hout, 15, 12);
	cout << "Sat Sun" << endl;
	setcolor(hout, 15, 0);
}

/* ������ƶ���ָ��λ�� */
void gotoxy(HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

void print_1()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	const int base_x = 0;
	const int base_y = 2;
	int x, y;
	setcolor(hout, 15, 5);
	for (y = 0; y <= 40; y++)
	{
		gotoxy(hout, base_x, base_y + y);
		if (y % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}   
	for (y = 0; y <= 40; y++)
	{
		gotoxy(hout, base_x+32, base_y + y);
		if (y % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}
	for (y = 0; y <= 40; y++)
	{
		gotoxy(hout, base_x+66, base_y + y);
		if (y % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}
	for (y = 0; y <= 40; y++)
	{
		gotoxy(hout, base_x + 98, base_y + y);
		if (y % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}
	
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y );
		if (x % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y+10);
		if (x % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y + 20);
		if (x % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y + 30);
		if (x % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y + 40);
		if (x % 2 == 0)
			cout << "*";
		else
			cout << " ";
	}
}

void print_2()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	const int base_x = 0;
	const int base_y = 2;
	int x, y;
	setcolor(hout, 15, 3);
	for (y = 0; y <= 40; y++)
	{
		gotoxy(hout, base_x, base_y + y);
		if (y % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	for (y = 0; y <= 40; y++)
	{
		gotoxy(hout, base_x + 32, base_y + y);
		if (y % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	for (y = 0; y <= 40; y++)
	{
		gotoxy(hout, base_x + 66, base_y + y);
		if (y % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	for (y = 0; y <= 40; y++)
	{
		gotoxy(hout, base_x + 98, base_y + y);
		if (y % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}

	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y);
		if (x % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y + 10);
		if (x % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y + 20);
		if (x % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y + 30);
		if (x % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	for (x = 0; x <= 98; x++)
	{
		gotoxy(hout, base_x + x, base_y + 40);
		if (x % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
}

int main()
{
	system("mode con cols=110 lines=80"); // cols Ϊ�� ���� lines Ϊ�� ����
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	int y,d;
	cout << "��������ݣ�1900-2100����";
	cin >> y;

	int dates[13][6][8] = { 0 };

	/*������*/
	int max;
	for (int i = 1; i <= 12; i++)
	{
		d = 1;
		bool done = false;
		switch (i)
		{
			case 4:
			case 6:
			case 9:
			case 11:
				max = 30;
				break;
			case 2:
				if ((y % 400 == 0) || y % 4 == 0 && y % 100 != 0)
					max = 29;
				else
					max = 28;
				break;
			default:
				max = 31;
				break;				
		}
		for (int j = 0; j <= 5; j++)
		{
			if (j == 0)
				for (int k = (zeller(y, i) == 0 ? 7 : zeller(y,i)); k <= 7; k++)
				{
					dates[i][j][k] = d;
					d++;
				}
		    if(j != 0)
				for (int k = 1; k <= 7; k++)
				{
					dates[i][j][k] = d;
					d++;
					if (d > max && done == false)
						done = true;
					if (done)
						break;
				}
			if (done)
				break;
		}
	}

	system("cls");

	/*���*/
	int n ;
	cout << endl;
	for (n = 1; n <= 10; n += 3)
	{
		int n0 = n + 2;
		head(n);
		for (int j = 0; j <= 5; j++)
		{
			cout << " ";
			for (int k = 1; k <= 7; k++)
			{
				if (dates[n][j][k] != 0)
				{
					if (k == 6 || k == 7)
						setcolor(hout, 15, 12);
					else
						setcolor(hout, 15, 8);
					cout << " " << setw(3) << resetiosflags(ios::right) << setiosflags(ios::left) << dates[n][j][k];
					Sleep(24);
				}
				else
					cout << "    ";

				if (k == 7)
				{
					if (n == n0)
					{
						n = n0 - 2;
						cout << endl;
					}
					else if (n == n0 - 1 || n == n0 - 2)
					{
						n++;
						k = -1;
						cout << "  ";
					}

				}
			}
			//cout << endl;
		}
	}
	gotoxy(hout, 0, 1);
	setcolor(hout, 15, 1);
	cout << "                                            �й������� ���� " << y << "��" << endl;
	while (1)
	{
		print_1();
		Sleep(81);
		print_2();
		Sleep(81);
	}

	gotoxy(hout, 0, 60);
	cout << endl;
	return 0;
}