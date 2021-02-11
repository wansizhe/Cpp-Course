#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<io.h>
using namespace std;

struct student
{
	string no;
	string name;
	string classn;
	string classc;
};

struct hanshu
{
	string line;
	hanshu *next;
};

struct filename
{
	char fn[20];
	filename *next;
};

int main(int argc, const char* argv[])
{
	bool checktitle = false, replace = false, all = false;
	string filename, filemian;
	student *stu;
	ifstream fin;
	fin.open(".\\source\\stu.dat", ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	int row = 0;
	while (!fin.eof())
	{
		string t;
		getline(fin, t);
		row++;
	}

	//cout << row << "人" << endl;

	fin.close();
	fin.open(".\\source\\stu.dat", ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	stu = new student[row];
	for (int i = 0; i < row; i++)
	{
		fin >> stu[i].no;
		fin >> stu[i].name;
		fin >> stu[i].classn;
		fin >> stu[i].classc;
	}
	fin.close();
	if (argc == 3)
	{
		if (strcmp(argv[1], "-checktitle") == 0)
		{			
			checktitle = true;
			if (strcmp(argv[2], "all") == 0)
				all = true;
			else
				filename = filename + argv[2];
		}


		if (all)
		{
			for (int i = 0; i < row; i++)
			{
				string path,p;
				path = ".\\source\\100384-";
				path = path + stu[i].no;
				path = path + "\\";
				p= path + "*.cpp";
				long handle;
				struct _finddata_t fileinfo;
				const char* to_search = p.c_str();

				handle = _findfirst(to_search, &fileinfo);
				if (handle == -1)
					return -1;
				struct filename *first;
				first = new  struct  filename [1];
				strcpy(fileinfo.name, (*first).fn);
				int n = 1;
				struct filename* nextone = first;
				while (!_findnext(handle, &fileinfo))
				{
					nextone->next = new struct filename[1];
					strcpy(fileinfo.name, nextone->next->fn);
					nextone = nextone->next;
					n++;
				}
				nextone->next = NULL;

				char pp[100];
				int a;
				for (a = 0; path[a] != '\0'; a++)
				{
					pp[a] = path[a];
				}
				pp[a] = '\0';
				nextone = first;
				while (nextone != NULL)
				{
					fin.open(strcat(pp, nextone->fn), ios::in);
					char str[3][25] = { { '\0' },{ '\0' },{ '\0' } };
					int n = 0;
					string line1;
					while (1)
					{
						if (fin.eof())
						{
							cout << stu[i].no << stu[i].name << "没写title" << endl;
							break;
						}
						getline(fin, line1);
						if (line1[0] == '/' && (line1[1] == '/' || line1[1] == '*'))
						{
							n = 2;
							break;
						}
					}
					//cout << line1 << endl;
					if (n != 2)
					{
						fin.close();
						continue;
					}
					else
					{
						char ch1 = '\0';
						string inf = line1;
						int nos = -1, nam = -1, ban = -1, b = -1, e = -1, k = 0, kg = 0;
						for (k = 0; inf[k] == ' ' || inf[k] == '\t'; k++);
						const char* p = inf.c_str() + k;
						for (kg = 2; p[kg] == ' ' || p[kg] == '\t'; kg++);
						for (unsigned int j = kg; j < strlen(p) && p[j] != '*'&& p[j] != '/'&&p[j] != '\t';)
						{
							unsigned int m;
							for (m = j + 1; m < strlen(p) && p[m] != ' '&& p[m] != '*'&&p[j] != '\t'; m++);
							if (m >= strlen(p) && p[1] == '*')
								break;
							if (nos == -1)
							{
								strncpy(str[0], p + j, m - j);
								for (j = m; p[j] == ' ' || p[j] == '\t'; j++);
								nos++;
								continue;
							}
							if (nam == -1)
							{
								strncpy(str[1], p + j, m - j);
								for (j = m; p[j] == ' ' || p[j] == '\t'; j++);
								nam++;
								continue;
							}
							if (ban == -1)
							{
								strncpy(str[2], p + j, m - j);
								for (j = m; p[j] == ' ' || p[j] == '\t'; j++);
								ban++;
								continue;
							}
						}
						//cout <<nos<<"  "<< str[0] << endl <<nam<<"  "<<str[1] <<endl<<ban<<"  "<< str[2] << endl;

						if (nam == -1 || nos == -1 || ban == -1)
						{
							cout << stu[i].no << stu[i].name << "信息不完整" << endl;
						}
						else
						{
							int nn[3] = { 0 };
							for (int b = 0; b < 3; b++)
							{
								if (strcmp(str[b], stu[i].no.c_str()) == 0)
									nn[0]++;
								if (strcmp(str[b], stu[i].no.c_str()) == 0)
									nn[1]++;
								for (unsigned int c = 0; c < strlen(str[b]); c++)
								{
									if (str[b][c] == stu[i].classn[0] && c + 1 < strlen(str[b]) && str[b][c + 1] == stu[i].classn[1] && c + 2 < strlen(str[b]) && str[b][c + 2] == stu[i].classn[2])
										nn[2]++;
									if (str[b][c] == stu[i].classc[0] && c + 1 < strlen(str[b]) && str[b][c + 1] == stu[i].classc[1] && c + 2 < strlen(str[b]) && str[b][c + 2] == stu[i].classc[2] && c + 3 < strlen(str[b]) && str[b][c + 3] == stu[i].classc[3])
										nn[2]++;
								}
							}
							if (nn[0] == 0)
								cout << stu[i].no << stu[i].name << "学号不匹配" << endl;
							if (nn[1] == 0)
								cout << stu[i].no << stu[i].name << "姓名不匹配" << endl;
							if (nn[2] == 0)
								cout << stu[i].no << stu[i].name << "班级不匹配" << endl;
						}
					}
					fin.close();


					fin.close();
				}


				nextone = first;
				while (nextone!=NULL)
				{
					struct filename * temp = nextone->next;
					delete nextone;
					nextone = temp;
				}
			}
		}

		else
		{
			for (int i = 0; i < row; i++)
			{
				string path;
				path = ".\\source\\100384-";
				path = path + stu[i].no;
				path = path + "\\";
				path = path + argv[2];
				fin.open(path, ios::in);
				char str[3][25] = { {'\0'},{'\0'},{'\0'} };
				int n = 0;
				string line1;
				while (1)
				{
					if (fin.eof())
					{
						cout << stu[i].no << stu[i].name << "没写title" << endl;
						break;
					}
					getline(fin, line1);
					if (line1[0] == '/' && (line1[1] == '/' || line1[1] == '*'))
					{
						n = 2;
						break;
					}
				}
				//cout << line1 << endl;
				if (n != 2)
				{
					fin.close();
					continue;
				}
				else
				{
					char ch1 = '\0';
					string inf=line1;
					int nos = -1, nam = -1, ban = -1, b = -1, e = -1, k = 0, kg = 0;
					for (k = 0; inf[k] == ' ' || inf[k] == '\t'; k++);
					const char* p = inf.c_str() + k;
					for (kg = 2; p[kg] == ' ' || p[kg] == '\t'; kg++);
					for (unsigned int j = kg; j < strlen(p)&&p[j]!='*'&& p[j] != '/'&&p[j] !='\t';)
					{
						unsigned int m;
						for (m = j + 1; m < strlen(p) && p[m] != ' '&& p[m] != '*'&&p[j] !='\t';m++);
						if (m >= strlen(p)&&p[1]=='*')
							break;
						if (nos == -1)
						{
							strncpy(str[0], p + j, m - j);
							for (j = m ;p[j] == ' ' || p[j] == '\t'; j++);
							nos++;
							continue;
						}
						if (nam == -1)
						{
							strncpy(str[1], p + j, m - j);
							for (j = m ; p[j] == ' '||p[j]== '\t'; j++);
							nam++;
							continue;
						}
						if (ban == -1)
						{
							strncpy(str[2], p + j, m - j);
							for (j = m ; p[j] == ' ' || p[j] == '\t'; j++);
							ban++;
							continue;
						}
					}
					//cout <<nos<<"  "<< str[0] << endl <<nam<<"  "<<str[1] <<endl<<ban<<"  "<< str[2] << endl;
					
					if(nam==-1||nos==-1||ban==-1)
					{
						cout << stu[i].no << stu[i].name << "信息不完整" << endl;
					}
					else
					{
						int nn[3] = { 0 };
						for (int b = 0; b < 3; b++)
						{
							if (strcmp(str[b], stu[i].no.c_str()) == 0)
								nn[0]++;
							if (strcmp(str[b], stu[i].no.c_str()) == 0)
								nn[1]++;
							for (unsigned int c = 0; c < strlen(str[b]); c++)
							{
								if (str[b][c] == stu[i].classn[0] && c + 1 < strlen(str[b]) && str[b][c + 1] == stu[i].classn[1] && c + 2 < strlen(str[b]) && str[b][c + 2] == stu[i].classn[2])
									nn[2]++;
								if (str[b][c] == stu[i].classc[0] && c + 1 < strlen(str[b]) && str[b][c + 1] == stu[i].classc[1] && c + 2 < strlen(str[b]) && str[b][c + 2] == stu[i].classc[2] && c + 3 < strlen(str[b]) && str[b][c + 3] == stu[i].classc[3])
									nn[2]++;
							}
						}
						if (nn[0] == 0)
							cout << stu[i].no << stu[i].name << "学号不匹配" << endl;
						if (nn[1] == 0)
							cout << stu[i].no << stu[i].name << "姓名不匹配" << endl;
						if (nn[2] == 0)
							cout << stu[i].no << stu[i].name << "班级不匹配" << endl;
					}
				}
				fin.close();
			}
		}
	}

	if (argc == 4)
	{
		if (strcmp(argv[1], "-replace") != 0)
			return 0;
		else if (strcmp(argv[1], "-replace") == 0 && (strcmp(argv[2], "all") == 0 || strcmp(argv[3], "all") == 0))
		    return 0;
		fstream f1, f2;
		for (int i = 0; i < row; i++)
		{
			string path1,path2;
			path1 = ".\\source\\100384-";
			path1 = path1 + stu[i].no;
			path1 = path1 + "\\";
			path1 = path1 + argv[2];
			path2 = ".\\source\\";
			path2 = path2 + argv[3];
			f1.open(path1, ios::in | ios::out);
			if (!f1.is_open())
			{
				cout << "打开文件失败" << endl;
				return 0;
			}
			f2.open(path2, ios::in);
			if (!f2.is_open())
			{
				cout << "打开文件失败" << endl;
				return 0;
			}
			hanshu *head = new hanshu[1];
			hanshu*p = head;
			f1 >> p->line;
			cout << "1" << endl;
			while (1)
			{
				p->next = new hanshu[1];
				f1 >> p->line;
				if (p->line == "int main()" || p->line == "int main(){")
				{
					delete p->next;
					p->next = NULL;
					break;
				}
				p = p->next;
			}
			cout << "2" << endl;
			p = head;
			while (p != NULL)
			{
				f1 << p->line << endl;
				p = p->next;
			}
			cout << "3" << endl;
			p = head;
			while (p != NULL)
			{
				hanshu *t = p->next;
				delete p;
				p = t;
			}
			cout << "4" << endl;
			head = new hanshu[1];
			p = head;
			f2 >> p->line;
			while (!f2.eof())
			{
				p->next = new hanshu[1];
				f2 >> p->line;
				p = p->next;
			}
			cout << "5" << endl;
			p = NULL;
			p = head;
			while (p != NULL)
			{
				f1 << p->line << endl;
				p = p->next;
			}
			cout << "6" << endl;
			p = head;
			while (p != NULL)
			{
				hanshu *t = p->next;
				delete p;
				p = t;
			}
			cout << "7" << endl;
			f1.close();
			f2.close();
		}
	}



	delete []stu;
	return 0;
}