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
		cout << "请输入长宽高：";
		cin >> length >> width >> height;
	}
	double volume()
	{
		return length*width*height;
	}
	void output()
	{
		cout << "体积为：" << volume() << endl;
	}
};

int main()
{
	cuboid c;
	c.input();
	c.output();
	return 0;
}