#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

						/* ������ƶ���ָ��λ�� */
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* ��ָ��λ�ô���ӡһ��ָ�����ַ� */
void showch(HANDLE hout, int X, int Y, char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	int    i;

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand(unsigned int(time(0)));

	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	ע�⣺������bug���������ѭ�����ɵ�XY����ǡ����ȫ��ͬ������ĸ�����᲻��20������˵��������Ҫ�����bug�� */
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	/* �ڴ˴������Ҫ�Ĵ���-begin */
	int x = 36, y = 10;
	gotoxy(hout, x, y);
	while (1)
	{
		char c;
		c = _getch();
		if (c == 'q' || c == 'Q')
			break;
		switch (c)
		{
		    case 'i':
		    case 'I':
			    gotoxy(hout, x, --y);
			    break;
		    case 'j':
		    case 'J':
			    gotoxy(hout, --x, y);
		    	break;
		    case 'k':
		    case 'K':
			    gotoxy(hout, x, ++y);
			    break;
		    case 'l':
		    case 'L':
			    gotoxy(hout, ++x, y);
			    break;
			case ' ':
				showch(hout, x, y, c);
				break;
		}
	}
		

			   /* �ڴ˴������Ҫ�Ĵ���-end */

	gotoxy(hout, 0, 23);
	cout << "��Ϸ���������س����˳�." << endl;
	getchar();
	return 0;
}
