#include<iostream>
using namespace std;

int main()
{
	char *month[13] = { "invalid", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int m;
	cout << "ÇëÊäÈëÔÂ·Ý£º";
	cin >> m;
	if (m >= 1 && m <= 12)
		cout << *(month + m);
	else
		cout << *month;
	cout << endl;
	return 0;
}
