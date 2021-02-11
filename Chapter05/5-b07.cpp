#include<iostream>
#include<iomanip>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

char qidian, zhongdian, fuzhu;
int a[10], b[10], c[10];
unsigned int s = 0;
int speed;
const int hanga = 62;
const int hangb = 80;
const int hangc = 98;
const int lie = 17;

/*确定打印速度*/
void spd(int s)
{
	switch (speed)
	{
	    case 0:
		    getchar();
		    break;
	    case 1:
		    Sleep(700);
		    break;
    	case 2:
		    Sleep(550);
		    break;
	    case 3:
		    Sleep(350);
		    break;
	    case 4:
		    Sleep(200);
		    break;
    	case 5:
		    Sleep(50);
		    break;
	}
}

/* 将光标移动到指定位置 */
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* 在指定位置处打印一个指定的字符 */
void showch(HANDLE hout, int X, int Y, char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/*打印盘子编号*/
void print()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int i;
	//cout << "A:";
	for (i = 0; i <= 9; i++)
	{
		if (a[i] > 0&&a[i]<=9)
		{
			gotoxy(hout, hanga, abs(i-lie));
			cout << ' ' << a[i];
		}
		else if (a[i] == 10)
		{
			gotoxy(hout, hanga, abs(i-lie));
			cout << a[i];
		}
		else if(a[i]==0)
		{
			gotoxy(hout, hanga - 2, abs(i - lie));
			cout << "    ";
		}
	}
	
	//cout << " B:";
	for (i = 0; i <= 9; i++)
	{
		if (b[i] > 0 && b[i] <= 9)
		{
			gotoxy(hout,hangb, abs(i - lie));
			cout << ' ' << b[i];
		}
		else if (b[i] == 10)
		{
			gotoxy(hout, hangb, abs(i - lie));
			cout << b[i];
		}
		else if(b[i]==0)
		{
			gotoxy(hout, hangb-2, abs(i - lie));
			cout << "    ";
		}
	}
	
	//cout << " C:";
	for (i = 0; i <= 9; i++)
	{
		if (c[i] > 0 && c[i] <= 9)
		{
			gotoxy(hout, hangc, abs(i - lie));
			cout << ' ' << c[i];
		}
		else if (c[i] == 10)
		{
			gotoxy(hout, hangc, abs(i - lie));
			cout << c[i];
		}
		else if(c[i]==0)
		{
			gotoxy(hout, hangc - 2, abs(i - lie));
			cout << "    ";
		}
	}
	
	spd(speed);

}

/*数组换值*/
void move(int n, char qi, char zhong)
{
	int  i = 1, j = 1, k = 1;
	s++;

	if (a[9] > 0)
		i = 9;
	else
	{
		for (i = 0; i < 9; i++)
			if (a[i] == 0)
				break;
		i--;
	}
	if (b[9] > 0)
		j = 9;
	else
	{
		for (j = 0; j < 9; j++)
			if (b[j] == 0)
				break;
		j--;
	}
	if (c[9] > 0)
		k = 9;
	else
	{
		for (k = 0; k < 9; k++)
			if (c[k] == 0)
				break;
		k--;
	}
	switch (qi)
	{
		case'A':
			a[i] = 0;
			break;
		case'B':
			b[j] = 0;
			break;
		case'C':
			c[k] = 0;
			break;
	}

	if (a[0] == 0)
		i = 0;
	else
	{
		for (i = 9; i > 0; i--)
			if (a[i] != 0)
				break;
		i++;
	}
	if (b[0] == 0)
		j = 0;
	else
	{
		for (j = 9; j > 0; j--)
			if (b[j] != 0)
				break;
		j++;
	}
	if (c[0] == 0)
		k = 0;
	else
	{
		for (k = 9; k > 0; k--)
			if (c[k] != 0)
				break;
		k++;
	}
	switch (zhong)
	{
		case'A':
			a[i] = n;
			break;
		case'B':
			b[j] = n;
			break;
		case'C':
			c[k] = n;
			break;
	}
	print();

}

/*递归移动*/
void han(int n, char q, char z, char f)
{
	if (n == 1)
		move(n, q, z);
	else
	{
		han(n - 1, q, f, z);
		move(n, q, z);
		han(n - 1, f, z, q);
	}
}

/*开始-输入-输出-结束*/
int main()
{
	system("cls");
	system("mode con cols=120 lines=30"); // cols 为列 即宽 lines 为行 即高

										  //cout << "0         1         2         3         4         5         6         7         8         9         ";
										  //cout << "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	int n, num;
	cout << "请输入层数(1-10) ";
	cin >> n;
	while (n < 1 || n>10)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入层数(1-10) ";
		cin >> n;
	}
	cout << "请输入起点(A-C) ";
	cin >> qidian;
	while (qidian != 65 && qidian != 97 && qidian != 66 && qidian != 98 && qidian != 67 && qidian != 99)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入起点(A-C) ";
		cin >> qidian;
	}
	cout << "请输入终点(A-C) ";
	cin >> zhongdian;
	while (zhongdian != 65 && zhongdian != 97 && zhongdian != 66 && zhongdian != 98 && zhongdian != 67 && zhongdian != 99)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入终点(A-C) ";
		cin >> zhongdian;
	}
	cout << "请确定速度（0为按回车显示，1--5速度递增）";
	cin >> speed;
	while (speed < 0 || speed>5)
	{
		cout << "输入错误";
		cout << endl;
		cout << "请确定速度（0为按回车显示，1--5速度递增）";
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

	if (qidian * zhongdian == 4290)
		fuzhu = 'C';
	else if (qidian * zhongdian == 4355)
		fuzhu = 'B';
	else if (qidian * zhongdian == 4422)
		fuzhu = 'A';

	int i;
	num = n;
	switch (qidian)
	{
		case 'A':
			for (i = 0; i <= 9; i++)
			{
				if (num >= 0)
				{
					a[i] = num;
					num--;
				}
				else
					a[i] = 0;
			}
			break;
		case 'B':
			for (i = 0; i <= 9; i++)
			{
				if (num >= 0)
				{
					b[i] = num;
					num--;
				}
				else
					b[i] = 0;
			}
			break;
		case 'C':
			for (i = 0; i <= 9; i++)
			{
				if (num >= 0)
				{
					c[i] = num;
					num--;
				}
				else
					c[i] = 0;
			}
			break;
	}

	cout << endl;
	cout<<endl<<"---------如右图所示---------"<<endl;
	
	gotoxy(hout, 56, lie + 1);
	cout << "===================================================" << endl;
	cout << "                                                               A                 B                 C";
	print();
	
	spd(speed);

	han(n, qidian, zhongdian, fuzhu);

	gotoxy(hout, 0, lie+10);
	cout << endl;

	return 0;
}