#include<iostream>
using namespace std;

struct date
{
	int year;
	int month;
	int day;
};

int main()
{
	struct date d;

	cout << "�����������ꡢ�¡��գ�" << endl;
	cin >> d.year >> d.month >> d.day;
	if ((d.day > 31 || d.day < 1) && (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12))
		cout << "�������" << endl;
	else if ((d.day > 30 || d.day < 1) && (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11))
		cout << "�������" << endl;
	else if (d.month == 2)
	{
		if ((d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0)) && (d.day>29 || d.day < 1))
			cout << "�������" << endl;
		else if (!(d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0)) && (d.day > 28 || d.day < 1))
			cout << "�������" << endl;
	    else
		{
			int i, j, sum = 0;
			int t[13][32];

			for (i = 1; i <= 12; i++)
				for (j = 1; j <= 31; j++)
					t[i][j] = 1;
			t[2][31] = 0;
			t[2][30] = 0;
			t[4][31] = 0;
			t[6][31] = 0;
			t[9][31] = 0;
			t[11][31] = 0;
			if (!(d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0)))
				t[2][29] = 0;

			for (i = 1; i <= d.month - 1; i++)
				for (j = 1; j <= 31; j++)
					sum += t[i][j];
			sum += d.day;

			cout << d.year << "��" << d.month << "��" << d.day << "���ǵ���ĵ� " << sum << " �졣" << endl;
		}
	}
	else
	{
		int i, j, sum = 0;
		int t[13][32];

		for (i = 1; i <= 12; i++)
			for (j = 1; j <= 31; j++)
				t[i][j] = 1;
		t[2][31] = 0;
		t[2][30] = 0;
		t[4][31] = 0;
		t[6][31] = 0;
		t[9][31] = 0;
		t[11][31] = 0;
		if (!(d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0)))
			t[2][29] = 0;

		for (i = 1; i <= d.month - 1; i++)
			for (j = 1; j <= 31; j++)
				sum += t[i][j];
		sum += d.day;

		cout << d.year << "��" << d.month << "��" << d.day << "���ǵ���ĵ� " << sum << " �졣" << endl;
	}

	return 0;
}