#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

struct student
{
	int no;
	char name[9];
	int score;
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
	stu = (student *)calloc(1, sizeof(student));
	head = stu;
	int end;

	for (int i = 1;; i++)
	{
		infile >> end;
		if (end == 9999999)
			break;
		else
		{
			if (i>1)
			{
				stu->next = (student *)calloc(1, sizeof(student));
				stu = stu->next;
			}
			stu->no = end;
			infile >> stu->name >> stu->score;
		}
	}
	stu->next = NULL;
	stu = head;
	while (1)
	{
		cout << stu->no << "  " << stu->name << "  " << stu->score << endl;
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
		free( stu);
		stu = temp;
	}

	return 0;
}