#include<iostream>
#include<iomanip>
using namespace std;

void countup(char row1[], char row2[], char row3[])
{
	int n = 0, i;
	for (i = 0; i <= 80; i++)
	{
		if (row1[i] >= 65 && row1[i] <= 90)
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if (row2[i] >= 65 && row2[i] <= 90)
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if (row3[i] >= 65 && row3[i] <= 90)
			n++;
	}
	cout << "��д��ĸ�� " <<setw(3)<< n << "��" << endl;
}

void countlow(char row1[], char row2[], char row3[])
{
	int n = 0, i;
	for (i = 0; i <= 80; i++)
	{
		if (row1[i] >= 97 && row1[i] <= 122)
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if (row2[i] >= 97 && row2[i] <= 122)
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if (row3[i] >= 97 && row3[i] <= 122)
			n++;
	}
	cout << "Сд��ĸ�� " <<setw(3)<< n << "��" << endl;
}

void countnum(char row1[], char row2[], char row3[])
{
	int n = 0, i;
	for (i = 0; i <= 80; i++)
	{
		if (row1[i] >= 48 && row1[i] <= 57)
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if (row2[i] >= 48 && row2[i] <= 57)
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if (row3[i] >= 48 && row3[i] <= 57)
			n++;
	}
	cout << "��    �֣� " <<setw(3)<< n << "��" << endl;
}

void countspace(char row1[], char row2[], char row3[])
{
	int n = 0, i;
	for (i = 0; i <= 80; i++)
	{
		if (row1[i] ==32)
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if (row2[i] == 32)
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if (row3[i] == 32)
			n++;
	}
	cout << "��    �� " <<setw(3)<< n << "��" << endl;
}

void countelse(char row1[], char row2[], char row3[])
{
	int n = 0,i;
	for (i = 0; i <= 80; i++)
	{
		if ((row1[i] >= 97 && row1[i] <= 112) || (row1[i] >= 65 && row1[i] <= 90) || (row1[i] >= 48 && row1[i] <= 57) || row1[i] == 32)
			continue;
		else
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if ((row2[i] >= 97 && row2[i] <= 112) || (row2[i] >= 65 && row2[i] <= 90) || (row2[i] >= 48 && row2[i] <= 57) || row2[i] == 32)
			continue;
		else
			n++;
	}
	for (i = 0; i <= 80; i++)
	{
		if ((row3[i] >= 97 && row3[i] <= 112) || (row3[i] >= 65 && row3[i] <= 90) || (row3[i] >= 48 && row3[i] <= 57) || row3[i] == 32)
			continue;
		else
			n++;
	}
	cout << "��    ���� " << setw(3)<<n << "��" << endl;
}

int main()
{
	char row1[81], row2[81], row3[81];
	cout << "�����루���У�ÿ��80�ַ�����" << endl;
	gets_s(row1);
	gets_s(row2);
	gets_s(row3);

	cout << endl;
	cout << "ͳ�ƽ����" << endl;
	countup(row1, row2, row3);
	countlow(row1, row2, row3);
	countnum(row1, row2, row3);
	countspace(row1, row2, row3);
	countelse(row1, row2, row3);
	cout << endl;
	
	return 0;
}