#include<iostream>
using namespace std;

void psout(int n)
{
	int x;
	if (n <= 9)
		cout << n << " ";
	else
	{
		x = n % 10;
		n /= 10;
		psout(n);
		cout << x<<" ";
	}
	return;
}

int main()
{
	int n;
	cout << "����������n��" << endl << "n=";
	cin >> n;
	cout << "����ֽ������" << endl;
	if (n < 0)
		cout << "- ";
	n = fabs(n);
	psout(n);
	cout << endl;
	return 0;
}