/*1552174 万思哲 计1*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int l = 100, n = 128, t = 0;
	int point = 0, end = argc - 1, p3,p2,p1;
	for (int i = 1; i < end; i++)
		for (int j = 0; argv[i][j] != '\0';j++)
			if (!((argv[i][j] >= '0'&&argv[i][j] <= '9') || argv[i][j] == '.' || argv[i][j] == '-' || argv[i][j] == 'l' || argv[i][j] == 'n' || argv[i][j] == 't'))
			{
				cout << "非法输入，含有要求之外的字符";
				return 0;
			}
	for (int i = 1; i < end; i++)
	{
		if (strcmp(argv[i], "-t") == 0)
			t = 1;
		else if (strcmp(argv[i], "-l") == 0)
		{
			if(i+1>=end)
			{
				cout << "-l 缺少参数";
				return 0;
			}
			for (int j = 0; argv[i + 1][j] != '\0'; j++)
			{
				if (argv[i + 1][j]<'0' || argv[i + 1][j]>'9')
				{
					cout << "-l 缺少参数";
					return 0;
				}
				if (i + 2<end&&j<(int)strlen(argv[i+2])&&argv[i + 2][j]>='0' && argv[i+2][j]<='9')
				{
					cout << "参数错误l";
					cout << argv[i + 2][j] << "   "<<j<<endl;
					return 0;
				}
			}
			if (atoi(argv[i + 1]) >= 64 && atoi(argv[i + 1]) <= 64000)
				l = atoi(argv[i + 1]);
		}
		else if (strcmp(argv[i], "-n") == 0)
		{
			if (i + 1 >= end)
			{
				cout << "-n 缺少参数";
				return 0;
			}
			for (int j = 0; argv[i + 1][j] != '\0'; j++)
			{
				if (argv[i + 1][j]<'0' || argv[i + 1][j]>'9')
				{
					cout << "-n 缺少参数";
					return 0;
				}
				if (i+2<end&&j<(int)strlen(argv[i + 2]) && argv[i + 2][j] >= '0' && argv[i + 2][j] <= '9')
				{
					cout << "参数错误n";
					return 0;
				}
			}
			if (atoi(argv[i + 1]) >= 1 && atoi(argv[i + 1]) <= 10000)
				n = atoi(argv[i + 1]);
		}
	}

	for (int i = 0; argv[end][i] != '\0'; i++)
	{
		if (!((argv[end][i] >= '0'&&argv[end][i] <= '9') || argv[end][i] == '.'))
		{
			cout << "IP地址错误1" ;
			return 0;
		}
		if (argv[end][i] == '.')
		{
			point++;
			if (point == 3)
				p3 = i;
			else if (point == 2)
				p2 = i;
			else if (point == 1)
				p1 = i;
		}
	}

	if (point != 3)
	{
		cout << "IP地址错误2";
		return 0;
	}
	if (argv[end][p3 + 1]<'0' || argv[end][p3 + 1]>'9')
	{
		cout << "IP地址错误3";
		return 0;
	}
	if (p3 - p2>4 || p2 - p1>4||p1>3||(int) strlen(argv[end])-p3-1>3)
	{
		cout << "IP地址错误4";
		return 0;
	}
	char ip1[4], ip2[4], ip3[4], ip4[4];
	strncpy(ip1, &argv[end][0], p1);
	strncpy(ip2, &argv[end][p1 + 1], p2 - p1 - 1);
	strncpy(ip3, &argv[end][p2 + 1], p3 - p2 - 1);
	strcpy(ip4, &argv[end][p3 + 1]);
	if (atoi(ip1) < 0 || atoi(ip1) > 255)
	{
		cout << "IP地址错误5";
		return 0;
	}
	if (atoi(ip2) < 0 || atoi(ip2) > 255)
	{
		cout << "IP地址错误6";
		return 0;
	}
	if (atoi(ip3) < 0 || atoi(ip3) > 255)
	{
		cout << "IP地址错误7";
		return 0;
	}
	if (atoi(ip4) < 0 || atoi(ip4) > 255)
	{
		cout << "IP地址错误8";
		return 0;
	}

	cout << "正确   l=" << l << "  n=" << n << "  t=" << t;
	return 0;
}