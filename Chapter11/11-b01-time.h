#pragma once
#include <iostream>
using namespace std;

class Time {
protected:
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(int);
	Time(int, int, int);
	operator int();
	Time operator+(int);
	int operator-(Time&);
	Time operator-(int);
	Time& operator++();
	Time operator++(int);
	Time& operator--();
	Time operator--(int);
	void tset(int, int, int);
	void tget(int&, int&, int&);
	void tshow();
	friend Time operator+(int, Time&);
	friend ostream& operator << (ostream&out, Time& a);
	friend istream& operator >> (istream&in, Time& a);
	friend bool operator==(Time&a, Time&b);
	friend bool operator!=(Time&a, Time&b);
	friend bool operator<=(Time&a, Time&b);
	friend bool operator>=(Time&a, Time&b);
	friend bool operator>(Time&a, Time&b);
	friend bool operator<(Time&a, Time&b);
};

Time operator+(int, Time&);
ostream& operator << (ostream&out, Time& a);
istream& operator >> (istream&in, Time& a);
bool operator==(Time&a, Time&b);
bool operator!=(Time&a, Time&b);
bool operator<=(Time&a, Time&b);
bool operator>=(Time&a, Time&b);
bool operator>(Time&a, Time&b);
bool operator<(Time&a, Time&b);



