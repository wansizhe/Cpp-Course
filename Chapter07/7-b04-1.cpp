#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdlib>
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
	stu = (student*)calloc(1, sizeof(student));
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
				stu->next = (student*)calloc(1, sizeof(student));
				stu = stu->next;
			}
			stu->no = (int*)calloc(1, sizeof(int));
			*(stu->no) = end;
			infile >> names;
			stu->name = (char*)calloc(strlen(names)+1, sizeof(char));
			stu->score = (int*)calloc(1, sizeof(int));
			infile  >> *(stu->score);
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
		free(stu->no);
		free(stu->name); 
		free(stu->score);
		free( stu);
		stu = temp;
	}

	return 0;
}