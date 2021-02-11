#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct stu
{
	int no;
	char name[10];
	int score;
	int rank;
};

int main()
{
	stu temp;
	stu* students, *head;
	int total, j, k, n = 0;
	ifstream infile;
	infile.open("student.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	infile >> total;
	students=new stu[total];
	head = students;
	for (int i = 1; i <= 88; i++)
		infile >> (students+i-1)->no >> (students + i - 1)->name >> (students + i - 1)->score;
	for (int i = 1; i <= 88; i++)
		(students + i - 1)->rank = 0;

	for (j = 1; j <= 87; j++)
		for (k = j + 1; k <= 88; k++)
			if ((students + j - 1)->score < (students + k - 1)->score)
			{
				temp = *(students+j-1);
				*(students + j - 1) = *(students + k - 1);
				*(students + k - 1) = temp;
			}
		
	for (int i = 1; i <= 88; i++)
	{
		if (i >= 2 && (students + i - 1)->score != (students + i - 1-1)->score)
			n = 0;
		else if (i >= 2 && (students + i - 1)->score == (students + i - 1 - 1)->score)
			n++;
		(students + i - 1)->rank = i - n;
	}

	for (j = 1; j <= 87; j++)
		for (k = j + 1; k <= 88; k++)
			if ((students+j-1)->no > (students + k - 1)->no)
			{
				temp = *(students + j - 1);
				*(students + j - 1) = *(students + k - 1);
				*(students + k - 1) = temp;
			}

	for (int i = 1; i <= 88; i++)
		cout << (students + i - 1)->no << "  " << (students + i - 1)->name << "  " << (students + i - 1)->score << "  " << (students + i - 1)->rank << endl;
	
	delete head;

	return 0;
}