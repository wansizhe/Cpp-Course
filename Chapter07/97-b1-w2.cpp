#include<iostream>
#include<fstream>
#include <windows.h>
using namespace std;

struct number
{
	int num;
	int color;
	int cell;
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

/*�жϱ�����д�Ƿ񷸹�*/
bool wrongwrite(int n, int r, int l,int c,number shudu[10][10])
{
	int k = 0;
	for (int i = 1; i <= 9; i++)
		if (n == shudu[r][i].num)
			k++;
	if (k != 1)
		return true;
	k = 0;
	for (int i = 1; i <= 9; i++)
		if (n == shudu[i][l].num)
			k++;
	if (k != 1)
		return true;
	k = 0;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (c == shudu[i][j].cell&&n == shudu[i][j].num)
				k++;
	if (k == 1)
		return true;
	return false;
}

/*�ж��Ƿ���д���*/
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

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; //���λ��
	//CONSOLE_SCREEN_BUFFER_INFO csbi;

	number sudoku[10][10];
	
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
			if (r_l(rownum(row)) || r_l(linenum(line))|| sudoku[rownum(row)][linenum(line)].num!=0)
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
		if(wrongwrite(n - 48, rownum(row), linenum(line), sudoku[rownum(row)][linenum(line)].cell, sudoku))
			sudoku[rownum(row)][linenum(line)].color = 12;
		else
			sudoku[rownum(row)][linenum(line)].color = 0;
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