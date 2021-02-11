#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct kfc
{
	char no;
	char *name;
	double rmb;
};

struct sp
{
	char *nos;
	char *names;
	int rmbs;
};

struct price
{
	int num = 0;
	int disc = 0;
};

int main()
{
	/* ģ������ */
	struct kfc list[] = {
		{ 'A', "�������ȱ�",         15.5 },
		{ 'B', "���༦�ȱ�",         15.5 },
		{ 'C', "�°¶��������ȱ�",   16.5 },
		{ 'D', "����˫�㼦�ȱ�",     16.0 },
		{ 'E', "������ȫϺ��",       15.5 },
		{ 'F', "�����������",     17.5 },
		{ 'G', "�ϱ��������",       15.0 },
		{ 'H', "������ţ��",         16.0 },
		{ 'I', "˱ָԭζ��",         10.5 },
		{ 'J', "�°¶�������",       10.5 },
		{ 'K', "��������",           9.5 },
		{ 'L', "���༦�׻�",         10.5 },
		{ 'M', "��������",           7.0 },
		{ 'N', "����(С)",           7.0 },
		{ 'O', "����(��)",           9.0 },
		{ 'P', "����(��)",           10.0 },
		{ 'Q', "ܽ��������",         7.5 },
		{ 'R', "�������װ�",         8.5 },
		{ 'S', "������",             6.0 },
		{ 'T', "����ɫ��",           8.0 },
		{ 'U', "��Ƥ��Ͳ",           4.0 },
		{ 'V', "���¿���(С)",       6.5 },
		{ 'W', "���¿���(��)",       8.0 },
		{ 'X', "���¿���(��)",       9.5 },
		{ 'Y', "����",               10.5 },
		{ 'Z', "ѩ������������",     11.0 },
		{ '\0', NULL,                0 }
	};
	struct sp special[] = {
		{ "ANV", "����������ֵ�ײ�",      28 },
		{ "IKIIKIJXIJRXX", "��ֵȫ��Ͱ",  98 },
		{ "UU", "��Ƥ��Ͳ��2�����",     6 },
		{ "OOO", "������2��1",          18 },
		{ NULL, NULL, 0 }
	};


	system("mode con cols=100 lines=40"); // cols Ϊ�� ���� lines Ϊ�� ����
	/*��Ʒ*/
	int total;
	for (int i = 1; ; i++)
	{
		if (list[2 * i - 2].no == '\0')
		{
			total = 2 * i - 2;
			break;
		}
		else
			cout << " " << list[2 * i - 2].no << " " << setw(25) << setiosflags(ios::left) << list[2 * i - 2].name << setw(8) << setiosflags(ios::left) << list[2 * i - 2].rmb << " |";
		if (list[2 * i - 1].no == '\0')
		{
			total = 2 * i - 1;
			break;
		}
		else
			cout << "    " << list[2 * i - 1].no << " " << setw(25) << setiosflags(ios::left) << list[2 * i - 1].name << setw(8) << setiosflags(ios::left) << list[2 * i - 1].rmb << " " << endl;
	}

	/*�ײ�*/
	int setnum=0;
	cout << endl;
	cout << "���Ż���Ϣ��" << endl;
	for (int i = 0; special[i].nos != NULL; i++)
	{
		int n = 0;
		cout << special[i ].names << '=';
		setnum++;
		for (char t = 'A'; t <= 'Z'; t++)
		{
			int count = 0;
			for (int j = 0; special[i].nos[j] != '\0'; j++)
				if (t == special[i].nos[j])
					count++;
			if (count != 0)
			{
				n++;
				if (n > 1)
					cout << '+';
				cout << list[t - 65].name ;
				if (count > 1)
					cout << '*' << count;
			}
		}
		cout << '=' << special[i].rmbs << endl;
	}
	price **set;
	set = new price* [setnum];
	for (int i = 0; i < setnum; i++)
	{
		set[i] = new price[total];
		for (int j = 0; special[i].nos[j] != '\0'; j++)
		{
			set[i][special[i].nos[j] - 65].num++;
			set[i][special[i].nos[j] - 65].disc++;
		}
	}

	/*����*/
	cout << endl;
	cout << "���������˵����" << endl;
	cout << "ANU=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;

	/*�㵥*/
	price *order;
	order = new price[total];
	for (int i = 0; i < total; i++)
	{
		order[i].num = 0;
		order[i].disc = 0;
	}
	cout << endl;
	cout << "��㵥��";
	char choice[5];
	for (int i = 1;; i++)
	{
		if (!cin.get(choice, 5))
			break;
		else
		{
			if (i == 1 && choice[0] == '0'&&choice[1] == '\0')
			{
				cout << endl << "���˳�" << endl;
				return 0;
			}
			else
			{
				for (int i = 0; choice[i] != '\0'; i++)
				{
					char temp = choice[i];
					if (temp >= 'A'&&temp <= 'Z')
						order[temp - 65].num++;
					else if (temp >= 'a'&&temp <= 'z')
						order[temp - 97].num++;
				}
			}
		}
	}
	cout <<endl<< "���ĵ㵥��" << endl;
	for (int i = 0; i < total; i++)
	{
		if (order[i].num > 0)
		{
			cout << list[i].name << '*' << order[i].num;
			cout << endl;
		}
	}
	cout << "���ƣ�";
	cout << endl << endl;
	/*for (int i = 0; i < setnum; i++)
	{
		cout << i+1<<"��  ";
		for (int j = 0; j < total; j++)
		{
			if (set[i][j].num>0)
				cout << list[j].no << '*' << set[i][j].num << '+';
		}
		cout << endl;
	}*/



	/*�Ƽ�*/
	int s = 0;
	double pay = 0;
	for (s = 0; s < setnum; s++)
	{
		while (s+1)
		{
			bool cannot = false;
			for (int i = 0; i < total; i++)
			{	
				if (set[s][i].num>0 && (order[i].num - order[i].disc) < set[s][i].num)
				{
					cannot = true;
					break;
				}
			}
			if (cannot)
				break;
			else
			{
				pay += special[s].rmbs;
				for (int i = 0; i < total; i++)
				{
					if (set[s][i].num>0 && (order[i].num - order[i].disc) >= set[s][i].num)
						order[i].disc += set[s][i].num;
				}
			}
		}
	}
	for (int i = 0; i < total; i++)
	{
		if (order[i].num > order[i].disc)
		{
			pay += ((order[i].num - order[i].disc)*list[i].rmb);
			order[i].disc = order[i].num;
		}
	}
	cout << "��"<<pay << endl;
	cout << endl << "�븶��" << endl;
	delete order;
	for (int i = 0; i < setnum; i++)
		delete set[i];
	delete[]set;

	return 0;
}