#include<iostream>
using namespace std;

void average_1(double (*p)[6])
{
	double a1=0;
	for (int i = 0; i <= 3; i++)
		a1 += *(*(p + i) + 1);
	a1 /= 4;
	cout << "��1�ſε�ƽ���ɼ�:" << a1;
}

void  search_low(double (*p)[6])
{
	cout << "�������Ͽγ̲�����ѧ����" << endl;
	for (int i = 0; i < 4; i++)
	{
		int n = 0;
		for (int j = 1; j < 6; j++)
			if (*(*(p + i) + j) < 60)
				n++;
		if (n > 2)
			for (int j = 0; j < 6; j++)
				cout << (*(*(p + i) + j)) << ' ';
		cout << endl;
	}
}

void  search_high(double (*p)[6])
{
	cout << "ƽ����90���ϻ�ȫ��85����ѧ����" ;
	for (int i = 0; i <= 3; i++)
	{
		int n = 0;
		double t = 0;
		for (int j = 1; j <= 5; j++)
		{
			t += *(*(p + i) + j);
			if (*(*(p + i) + j) > 85)
				n++;
		}
		if (t / 4 > 90 || n == 5)
			for (int j = 0; j < 6; j++)
				cout << *(*(p + i) + j) << ' ';
		cout << endl;
	}
}

int main()
{
	double all[4][6];
	cout << "���������ĸ�ѧ����ѧ�ź����ſγɼ�" << endl;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			cin >> *(*(all + i) + j);
	cout << endl;
	average_1(all);
	cout << endl<<endl;
	search_low(all);
	cout << endl;
	search_high(all);
	cout << endl;

	return 0;
}