#include<iostream>
using namespace std;

int min(int a, int b, int c = 2147483647, int d = 2147483647)
{
	int t1, t2, t;
	if (a > b)
		t1 = b;
	else
		t1 = a;

	if (c > d)
		t2 = d;
	else
		t2 = c;

	if (t1 > t2)
		t = t2;
	else
		t = t1;
	
	return t;
}

int main()
{
	int n, a, b, c, d;
	cout << "请输入整数个数（2，3，4）和相应个数的整数" << endl;
	cin >> n;
	if (n == 2)
		cin >> a >> b;
	else if (n == 3)
		cin >> a >> b >> c;
	else if (n == 4)
		cin >> a >> b >> c >> d;
	else
		while (n != 2 && n != 3 && n != 4)
		{
			cout << "输入错误";
			cout << "请输入整数个数（2，3，4）和相应个数的整数" << endl;
			cin >> n;
			if (n == 2)
				cin >> a >> b;
			else if (n == 3)
				cin >> a >> b >> c;
			else if (n == 4)
				cin >> a >> b >> c >> d;
		}

	while ((n == 2 && (a <= 0 || b <= 0)) || (n == 3 && (a <= 0 || b <= 0 || c <= 0)) || (n == 4 && (a <= 0 || b <= 0 || c <= 0 || d <= 0)))
	{
		cout << "输入错误" << endl;
		cout << "请输入整数个数（2，3，4）和相应个数的整数" << endl;
		cin >> n;
		if (n == 2)
			cin >> a >> b;
		else if (n == 3)
			cin >> a >> b >> c;
		else if (n == 4)
			cin >> a >> b >> c >> d;
	}

	if (n == 2)
		cout << min(a, b);
	if (n == 3)
		cout << min(a, b, c);
	if (n == 4)
		cout << min(a, b, c, d);

	cout << endl;
	return 0;
}