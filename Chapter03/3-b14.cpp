#include<iostream>
using namespace std;

int main()
{
	int y, m, d, w, n = 0;
    cout << "请输入年份（2000-2030）和月份（1-12）：";
	cin >> y >> m;
	if (y < 2000 || y > 2030 || m < 1 || m > 12)
	{
		do
		{
			cout << "输入错误" << endl;
			cout << "请输入年份（2000-2030）和月份（1-12）：";
			cin >> y >> m;
		} 
		while (y < 2000 || y > 2030 || m < 1 || m > 12);
	}
	cout << "请输入" << y << "年" << m << "月1日的星期（0-6表示星期日-星期六）";
	cin >> w;
	if (w < 0 || w > 6)
	{
		do
		{
			cout << "输入错误" << endl;
			cout << "请输入" << y << "年" << m << "月1日的星期（0-6表示星期日-星期六）";
			cin >> w;
		} 
		while (w < 0 || w > 6);
	}
	cout << endl;
	cout << y << "年" << m << "月的月历为：";
	cout << endl << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六";
	cout << endl;
	while (n < (8 * w ))
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
			if (d % 7 == (7 - w))
				cout << endl;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11 )
	{
		for (d = 1; d <= 30; d++)
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
	return 0;
}