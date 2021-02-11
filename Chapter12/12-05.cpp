#include<iostream>
using namespace std;

#define pi 3.1415926;
class shape
{
public:
	virtual double area() = 0;
};

class circle :public shape
{
protected:
	double r;
public:
	circle(double t)
	{
		r = t;
	}
	double area()
	{
		double s;
		s = r*r*pi;
		cout << "circle's area=" << s << endl;
		return s;
	}
};

class square :public shape
{
protected:
	double a;
public:
	square(double t)
	{
		a = t;
	}
	double area()
	{
		double s;
		s = a*a;
		cout << "square's area=" << s << endl;
		return s;
	}
};

class rectangle :public shape
{
protected:
	double a;
	double b;
public:
	rectangle(double t,double p)
	{
		a = t;
		b = p;
	}
	double area()
	{
		double s;
		s = a*b;
		cout << "rectangle's area=" << s << endl;
		return s;
	}
};

class trapezoid :public shape
{
protected:
	double a;
	double b;
	double h;
public:
	trapezoid(double t, double p,double q)
	{
		a = t;
		b = p;
		h = q;
	}
	double area()
	{
		double s;
		s = 0.5*(a + b)*h;
		cout << "trapezoid's area=" << s << endl;
		return s;
	}
};

class triangle :public shape
{
protected:
	double a;
	double b;
	double c;
public:
	triangle(double t, double p, double q)
	{
		a = t;
		b = p;
		c = q;
	}
	double area()
	{
		double s, p;
		p = 0.5*(a + b + c);
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << "triangle's area=" << s << endl;
		return s;
	}
};

int main()
{
	circle c1(2);
	square s1(10);
	rectangle r1(2.5,4);
	trapezoid t1(2.5,7.5,4);
	triangle t2(3,4,5);
	shape *s[5] = { &c1,&s1,&r1,&t1,&t2 };

	int i;
	for (i = 0; i < 5; i++)
		s[i]->area();

	return 0;
}