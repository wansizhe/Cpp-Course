#include<iostream>
using namespace std;

int main()
{
	int i, j, m, n;
	i = 8;
	j = 10;
	m = ++i + j++;
	n = (++i) + (++j) + m;
	cout << i << '\t' << j << '\t' << n << endl;
	return 0;/*将8+1赋给i，将9+10赋给m，将10+1赋给j，将9+1赋给i，将11+1赋给j，将10+12+19赋给n，即i=10，j=12，m=19，n=41，最终输出：i，水平制表，j，水平制表，n，换行*/
}