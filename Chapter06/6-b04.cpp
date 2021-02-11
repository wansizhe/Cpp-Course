#include<iostream>
using namespace std;

void huiwen(char *p)
{
	int num;
	bool is = true;
	for (num = 0; *(p + num); num++)
		;
	for (int i = 0; i <= num / 2; i++)
		if (*(p + i) != *(p + num - 1 - i))
		{
			is = false;
			break;
		}
	if (is)
		cout << "yes";
	else
		cout << "no";
	cout << endl;
}


int main()
{
	char str[100];
	cin >> str;
	huiwen(str);
	return 0;
}