#include<iostream>
using namespace std;

void nsout(int n)
{
	int x;
	if (n <= 9)
		cout << n << " ";
	else
	{
		x = n % 10;
		n /= 10;
		cout << x << " ";
		nsout(n);
	}
	return;
}

int main()
{
	int n;
	cout << "请输入整数n：" << endl << "n=";
	cin >> n;
	cout << "反序分解输出：" << endl;
	if (n < 0)
	{
		n = -n;
		nsout(n);
		cout << "- ";
	}
	else
		nsout(n);
	cout << endl;
	return 0;
}