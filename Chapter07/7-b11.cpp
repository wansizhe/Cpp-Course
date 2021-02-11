#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	system("mode con cols=100 lines=40"); // cols Ϊ�� ���� lines Ϊ�� ����
	char *meaning[26] = { "�ǳ�","����ֵ","����ֵ","����","����","��Ǯ","����ֵ","����ֵ","Ԥ��","�ƶ��ٶ�","�����ٶ�","������Χ","Ԥ��","������","������","���ݶ�","����","����","�ȼ�","ħ��ֵ","ħ������","ħ���˺�","������","ħ������","������","����" };
	int value[26] = { 0 };
	value[8] = -1;
	value[12] = -1;
	char name[17], temp[2][10];
	const int len[26] = { 16,2,2,2,2,4,4,4,8,1,1,1,1,2,2,1,1,1,1,2,1,1,1,1,1,1 };
	ifstream fin("game.dat", ios::binary);
	if (!fin.is_open())
	{
		cerr << "���ļ�ʧ��" << endl;
		return 0;
	}
	for (int i = 0; i < 26; i++)
	{
		if(i==0)
			fin.read(&name[i], len[i]);
		else if (value[i] != -1)
			fin.read((char*)&value[i], len[i]);
		else if (value[i] == -1)
		{
			if(i==8)
			    fin.read(temp[0], len[i]);
			else if(i==12)
				fin.read(temp[1], len[i]);
		}
	}
	fin.close();
	cout << ' ' << char(65) << ". " << setw(10) << setiosflags(ios::left) << meaning[0] << "��" << setw(15) << setiosflags(ios::left) << name << endl;
	int n = 1;
	for (int i = 0; i < 13; i++)
	{
		cout << ' ' << char(2*i + 66) << ". ";
		if (strcmp(meaning[n], "Ԥ��") == 0)
			n++;
		cout << setw(10) << setiosflags(ios::left) << meaning[n];
		cout << "��" << setw(9) << setiosflags(ios::left) << value[n];
		if (n == 25)
			break;
		n++;
		cout << "  | ";
		cout << ' ' << char(2 * i + 67) << ". ";
		if (strcmp(meaning[n], "Ԥ��") == 0)
			n++;
		cout << setw(10) << setiosflags(ios::left) << meaning[n];
		cout << "��" << setw(9) << setiosflags(ios::left) << value[n];
		if (n == 25)
			break;
		n++;
		cout << endl;
	}
	cout << endl << endl;
	while (1)
	{
		cout << "��ѡ���޸���,����z�˳�" << endl;
		char choice;
		int change;
		char tname[16], ch;
		const int top[26] = { 15,10000,10000,8192,1024,100000000,1000000,1000000,-1,100,100,100,-1,2000,2000,100,100,100,100,10000,100,100,100,100,100,100 };
		cin >> choice;
		if (choice == 'Z' || choice == 'z')
		{
			cout << "���˳�" << endl;
			return 0;
		}
		int c;
		if (!(choice >= 'A'&&choice <= 'X' || choice >= 'a'&&choice <= 'x'))
		{
			cout << "�޸�ʧ��" << endl;
			return 0;
		}
		else if (choice >= 'a'&&choice <= 'x')
			choice -= 32;
		if (choice >= 'A'&&choice <= 'H')
			c = choice - 65;
		else if (choice >= 'I'&&choice <= 'K')
			c = choice - 64;
		else if (choice >= 'L'&&choice <= 'X')
			c = choice - 63;
		if (value[c] == -1)
			c++;
		cout << "���޸� ��" << meaning[c] << "�� ��������ע�������Χ 0-" << top[c] << endl;
		if (c == 0)
		{
			int i;
			string newname;
			cin >> newname;
			i = strlen(newname.c_str());
			if (i > 15)
			{
				cout << "�޸�ʧ��" << endl;
				return 0;
			}
			else
			{
				int k;
				for (k = 0; newname[k] != '\0'; k++)
				{
					name[k] = newname[k];
				}
				name[k] = '\0';
			}
		}
		else
		{
			cin >> change;
			if (change<0 || change>top[c])
			{
				cout << "�޸�ʧ��" << endl;
				return 0;
			}
			else
				value[c] = change;
		}
		ofstream fout("game.dat", ios::out | ios::binary);
		if (!fout.is_open())
		{
			cerr << "���ļ�ʧ��" << endl;
			return 0;
		}
		for (int k = 0; k < 26; k++)
		{
			if (k == 0)
				fout.write(name, len[k]);
			else if (k == 8)
				fout.write(temp[0], len[k]);
			else if (k == 12)
				fout.write(temp[1], len[k]);
			else
				fout.write((char*)&value[k], len[k]);
		}
		fout.close();
		cout << "�޸ĳɹ�" << endl;
		if (c == 0)
		{
			cout << meaning[c] << "  �Ѹ�Ϊ  " << name;
		}
		else
			cout << meaning[c] << "  �Ѹ�Ϊ  " << value[c];
		cout << endl << "======================================" << endl;
	}

	return 0;
}