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
	return 0;/*��8+1����i����9+10����m����10+1����j����9+1����i����11+1����j����10+12+19����n����i=10��j=12��m=19��n=41�����������i��ˮƽ�Ʊ�j��ˮƽ�Ʊ�n������*/
}