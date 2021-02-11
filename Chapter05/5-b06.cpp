#include<iostream>
#include<iomanip>
using namespace std;

char qidian, zhongdian, fuzhu;
int a[10], b[10], c[10];
unsigned int s = 0;

void print()
{
	int i;
	cout << "A:";
	for (i = 0; i <= 9; i++)
	{
		if (a[i] > 0)
			cout  << setw(2) << a[i];
		else
			cout << "  ";
	}

	cout << " B:";
	for (i = 0; i <= 9; i++)
	{
		if (b[i] > 0)
			cout << setw(2) << b[i];
		else
			cout << "  ";
	}

	cout << " C:";
	for (i = 0; i <= 9; i++)
	{
	    if (c[i] > 0)
			cout << setw(2) << c[i];
		else
			cout << "  ";
	}
	cout << endl;
}

void move(int n, char qi, char zhong)
{
	int  i = 1, j = 1, k = 1;
	s++;

	cout << "第" << setw(5) << s << "步:" << qi << " ------> " << zhong << " (" << n << ") ";

	if (a[9] > 0)
		i = 9;
	else
	{
		for (i = 0; i < 9; i++)
			if (a[i] == 0)
				break;
		i--;
	}
	if (b[9] > 0)
		j = 9;
	else
	{
		for (j = 0; j < 9; j++)
			if (b[j] == 0)
				break;
		j--;
	}
	if (c[9] > 0)
		k = 9;
	else
	{
		for (k = 0; k < 9; k++)
			if (c[k] == 0)
				break;
		k--;
	}
	switch (qi)
	{
	    case 'A':
		    a[i] = 0;
		    break;
	    case 'B':
			b[j] = 0;
		    break;
	    case 'C':
			c[k] = 0;
		    break;
	}
	
	if (a[0] == 0)
		i = 0;
	else
	{
		for (i = 9; i > 0; i--)
			if (a[i] != 0)
				break;
		i++;
	}
	if (b[0] == 0)
		j = 0;
	else
	{
		for (j = 9; j > 0; j--)
			if (b[j] != 0)
				break;
		j++;
	}
	if (c[0] == 0)
		k = 0;
	else
	{
		for (k = 9; k > 0; k--)
			if (c[k] != 0)
				break;
		k++;
	}
	switch (zhong)
	{
	    case 'A':
			a[i] = n;
		    break;
	    case 'B':
			b[j] = n;
			break;
	    case 'C':
			c[k] = n;
			break;
	}
	print();
}


void han(int n, char q, char z,char f)
{
	if (n == 1)
		move(n, q, z);
	else
	{
		han(n - 1, q, f,z);
		move(n,q,z);
		han(n - 1, f, z, q);
	}
}


int main()
{
	system("cls");
	system("mode con cols=100 lines=30"); // cols 为列 即宽 lines 为行 即高

	//cout << "0         1         2         3         4         5         6         7         8         9         ";
	//cout << "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";
	
	int n,num;
	cout << "请输入层数(1-10) ";
	cin >> n;
	while (n < 1 || n>10)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入层数(1-10) ";
		cin >> n;
	}
	cout << "请输入起点(A-C) ";
	cin >> qidian;
	while (qidian != 65 && qidian != 97 && qidian != 66 && qidian != 98 && qidian != 67 && qidian != 99)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入起点(A-C) ";
		cin >> qidian;
	}
	cout << "请输入终点(A-C) ";
	cin >> zhongdian;
	while (zhongdian != 65 && zhongdian != 97 && zhongdian != 66 && zhongdian != 98 && zhongdian != 67 && zhongdian != 99)
	{
		cout << "Input Error" << endl;
		cin.clear();
		cin.ignore();
		cout << "请输入终点(A-C) ";
		cin >> zhongdian;
	}

	if (qidian / 10 != 6)
		qidian -= 32;
	if (zhongdian / 10 != 6)
		zhongdian -= 32;

	if (qidian * zhongdian == 4290)
		fuzhu = 'C';
	else if (qidian * zhongdian == 4355)
		fuzhu = 'B';
	else if (qidian * zhongdian == 4422)
		fuzhu = 'A';

	int i;
	num = n;
	switch (qidian)
	{
	    case 'A':
		    for (i = 0; i <= 9; i++)
		    {
			    if (num >= 0)
			    {
				    a[i] = num;
				    num--;
		    	}
			    else
			        a[i] = 0;
		    }
		    break;
	    case 'B':
		    for (i = 0; i <= 9; i++)
		    {
			    if (num >= 0)
		    	{
			    	b[i] = num;
			    	num--;
			    }
			    else
				    b[i] = 0;
	    	}
		    break;
	    case 'C':
		    for (i = 0; i <= 9; i++)
		    {
			    if (num >= 0)
			    {
				    c[i] = num;
				    num--;
		    	}
			    else
				    c[i] = 0;
		    }
	    	break;
	}
	
	cout << "初     始:                ";
	print();
	
	han(n, qidian, zhongdian, fuzhu);

	cout << endl;

	return 0;
}