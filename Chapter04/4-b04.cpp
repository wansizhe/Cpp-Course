#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/* ������Ա��������κ��޸�
���������⣬�������κκ�����������㡱-������!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//�˱��ʲô��˼������˼��
			cout << "��";
		break;
	case 1:
		cout << "Ҽ";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "��";
		break;
	case 5:
		cout << "��";
		break;
	case 6:
		cout << "½";
		break;
	case 7:
		cout << "��";
		break;
	case 8:
		cout << "��";
		break;
	case 9:
		cout << "��";
		break;
	default:
		cout << "error";
		break;
	}
}

/* �ɸ�����Ҫ�Զ����������� */


int main()
{
	double m = 1e-5;
	double y, z;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	cout << "������һ��0.00��1000000000.00������С����������λ��" << endl;
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
	z = z - 0.1 * k;
	l = int(z / 0.01);

	daxie(a, a != 0);
	if (a != 0)
		cout << "ʰ";

	daxie(b, a * b != 0);
	if(!(a==0 && b==0))
	    cout << "��";

	daxie(c, (!(a == 0 && b == 0) && d != 0));
	if (c != 0)
		cout << "Ǫ";

	daxie(d, (!(a == 0 && b == 0 && c == 0) && e != 0));
	if (d != 0)
		cout << "��";

	daxie(e, (!(a == 0 && b == 0 && c == 0 && d == 0) && f != 0));
	if (e != 0)
		cout << "ʰ";

	daxie(f, 0);
	if(!(c == 0 && d == 0 && e == 0 && f == 0))
	cout << "��";

	daxie(g, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) && h != 0));
	if (g != 0)
		cout << "Ǫ";

	daxie(h, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0) && i != 0));
	if (h != 0)
		cout << "��";

	daxie(i, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0) && j != 0));
    if (i != 0)
		cout << "ʰ";

	daxie(j, (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0) && (k == 0 && l == 0));
	if(!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0) || (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0))
	    cout << "Բ";

	if (k == 0 && l == 0)
		cout << "��";
	else if (k != 0 && l == 0)
	{
		daxie(k, 0);
		cout << "����";
	}
	else if (k !=0 && l != 0)
	{
		daxie(k, (l != 0));
		cout << "��";
	}
		
	daxie(l, 0);
	if (l != 0)
		cout << "��";
	
	cout << endl;
	
	return 0;
}

