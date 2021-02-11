#pragma once
#include <iostream>
using namespace std;

class Date {
protected:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int);
	Date(int, int, int);
	operator int();
	Date operator+(int);
	int operator-(Date&);
	Date operator-(int);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	void dset(int, int, int);
	void dget(int&, int&, int&);
	void dshow();
	friend Date operator+(int, Date&);
	friend ostream& operator << (ostream&out, Date& a);
	friend istream& operator >> (istream&in, Date& a);
	friend bool operator==(Date&a, Date&b);
	friend bool operator!=(Date&a, Date&b);
	friend bool operator<=(Date&a, Date&b);
	friend bool operator>=(Date&a, Date&b);
	friend bool operator>(Date&a, Date&b);
	friend bool operator<(Date&a, Date&b);
};

Date operator+(int, Date&);
ostream& operator << (ostream&out, Date& a);
istream& operator >> (istream&in, Date& a);
bool operator==(Date&a, Date&b);
bool operator!=(Date&a, Date&b);
bool operator<=(Date&a, Date&b);
bool operator>=(Date&a, Date&b);
bool operator>(Date&a, Date&b);
bool operator<(Date&a, Date&b);
bool run(int y);


