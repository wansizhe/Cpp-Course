#include<iostream>
using namespace std;

int main()
{
	int y, m, d, w, n = 0;
    cout << "��������ݣ�2000-2030�����·ݣ�1-12����";
	cin >> y >> m;
	if (y < 2000 || y > 2030 || m < 1 || m > 12)
	{
		do
		{
			cout << "�������" << endl;
			cout << "��������ݣ�2000-2030�����·ݣ�1-12����";
			cin >> y >> m;
		} 
		while (y < 2000 || y > 2030 || m < 1 || m > 12);
	}
	cout << "������" << y << "��" << m << "��1�յ����ڣ�0-6��ʾ������-��������";
	cin >> w;
	if (w < 0 || w > 6)
	{
		do
		{
			cout << "�������" << endl;
			cout << "������" << y << "��" << m << "��1�յ����ڣ�0-6��ʾ������-��������";
			cin >> w;
		} 
		while (w < 0 || w > 6);
	}
	cout << endl;
	cout << y << "��" << m << "�µ�����Ϊ��";
	cout << endl << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������";
	cout << endl;
	while (n < (8 * w ))
	{
		cout << " ";
		n++;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		for (d = 1; d <= 31; d++)
		{
			cout << "  ";
			if (d < 10)
				cout << " ";
			cout << d;
			cout << "    ";
			if (d % 7 == (7 - w))
				cout << endl;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11 )
	{
		for (d = 1; d <= 30; d++)
		{
			cout << "  ";
			if (d < 10)
				cout << " ";
			cout << d;
			cout << "    ";
			if (d % 7 == (7 - w))
				cout << endl;
		}
	}
    else if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
	{
		for (d = 1; d <= 29; d++)
		{
			cout << "  ";
			if (d < 10)
				cout << " ";
			cout << d;
			cout << "    ";
			if (d % 7 == (7 - w))
				cout << endl;
		}
	}
	else 
	{
		for (d = 1; d <= 28; d++)
		{
			cout << "  ";
			if (d < 10)
				cout << " ";
			cout << d;
			cout << "    ";
			if (d % 7 == (7 - w))
				cout << endl;
		}
	}
	cout << endl;
	cout << endl;
	return 0;
}