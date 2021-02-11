#include<iostream>
using namespace std;

int main()
{
	double x, a, t;
	cout << "请输入被开方数a：";
	cin >> a;
	x = a;
	t = 0;
	while (fabs(x - t) >= 1e-5)
	{
		t = x;
		x = 0.5 * (x + a / x);
	}
	cout << "a^(1/2)=" << x;
	cout << endl;
	return 0;
}