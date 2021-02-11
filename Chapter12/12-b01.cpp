#include<iostream>
using namespace std;

class integral
{
protected:
	double h;
	double l;
public:
	virtual double value() = 0;
};

class integral_sin:public integral
{
public:
	virtual double value()
	{
		double t, s = 0;
		t = h - l;
		t /= 10000;
		for (int i = 0; i<10000; i++)
			s += t*sin(l + i*t + t / 2);
		return s;
	}
	friend istream& operator>>(istream& in, integral_sin& s);
};

class integral_cos :public integral
{
public:
	virtual double value()
	{
		double t, s = 0;
		t = h - l;
		t /= 10000;
		for (int i = 0; i<10000; i++)
			s += t*cos(l + i*t + t / 2);
		return s;
	}
	friend istream& operator>>(istream& in, integral_cos& s);
};

class integral_exp :public integral
{
public:
	virtual double value()
	{
		double t, s = 0;
		t = h - l;
		t /= 10000;
		for (int i = 0; i<10000; i++)
			s += t*exp(l + i*t + t / 2);
		return s;
	}
	friend istream& operator>>(istream& in, integral_exp& s);
};

istream& operator>>(istream& in, integral_sin& s)
{
	in >> s.l >> s.h;
	return in;
}

istream& operator>>(istream& in, integral_cos& s)
{
	in >> s.l >> s.h;
	return in;
}

istream& operator>>(istream& in, integral_exp& s)
{
	in >> s.l >> s.h;
	return in;
}

int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;
	integral *p;

	cin >> s1;
	p = &s1;
	cout << p->value() << endl;

	cin >> s2;
	p = &s2;
	cout << p->value() << endl;

	cin >> s3;
	p = &s3;
	cout << p->value() << endl;

	return 0;
}