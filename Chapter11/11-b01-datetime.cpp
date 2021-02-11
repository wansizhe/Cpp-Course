#include <iostream>
#include<iomanip>
#include "11-b1-datetime.h"
using namespace std;

DateTime::DateTime():Date(),Time(){}
DateTime::DateTime(long long n0)
{
	if (n0<0)
		n0 = long long(long long(73049) * long long(24) * long long(60) * long long(60)) - abs(n0);
	if (abs(n0) > long long(long long(73049) * long long(24) * long long(60) * long long(60)))
		n0 = n0 % long long(long long(73049) * long long(24) * long long(60) * long long(60));
	if (n0 >= 0)
	{
		long long n1 = n0 / (24 * 60 * 60), n2 = n0 % (24 * 60 * 60);
		if (n1 > 1 && n1<73049)
		{
			int i = 0;
			while (i != n1)
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
		else if (n1 == 73049)
		{
			year = 2099;
			month = 12;
			day = 31;
		}
		if (n2 >= 1 && n2<86399)
		{
			int i = 0;
			while (i != n2)
			{
				second++;
				if (second == 60)
				{
					minute++;
					second = 0;
				}
				if (minute == 60)
				{
					hour++;
					minute = 0;
				}
				i++;
			}
		}
		else if (n2 == 86399)
		{
			hour = 23;
			minute = 59;
			second = 59;
		}
	}

}
DateTime::DateTime(int y, int m, int d,int h,int mi,int s):Date(y,m,d),Time(h,mi,s){}
DateTime::operator long long()
{
	int y = 1900;
	int m = 1;
	int d = 1;
	long long i = 0;
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
	for (; d < day; d++)
		i++;
	i = i * 24 + hour;
	i = i * 60 + minute;
	i = i * 60 + second;
	return i;
}
DateTime DateTime::operator+(long long n)
{
	DateTime d = *this;
	for ( long long i = 1; i <= n; i++)
		d++;
	return d;
}
long long DateTime::operator-(DateTime& d)
{
	return long long(*this) - long long(d);
}
DateTime DateTime::operator-(long long n)
{
	DateTime d = *this;
	for ( long long i = 1; i <= n; i++)
		d--;
	return d;
}
DateTime& DateTime::operator++()
{
	second++;
	if (second >= 60)
	{
		minute = minute + second / 60;
		second = second % 60;
	}
	if (minute >= 60)
	{
		hour = hour + minute / 60;
		minute = minute % 60;
	}
	if (hour >= 24)
	{
		day = day + hour / 24;
		hour = hour % 24;
	}
	if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10))
	{
		day -= 31;
		month++;
	}
	if (month == 12 && day > 31)
	{
		day -= 31;
		month = 1;
		year++;
	}
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
	{
		day -= 30;
		month++;
	}
	if (day > 29 && run(year) && month == 2)
	{
		day -= 29;
		month++;
	}
	if (day > 28 && !run(year) && month == 2)
	{
		day -= 28;
		month++;
	}
	if (year > 2099)
		year = 1900;
	return *this;
}
DateTime DateTime::operator++(int)
{
	DateTime d = (*this);
	second++;
	if (second >= 60)
	{
		minute = minute + second / 60;
		second = second % 60;
	}
	if (minute >= 60)
	{
		hour = hour + minute / 60;
		minute = minute % 60;
	}
	if (hour >= 24)
	{
		day = day + hour / 24;
		hour = hour % 24;
	}
	if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10))
	{
		day -= 31;
		month++;
	}
	if (month == 12 && day > 31)
	{
		day -= 31;
		month = 1;
		year++;
	}
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
	{
		day -= 30;
		month++;
	}
	if (day > 29 && run(year) && month == 2)
	{
		day -= 29;
		month++;
	}
	if (day > 28 && !run(year) && month == 2)
	{
		day -= 28;
		month++;
	}
	if (year > 2099)
		year = 1900;
	return d;
}
DateTime& DateTime::operator--()
{
	second--;
	if (second < 0)
	{
		minute--;
		second = 59;
	}
	if (minute < 0)
	{
		minute = 59;
		hour--;
	}
	if (hour <0)
	{
		day--;
		hour = 23;
	}
	if (day <1 && (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11))
	{
		day = 31;
		month--;
	}
	if (month == 1 && day <1)
	{
		day = 31;
		month = 12;
		year--;
	}
	if (day < 1 && (month == 5 || month == 7 || month == 10 || month == 12))
	{
		day = 30;
		month--;
	}
	if (day <1 && run(year) && month == 3)
	{
		day = 29;
		month--;
	}
	if (day <1 && !run(year) && month == 3)
	{
		day = 28;
		month--;
	}
	if (year < 1900)
		year = 2099;
	return *this;
}
DateTime DateTime::operator--(int)
{
	DateTime d = (*this);
	second--;
	if (second < 0)
	{
		minute--;
		second = 59;
	}
	if (minute < 0)
	{
		minute = 59;
		hour--;
	}
	if (hour <0)
	{
		day--;
		hour = 23;
	}
	if (day <1 && (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11))
	{
		day = 31;
		month--;
	}
	if (month == 1 && day <1)
	{
		day = 31;
		month = 12;
		year--;
	}
	if (day < 1 && (month == 5 || month == 7 || month == 10 || month == 12))
	{
		day = 30;
		month--;
	}
	if (day <1 && run(year) && month == 3)
	{
		day = 29;
		month--;
	}
	if (day <1 && !run(year) && month == 3)
	{
		day = 28;
		month--;
	}
	if (year < 1900)
		year = 2099;
	return d;
}
void DateTime::dtset(int y, int m, int d,int h,int mi,int s)
{
	dset(y, m, d);
	tset(h, mi, s);
}
void DateTime::dtget(int& y, int& m, int& d,int&h,int&mi,int& s)
{
	dget(y, m, d);
	tget(h, mi, s);
}
void DateTime::dtshow()
{
	dshow();
	cout << ' ';
	tshow();
}
/*void DateTime::std()
{
	if (second >= 60)
	{
		minute = minute + second / 60;
		second = second % 60;
	}
	if (minute >= 60)
	{
		hour = hour + minute / 60;
		minute = minute % 60;
	}
	if (hour >= 24)
	{
		day = day + hour / 24;
		hour = hour % 24;
	}
	while (!datestd())
	{
		if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10))
		{
			day -= 31;
			month++;
		}
		if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		{
			day -= 30;
			month++;
		}
		if (day > 31 && month == 12)
		{
			day -= 31;
			month=
		}
	}
}*/
bool DateTime::datestd()
{
	int y = year, m = month, d = day;
	if (y < 1900 || y>2099)
		return false;
	if (m < 1 || m>12)
		return false;
	if (d < 1)
		return false;
	if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
		return false;
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
		return false;
	if (d > 29 && run(y) && m == 2)
		return false;
	if (d > 28 && !run(y) && m == 2)
		return false;
	return true;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
DateTime operator+(long long n, DateTime& d)
{
	return (d + n);
}
ostream& operator << (ostream&out, DateTime& a)
{
	out << setw(4) << setfill('0') << a.year;
	out << setw(1) << '-' << setw(2) << setfill('0') << a.month;
	out << setw(1) << '-' << setw(2) << setfill('0') << a.day;
	out << ' ';
	out << setw(2) << setfill('0') << a.hour;
	out << setw(1) << ':' << setw(2) << setfill('0') << a.minute;
	out << setw(1) << ':' << setw(2) << setfill('0') << a.second;
	return out;
}
istream& operator >> (istream&in, DateTime& a)
{
	int y, m, d,h,mi,s;
	in >> y >> m >> d >> h >> mi >> s;
	a.dtset(y, m, d, h, mi, s);
	return in;
}
bool operator==(DateTime&a, DateTime&b)
{
	if (a.year != b.year)
		return false;
	if (a.month != b.month)
		return false;
	if (a.day != b.day)
		return false;
	if (a.hour != b.hour)
		return false;
	if (a.minute != b.minute)
		return false;
	if (a.second != b.second)
		return false;
	return true;
}
bool operator!=(DateTime&a, DateTime&b)
{
	if (a.year != b.year)
		return true;
	if (a.month != b.month)
		return true;
	if (a.day != b.day)
		return true;
	if (a.hour != b.hour)
		return true;
	if (a.minute != b.minute)
		return true;
	if (a.second != b.second)
		return true;
	return false;
}
bool operator<=(DateTime&a, DateTime&b)
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
			else if(a.day<b.day)
				return true;
			else
			{
				if (a.hour > b.hour)
					return false;
				else if (a.hour < b.hour)
					return true;
				else
				{
					if (a.minute  > b.minute)
						return false;
					else if (a.minute  < b.minute)
						return true;
					else
					{
						if (a.second > b.second)
							return false;
						else
							return true;
					}
				}
			}
		}
	}
}
bool operator>=(DateTime&a, DateTime&b)
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
			else if(a.day>b.day)
				return true;
			else
			{
				if (a.hour < b.hour)
					return false;
				else if (a.hour > b.hour)
					return true;
				else
				{
					if (a.minute  < b.minute)
						return false;
					else if (a.minute  > b.minute)
						return true;
					else
					{
						if (a.second < b.second)
							return false;
						else
							return true;
					}
				}
			}
		}
	}
}
bool operator>(DateTime&a, DateTime&b)
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
			else if(a.day<b.day)
				return false;
			else
			{
				if (a.hour> b.hour)
					return true;
				else if (a.hour < b.hour)
					return false;
				else
				{
					if (a.minute  > b.minute)
						return true;
					else if (a.minute  < b.minute)
						return false;
					else
					{
						if (a.second > b.second)
							return true;
						else
							return false;
					}
				}
			}
		}
	}
}
bool operator<(DateTime&a, DateTime&b)
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
			else if(a.day>b.day)
				return false;
			else
			{
				if (a.hour < b.hour)
					return true;
				else if (a.hour > b.hour)
					return false;
				else
				{
					if (a.minute  < b.minute)
						return true;
					else if (a.minute  > b.minute)
						return false;
					else
					{
						if (a.second < b.second)
							return true;
						else
							return false;
					}
				}
			}
		}
	}
}
