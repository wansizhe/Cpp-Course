#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

/*蔡勒公式计算每月第一天是星期几*/
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

/*打印头部*/
void head(int n)
{
	cout << "           " << setw(2) << setiosflags(ios::right)<<n << "月               " << "           " <<  setw(2) << setiosflags(ios::right) << n+1<< "月               " << "           " << setw(2) <<setiosflags(ios::right)<< n+2 << "月               " << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat   Sun Mon Tue Wed Thu Fri Sat   Sun Mon Tue Wed Thu Fri Sat   " << endl;
}

int main()
{
	system("mode con cols=100 lines=45"); // cols 为列 即宽 lines 为行 即高
	
	int y,d;
	cout << "请输入年份（1900-2100）：";
	cin >> y;

	int dates[13][6][7] = { 0 };

	/*赋日期*/
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
				for (int k = zeller(y, i); k <= 6; k++)
				{
					dates[i][j][k] = d;
					d++;
				}
		    if(j != 0)
				for (int k = 0; k <= 6; k++)
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

	/*输出*/
	cout << y << "年日历" << endl;
	int n ;
	for (n = 1; n <= 10; n += 3)
	{
		int n0 = n + 2;
		head(n);
		for (int j = 0; j <= 5; j++)
			for (int k = 0; k <= 6; k++)
			{
				if (dates[n][j][k] != 0)
				{
					cout << setw(3) << resetiosflags(ios::right) << setiosflags(ios::left) << dates[n][j][k] << " ";
					Sleep(24);
				}
				else
					cout << "    ";

				if (k == 6)
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
		cout << endl;
	}
	
	cout << endl;
	return 0;
}