#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct student
{
	int *no;
	char *name;
	int *score;
	struct student* next;
};

int main()
{
	ifstream infile;
	infile.open("list.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	struct student  *stu, *head;
	stu = new student[1];
	head = stu;
	int end;
	char names[9];

	for (int i = 1;; i++)
	{
		infile >> end;
		if (end == 9999999)
			break;
		else
		{
			if (i>1)
			{
				stu->next = new student[1];
				stu = stu->next;
			}
			stu->no = new int [1];
			*(stu->no) = end;
			infile >> names;
			stu->name = new char[strlen(names) + 1];
			stu->score = new int[1];
			infile >> *(stu->score);
			strcpy(stu->name, names);
		}
	}
	stu->next = NULL;

	stu = head;
	while (1)
	{
		cout << *(stu->no) << "  " << (stu->name) << "  " << *(stu->score) << endl;
		if (stu->next == NULL)
			break;
		else
			stu = stu->next;
	}

	stu = head;
	student *temp;
	while (1)
	{
		if (stu == NULL)
			break;
		temp = stu->next;
		delete stu->no; 
		delete stu->name;
		delete stu->score;
		delete stu;
		stu = temp;
	}

	return 0;
}