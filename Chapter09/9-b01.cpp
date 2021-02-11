#include <iostream>
using namespace std;

class Days {
private:
	int year;
	int month;
	int day;
	int is_leap_year();  //判断是否闰年，是：返回1  /   否：返回0
public:
	int calc_days();     //计算是当年的第几天
						 /* 下面可以补充其它需要的类成员函数的定义，数量不限 */
	Days(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};

/* 此处给出类成员函数的体外实现 */
int Days::is_leap_year()
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return 1;
	else
		return 0;
}

int Days::calc_days()
{
	if (day > 31)
		return -1;
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return -1;
	if (is_leap_year() == 1 && month == 2 && day > 29)
		return -1;
	if (is_leap_year() == 0 && month == 2 && day > 28)
		return -1;
	
	int sum = 0;
	int date[13][32];
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 31; j++)
			date[i][j] = 1;
	date[2][31] = 0;
	date[2][30] = 0;
	date[4][31] = 0;
	date[6][31] = 0;
	date[9][31] = 0;
	date[11][31] = 0;
	if (is_leap_year() == 0)
		date[2][29] = 0;
	for (int i = 1; i <= month - 1; i++)
		for (int j = 1; j <= 31; j++)
			sum += date[i][j];
	sum += day;
	return sum;
}




/* main函数不准动 */
int main()
{
	if (1) {
		Days d1(2012, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2012, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
