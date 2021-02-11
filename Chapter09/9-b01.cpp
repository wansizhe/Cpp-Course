#include <iostream>
using namespace std;

class Days {
private:
	int year;
	int month;
	int day;
	int is_leap_year();  //�ж��Ƿ����꣬�ǣ�����1  /   �񣺷���0
public:
	int calc_days();     //�����ǵ���ĵڼ���
						 /* ������Բ���������Ҫ�����Ա�����Ķ��壬�������� */
	Days(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};

/* �˴��������Ա����������ʵ�� */
int Days::is_leap_year()
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return 1;
	else
		return 0;
}

int Days::calc_days()
{
	if (day > 31)
		return -1;
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return -1;
	if (is_leap_year() == 1 && month == 2 && day > 29)
		return -1;
	if (is_leap_year() == 0 && month == 2 && day > 28)
		return -1;
	
	int sum = 0;
	int date[13][32];
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 31; j++)
			date[i][j] = 1;
	date[2][31] = 0;
	date[2][30] = 0;
	date[4][31] = 0;
	date[6][31] = 0;
	date[9][31] = 0;
	date[11][31] = 0;
	if (is_leap_year() == 0)
		date[2][29] = 0;
	for (int i = 1; i <= month - 1; i++)
		for (int j = 1; j <= 31; j++)
			sum += date[i][j];
	sum += day;
	return sum;
}




/* main������׼�� */
int main()
{
	if (1) {
		Days d1(2012, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2012, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
