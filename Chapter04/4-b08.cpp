#include<iostream>
using namespace std;

int max(int a, int b)
{
	int t;
	if (a < b)
		t = b;
	else
		t = a;
	return t;
}

int max(int a, int b, int c)
{
	int t;
	if (max(a, b) < c)
		t = c;
	else
		t = max(a, b);
	return t;
}

int max(int a, int b, int c,int d)
{
	int t;
	if (max(a, b, c) < d)
		t = d;
	else
		t = max(a, b, c);
	return t;
}

int main()
{
	int n, a, b, c, d;
	cout << "����������������2��3��4������Ӧ����������" << endl;
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
			cout << "�������";
			cout << "����������������2��3��4������Ӧ����������" << endl;
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
		cout << "�������" << endl;
		cout << "����������������2��3��4������Ӧ����������" << endl;
		cin >> n;
		if (n == 2)
			cin >> a >> b;
		else if (n == 3)
			cin >> a >> b >> c;
		else if (n == 4)
			cin >> a >> b >> c >> d;
	}
	
	if (n == 2)
		cout << max(a, b);
	if (n == 3)
		cout << max(a, b, c);
	if (n == 4)
		cout << max(a, b, c, d);
	
	cout << endl;
	return 0;
}