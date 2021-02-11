#include<iostream>
using namespace std;

void calender(int y, int m, int w)
{
	int n = 0, d;
	cout << endl;
	cout << y << "年" << m << "月的月历为：";
	cout << endl << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六";
	cout << endl;
	while (n < (8 * w))
	{
		cout << " ";
		n++;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		for (d = 1; d <= 31; d++)
		{
			cout << "  ";
			if (d < 10)
				cout << " ";
			cout << d;
			cout << "    ";
			if (d % 7 == (7 - w)||d%7==0)
				cout << endl;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		for (d = 1; d <= 30; d++)
		{
			cout << "  ";
			if (d < 10)
				cout << " ";
			cout << d;
			cout << "    ";
			if (d % 7 == (7 - w)||d%7==0)
				cout << endl;
		}
	}
	else if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
	{
		for (d = 1; d <= 29; d++)
		{
			cout << "  ";
			if (d < 10)
				cout << " ";
			cout << d;
			cout << "    ";
			if (d % 7 == (7 - w))
				cout << endl;
		}
	}
	else
	{
		for (d = 1; d <= 28; d++)
		{
			cout << "  ";
			if (d < 10)
				cout << " ";
			cout << d;
			cout << "    ";
			if (d % 7 == (7 - w))
				cout << endl;
		}
	}
	cout << endl;
	cout << endl;
}

int zeller(int year, int month, int day=1)
{
	int w, c, y, m, d, week;
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
	c = year / 100 ;
	y = year % 100;
	d = day;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0)
	{
		for (; w < 0;)
			w += 7;
	}
	week = w % 7;
	return week;
}

int main()
{
	int y, m;
	cout << "请输入年份（2000-2030）和月份（1-12）：";
	cin >> y >> m;
	if (y < 1900 || y > 2100 || m < 1 || m > 12)
	{
		do
		{
			cout << "输入错误" << endl;
			cout << "请输入年份（2000-2030）和月份（1-12）：";
			cin >> y >> m;
		} while (y < 1900 || y > 2100 || m < 1 || m > 12);
	}

	calender(y, m, zeller(y, m));

	return 0;
}