#include<iostream>
#define _CRT_SECURE_NO_WARINGS
using namespace std;

char chistr[] = "零壹贰叁肆伍陆柒捌玖";
char result[256] = { 0 };
char unit[] = "拾佰仟万亿圆角分整";


void daxie(int num, int flag_of_zero)
{
	char temp[10] = { 0 };
	switch (num) 
	{
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
			{
				temp[0] = chistr[0];
				temp[1] = chistr[1];
			}
			break;
		case 1:
			temp[0] = chistr[2];
			temp[1] = chistr[3];
			break;
		case 2:
			temp[0] = chistr[4];
			temp[1] = chistr[5];
			break;
		case 3:
			temp[0] = chistr[6];
			temp[1] = chistr[7];
			break;
		case 4:
			temp[0] = chistr[8];
			temp[1] = chistr[9];
			break;
		case 5:
			temp[0] = chistr[10];
			temp[1] = chistr[11];
			break;
		case 6:
			temp[0] = chistr[12];
			temp[1] = chistr[13];
			break;
		case 7:
			temp[0] = chistr[14];
			temp[1] = chistr[15];
			break;
		case 8:
			temp[0] = chistr[16];
			temp[1] = chistr[17];
			break;
		case 9:
			temp[0] = chistr[18];
			temp[1] = chistr[19];
			break;
		default:
			cout << "error";
			break;
	}
	strcat_s(result, temp);
}

int main()
{
	double m = 1e-5;
	double y, z;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	cout << "请输入一个0.00～1000000000.00的数（小数点后最多两位）" << endl;
	cin >> y;
	y = y + m;
	a = int(y / 1000000000);
	y = y - 1.0 * 1000000000 * a;
	b = int(y / 100000000);
	y = y - 1.0 * 100000000 * b;
	c = int(y / 10000000);
	y = y - 1.0 * 10000000 * c;
	d = int(y / 1000000);
	y = y - 1.0 * 1000000 * d;
	e = int(y / 100000);
	y = y - 1.0 * 100000 * e;
	f = int(y / 10000);
	y = y - 1.0 * 10000 * f;
	g = int(y / 1000);
	y = y - 1.0 * 1000 * g;
	h = int(y / 100);
	y = y - 1.0 * 100 * h;
	i = int(y / 10);
	y = y - 1.0 * 10 * i;
	j = int(y / 1);
	z = y - j;

	k = int(z / 0.1);
	z = z - 0.1*k;
	l = int(z / 0.01);

	char temp[10] = { 0 };
	daxie(a, a != 0);
	if (a != 0)
	{
		temp[0] = unit[0];
		temp[1] = unit[1];
		strcat_s(result, temp);
	}

	daxie(b, a*b != 0);
	if (!(a == 0 && b == 0))
	{
		temp[0] = unit[8];
		temp[1] = unit[9];
		strcat_s(result, temp);
	}

	daxie(c, (!(a == 0 && b == 0) && d != 0));
	if (c != 0)
	{
		temp[0] = unit[4];
		temp[1] = unit[5];
		strcat_s(result, temp);
	}

	daxie(d, (!(a == 0 && b == 0 && c == 0) && e != 0));
	if (d != 0)
	{
		temp[0] = unit[2];
		temp[1] = unit[3];
		strcat_s(result, temp);
	}

	daxie(e, (!(a == 0 && b == 0 && c == 0 && d == 0) && f != 0));
	if (e != 0)
	{
		temp[0] = unit[0];
		temp[1] = unit[1];
		strcat_s(result, temp);
	}

	daxie(f, 0);
	if (!(c == 0 && d == 0 && e == 0 && f == 0))
	{
		temp[0] = unit[6];
		temp[1] = unit[7];
		strcat_s(result, temp);
	}

	daxie(g, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) && h != 0));
	if (g != 0)
	{
		temp[0] = unit[4];
		temp[1] = unit[5];
		strcat_s(result, temp);
	}

	daxie(h, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0) && i != 0));
	if (h != 0)
	{
		temp[0] = unit[2];
		temp[1] = unit[3];
		strcat_s(result, temp);
	}

	daxie(i, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0) && j != 0));
	if (i != 0)
	{
		temp[0] = unit[0];
		temp[1] = unit[1];
		strcat_s(result, temp);
	}

	daxie(j, (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0) && (k == 0 && l == 0));
	if (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0) || (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0))
	{
		temp[0] = unit[10];
		temp[1] = unit[11];
		strcat_s(result, temp);
	}

	if (k == 0 && l == 0)
	{
		temp[0] = unit[16];
		temp[1] = unit[17];
		strcat_s(result, temp);
	}
	else if (k != 0 && l == 0)
	{
		daxie(k, 0);
		temp[0] = unit[12];
		temp[1] = unit[13];
		temp[2] = unit[16];
		temp[3] = unit[17];
		strcat_s(result, temp);
	}
	else if (k != 0 && l != 0)
	{
		daxie(k, (l != 0));
		temp[0] = unit[12];
		temp[1] = unit[13];
		strcat_s(result, temp);
	}

	daxie(l, 0);
	if (l != 0)
	{
		temp[0] = unit[14];
		temp[1] = unit[15];
		strcat_s(result, temp);
	}
	
	cout << endl;
	cout << result;
	cout << endl;
	
	for (int q = 0; q <= 255; q++)
		result[q] = 0;

	return 0;
}
