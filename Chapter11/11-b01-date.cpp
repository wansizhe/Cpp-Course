#include <iostream>
#include<iomanip>
#include "11-b1-date.h"
using namespace std;

Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}
Date::Date(int n)
{
	year = 1900;
	month = 1;
	day = 1;
	while (n > 73049)
		n -= 73049;
	if (n > 1 && n<73049)
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
			if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
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
	else if (n == 73049)
	{
		year = 2099;
		month = 12;
		day = 31;
	}
}
Date::Date(int y, int m, int d)
{
	if (y < 1900 || y>2099)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (m < 1 || m>12)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d < 1)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 29 && run(y) && m == 2)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 28 && !run(y) && m == 2)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
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
	d += n - 1;
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
	return Date(d - n - 1);
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
void Date::dset(int y, int m, int d)
{
	if (y < 1900 || y>2099)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (m < 1 || m>12)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d < 1)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 29 && run(y) && m == 2)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 28 && !run(y) && m == 2)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	year = y;
	month = m;
	day = d;
}
void Date::dget(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}
void Date::dshow()
{
	cout << setw(4) << setfill('0') << year;
	cout << setw(1) << '-' << setw(2) << setfill('0') << month;
	cout << setw(1) << '-' << setw(2) << setfill('0') << day;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
Date operator+(int n, Date& d)
{
	return (d + n);
}
ostream& operator << (ostream&out, Date& a)
{
	out << setw(4) << setfill('0') << a.year;
	out << setw(1) << '-' << setw(2) << setfill('0') << a.month;
	out << setw(1) << '-' << setw(2) << setfill('0') << a.day;
	return out;
}
istream& operator >> (istream&in, Date& a)
{
	int y, m, d;
	in >> y >> m >> d;
	if (y < 1900 || y>2099)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (m < 1 || m>12)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d < 1)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 29 && run(y) && m == 2)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	if (d > 28 && !run(y) && m == 2)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	a.year = y;
	a.month = m;
	a.day = d;
	return in;
}
bool operator==(Date&a, Date&b)
{
	if (a.year != b.year)
		return false;
	if (a.month != b.month)
		return false;
	if (a.day != b.day)
		return false;
	return true;
}
bool operator!=(Date&a, Date&b)
{
	if (a.year != b.year)
		return true;
	if (a.month != b.month)
		return true;
	if (a.day != b.day)
		return true;
	return false;
}
bool operator<=(Date&a, Date&b)
{
	if (a.year > b.year)
		return false;
	else if (a.year < b.year)
		return true;
	else
	{
		if (a.month > b.month)
			return false;
		else if (a.month < b.month)
			return true;
		else
		{
			if (a.day > b.day)
				return false;
			else 
				return true;
		}
	}
}
bool operator>=(Date&a, Date&b)
{
	if (a.year < b.year)
		return false;
	else if (a.year > b.year)
		return true;
	else
	{
		if (a.month < b.month)
			return false;
		else if (a.month > b.month)
			return true;
		else
		{
			if (a.day < b.day)
				return false;
			else
				return true;
		}
	}
}
bool operator>(Date&a, Date&b)
{
	if (a.year > b.year)
		return true;
	else if (a.year < b.year)
		return false;
	else
	{
		if (a.month > b.month)
			return true;
		else if (a.month < b.month)
			return false;
		else
		{
			if (a.day > b.day)
				return true;
			else
				return false;
		}
	}
}
bool operator<(Date&a, Date&b)
{
	if (a.year < b.year)
		return true;
	else if (a.year > b.year)
		return false;
	else
	{
		if (a.month < b.month)
			return true;
		else if (a.month > b.month)
			return false;
		else
		{
			if (a.day < b.day)
				return true;
			else
				return false;
		}
	}
}
bool run(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		return true;
	else
		return false;
}
