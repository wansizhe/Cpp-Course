#include<iostream>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	char str[4][30], temp[3][31];
	cout << "请输入三个字符串：" << endl;
	cin >> str[1] >> str[2] >> str[3];

	if (strcmp(str[1], str[2]) > 0)
	{
		strcpy_s(temp[2], str[1]);
		strcpy_s(temp[1], str[2]);
	}
	else
	{
		strcpy_s(temp[1], str[1]);
		strcpy_s(temp[2], str[2]);
	}

	cout << endl;
	cout << "三个字符串由小到大排序为：" << endl;
	if (strcmp(temp[1], str[3]) > 0)
		cout << str[3] << endl << temp[1] << endl << temp[2] << endl;
	else if(strcmp(str[3],temp[2])>0)
		cout << temp[1] << endl << temp[2] << endl << str[3] << endl;
	else
		cout << temp[1] << endl << str[3] << endl << temp[2] << endl;

	return 0;
}