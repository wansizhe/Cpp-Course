/*1552174 ��˼�� ��1*/
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <windows.h>
using namespace std;

char qidian, zhongdian, fuzhu;
int num;
int a, b, c;
const int lie = 17;
int speed;
int color[11], leftp[11], wide[11];

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

/*ȷ����ӡ�ٶ�*/
void pause()
{
	switch (speed)
	{
	case 0:
		getchar();
		break;
	case 1:
		Sleep(900);
		break;
	case 2:
		Sleep(520);
		break;
	case 3:
		Sleep(240);
		break;
	case 4:
		Sleep(100);
		break;
	case 5:
		Sleep(10);
		break;
	}
}

/*��ӡ����*/
void print(HANDLE hout, char q, int n)
{
	int p, h, w, fcol = 0, bcol = 2;
	char ch = ' ';
	switch (q)
	{
	case 'A':
		p = 18;
		a = n;
		b = 0;
		c = 0;
		break;
	case 'B':
		p = 51;
		b = n;
		a = 0;
		c = 0;
		break;
	case 'C':
		p = 84;
		a = 0;
		b = 0;
		c = n;
		break;
	default:
		break;
	}
	w = 3 + 2 * n;
	p = p - (w - 1) / 2;
	int i = n;
	leftp[i] = p;
	wide[i] = w;
	color[i] = bcol;
	i--;
	for (h = 17; h >= 17 - n + 1; h--)
	{
		showch(hout, p, h, bcol, fcol, ch, w);
		w -= 2;
		wide[i] = w;
		bcol++;
		color[i] = bcol;
		p++;
		leftp[i] = p;
		i--;
		Sleep(50);
	}
}

/*����*/
void carry(HANDLE hout, char q, char z, int n)
{
	int p, pp, p0, h0;
	int from, to;
	char ch = ' ';
	switch (q)
	{
	case 'A':
		p = 18;
		from = a;
		break;
	case 'B':
		p = 51;
		from = b;
		break;
	case 'C':
		p = 84;
		from = c;
		break;
	default:
		break;
	}
	switch (z)
	{
	case 'A':
		pp = 18;
		to = a;
		break;
	case 'B':
		pp = 51;
		to = b;
		break;
	case 'C':
		pp = 84;
		to = c;
		break;
	default:
		break;
	}
	
	p0 = leftp[n];

	pause();

	/*����*/
	for (h0 = 18 - from; h0 >= 5; h0--)
	{
		Sleep(60);
		showch(hout, p0, h0, 15, 0, ch, wide[n]);
		showch(hout, p, h0, 14, 0, ch, 1);
		showch(hout, p0, h0 - 1, color[n], 0, ch, wide[n]);
	}
	for (; h0 >= 3; h0--)
	{
		Sleep(60);
		showch(hout, p0, h0, 15, 0, ch, wide[n]);
		showch(hout, p0, h0 - 1, color[n], 0, ch, wide[n]);
	}
	/*ƽ��*/
	if (pp > p)
	{
		for (; p0 <= pp - (wide[n] + 1) / 2; p0++)
		{
			Sleep(40);
			showch(hout, p0, h0, 15, 0, ch, wide[n]);
			showch(hout, p0 + 1, h0, color[n], 0, ch, wide[n]);
		}
	}
	else
	{
		for (; p0 >= pp - (wide[n] - 3) / 2; p0--)
		{
			Sleep(40);
			showch(hout, p0, h0, 15, 0, ch, wide[n]);
			showch(hout, p0 - 1, h0, color[n], 0, ch, wide[n]);
		};
	}
	/*����*/

	for (; h0 < 5; h0++)
	{
		Sleep(40);
		showch(hout, p0, h0, 15, 0, ch, wide[n]);
		showch(hout, p0, h0 + 1, color[n], 0, ch, wide[n]);
	}
	for (; h0 <(17-to); h0++)
	{
		Sleep(40);
		showch(hout, p0, h0, 15, 0, ch, wide[n]);
		showch(hout, pp, h0, 14, 0, ch, 1);
		showch(hout, p0, h0 + 1, color[n], 0, ch, wide[n]);
	}
	leftp[n] = p0;
}

/*�ƶ�*/
void move(int n, char qi, char zhong)
{
	switch (qi)
	{
	case 'A':
		a--;
		break;
	case 'B':
		b--;
		break;
	case 'C':
		c--;
		break;
	}
	switch (zhong)
	{
	case 'A':
		a++;
		break;
	case 'B':
		b++;
		break;
	case 'C':
		c++;
		break;
	}
}

/*��ŵ���ݹ�*/
void han(HANDLE hout,int n, char q, char z, char f)
{
	if (n == 1)
	{
		carry(hout, q, z, n);
		move(n, q, z);
	}
	else
	{
		han(hout,n - 1, q, f, z);
		carry(hout, q, z, n);
		move(n, q, z);
		han(hout,n - 1, f, z, q);
	}
}

int main()
{
	system("mode con cols=100 lines=30"); // cols Ϊ�� ���� lines Ϊ�� ����
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	cout << "���������(1-10) ";
	cin >> num;
	while (num < 1 || num>10)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "���������(1-10) ";
		cin >> num;
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
	cout << "�������յ�(A-C) ";
	cin >> zhongdian;
	while (zhongdian != 65 && zhongdian != 97 && zhongdian != 66 && zhongdian != 98 && zhongdian != 67 && zhongdian != 99)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "�������յ�(A-C) ";
		cin >> zhongdian;
	}
	cout << "��ȷ���ٶȣ�0Ϊ���س���ʾ��1--5�ٶȵ�����";
	cin >> speed;
	while (speed < 0 || speed>5)
	{
		cout << "�������";
		cout << endl;
		cout << "��ȷ���ٶȣ�0Ϊ���س���ʾ��1--5�ٶȵ�����";
		cin.clear();
		cin.ignore();
		cin >> speed;
		if (speed >= 0 && speed <= 5)
			break;
	}

	if (qidian / 10 != 6)
		qidian -= 32;
	if (zhongdian / 10 != 6)
		zhongdian -= 32;

	if (qidian*zhongdian == 4290)
		fuzhu = 'C';
	else if (qidian*zhongdian == 4355)
		fuzhu = 'B';
	else if (qidian*zhongdian == 4422)
		fuzhu = 'A';

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
	Sleep(50);

	char ch = ' ';
	for (int i = 17; i >= 5; i--)
	{
		showch(hout, 18, i, 14, 0, ch, 1);
		Sleep(50);
		showch(hout, 51, i, 14, 0, ch, 1);
		Sleep(50);
		showch(hout, 84, i, 14, 0, ch, 1);
		Sleep(50);
	}

	print(hout, qidian, num);
	pause();

	han(hout, num, qidian, zhongdian, fuzhu);
	
	gotoxy(hout, 0, 22);
	setcolor(hout, 15, 0);
	cout << endl;
	return 0;
}