#include<iostream>
using namespace std;

struct student
{
	int no;
	char name[9];
	float score[3];
	float ave;
};

void input(int *no, char name[],float *s1,float *s2,float *s3)
{
	cin >> *no;
	cin >> name;
	cin >> *s1 >> *s2 >> *s3;
}

float average(float s1, float s2, float s3)
{
	float a;
	a = (s1 + s2 + s3) / 3;
	return a;
}

void highest(student s[])
{
	float h[3];
	for (int i = 0; i <= 2; i++)
	{
		int k = 0;
		h[i] = s[0].score[i];
		for (int j = 0; j <= 9; j++)
		{
			if (h[i] < s[j].score[i])
			{
				h[i] = s[j].score[i];
				k = j;
			}
		}
		cout << "第"<<i+1<<"科获得最高分的同学：" << endl;
		cout << "学号：" << s[k].no << "   姓名：" << s[k].name << endl;
		cout << "1、" << s[k].score[0] << "   2、" << s[k].score[1] << "   3、" << s[k].score[2] << endl;
		cout << "平均分：" << s[k].ave << endl;
		cout << endl;
	}
}

int main()
{
	struct student s[10];
	 
	for (int i = 0; i <= 9; i++)
	{
		cout << "请输入第"<<i+1<<"个学生的信息" << endl;
		input(&s[i].no, s[i].name, &s[i].score[0], &s[i].score[1], &s[i].score[2]);
	}

	cout << endl << endl;
	cout << "======================================================================";
	cout << endl << endl;

	for (int i = 0; i <= 9; i++)
		s[i].ave = average(s[i].score[0], s[i].score[1], s[i].score[2]);

	for (int i = 0; i <= 9; i++)
	{
		cout << "学号：" << s[i].no << "   姓名：" << s[i].name << endl;
		cout << "1、" << s[i].score[0] << "   2、" << s[i].score[1] << "   3、" << s[i].score[2] << endl;
		cout << "平均分：" << s[i].ave << endl;
		cout << endl;
	}

	highest(s);

	return 0;
}