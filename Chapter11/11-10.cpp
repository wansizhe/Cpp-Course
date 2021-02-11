#include<iostream>
#include<string>
using namespace std;

class teacher
{
public:
	teacher(string nam, int a, char t)
	{
		name = nam;
		num = a;
		sex = t;
	}
	void display()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" <<sex << endl;
	}
private:
	string name;
	int num;
	char sex;
};

class birthdate
{
public:
	birthdate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void display1()
	{
		cout << "birthday:" << year << '.' << month << '.' << day << endl;
	}
	birthdate& change(int dy, int dm, int dd)
	{
		if (dy != 0)
			year = dy;
		if (dm != 0)
			month = dm;
		if (dd != 0)
			day = dd;
		return *this;
	}
private:
	int year;
	int month;
	int day;
};

class professor :public teacher
{
public:
	professor(string nam, int a, char t, int y, int m, int d):teacher(nam,a,t),birthday(y,m,d){}
	void show()
	{
		display();
		birthday.display1();
	}
	professor& pchange(int dy, int dm, int dd)
	{
		birthday.change(dy, dm, dd);
		return *this;
	}
private:
	birthdate birthday;
};

int main()
{
	professor prof1("Dumbledore", 1234567, 'M', 1881, 1,1);
	prof1.show();
	cout << endl;
	int y = 0, m = 0, d = 0;
	cin >> y >> m >> d;
	cout << endl;
	prof1.pchange(y, m, d);
	prof1.show();
	return 0;
}
//"Dumbledore", 1234567, 'M', 1881, 1,1
//1997 6 26