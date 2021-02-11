#pragma once
#include <iostream>
using namespace std;

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
public:
	/* 根据需要定义所需的成员函数、友元函数等 */
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
	void set(int, int , int );
	void set(int, int);
	void set(int);
	void get(int&, int&, int&);
	void show();
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

/* 如果有其它全局函数需要声明，写于此处 */
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

/* 如果有需要的宏定义、只读全局变量等，写于此处 */

