#include<iostream>
using namespace std;

int main()
{
	double x, y;
	int h;
	cout << "请依次输入横、纵坐标： ";
	cin >> x >> y;
	if (x*y==0)
		h = 0;
	else
	{
		if (x > 0 && y > 0 && x + y <= 3)
			h = 1;
		else if (x < 0 && y > 0 && y - x <= 3)
			h = 2;
		else if (x < 0 && y < 0 && x + y >= -3)
			h = 3;
		else if (x > 0 && y < 0 && y - x >= -3)
			h = 4;
		else
			h = 0;
	}
	cout << "该点处高度 h=" << h;
	cout << endl;
	return 0;
}