#include<iostream>
#include <windows.h>
#include <time.h>
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

/*�жϲ����Ƿ�Ϸ�*/
bool cin_rl(char *cinr, char *cinl, int row, int line)
{
	bool error = true;
	if (!((*cinr >= 65 && *cinr <= 64 + row) || (*cinr >= 97 && *cinr <= 96 + row)) || (*cinl - 48 < 0 || *cinl - 48 > line - 1))
		return error;
	if (*cinr >= 97 && *cinr <= 96 + row)
		*cinr -= 32;
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

/*��ӡ*/
void print(int row, int line, int bgetx[][22], int getX[][22])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	cout << "��ǰ���飺" << endl;
	cout << "  | ";
	for (int i = 0; i < line; i++)
		cout << ' ' << i << ' ';
	cout << endl;
	cout << "--+-";
	for (int i = 0; i < line; i++)
		cout << "---";
	cout << endl;
	for (int i = 1; i <= row; i++)
	{
		cout << char(64 + i) << " | ";
		for (int j = 1; j <= line; j++)
		{
			if (bgetx[i][j] == 1)
				setcolor(hout, 15, 3);
			cout << setw(2) << getX[i][j] << ' ';
			setcolor(hout, 15, 0);
		}
		cout << endl;
	}

}

/*ȷ�����ֵ*/
int the_max(int getX[][22], int row, int line)
{
	int max = getX[1][1];
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			if (getX[i][j]>max)
				max = getX[i][j];
	return max;
}

/*�ж�����*/
void continuous(int r, int l, int bgetx[][22], int getX[][22])
{
	bgetx[r][l] = 1;
	if (getX[r - 1][l] == getX[r][l] && bgetx[r - 1][l] == 0)
	{
		bgetx[r - 1][l] = 1;
		continuous(r - 1, l, bgetx, getX);
	}
	if (getX[r + 1][l] == getX[r][l] && bgetx[r + 1][l] == 0)
	{
		bgetx[r + 1][l] = 1;
		continuous(r + 1, l, bgetx, getX);
	}
	if (getX[r][l - 1] == getX[r][l] && bgetx[r][l - 1] == 0)
	{
		bgetx[r][l - 1] = 1;
		continuous(r, l - 1, bgetx, getX);
	}if (getX[r][l + 1] == getX[r][l] && bgetx[r][l + 1] == 0)
	{
		bgetx[r][l + 1] = 1;
		continuous(r, l + 1, bgetx, getX);
	}
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
												   /* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand(unsigned int(time(0)));

	int getX[22][22] = { 0 }, row, line;
	int bgetx[22][22] = { 0 };
	char cinr, cinl;

	/*�������в��ж��Ƿ�Ϸ�*/
	cout << "������������5-8����";
	cin >> row;
	while (r_l(row))
	{
		cout << "����������������롣";
		showch(hout, 19, 0, 15, 0, ' ', 2);
		gotoxy(hout, 19, 0);
		cin >> row;
	}
	showch(hout, 0, 1, 15, 0, ' ', 25);
	gotoxy(hout, 0, 1);
	cout << "������������5-8����";
	cin >> line;
	while (r_l(line))
	{
		cout << "����������������롣";
		showch(hout, 19, 1, 15, 0, ' ', 2);
		gotoxy(hout, 19, 1);
		cin >> line;
	}
	showch(hout, 0, 2, 15, 0, ' ', 30);
	cout << endl;

	/*��ʼ������ӡ*/
	initialize(row,line,getX);
	print(row,line,bgetx,getX);
	cout << endl;

	/*������ʾ*/
	cout << "���� ����ĸ+���֡� ����ʽ�����磺c2������������꣺";
	cin >> cinr >> cinl;
	while (cin_rl(&cinr,&cinl,row,line))
	{
		cout << "����������������롣";
		showch(hout, 51, 7 + row, 15, 0, ' ', 2);
		gotoxy(hout, 51, 7 + row);
		cin >> cinr >> cinl;
	}
	showch(hout, 0, 8 + row, 15, 0, ' ', 25);
	gotoxy(hout, 0, 8 + row);
	cout << "����Ϊ" << cinr << "��" << cinl << "�С�" << endl;

	/*����ִ��*/
	int i, j;
	i = int(cinr) - 64;
	j = int(cinl) - 47;
	while (getX[i][j] != getX[i - 1][j] && getX[i][j] != getX[i + 1][j] && getX[i][j] != getX[i][j - 1] && getX[i][j] != getX[i][j + 1])
	{
		cout << "����ľ�������λ�ô���������ֵͬ�����������롣";
		showch(hout, 51, 7 + row, 15, 0, ' ', 2);
		gotoxy(hout, 51, 7 + row);
		cin >> cinr >> cinl;
		while (cin_rl(&cinr,&cinl,row,line))
		{
			cout << "����������������롣";
			showch(hout, 51, 7 + row, 15, 0, ' ', 2);
			gotoxy(hout, 51, 7 + row);
			cin >> cinr >> cinl;
		}
		cout << "����Ϊ" << cinr << "��" << cinl << "�С�" << endl;
		i = int(cinr) - 64;
		j = int(cinl) - 47;
	}
	cout << endl;
	showch(hout, 0, 9 + row, 15, 0, ' ', 50);
	gotoxy(hout, 0, 9 + row);
	cout << endl;

	continuous(i, j,bgetx,getX);
	print(row,line,bgetx,getX);



	return 0;
}