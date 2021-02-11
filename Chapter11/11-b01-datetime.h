#pragma once
#include <iostream>
#include "11-b1-date.h"
#include "11-b1-time.h"
using namespace std;

class DateTime :public Date, public Time
{
public:
	DateTime();
	DateTime(long long);
	DateTime(int, int, int,int,int,int);
	operator long long();
	DateTime operator+(long long);
	long long operator-(DateTime&);
	DateTime operator-(long long);
	DateTime& operator++();
	DateTime operator++(int);
	DateTime& operator--();
	DateTime operator--(int);
	void dtset(int, int, int,int,int,int);
	void dtget(int&, int&, int&, int&, int&, int&);
	void dtshow();
	//void std();
	bool datestd();
	friend DateTime operator+(int, DateTime&);
	friend ostream& operator << (ostream&out, DateTime& a);
	friend istream& operator >> (istream&in, DateTime& a);
	friend bool operator==(DateTime&a, DateTime&b);
	friend bool operator!=(DateTime&a, DateTime&b);
	friend bool operator<=(DateTime&a, DateTime&b);
	friend bool operator>=(DateTime&a, DateTime&b);
	friend bool operator>(DateTime&a, DateTime&b);
	friend bool operator<(DateTime&a, DateTime&b);
};


DateTime operator+(long long, DateTime&);
ostream& operator << (ostream&out, DateTime& a);
istream& operator >> (istream&in, DateTime& a);
bool operator==(DateTime&a, DateTime&b);
bool operator!=(DateTime&a, DateTime&b);
bool operator<=(DateTime&a, DateTime&b);
bool operator>=(DateTime&a, DateTime&b);
bool operator>(DateTime&a, DateTime&b);
bool operator<(DateTime&a, DateTime&b);
bool run(int y);
