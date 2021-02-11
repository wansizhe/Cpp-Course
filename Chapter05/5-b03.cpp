#include<iostream>
using namespace std;

int runnian(int y)
{
	int r;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		r = 0;
	else
		r = 1;
	return r;
}

void date(int y, int m, int d)
{
	int i, j, sum=0;
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
	if (runnian(y))
		t[2][29] = 0;

	for (i = 1; i <= m - 1; i++)
		for (j = 1; j <= 31; j++)
			sum += t[i][j];
	sum += d;
	
	cout << y << "年" << m << "月" << d << "日是当年的第 " << sum << " 天。" << endl;
}

int main()
{
	int y, m, d;
	cout << "请依次输入年、月、日：" << endl;
	cin >> y >> m >> d;
	if ((d > 31 || d < 1) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
		cout << "输入错误！" << endl;
	else if ((d > 30 || d < 1) && (m == 4 || m == 6 || m == 9 || m == 11))
		cout << "输入错误！" << endl;
	else if (m == 2)
	{
		if (runnian(y) == 0 && (d > 29 || d < 1))
			cout << "输入错误！" << endl;
		else if (runnian(y) == 1 && (d > 28 || d < 1))
			cout << "输入错误！" << endl;
		else
			date(y, m, d);
	}
	else
		date(y, m, d);

	return 0;
}
