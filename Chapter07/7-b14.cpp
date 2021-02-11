#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<io.h>
#include<stdio.h>
using namespace std;

struct student
{
	char no[8];
	char name[8];
	char class1[5];
	char class2[9];
};
struct vs2015
{
	char line[1000];
	vs2015* next;
};

void tchecktitle(FILE*cpp_fin, student curstuinfo)
{
	char ch;
	char curinfo[3][100] = { { '\0' },{ '\0' },{ '\0' } };
	int getone = 0;
	while (!feof(cpp_fin))
	{
		ch = fgetc(cpp_fin);
		if ((ch == ' ' || ch == '\t' || ch == 10) && getone == 0)
			continue;
		else if (ch != ' '&&ch != '\t'&&ch != 10 && ch != '/'&&getone == 0)
			break;
		else if (ch == '/'&&getone == 0)
		{
			getone++;
			continue;
		}
		else if (ch != '*'&&ch != '/'&&getone == 1)
			break;
		else if ((ch == '*' || ch == '/') && getone == 1)
		{
			getone++;
			break;
		}
	}
	if (getone != 2)
	{
		cout << " δ��ȡ����Ϣ" << endl;
		return;
	}
	for (int a = 0; a < 3; a++)
	{
		getone = 0;
		for (int b = 0; b < 100;)
		{
			ch = fgetc(cpp_fin);

			if ((ch == 10 || ch == '*'))
				break;
			else if ((ch == ' ' || ch == '\t') && getone == 1)
			{
				curinfo[a][b] = '\0';
				break;
			}
			else if ((ch == ' ' || ch == '\t') && getone == 0)
				continue;
			else if (ch != 10 && ch != '\t'&&ch != ' '&&ch != '*')
			{
				getone = 1;
				curinfo[a][b] = ch;
				b++;
			}
		}
		if (ch == 10 || ch == '*')
		{
			getone = a;
			break;
		}
		else if (ch == ' ' || ch == '\t')
		{
			continue;
		}
	}

	for (int k = 0; k < 3; k++)
	{
		if (curinfo[k][0] == '\0')
		{
			cout << "��Ϣ��ȫ" << endl;
			return;
		}
	}

	int sno = 0, sname = 0, sclass = 0;
	for (int k = 0; k < 3; k++)
	{
		if (strstr(curinfo[k], curstuinfo.no) != NULL)
		{
			sno = 1;
			break;
		}
	}
	for (int k = 0; k < 3; k++)
	{
		if (strstr(curinfo[k], curstuinfo.name) != NULL)
		{
			sname = 1;
			break;
		}
	}
	for (int k = 0; k < 3; k++)
	{
		if (strstr(curinfo[k], curstuinfo.class1) != NULL || strstr(curinfo[k], curstuinfo.class2) != NULL)
		{
			sclass = 1;
			break;
		}
	}
	
	if (sno == 0)
		cout << "ѧ��";
	if (sname == 0)
		cout << "����";
	if (sclass == 0)
		cout << "�༶";
	if (sno == 0 || sname == 0 || sclass == 0)
		cout << "��ƥ��" << endl;
	else
		cout << "ͨ��" << endl;

}

int main(int argc, const char *argv[])
{
	FILE *stu_fin, *cpp_fin, *main_fin, *fout;
	student *stuinfo;
	vs2015 *cpphead, *mainhead;
	vs2015 *curline;
	int stu_num = 0;
	char path[100] = ".\\source\\", pathm[100] = ".\\source\\";
	if (argc == 4)
	{
		if (strcmp(argv[1], "-checktitle") != 0)
		{
			cout << "ָ�����" << endl;
			return 0;
		}
		strcat(path, argv[2]);
		strcat(path, ".dat");
		/*�� �κ�.dat ¼��ѧ����Ϣ*/
		stu_fin = fopen(path, "r");
		if (stu_fin == NULL)
		{
			cout << path << "��ʧ��" << endl << endl;
			return 0;
		}
		while (!feof(stu_fin))
		{
			if (fgetc(stu_fin) == 10)
			    stu_num++;
		}
		fclose(stu_fin);

		stu_num++;
		stuinfo = new student[stu_num];
		stu_fin = fopen(path, "r");
		if (stu_fin == NULL)
		{
			cout << path << "��ʧ��" << endl << endl;
			delete stuinfo;
			return 0;
		}
		int i = 0;
		while (!feof(stu_fin))
		{
			if (i < stu_num)
			{
				fscanf(stu_fin, "%s%s%s%s", stuinfo[i].no, stuinfo[i].name, stuinfo[i].class1, stuinfo[i].class2);
				i++;
			}
		}
		fclose(stu_fin);

		/*��ѧ������ҵ*/
		if (strcmp(argv[3], "all") != 0)
		{
			for (int i = 0; i < stu_num; i++)
			{
				cout << "���" << stuinfo[i].name << "   ";
				strcpy(path, ".\\source\\");
				strcat(path, argv[2]);
				strcat(path, "-");
				strcat(path, stuinfo[i].no);
				strcat(path, "\\");
				strcat(path, argv[3]);
				cpp_fin = fopen(path, "r");
				if (cpp_fin == NULL)
				{
					cout  << " δ��" << endl;
					continue;
				}
				/*Ѱ��ע�����*/
				tchecktitle(cpp_fin, stuinfo[i]);
				fclose(cpp_fin);
			}
		}

		else
		{
			for (int i = 0; i < stu_num; i++)
			{
				cout << "���" << stuinfo[i].name << "  ";
				strcpy(path, ".\\source\\");
				strcat(path, argv[2]);
				strcat(path, "-");
				strcat(path, stuinfo[i].no);
				strcat(path, "\\");
				strcat(path, "*.cpp");
				const char *to_search = path;
				long handle;
				struct _finddata_t fileinfo;
				handle = _findfirst(to_search, &fileinfo);
				if (handle == -1)
				{
					cout << endl << "����ҵ" << endl << endl;
					continue;
				}
				cout << endl << fileinfo.name << "  ";
				strcpy(path, ".\\source\\");
				strcat(path, argv[2]);
				strcat(path, "-");
				strcat(path, stuinfo[i].no);
				strcat(path, "\\");
				strcat(path, fileinfo.name);
				cpp_fin = fopen(path, "r");
				if (cpp_fin == NULL)
				{
					cout << " δ��" << endl;
					continue;
				}
				tchecktitle(cpp_fin, stuinfo[i]);
				fclose(cpp_fin);
				while (!_findnext(handle, &fileinfo))
				{
					cout << fileinfo.name << "  ";
					strcpy(path, ".\\source\\");
					strcat(path, argv[2]);
					strcat(path, "-");
					strcat(path, stuinfo[i].no);
					strcat(path, "\\");
					strcat(path, fileinfo.name);
					cpp_fin = fopen(path, "r");
					if (cpp_fin == NULL)
					{
						cout << " δ��" << endl;
						continue;
					}
					tchecktitle(cpp_fin, stuinfo[i]);
					fclose(cpp_fin);
				}
				_findclose(handle);
				cout << endl;
			}
		}
	}
	
    else if (argc == 5)
	{
		if (strcmp(argv[1], "-replace") != 0)
		{
			cout << "ָ�����" << endl;
			return 0;
		}
		strcat(path, argv[2]);
		strcat(path, ".dat");
		/*�� �κ�.dat ¼��ѧ����Ϣ*/
		stu_fin = fopen(path, "r");
		if (stu_fin == NULL)
		{
			cout << path << "��ʧ��" << endl << endl;
			return 0;
		}
		while (!feof(stu_fin))
		{
			if (fgetc(stu_fin) == 10)
				stu_num++;
		}
		fclose(stu_fin);

		stu_num++;
		stuinfo = new student[stu_num];
		stu_fin = fopen(path, "r");
		if (stu_fin == NULL)
		{
			cout << path << "��ʧ��" << endl << endl;
			return 0;
		}
		int i = 0;
		while (!feof(stu_fin))
		{
			if (i < stu_num)
			{
				fscanf(stu_fin, "%s%s%s%s", stuinfo[i].no, stuinfo[i].name, stuinfo[i].class1, stuinfo[i].class2);
				i++;
			}
		}
		fclose(stu_fin);

		strcat(pathm, argv[4]);
		for (i = 0; i < stu_num; i++)
		{
			cout << "�滻" << stuinfo[i].name << "   ";
			strcpy(path, ".\\source\\");
			strcat(path, argv[2]);
			strcat(path, "-");
			strcat(path, stuinfo[i].no);
			strcat(path, "\\");
			strcat(path, argv[3]);
			cpp_fin = fopen(path, "r");
			if (cpp_fin == NULL)
			{
				cout << "δ��" << endl;
				continue;
			}
			cpphead = new vs2015[1];
			curline = cpphead;
			fgets(cpphead->line, 999, cpp_fin);
			while (!feof(cpp_fin))
			{
				curline->next = new vs2015[1];
				vs2015 *t = curline->next;
				fgets(t->line,999,cpp_fin);
				curline = t;
				curline->next = NULL;
			}
			fclose(cpp_fin);
			
			main_fin = fopen(pathm, "r");
			if (main_fin == NULL)
			{
				cout << "�����滻��main����������" << endl;
				continue;
			}
			mainhead = new vs2015[1];
			curline = mainhead;
			fgets(mainhead->line, 999, main_fin);
			while (!feof(main_fin))
			{
				curline->next = new vs2015[1];
				vs2015 *t = curline->next;
				fgets(t->line, 999, main_fin);
				curline = t;
				curline->next = NULL;
			}
			fclose(main_fin);

			fout = fopen(path, "w");
			if (fout== NULL)
			{
				cout << "δ��" << endl;
				continue;
			}
			curline = cpphead;
			while (curline->next != NULL)
			{
				if (strstr(curline->line, "int main()") != NULL)
					break;
				fputs(curline->line, fout);
				curline = curline->next;
			}
			curline = mainhead;
			while (curline!= NULL)
			{
				fputs(curline->line, fout);
				curline = curline->next;
			}
			fclose(fout);
			cout << "���"<<endl;
			curline = cpphead;
			while (curline != NULL)
			{
				vs2015 *t = curline->next;
				delete curline;
				curline = t;
			}
			curline = mainhead;
			while (curline != NULL)
			{
				vs2015 *t = curline->next;
				delete curline;
				curline = t;
			}
			cout << endl;

		}
	}

	delete stuinfo;
	return 0;
}