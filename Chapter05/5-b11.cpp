#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	char name[50][9], num[50][10], one[9];
	int n;
	cout << "请输入总人数：";
	cin >> n;
	
	/*输入学生信息*/
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "名学生的姓名和学号：";
		cin >> name[i] >> num[i];
	}
	cout << endl;

	/*查找学生*/
	cout << "请输入所要查找的学生姓名：";
	cin >> one;
	int k = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(one, name[i]) == 0)
		{
			k++;
			break;
		}
	}
	cout << endl;

	/*输出查找结果*/
	if (k == 0)
		cout << "查无此人！";
	else
		cout <<"姓名："<< setw(9) << setiosflags(ios::left) << name[i] << "学号：" << setw(10) << setiosflags(ios::left) << num[i];

	cout << endl;
	cout << endl;
	return 0;
}