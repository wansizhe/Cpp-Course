#include<iostream>
using namespace std;
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
	
	switch (a) 
	{
	    case 1:
		    cout << "壹拾";
			break;
	    case 2:
		    cout << "贰拾";
			break;
	    case 3:
		    cout << "叁拾";
			break;
	    case 4:
		    cout << "肆拾";
			break;
	    case 5:
		    cout << "伍拾";
			break;
	    case 6:
		    cout << "陆拾";
			break;
	    case 7:
		    cout << "柒拾";
			break;
	    case 8:
		    cout << "捌拾";
			break;
	    case 9:
		    cout << "玖拾";
			break;
	}

	switch (b) 
	{
	    case 1:
		    cout << "壹亿";
			break;
	    case 2:
		    cout << "贰亿";
			break;
	    case 3:
		    cout << "叁亿";
			break;
		case 4:
		    cout << "肆亿";
			break;
	    case 5:
		    cout << "伍亿";
			break;
	    case 6:
		    cout << "陆亿";
			break;
	    case 7:
		    cout << "柒亿";
			break;
	    case 8:
		    cout << "捌亿";
			break;
	    case 9:
		    cout << "玖亿";
			break;
	    case 0:
		    if (a!=0)
			    cout << "亿";
			break;
	}

	switch (c) 
	{
	    case 1:
		    cout << "壹仟";
			break;
	    case 2:
		    cout << "贰仟";
			break;
	    case 3:
		    cout << "叁仟";
			break;
	    case 4:
		    cout << "肆仟";
			break;
	    case 5:
		    cout << "伍仟";
			break;
	    case 6:
		    cout << "陆仟";
			break;
	    case 7:
		    cout << "柒仟";
			break;
	    case 8:
		    cout << "捌仟";
			break;
	    case 9:
		    cout << "玖仟";
			break;
	    case 0:
			if (!(a == 0 && b == 0 ) && d != 0)
			    cout << "零";
			break;
	}

	switch (d) 
	{
	    case 1:
		    cout << "壹佰";
			break;
	    case 2:
		    cout << "贰佰";
			break;
	    case 3:
		    cout << "叁佰";
			break;
	    case 4:
		    cout << "肆佰";
			break;
	    case 5:
		    cout << "伍佰";
			break;
	    case 6:
		    cout << "陆佰";
			break;
	    case 7:
		    cout << "柒佰";
			break;
	    case 8:
		    cout << "捌佰";
			break;
	    case 9:
		    cout << "玖佰";
			break;
	    case 0:
			if (!(a == 0 && b == 0 && c == 0 ) && e != 0)
		        cout << "零";
			break;
	}

	switch (e) 
	{
	    case 1:
		    cout << "壹拾";
			break;
	    case 2:
		    cout << "贰拾";
			break;
	    case 3:
		    cout << "叁拾";
			break;
	    case 4:
		    cout << "肆拾";
			break;
	    case 5:
		    cout << "伍拾";
			break;
	    case 6:
		    cout << "陆拾";
			break;
	    case 7:
		    cout << "柒拾";
			break;
	    case 8:
		    cout << "捌拾";
			break;
	    case 9:
		    cout << "玖拾";
			break;
	    case 0:
			if (!(a == 0 && b == 0 && c == 0 && d == 0 ) && f != 0)
			    cout << "零";
			break;
	}

	switch (f) 
	{
	    case 1:
		    cout << "壹万";
			break;
	    case 2:
		    cout << "贰万";
			break;
	    case 3:
		    cout << "叁万";
			break;
	    case 4:
		    cout << "肆万";
			break;
	    case 5:
		    cout << "伍万";
			break;
	    case 6:
		    cout << "陆万";
			break;
	    case 7:
		    cout << "柒万";
			break;
	    case 8:
		    cout << "捌万";
			break;
	    case 9:
		    cout << "玖万";
			break;
	    case 0:
		    if (c != 0 || d != 0 || e != 0)
			    cout << "万";
			break;
	}

	switch (g) 
	{
	    case 1:
		    cout << "壹仟";
			break;
	    case 2:
		    cout << "贰仟";
			break;
	    case 3:
		    cout << "叁仟";
			break;
	    case 4:
		    cout << "肆仟";
			break;
	    case 5:
		    cout << "伍仟";
			break;
	    case 6:
		    cout << "陆仟";
			break;
	    case 7:
		    cout << "柒仟";
			break;
	    case 8:
		    cout << "捌仟";
			break;
	    case 9:
		    cout << "玖仟";
			break;
	    case 0:
		    if (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) && h != 0)
			    cout << "零";
			break;
	}

	switch (h) 
	{
	    case 1:
		    cout << "壹佰";
			break;
	    case 2:
		    cout << "贰佰";
			break;
	    case 3:
		    cout << "叁佰";
			break;
	    case 4:
		    cout << "肆佰";
			break;
    	case 5:
		    cout << "伍佰";
			break;
	    case 6:
		    cout << "陆佰";
			break;
	    case 7:
		    cout << "柒佰";
			break;
	    case 8:
		    cout << "捌佰";
			break;
	    case 9:
		    cout << "玖佰";
			break;
	    case 0:
		    if (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 ) && i != 0)
			    cout << "零";
			break;
	}

	switch (i) 
	{
	    case 1:
		    cout << "壹拾";
			break;
	    case 2:
		    cout << "贰拾";
			break;
	    case 3:
		    cout << "叁拾";
			break;
	    case 4:
		    cout << "肆拾";
			break;
	    case 5:
		    cout << "伍拾";
			break;
	    case 6:
		    cout << "陆拾";
			break;
	    case 7:
		    cout << "柒拾";
			break;
	    case 8:
		    cout << "捌拾";
			break;
	    case 9:
		    cout << "玖拾";
			break;
	    case 0:
			if (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 ) && j != 0)
			    cout << "零";
			break;
	}

	switch (j) 
	{
	    case 1:
		    cout << "壹圆";
			break;
	    case 2:
		    cout << "贰圆";
			break;
	    case 3:
		    cout << "叁圆";
			break;
	    case 4:
		    cout << "肆圆";
			break;
	    case 5:
		    cout << "伍圆";
			break;
	    case 6:
		    cout << "陆圆";
			break;
	    case 7:
		    cout << "柒圆";
			break;
	    case 8:
		    cout << "捌圆";
			break;
	    case 9:
			cout << "玖圆";
			break;
	    case 0:
			if (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0))
				cout << "圆";
			else if ((a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0) && (k == 0 && l == 0))
				cout << "零圆";
			break;
	}

	if (k == 0 && l == 0)
		cout << "整";
	else if (k != 0 && l == 0)
	    switch (k) 
		{
	        case 1:
		        cout << "壹角整";
				break;
	        case 2:
		        cout << "贰角整";
				break;
	        case 3:
		        cout << "叁角整";
				break;
	        case 4:
		        cout << "肆角整";
				break;
	        case 5:
		        cout << "伍角整";
				break;
	        case 6:
		        cout << "陆角整";
				break;
	        case 7:
		        cout << "柒角整";
				break;
	        case 8:
		        cout << "捌角整";
				break;
	        case 9:
		        cout << "玖角整";
				break;
		}
	else if (l != 0)
	{
		switch (k) 
		{
		    case 1:
			    cout << "壹角";
				break;
		    case 2:
			    cout << "贰角";
				break;
		    case 3:
			    cout << "叁角";
				break;
		    case 4:
			    cout << "肆角";
				break;
		    case 5:
			    cout << "伍角";
				break;
		    case 6:
			    cout << "陆角";
				break;
		    case 7:
		   	    cout << "柒角";
				break;
		    case 8:
			    cout << "捌角";
				break;
		    case 9:
			    cout << "玖角";
				break;
			case 0:
				if (l == 0)
					cout << "角";
		}
		switch (l) 
		{
		    case 1:
			    cout << "壹分";
				break;
		    case 2:
			    cout << "贰分";
				break;
		    case 3:
			    cout << "叁分";
				break;
		    case 4:
		     	cout << "肆分";
				break;
		    case 5:
			    cout << "伍分";
				break;
		    case 6:
			    cout << "陆分";
				break;
		    case 7:
			    cout << "柒分";
				break;
		    case 8:
			    cout << "捌分";
				break;
		    case 9:
			    cout << "玖分";
				break;
		}
    }
	cout << endl;
	return 0;
}

