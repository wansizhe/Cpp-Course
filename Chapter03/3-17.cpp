#include<iostream>
using namespace std;

int main()
{
	int a, n, sum = 0, i = 1, j = 1, b = 0;
	cout << "ÇëÒÀ´ÎÊäÈëa£¬n£º" << endl;
	cin >> a >> n;
	for (; i <= n; i++)
	{
		while (j <= i)
		{    
		    b = a + 10 * b;
            j++;
		}
		sum = sum + b;
	}
	cout << "sum=" << sum << endl;
	return 0;
}
		

