#include<iostream>
using namespace std;

int main()
{
	int a[20], temp[20];
	int m, n;
	cout << "��������m��n��";
	cin >> m >> n;
	cout << "��������"<< n <<"��������";
	for (int i = 0; i < n; i++)
		cin >> *(a + i);
	for (int i = 0; i < n; i++)
		cout << *(a + i);
	cout << endl;
	int j = 0;
	for (int i = n - m; i < n; i++)
	{
		*(temp + j) = *(a + i);
		j++;
	}
	for (int i = n - m - 1; i >= 0; i--)
		*(a + i + m) = *(a + i);
	for (int i = 0; i < m; i++)
		*(a + i) = *(temp + i);
	for (int i = 0; i < n; i++)
		cout << *(a + i);
	cout << endl;
	return 0;
}