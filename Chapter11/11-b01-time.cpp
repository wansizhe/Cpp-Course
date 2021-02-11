#include <iostream>
#include<iomanip>
#include "11-b1-time.h"
using namespace std;

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}
Time::Time(int n)
{
	hour = 0;
	minute = 0;
	second = 0;
	while (n > 86399)
		n -= 86399;
	if (n >= 1 && n<86399)
	{
		int i = 0;
		while (i != n)
		{
			second++;
			if (second == 60)
			{
				minute++;
				second = 0;
			}
			if (minute==60)
			{
				hour++;
			}
			i++;
		}
	}
	else if (n == 86399)
	{
		hour = 23;
		minute = 59;
		second = 59;
	}
}
Time::Time(int h, int m, int s)
{
	if (h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59)
	{
		h = 0;
		m = 0;
		s = 0;
	}
	hour = h;
	minute = m;
	second = s;
}
Time::operator int()
{
	int h = 0;
	int m = 0;
	int s = 0;
	int i = 0;
	for (;h < hour; h++)
	{
		i += 3600;
	}
	for (; m < minute; m++)
	{
		i += 60;
	}
	i += second;
	return i;
}
Time Time::operator+(int n)
{
	int t = int(*this);
	t += n - 1;
	return Time(t);
}
int Time::operator-(Time& d)
{
	int t1 = int(*this), t2 = int(d);
	return (t1 - t2);
}
Time Time::operator-(int n)
{
	int t = int(*this);
	return Time(t - n - 1);
}
Time& Time::operator++()
{
	*this = *this + 1;
	return *this;
}
Time Time::operator++(int)
{
	Time t = (*this);
	*this = *this + 1;
	return t;
}
Time& Time::operator--()
{
	*this = *this - 1;
	return *this;
}
Time Time::operator--(int)
{
	Time t = (*this);
	*this = *this - 1;
	return t;
}
void Time::tset(int h, int m, int s)
{
	if (h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59)
	{
		h = 0;
		m = 0;
		s = 0;
	}
	hour = h;
	minute = m;
	second = s;
}
void Time::tget(int& h, int& m, int& s)
{
	h = hour;
	m = minute;
	s = second;
}
void Time::tshow()
{
	cout << setw(2) << setfill('0') << hour;
	cout << setw(1) << ':' << setw(2) << setfill('0') << minute;
	cout << setw(1) << ':' << setw(2) << setfill('0') << second;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
Time operator+(int n, Time& t)
{
	return (t + n);
}
ostream& operator << (ostream&out, Time& a)
{
	out << setw(2) << setfill('0') << a.hour;
	out << setw(1) << ':' << setw(2) << setfill('0') << a.minute;
	out << setw(1) << ':' << setw(2) << setfill('0') << a.second;
	return out;
}
istream& operator >> (istream&in, Time& a)
{
	int h, m, s;
	in >> h >> m >> s;
	if (h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59)
	{
		h = 0;
		m = 0;
		s = 0;
	}
	a.hour = h;
	a.minute = m;
	a.second = s;
	return in;
}
bool operator==(Time&a, Time&b)
{
	if (a.hour != b.hour)
		return false;
	if (a.minute != b.minute)
		return false;
	if (a.second != b.second)
		return false;
	return true;
}
bool operator!=(Time&a, Time&b)
{
	if (a.hour != b.hour)
		return true;
	if (a.minute != b.minute)
		return true;
	if (a.second != b.second)
		return true;
	return false;
}
bool operator<=(Time&a, Time&b)
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
bool operator>=(Time&a, Time&b)
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
bool operator>(Time&a, Time&b)
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
bool operator<(Time&a, Time&b)
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
