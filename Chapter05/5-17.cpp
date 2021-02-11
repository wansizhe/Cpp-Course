#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "请输入学生姓名、学号和成绩：" << endl;
	char name[10][5], num[10][8];
	int  grade[10];
	
	for (int i = 0; i <= 9; i++)
	{
		cin >> name[i];
		cin >> num[i];
		cin >> grade[i];
	}

	cout << endl;
	cout << "不及格名单：" << endl;
	int i = 0;
	for (int k = 0; k <= 9; k++)
	{
		if (grade[k] < 60)
		{
			cout << setw(7) << name[k] << setw(10) << num[k] << setw(5) << grade[k] << endl;
			i++;
		}
	}
	if (i == 0)
		cout << "无" << endl;

	return 0;
}