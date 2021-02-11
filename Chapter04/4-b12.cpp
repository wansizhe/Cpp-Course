#include<iostream>
using namespace std;

int zeller(int year, int month, int day)
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
	int y, m, d;
	cout << "请输入年份（1900-2100）、月份（1-12）和日期：";
	cin >> y >> m >> d;
	if (y < 1900 || y > 2100 || m < 1 || m > 12)
	{
		do
		{
			cout << "输入错误" << endl;
			cout << "请输入年份（1900-2100）、月份（1-12）和日期：";
			cin >> y >> m >> d;
		} while (y < 1900 || y>2100 || m < 1 || m>12);
	}
	if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 1 || d > 31))
	{
		do
		{
			cout << "输入错误" << endl;
			cout << "请输入年份（1900-2100）、月份（1-12）和日期：";
			cin >> y >> m >> d;
		} while ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 1 || d > 31));
	}
	if ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d > 30))
	{
		do
		{
			cout << "输入错误" << endl;
			cout << "请输入年份（1900-2100）、月份（1-12）和日期：";
			cin >> y >> m >> d;
		} while ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d > 30));
	}
	if (m == 2)
	{
		if (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && (d < 1 || d > 29))
		{
			do
			{
				cout << "输入错误" << endl;
				cout << "请输入年份（1900-2100）、月份（1-12）和日期：";
				cin >> y >> m >> d;
			} while (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && (d < 1 || d > 29));
		}
		if (!((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && (d < 1 || d > 28))
		{
			do
			{
				cout << "输入错误" << endl;
				cout << "请输入年份（1900-2100）、月份（1-12）和日期：";
				cin >> y >> m >> d;
			} while (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && (d < 1 || d > 29));
		}
	}

	cout << "星期";
	switch (zeller(y, m, d))
	{
	    case 0:
		    cout << "日";
		    break;
	    case 1:
		    cout << "一";
		    break;
	    case 2:
		    cout << "二";
		    break;
	    case 3:
		    cout << "三";
		    break;
	    case 4:
		    cout << "四";
		    break;
	    case 5:
		    cout << "五";
		    break;
	    default:
		    cout << "六";
		    break;
	}	
	cout << endl;
	
	return 0;
}