#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//获得时钟频率
	QueryPerformanceCounter(&fc_begin);	//获得初始硬件定时器计数

										/* 此处是你的程序开始 */
	int a, b, c, t=0, a1, b1, c1, a2, b2, c2, a3, b3, c3;
	for (a = 123; a <= 987; a++)
	{
		a1 = a / 100;
		a2 = a % 100 / 10;
		a3 = a % 10;
		if (a1 != a2 && a1 != a3 && a2 != a3 && a2!=0 && a3!=0)
			for (b = 123; b <= 987; b++)
			{
				b1 = b / 100;
				b2 = b % 100 / 10;
				b3 = b % 10;
				if (b1 != b2 && b1 != b3 && b2 != b3 && b2!=0 && b3 != 0)
					for (c = 123; c <= 987; c++)
					{
						c1 = c / 100;
						c2 = c % 100 / 10;
						c3 = c % 10;
						if (c1 != c2 && c1 != c3 && c2 != c3 && c2!=0 && c3!=0 && c1 != a1 && c1 != a2 && c1 != a3 && c1 != b1 && c1 != b2 && c1 != b3 && c2 != a1 && c2 != a2 && c2 != a3 && c2 != b1 && c2 != b2 && c2 != b3 && c3 != a1 && c3 != a2 && c3 != a3 && c3 != b1 && c3 != b2 && c3 != b3 && b1 != a1 && b1 != a2 && b1 != a3 && b2 != a1 && b2 != a2 && b2 != a3 && b3 != a1 && b3 != a2 && b3 != a3)
						{
							if ((a + b + c == 1953) && (a <= b && b <= c))
							{
								cout << a << '+' << b << '+' << c << "=1953" << endl;
								t++;
							}
						}
					}
			}
	}
	cout << "total=" << t << endl;

										/* 此处是你的程序结束 */

	QueryPerformanceCounter(&fc_end);//获得终止硬件定时器计数
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "时钟频率：" << double(tick.QuadPart) / 1024 / 1024 << "GHz" << endl;
	cout << setprecision(0);
	cout << "时钟计数：" << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;
	cout << setprecision(6) << double(fc_end.QuadPart - fc_begin.QuadPart) / double(tick.QuadPart) << "秒" << endl;

	return 0;
}
