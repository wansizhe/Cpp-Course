#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;

short two(int n)
{
	short r = 1;
	for (int i = 1; i <= n - 1; i++)
		r *= 2;
	return r;
}

void means1(short *room,  char **name, int n, int m,char *fname, const int row, const int line)
{
	ofstream outfile;
	outfile.open(fname, ios::in);
	if (!outfile.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	int (*seat)[16];
	seat = new int[row][16];
	short t;
	int q, p, s = 0;
	int *bname;
	bname = new int[n];
	for (int i = 0; i < n; i++)
		bname[i] = 0;
	for (int i = 0; i < row; i++)
	{
		t = room[i];
		for (int j = 0; j < 16; j++)
		{
			if ((t & two(line-j)) == 0)
				seat[i][j] = 0;
			else
				seat[i][j] = 1;
			t <<= 1;
		}
	}
	/*for (int i = 0; room[i] != 0; i++)
	{
		t = room[i];
		q = 0;
		for (int j = 1; j <= 16; j++)
		{
			if ((t & two(line - j+1)) == two(line - j+1))
			{
				q++;
				if (q == 1)
					outfile << "| /    |";
				if (s<n)
					while (1)
					{
						p = rand() % n;
						if (bname[p] == 0)
						{
							outfile << setw(6) << setiosflags(ios::left) << *name[p] << "|";
							bname[p] = 1;
							s += 1;
							break;
						}
					}
				else
					outfile << " /    |";
			}
			else
				if (q != 0)
					outfile << " /    |";
			t <<= 1;
		}
		cout << endl;
	}*/
	for (int i = 0; i < row; i++)
	{
		q = 0;
		outfile << "| /    |";
        for (int j = 0; j < line; j++)
		{
			if (seat[i][j] == 1)
			{
				if (s < n)
					while (1)
					{
						p = rand() % n;
						if (bname[p] == 0)
						{
							outfile << setw(6) << setiosflags(ios::left) << (name)[p] << "|";
							bname[p] = 1;
							s += 1;
							break;
						}
					}
				else
					if(s>0)
						outfile << " /    |";
			}
			else
			{
				if (q != 0)
					outfile << " /    |";
			}
		}
		cout << endl;
	}
	delete bname;
}

/*void means2(short room[],  char **name, int n, int m,char *fname, const int row, const int line)
{
	ofstream outfile;
	outfile.open(fname, ios::in);
	if (!outfile.is_open())
	{
		cout << "打开文件失败" << endl;
		return ;
	}
	
	int *bname, row = 0;
	int(*seat)[16];
	bname = new int[n];
	for (int i = 0; i < n; i++)
		bname[i] = 0;
	seat = new int[row][16];
	short t;
	int r, l, p, s = 0;
	for (int i = 0; i < row; i++)
	{
		t = room[i];
		for (int j = 0; j < 16; j++)
		{
			if ((t & 0x8000) == 0)
				seat[i][j] = 0;
			else
				seat[i][j] = 1;
			t <<= 1;
		}
	}
	for (int i = 1; s < n; i++)
	{
		r = rand() % row;
		l = rand() % 16;
		if (seat[r][l] == 1)
		{
			seat[r][l] = 2;
			s++;
		}
	}
	int line;
	for (int j = 0; j < 16; j++)
	{
		int get = 0;
		for (int i = 0; i < row; i++)
			if (seat[i][j] != 0)
			{
				line = j;
				get = 1;
				break;
			}
		if (get == 1)
			break;
	}
	for (int i = 0; i < row; i++)
	{
		s = 0;
		for (int j = line; j < 16; j++)
		{
			if (s == 0)
			{
				outfile << "| /    |";
				s++;
			}
			if (seat[i][j] == 2)
			{
				while (1)
				{
					p = rand() % n;
					if (bname[p] == 0)
					{
						outfile << setw(6) << setiosflags(ios::left) << name[p] << "|";
						bname[p] = 1;
						break;
					}
				}
			}
			else
				outfile << " /    |";
		}
		cout << endl;
	}
	delete bname;
	delete[]seat;
}*/


int main(int argc,char *argv[])
{
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(unsigned int(time(0)));
	int c;
	cout << "========================" << endl;
	cout << "1、方法一" << endl;
	cout << "2、方法二" << endl;
	cout << "========================" << endl;
	cout << "请选择：";
	cin >> c;
	
	int n, m, row=0, line=0;
	ifstream fin;
	char str[50];
	fin.open(argv[1], ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	int count = 0;
	while (1)
	{
		fin >> str;
		if (strcmp(str,"NULL")==0)
			break;
		else
			count++;
	}
	fin.close();
	n = count;
	char **name;
	name = new char*[n];
	fin.open(argv[1], ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	for (int i = 0; i <n; i++)
	{
		fin >> str;
		const char *p = str;
		name[i] = new char[strlen(p) + 1];
		strcpy(name[i], p);
	}
	cout << "名字读入完成" << endl;

	fin.open(argv[2], ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
    count = 0;
	
	while (1)
	{
		string stri;
		fin >> stri;
		cout << stri << endl;
		const char*t = stri.c_str();
		char *p=new char[strlen(t) + 1];
		for (unsigned int i = 0; i < strlen(t); i++)
			p[i] = 'N';
		p[strlen(t)] = '\0';
		cout << t <<'*'<< endl;
		cout << "*********" << endl;
		cout << p << endl;
		if (strcmp(t, p) == 0)
		{
			line = strlen(t);
			
			delete []p;
			break;
		}
		else
		{
			row++;
			
			delete []p;
		}
	}
	cout << row << endl;
	m = row;
	fin.close();
	fin.open(argv[2], ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	short *room;
	char (*st)[17];
	st = new char[m][17];
	room = new short[m];
	int(*seat)[16];
	seat = new int[row][16];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < 16; j++)
			seat[i][j] = 0;

	for (int i = 0; i < m; i++)
	{
		fin >> st[i];
		room[i] = 0;
		for (int j = 0; st[i][j] == '\0'; j++)
		{
			if (st[i][j] == 'Y')
			{
				room[i] += two(strlen(st[i]) - j);
				seat[i][j] = 1;
			}
		}
	}
	cout << "座位读入完成" << endl;
	ofstream outfile;
	outfile.open(argv[3], ios::in);
	if (!outfile.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 16; j++)
			cout << seat[i][j];
		cout << endl;
	}
	cout << row << line;
	if (c == 1)
	{
		int s = 0;
		int *bname;
		bname = new int[n];
		for (int i = 0; i < n; i++)
			bname[i] = 0;
		for (int i = 0; i < row; i++)
		{
			outfile << "| /    ";
			for (int j = 0; j < line; j++)
			{
				if (seat[i][j] == 1&&s!=n)
				{
					while (1)
						{
							int p = rand() % n;
							if (bname[p] == 0)
							{
								outfile << "|" << setw(6) << setiosflags(ios::left) << (name)[p] ;
								if (j == line - 1)
									cout << "|";
								bname[p] = 1;
								s += 1;
								break;
							}
						}
				}
				else
				{
					outfile << "| /    ";
					if (j == line - 1)
						cout << "|";
				}
			}
			outfile << endl;
		}
		delete bname;
		cout << "完成";
	}
	else if (c == 2)
	{
		int *bname;
		int(*seat)[16];
		bname = new int[n];
		seat = new int[row][16];
		short t;
		int r, l, p, s = 0;
		for (int i = 0; i < row; i++)
		{
			t = room[i];
			for (int j = 0; j < 16; j++)
			{
				if ((t & 0x8000) == 0)
					seat[i][j] = 0;
				else
					seat[i][j] = 1;
				t <<= 1;
			}
		}
		for (int i = 1; s < n; i++)
		{
			r = rand() % row;
			l = rand() % 16;
			if (seat[r][l] == 1)
			{
				seat[r][l] = 2;
				s++;
			}
		}
		int line;
		for (int j = 0; j < 16; j++)
		{
			int get = 0;
			for (int i = 0; i < row; i++)
				if (seat[i][j] != 0)
				{
					line = j;
					get = 1;
					break;
				}
			if (get == 1)
				break;
		}
		for (int i = 0; i < row; i++)
		{
			s = 0;
			for (int j = line; j < 16; j++)
			{
				if (s == 0)
				{
					outfile << "| /    |";
					s++;
				}
				if (seat[i][j] == 2)
				{
					while (1)
					{
						p = rand() % n;
						if (bname[p] == 0)
						{
							outfile << setw(6) << setiosflags(ios::left) << name[p] << "|";
							bname[p] = 1;
							break;
						}
					}
				}
				else
					outfile << " /    |";
			}
			cout << endl;
		}
		delete bname;
		delete[]seat;
	}

	for (int i = 0; i <n; i++)
	{
		delete name[i];
	}
	delete name;
	delete []st;
	delete []room;

	return 0;

}