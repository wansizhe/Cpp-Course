#include<iostream>
using namespace std;

void average_1(double(*p)[4])
{
	double a1 = 0;
	for (int j = 0; j <= 3; j++)
		a1 += *(*(p + 1) + j);
	a1 /= 4;
	cout << "��1�ſε�ƽ���ɼ�:" << a1;
}

void  search_low(double(*p)[4])
{
	cout << "�������Ͽγ̲�����ѧ����" ;
	for (int j = 0; j < 4; j++)
	{
		int n = 0;
		for (int i = 1; i < 6; i++)
			if (*(*(p + i) + j) < 60)
				n++;
		if (n > 2)
			for (int i = 0; i < 6; i++)
				cout << (*(*(p + i) + j)) << ' ';
		cout << endl;
	}
}

void  search_high(double(*p)[4])
{
	cout << "ƽ����90���ϻ�ȫ��85����ѧ����"<<endl;
	for (int j = 0; j <= 3; j++)
	{
		int n = 0;
		double t = 0;
		for (int i = 1; i <= 5; i++)
		{
			t += *(*(p + i) + j);
			if (*(*(p + i) + j) > 85)
				n++;
		}
		if (t / 4 > 90 || n == 5)
			for (int i = 0; i < 6; i++)
				cout << *(*(p + i) + j) << ' ';
		cout << endl;
	}
}

int main()
{
	double all[6][4];
	cout << "���������ĸ�ѧ����ѧ�ź����ſ��ĸ�ѧ���ĳɼ�" << endl;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 4; j++)
			cin >> *(*(all + i) + j);
	cout << endl;
	average_1(all);
	cout << endl << endl;
	search_low(all);
	cout << endl;
	search_high(all);
	cout << endl;

	return 0;
}