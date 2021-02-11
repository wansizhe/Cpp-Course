#include"97-b5.h"

/*填充固定信息*/
qrcode::qrcode(int v=1)
{
	if (v < 1)
		version = 1;
	else if (v>40)
		version = 40;
	else
		version = v;
	if (version >= 1 && version <= 9)
	{
		nm = 10;
		am = 9;
		bm8 = 8;
		km = 8;
	}
	else if(version>=10&&version<=26)
	{
		nm = 12;
		am = 11;
		bm8 = 16;
		km = 10;
	}
	else
	{
		nm = 14;
		am = 13;
		bm8 = 16;
		km = 12;
	}
	size = (version - 1) * 4 + 21;
	code = new int* [size+2];
	for (int i = 0; i < size + 2; i++)
	{
		code[i] = new int[size + 2];
		for (int j = 0; j < size + 2; j++)
			code[i][j] = 0;
	}

	for (int i = 1; i <= 7; i++)
		code[1][i] = 1;
	for (int i = 2; i <= 6; i++)
	{
		code[i][1] = 1;
		code[i][7] = 1;
	}
	for (int i = 1; i <= 7; i++)
		code[7][i] = 1;
	for (int i = 3; i <= 5; i++)
		for (int j = 3; j <= 5; j++)
			code[i][j] = 1;

	for (int i = size; i >= size - 6; i--)
	{
		code[i][1] = 1;
		code[i][7] = 1;
	}
	for (int i = 2; i <= 6; i++)
	{
		code[size - 6][i] = 1;
		code[size][i] = 1;
	}
	for (int i = size - 2; i >= size - 4; i--)
		for (int j = 3; j <= 5; j++)
			code[i][j] = 1;
	for (int i = size; i >= size - 6; i--)
	{
		code[1][i] = 1;
		code[7][i] = 1;
	}
	for (int i = 2; i <= 6; i++)
	{
		code[i][size - 6] = 1;
		code[i][size] = 1;
	}
	for (int i = size - 2; i >= size - 4; i--)
		for (int j = 3; j <= 5; j++)
			code[j][i] = 1;

	for (int i = size - 8; i <= size - 4; i++)
	{
		code[i][size - 8] = 1;
		code[i][size - 4] = 1;
	}
	for (int i = size - 7; i <= size - 5; i++)
	{
		code[size - 8][i] = 1;
		code[size - 4][i] = 1;
	}
	code[size - 6][size - 6] = 1;

	for (int i = 11; i <= size - 8; i += 2)
		code[7][i] = 1;
	for (int i = 11; i <= size - 8; i += 2)
		code[i][7] = 1;

	for (int i = 1; i <= 9; i++)
		code[9][i] = 1;
	code[9][4] = 0;
	code[3][9] = 1;
	code[7][9] = 1;
	code[8][9] = 1;
	for (int i = size; i >= size - 7; i--)
		code[i][9] = 1;
	code[size - 3][9] = 0;
	code[size - 8][1] = 1;
	code[size - 9][2] = 1;
	code[size - 10][1] = 1;
	code[9][size - 2] = 1;
	code[9][size - 6] = 1;
	code[9][size - 7] = 1;
}
qrcode::~qrcode()
{
	for (int i = 0; i < size + 2; i++)
		delete code[i];
	delete code;
}
/*打印*/
void qrcode::show(HANDLE hout)
{
	for (int i = 0; i < size + 2; i++)
	{
		for (int j = 0; j < size + 2; j++)
		{
			if (code[i][j] == 0)
			{
				setcolor(hout, 15, 15);
				cout << "  ";
			}
			else
			{
				setcolor(hout, 0, 0);
				cout << "  ";
			}
		}
		cout << endl;
	}
}
/*掩码*/
void qrcode::mask()
{
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
		{
			if ()
			{
				if (code[i][j] == 0)
					code[i][j] = 1;
				else
					code[i][j] = 0;
			}
		}
}
/*填充信息*/
void qrcode::fill(string s)
{
	/*从右下角到左上角，以一个4*2的竖着的矩形为单位，填充*/
}


/* 将光标移动到指定位置 */
void gotoxy(HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}
/* 设置指定的颜色

颜色的取值由背景色+前景色组成，各16种
fg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
bg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
最终的颜色为 背景色*16+前景色 */
void setcolor(HANDLE hout, const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(hout, bg_color * 16 + fg_color);
}
/*转为规定位数的二进制*/
string tobin(int t,int st)
{
	int i = 0;
	int x = t;
	string bin;
	char* s = new char[st];
	i = st-1;
	while (x != 0)
	{
		int y;
		y = x % 2;
		s[i] =char(y + 48);
		i--;
		x = x / 2;
	}
	while (i >= 0)
	{
		s[i] = '0';
		i--;
	}
	int k = 0;
	while (k <st )
	{
		bin[k] = s[i];
		k++;
	}
	delete s;
	return bin;
}
/*确定编码模式*/
int modal(string s)
{
	int m = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			if (m == 0 || m == 1)
				m = 1;
		}
		else if ((s[i] >= 'A'&&s[i] <= 'Z') || s[i] == '$' || s[i] == '%' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '.' || s[i] == ':'||s[i]==' ')
		{
			if (m == 0 || m == 1||m==2)
				m = 2;
		}
		else if (s[i] < 0)
		{
			if (m == 0 || m == 1 || m == 2 || m == 3)
				m = 3;
		}
	}
}
/*数字编码*/
string numcod(string s)
{
	int l = s.length();
	int x = l % 3;
	int y = l / 3;
	string str = "0001";
	str = str + tobin(l, 10);
	char* temp = new char[4];
	int i;
	for (i = 1; i <= y; i++)
	{
		temp[0] = s[3 * (i - 1)];
		temp[1] = s[3 * (i - 1) + 1];
		temp[2] = s[3 * (i - 1) + 2];
		temp[3] = '\0';
		str = str + tobin(atoi(temp), 10);
	}
	switch (x)
	{
	case 1:
		temp[0] = s[3 * (i - 1)];
		temp[1] = '\0';
		str = str + tobin(atoi(temp), 4);
		break;
	case 2:
		temp[0] = s[3 * (i - 1)];
		temp[1] = s[3 * (i - 1) + 1];
		temp[2] = '\0';
		str = str + tobin(atoi(temp), 7);
		break;
	}
	delete temp;
	return str;
}
/*字母数字字符编码*/
string letnumcod(string s)
{
	int temp[2];
	int l = s.length();
	string str = "0010";
	str = str + tobin(l, 9);
	int i;
	int x = l % 2, y = l / 2;
	for (int i = 1; i <= y; i++)
	{
		temp[0] = letnumtab(s[2*(i-1)]);
		temp[1] = letnumtab(s[2 * (i - 1) + 1]);
		str = str + tobin(temp[0] * 45 + temp[1], 9);
	}
	if (x != 0)
	{
		str = str + tobin(letnumtab(s[2 * (i - 1)]), 6);
	}
}
/*字母数字字符编码转化表*/
int letnumtab(char ch)
{
	if (ch >= '0' && ch <= '9')
		return int(ch - 48);
	else if (ch >= 'A'&&ch <= 'Z')
		return int(ch - 55);
	else
	{
		switch (ch)
		{
		case ' ':
			return 36;
		case '$':
			return 37;
		case '%':
			return 38;
		case '*':
			return 39;
		case '+':
			return 40;
		case '-':
			return 41;
		case '.':
			return 42;
		case '/':
			return 43;
		case ':':
			return 44;
		default:
			return -1;
		}
	}
}
/*汉字编码*/
string hanzicod(string s)
{
	string str = "11010001";
	int l = s.length() / 2;
	str = str + tobin(l, 8);
	for (int i = 1; i <= l; i++)
	{
		int a = int(s[2 * (i - 1)])&0xff;
		int b = int(s[2 * (i - 1) + 1])&0xff;
		a = a - 0xa6;
		a = a * 0x60;
		b = b - 0xa1;
		str = str + tobin(a + b, 13);
	}
	return str;
}
/*结束符与补齐符*/
string addcod(string s,int max)
{
	s = s + "0000";
	while (s.length() % 8 != 0)
	{
		s = s + "0";
	}
	while (s.length() >= max)
	{
		s += "1110110000010001";
	}
	if (s.length() > max)
	{
		s[max] = '\0';
	}
	return s;
}
/*纠错码*/
string errcod(string s)
{

}

