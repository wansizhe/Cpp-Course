#pragma once
#include <iostream>
using namespace std;

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������ */
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

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
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

/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */

