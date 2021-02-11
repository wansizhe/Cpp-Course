#include<iostream>
using namespace std;

struct date
{
	int year;
	int month;
	int day;
};

int runnian(int y)
{
	int r;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		r = 0;
	else
		r = 1;
	return r;
}

int days(int* y, int* m, int* d)
{
	int i, j, sum = 0;
	int t[13][32];

	for (i = 1; i <= 12; i++)
		for (j = 1; j <= 31; j++)
			t[i][j] = 1;
	t[2][31] = 0;
	t[2][30] = 0;
	t[4][31] = 0;
	t[6][31] = 0;
	t[9][31] = 0;
	t[11][31] = 0;
	if (runnian(*y))
		t[2][29] = 0;

	for (i = 1; i <= *m - 1; i++)
		for (j = 1; j <= 31; j++)
			sum += t[i][j];
	sum += *d;
	return sum;
}

int main()
{
	struct date d;

	cout << "请依次输入年、月、日：" << endl;
	cin >> d.year >> d.month >> d.day;
	if ((d.day > 31 || d.day < 1) && (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12))
		cout << "输入错误！" << endl;
	else if ((d.day > 30 || d.day < 1) && (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11))
		cout << "输入错误！" << endl;
	else if (d.month == 2)
	{
		if ((d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0)) && (d.day>29 || d.day < 1))
			cout << "输入错误！" << endl;
		else if (!(d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0)) && (d.day > 28 || d.day < 1))
			cout << "输入错误！" << endl;
		else
			cout << d.year << "年" << d.month << "月" << d.day << "日是当年的第 " << days(&d.year, &d.month, &d.day) << " 天。" << endl;
	}
	else
		cout << d.year << "年" << d.month << "月" << d.day << "日是当年的第 " << days(&d.year, &d.month, &d.day) << " 天。" << endl;

	return 0;
}