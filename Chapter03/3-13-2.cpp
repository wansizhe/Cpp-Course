#include<iostream>
using namespace std;

int main()
{
	int i;
	double k;
	cout << "????? i=";
	cin >> i;
	switch (i / 100000) 
	{
		case 0:
			k = 0.1 * i;
			break;
		case 1:
			k = 10000 + 0.075 * (i - 100000);
			break;
		case 2:
		case 3:
			k = 10000 + 7500 + 0.05 * (i - 200000);
			break;
		case 4:
		case 5:
			k = 10000 + 7500 + 100000 + 0.03 * (i - 400000);
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			k = 10000 + 7500 + 10000 + 6000 + 0.015 * (i - 600000);
			break;
		default:
			k = 10000 + 7500 + 10000 + 6000 + 6000 + 0.01 * (i - 1000000);
			break;
	}
	cout << "?? k=" << k << endl;
	return 0;
}