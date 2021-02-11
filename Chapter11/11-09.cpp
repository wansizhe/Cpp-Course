#include<iostream>
#include<string>
using namespace std;

class teacher
{
protected:
	string name;
	int age;
	string sex;
	string addr;
	string tel;
	string title;
public:
	void display();
};
class cadre
{
protected:
	string name;
	int age;
	string sex;
	string addr;
	string tel;
	string post;
};
class teacher_cadre:public teacher,public cadre
{
	int wages;
public:
	teacher_cadre(string, int, string, string, string, string, string,int);
	void show();
};

void teacher::display()
{
	cout << "姓名 :" << name << endl;
	cout << "年龄 :" << age << endl;
	cout << "性别 :" << sex << endl;
	cout << "地址 :" << addr << endl;
	cout << "电话 :" << tel << endl;
}
teacher_cadre::teacher_cadre(string na, int ag, string se, string ad, string te, string ti, string po, int wa)
{
	teacher::name = na;
	cadre::name = na;
	teacher::age = ag;
	cadre::age = ag;
	teacher::sex = se;
	cadre::sex = se;
	teacher::addr = ad;
	cadre::addr = ad;
	teacher::tel = te;
	cadre::tel = te;
	title = ti;
	post = po;
	wages = wa;
}
void teacher_cadre::show()
{
	display();
	cout << "职称 :" << title << endl;
	cout << "职务 :" << post << endl;
	cout << "工资 :" << wages << endl;
}

int main()
{
	teacher_cadre one("Albus Dumbledore", 116, "Male", "Hogwarts", "123****4567", "Professor", "Headmaster",123456789);
	one.show();
	return 0;
}
//  "Albus Dumbledore", 116, "Male", "Hogwarts", "123****4567", "Professor", "Headmaster",123456789