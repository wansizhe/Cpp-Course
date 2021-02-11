#include<iostream>
#include <windows.h>
#include <time.h>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
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
bool cin_rl(char *cinr,char *cinl,int row,int line)
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
void initialize(int row,int line,int getX[][22])
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
void print(int row,int line,int bgetx[][22],int getX[][22])
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
int the_max(int getX[][22],int row,int line)
{
	int max = getX[1][1];
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			if (getX[i][j]>max)
				max = getX[i][j];
	return max;
}

/*�������������*/
int probability(int m)
{
	int n = rand() % 100;
	switch (m)
	{
	case 3:
		if (n <= 33)
			return 1;
		else if (n >= 67)
			return 2;
		else
			return 3;
	case 4:
		if (n < 30)
			return 1;
		else if (n >= 30 && n < 60)
			return 2;
		else if (n >= 60 && n < 90)
			return 3;
		else
			return 4;
	case 5:
		if (n < 25)
			return 1;
		else if (n >= 25 && n < 50)
			return 2;
		else if (n >= 50 && n < 75)
			return 3;
		else if (n >= 75 && n < 90)
			return 4;
		else
			return 5;
	case 6:
		if (n < 20)
			return 1;
		else if (n >= 20 && n < 40)
			return 2;
		else if (n >= 40 && n < 60)
			return 3;
		else if (n >= 60 && n < 80)
			return 4;
		else if (n >= 80 && n < 95)
			return 5;
		else
			return 6;
	default:
		if (n < 5)
			return m;
		else if (n >= 5 && n < 10)
			return m - 1;
		else if (n >= 10 && n < 20)
			return m - 2;
		else
			return (rand() % (m - 2)) + 1;
	}
}

/*�ж�����*/
void continuous(int r, int l,int bgetx[][22],int getX[][22])
{
	bgetx[r][l] = 1;
	if (getX[r - 1][l] == getX[r][l] && bgetx[r - 1][l] == 0)
	{
		bgetx[r - 1][l] = 1;
		continuous(r - 1, l,bgetx, getX);
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

/*�ϲ���ͬ��*/
void merge(int r, int l,int row,int line,int bgetx[][22],int getX[][22],int *ds,int *s)
{
	int num = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			if ((i != r || j != l) && bgetx[i][j] == 1)
			{
				getX[i][j] = 0;
				num++;
			}
	*ds= getX[r][l] * 3 * (num + 1);
	*s += *ds;
	getX[r][l]++;
}

/*����*/
void drop(int row,int line,int bgetx[][22],int getX[][22])
{
	for (int j = 1; j <= line; j++)
	{
		int t;
		while (1)
		{
			int n = 0;
			for (int i = row; i >= 1; i--)
				if (getX[i][j] == 0 && getX[i - 1][j] != 0)
				{
					t = getX[i][j];
					getX[i][j] = getX[i - 1][j];
					bgetx[i][j] = 0;
					getX[i - 1][j] = t;
					bgetx[i - 1][j] = 1;
					n++;
				}
			if (n == 0)
				break;
		}
	}
}

/*����*/
void regenerate(int row,int line, int getX[][22])
{
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			if (getX[i][j] == 0)
				getX[i][j] = probability(the_max(getX,row,line));
}

/*�ж��Ƿ����*/
bool dead(int row, int line, int getX[][22])
{
	bool d = true;
	for (int r = 1; r <= row; r++)
		for (int l = 1; l <= line; l++)
		{
			if (getX[r - 1][l] == getX[r][l])
			{
				d = false;
				return d;
			}
			if (getX[r + 1][l] == getX[r][l])
			{
				d = false;
				return d;
			}
			if (getX[r][l-1] == getX[r][l])
			{
				d = false;
				return d;
			}
			if (getX[r][l + 1] == getX[r][l])
			{
				d = false;
				return d;
			}
		}
	return d;
}

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //���λ��
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand(unsigned int(time(0)));
	int step=1,X,Y;

	int getX[22][22] = { 0 }, row, line, score = 0, dscore = 0;
	int bgetx[22][22] = { 0 };
	char cinr, cinl;





	/*�������в��ж��Ƿ�Ϸ�*/
	cout << "������������5-8����";
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//��ȡ��ǰ����
	cin >> row;
	while (r_l(row))
	{
		cout << "����������������롣";
		showch(hout, X, Y, 15, 0, ' ', 2);
		gotoxy(hout,X,Y);
		cin >> row;
	}
	showch(hout, 0,Y+1, 15, 0, ' ', 25);
	gotoxy(hout, 0, Y+1);
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

	/*��ʼ������ӡ*/
	while (1)
	{
		initialize(row,line,getX);
		if (!dead(row,line,getX))
			break;
	}
	
	/*��ʼ��Ϸ*/
	while (1)
	{
		cout << endl << endl;
		/*����������*/
		for (int a = 1; a <= row; a++)
			for (int b = 1; b <= line; b++)
				bgetx[a][b] = 0;

		/*�ж���Ϸ����*/
		if (dead(row, line, getX))
			break;

		print(row,line,bgetx,getX);
		cout << endl;

		/*������ʾ*/
		cout << "���� ����ĸ+���֡� ����ʽ�����磺c2������������꣺";
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		X = csbi.dwCursorPosition.X, Y = csbi.dwCursorPosition.Y;//��ȡ��ǰ����
		cin >> cinr >> cinl;
		while (cin_rl(&cinr,&cinl,row,line))
		{
			cout << "����������������롣";
			showch(hout, X,Y, 15, 0, ' ', 2);
			gotoxy(hout,X, Y);
			cin >> cinr >> cinl;
		}
		showch(hout, 0, Y+1, 15, 0, ' ', 25);
		gotoxy(hout, 0, Y+1);
		cout << "����Ϊ" << cinr << "��" << cinl << "�С�" << endl;

		/*����ִ��*/
		dscore = 0;
		int i, j;
		i = int(cinr) - 64;
		j = int(cinl) - 47;
		while (getX[i][j] != getX[i - 1][j] && getX[i][j] != getX[i + 1][j] && getX[i][j] != getX[i][j - 1] && getX[i][j] != getX[i][j + 1])
		{
			cout << "����ľ�������λ�ô���������ֵͬ�����������롣";
			showch(hout, X, Y, 15, 0, ' ', 2);
			gotoxy(hout, X, Y);
			cin >> cinr >> cinl;
			while (cin_rl(&cinr, &cinl, row, line))
			{
				cout << "����������������롣";
				showch(hout, X, Y, 15, 0, ' ', 2);
				gotoxy(hout, X, Y);
				cin >> cinr >> cinl;
			}
			cout << "����Ϊ" << cinr << "��" << cinl << "�С�" << endl;
			i = int(cinr) - 64;
			j = int(cinl) - 47;
		}
		cout << endl;
		showch(hout, 0, Y+2, 15, 0, ' ', 50);
		gotoxy(hout, 0, Y+2);
		cout << endl;

		continuous(i, j,bgetx,getX);
		print(row,line,bgetx,getX);
		cout << endl << "��ȷ���Ƿ����ڵ���ֵͬ�ϲ���" << cinr << cinl << "��(Y/N/Q)��";
		switch (_getch())
		{
		case 'Y':
		case 'y':
			merge(i, j,row,line,bgetx,getX,&dscore,&score);
			cout << endl << endl;
			print(row, line, bgetx, getX);
			cout << endl << endl << "���ε÷֣�" << dscore << "   �ܵ÷֣�" << score << "   �ϳ�Ŀ�꣺10";
			cout << endl << endl << "���س����������������" << endl;
			_getch();
			drop(row, line, bgetx, getX);
			print(row, line, bgetx, getX);
			cout << endl << endl << "���س�������ֵ��䡣" << endl;
			_getch();
			regenerate(row, line, getX);
			print(row, line, bgetx, getX);
			break;
		case 'N':
		case 'n':
			continue;
		case 'Q':
		case'q':
			return 0;
		}
		_getch();
		cout << endl;
		cout << "----------------------------------------------------";
		cout << endl << endl ;
		step++;
		if (the_max(getX,row,line) == 10)
		{
			setcolor(hout, 15, 12);
			cout << "��ϲ�㣡�Ѻϳ�10��������";
			setcolor(hout, 15, 0);
		}
	}
	setcolor(hout, 15, 12);
	cout << endl << endl << "��Ϸ������       �ܵ÷֣�" << score << endl;
	setcolor(hout, 15, 0);

	return 0;
}