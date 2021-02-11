#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include <time.h>
using namespace std;

struct student
{
	int no;
	char *name;
	char *sch;
	int get;
	student *next;
};

int main()
{
	ifstream infile;
	infile.open("stulist.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}

	int want, total;
	char names[10], school[10];
	struct student  *stu, *head;
	stu = new student [1];
	head = stu;
	infile >> want >> total;

	for (int i = 1; i <= total; i++)
	{
		if (i>1)
		{
			stu->next = new student[1];
			stu = stu->next;
		}
		infile >> stu->no;
		infile >> names >> school;
		stu->name = new char[strlen(names) + 1];
		stu->sch = new char[strlen(school) + 1];
		strcpy(stu->name, names);
		strcpy(stu->sch, school);
		stu->get = 0;
	}
	stu->next = NULL;

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(unsigned int(time(0)));
	stu = head;
	for (int i = 0; i < want;)
	{
		int n = rand() % total;
		if ((stu + n)->get == 0)
		{
			(stu + n)->get = 1;
			i++;
		}
	}

	ofstream outfile;
	outfile.open("result.txt", ios::in);
	if (!outfile.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	int w = 0;
	for (int i = 1; i <= total; i++)
	{
		if (i == 1)
			stu = head;
		if (stu->get == 1)
		{
			outfile << stu->no << "  " << stu->name << "  " << stu->sch << endl;
			w++;
		}
		stu = stu->next;
		if (w == want)
			break;
	}


	stu = head;
	student *temp;
	while (1)
	{
		if (stu == NULL)
			break;
		temp = stu->next;
		delete stu->name;
		delete stu->sch;
		delete stu;
		stu = temp;
	}

	return 0;
}