#include <iostream>
#include "10-b2.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}
Date::Date(int n)
{
	year = 1900;
	month = 1;
	day = 1;
	if (n > 1&&n<73049)
	{
		int i = 0;
		while (i != n)
		{
			day++;
			if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 32)
			{
				month++;
				day = 1;
			}
			if ((month == 4 || month == 6 || month == 9 || month == 11 ) && day == 31)
			{
				month++;
				day = 1;
			}
			if (month == 12 && day == 32)
			{
				year++;
				month = 1;
				day = 1;
			}
			if (month == 2 && run(year) && day == 30)
			{
				month++;
				day = 1;
			}
			if (month == 2 && !run(year) && day == 29)
			{
				month++;
				day = 1;
			}
			i++;
		}
	}
	else if (n >= 73049)
	{
		year = 2099;
		month = 12;
		day = 31;
	}
}
Date::Date(int y, int m, int d)
{
	if (y < 1900 || y>2099)
		y = 2000;
	if (m < 1 || m>12)
		m = 1;
	if (d < 1)
		d = 1;
	if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
		d = 1;
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
		d = 1;
	if (d > 29 && run(y) && m == 2)
		d = 1;
	if (d > 28 && !run(y) && m == 2)
		d = 1;
	year = y;
	month = m;
	day = d;
}
Date::operator int()
{
	int y = 1900;
	int m = 1;
	int d = 1;
	int i = 0;
	for (; y < year; y++)
	{
		if (run(y))
			i += 366;
		else
			i += 365;
	}
	for (; m < month; m++)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			i += 31;
		else if (m == 4 || m == 6 || m == 9 || m == 11)
			i += 30;
		else if (m == 2 && run(y))
			i += 29;
		else if (m == 2 && !run(y))
			i += 28;
	}
	i += day;
	return i;
}
Date Date::operator+(int n)
{
	int d = int(*this);
	d += n-1;
	return Date(d);
}
int Date::operator-(Date& d)
{
	int d1 = int(*this), d2 = int(d);
	return (d1 - d2);
}
Date Date::operator-(int n)
{
	int d = int(*this);
	return Date(d - n-1);
}
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int)
{
	Date d = (*this);
	*this = *this + 1;
	return d;
}
Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}
Date Date::operator--(int)
{
	Date d = (*this);
	*this = *this - 1;
	return d;
}
void Date::set(int y, int m, int d)
{
	if (y == 0)
		y = year;
	if (m == 0)
		m = month;
	if (d == 0)
		d = day;
	if ((y < 1900 || y>2099)&&y!=0)
		y = 2000;
	if ((m < 1 || m>12)&&m!=0)
		m = 1;
	if (d < 1&&d!=0)
		d = 1;
	if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
		d = 1;
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
		d = 1;
	if (d > 29 && run(y) && m == 2)
		d = 1;
	if (d > 28 && !run(y) && m == 2)
		d = 1;
	
     year = y;
     month = m;
	 day = d;
}
void Date::set(int y, int m)
{
	if (y != 0)
		year = y;
	if (m != 0)
		month = m;
	day = 1;
}
void Date::set(int y)
{
	if (y != 0)
		year = y;
	month = 1;
	day = 1;
}
void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}
void Date::show()
{
	cout << year << "年" << month << "月" << day << "日";
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
Date operator+(int n, Date& d)
{
	return (d + n);
}
ostream& operator << (ostream&out, Date& a)
{
	out << a.year << "年" << a.month << "月" << a.day << "日";
	return out;
}
istream& operator >> (istream&in, Date& a)
{
	int y, m, d;
	in >> y>>m >> d;
	if (y < 1900 || y>2099)
		y = 2000;
	if (m < 1 || m>12)
		m = 1;
	if (d < 1)
		d = 1;
	if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
		d = 1;
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
		d = 1;
	if (d > 29 && run(y) && m == 2)
		d = 1;
	if (d > 28 && !run(y) && m == 2)
		d = 1;
	a.year = y;
	a.month = m;
	a.day = d;
	return in;
}
bool operator==(Date&a, Date&b)
{
	int d1 = a, d2 = b;
	if (d1 == d2)
		return true;
	else
		return false;
}
bool operator!=(Date&a, Date&b)
{
	int d1 = a, d2 = b;
	if (d1 != d2)
		return true;
	else
		return false;
}
bool operator<=(Date&a, Date&b)
{
	int d1 = a, d2 = b;
	if (d1 <= d2)
		return true;
	else
		return false;
}
bool operator>=(Date&a, Date&b)
{
	int d1 = a, d2 = b;
	if (d1 >= d2)
		return true;
	else
		return false;
}
bool operator>(Date&a, Date&b)
{
	int d1 = a, d2 = b;
	if (d1 > d2)
		return true;
	else
		return false;
}
bool operator<(Date&a, Date&b)
{
	int d1 = a, d2 = b;
	if (d1 < d2)
		return true;
	else
		return false;
}
bool run(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		return true;
	else
		return false;
}
