#include<iostream>
using namespace std;

class cuboid
{
private:
	double length;
	double width;
	double height;
public:
	void input()
	{
		cout << "�����볤��ߣ�";
		cin >> length >> width >> height;
	}
	double volume()
	{
		return length*width*height;
	}
	void output()
	{
		cout << "���Ϊ��" << volume() << endl;
	}
};

int main()
{
	cuboid c;
	c.input();
	c.output();
	return 0;
}