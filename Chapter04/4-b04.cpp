#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/* 不允许对本函数做任何修改
除本函数外，不允许任何函数中输出“零”-“玖”!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数 */


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
	z = z - 0.1 * k;
	l = int(z / 0.01);

	daxie(a, a != 0);
	if (a != 0)
		cout << "拾";

	daxie(b, a * b != 0);
	if(!(a==0 && b==0))
	    cout << "亿";

	daxie(c, (!(a == 0 && b == 0) && d != 0));
	if (c != 0)
		cout << "仟";

	daxie(d, (!(a == 0 && b == 0 && c == 0) && e != 0));
	if (d != 0)
		cout << "佰";

	daxie(e, (!(a == 0 && b == 0 && c == 0 && d == 0) && f != 0));
	if (e != 0)
		cout << "拾";

	daxie(f, 0);
	if(!(c == 0 && d == 0 && e == 0 && f == 0))
	cout << "万";

	daxie(g, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) && h != 0));
	if (g != 0)
		cout << "仟";

	daxie(h, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0) && i != 0));
	if (h != 0)
		cout << "佰";

	daxie(i, (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0) && j != 0));
    if (i != 0)
		cout << "拾";

	daxie(j, (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0) && (k == 0 && l == 0));
	if(!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0) || (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0))
	    cout << "圆";

	if (k == 0 && l == 0)
		cout << "整";
	else if (k != 0 && l == 0)
	{
		daxie(k, 0);
		cout << "角整";
	}
	else if (k !=0 && l != 0)
	{
		daxie(k, (l != 0));
		cout << "角";
	}
		
	daxie(l, 0);
	if (l != 0)
		cout << "分";
	
	cout << endl;
	
	return 0;
}

