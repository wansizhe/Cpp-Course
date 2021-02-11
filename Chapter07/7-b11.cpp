#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	system("mode con cols=100 lines=40"); // cols 为列 即宽 lines 为行 即高
	char *meaning[26] = { "昵称","生命值","力量值","体质","灵巧","金钱","名声值","魅力值","预留","移动速度","攻击速度","攻击范围","预留","攻击力","防御力","敏捷度","智力","经验","等级","魔法值","魔法消耗","魔法伤害","命中率","魔法防御","暴击率","耐力" };
	int value[26] = { 0 };
	value[8] = -1;
	value[12] = -1;
	char name[17], temp[2][10];
	const int len[26] = { 16,2,2,2,2,4,4,4,8,1,1,1,1,2,2,1,1,1,1,2,1,1,1,1,1,1 };
	ifstream fin("game.dat", ios::binary);
	if (!fin.is_open())
	{
		cerr << "打开文件失败" << endl;
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
	cout << ' ' << char(65) << ". " << setw(10) << setiosflags(ios::left) << meaning[0] << "：" << setw(15) << setiosflags(ios::left) << name << endl;
	int n = 1;
	for (int i = 0; i < 13; i++)
	{
		cout << ' ' << char(2*i + 66) << ". ";
		if (strcmp(meaning[n], "预留") == 0)
			n++;
		cout << setw(10) << setiosflags(ios::left) << meaning[n];
		cout << "：" << setw(9) << setiosflags(ios::left) << value[n];
		if (n == 25)
			break;
		n++;
		cout << "  | ";
		cout << ' ' << char(2 * i + 67) << ". ";
		if (strcmp(meaning[n], "预留") == 0)
			n++;
		cout << setw(10) << setiosflags(ios::left) << meaning[n];
		cout << "：" << setw(9) << setiosflags(ios::left) << value[n];
		if (n == 25)
			break;
		n++;
		cout << endl;
	}
	cout << endl << endl;
	while (1)
	{
		cout << "请选择修改项,输入z退出" << endl;
		char choice;
		int change;
		char tname[16], ch;
		const int top[26] = { 15,10000,10000,8192,1024,100000000,1000000,1000000,-1,100,100,100,-1,2000,2000,100,100,100,100,10000,100,100,100,100,100,100 };
		cin >> choice;
		if (choice == 'Z' || choice == 'z')
		{
			cout << "已退出" << endl;
			return 0;
		}
		int c;
		if (!(choice >= 'A'&&choice <= 'X' || choice >= 'a'&&choice <= 'x'))
		{
			cout << "修改失败" << endl;
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
		cout << "请修改 “" << meaning[c] << "” 参数，请注意参数范围 0-" << top[c] << endl;
		if (c == 0)
		{
			int i;
			string newname;
			cin >> newname;
			i = strlen(newname.c_str());
			if (i > 15)
			{
				cout << "修改失败" << endl;
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
				cout << "修改失败" << endl;
				return 0;
			}
			else
				value[c] = change;
		}
		ofstream fout("game.dat", ios::out | ios::binary);
		if (!fout.is_open())
		{
			cerr << "打开文件失败" << endl;
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
		cout << "修改成功" << endl;
		if (c == 0)
		{
			cout << meaning[c] << "  已改为  " << name;
		}
		else
			cout << meaning[c] << "  已改为  " << value[c];
		cout << endl << "======================================" << endl;
	}

	return 0;
}