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
	/* 模拟数据 */
	struct kfc list[] = {
		{ 'A', "香辣鸡腿堡",         15.5 },
		{ 'B', "劲脆鸡腿堡",         15.5 },
		{ 'C', "新奥尔良烤鸡腿堡",   16.5 },
		{ 'D', "川香双层鸡腿堡",     16.0 },
		{ 'E', "新至珍全虾堡",       15.5 },
		{ 'F', "培根鸡腿燕麦堡",     17.5 },
		{ 'G', "老北京鸡肉卷",       15.0 },
		{ 'H', "川辣嫩牛卷",         16.0 },
		{ 'I', "吮指原味鸡",         10.5 },
		{ 'J', "新奥尔良烤翅",       10.5 },
		{ 'K', "香辣鸡翅",           9.5 },
		{ 'L', "劲脆鸡米花",         10.5 },
		{ 'M', "骨肉相连",           7.0 },
		{ 'N', "薯条(小)",           7.0 },
		{ 'O', "薯条(中)",           9.0 },
		{ 'P', "薯条(大)",           10.0 },
		{ 'Q', "芙蓉蔬荟汤",         7.5 },
		{ 'R', "香甜粟米棒",         8.5 },
		{ 'S', "土豆泥",             6.0 },
		{ 'T', "玉米色拉",           8.0 },
		{ 'U', "脆皮甜筒",           4.0 },
		{ 'V', "百事可乐(小)",       6.5 },
		{ 'W', "百事可乐(中)",       8.0 },
		{ 'X', "百事可乐(大)",       9.5 },
		{ 'Y', "九珍",               10.5 },
		{ 'Z', "雪顶爱尔兰咖啡",     11.0 },
		{ '\0', NULL,                0 }
	};
	struct sp special[] = {
		{ "ANV", "香辣汉堡超值套餐",      28 },
		{ "IKIIKIJXIJRXX", "超值全家桶",  98 },
		{ "UU", "脆皮甜筒第2件半价",     6 },
		{ "OOO", "中薯买2送1",          18 },
		{ NULL, NULL, 0 }
	};


	system("mode con cols=100 lines=40"); // cols 为列 即宽 lines 为行 即高
	/*单品*/
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

	/*套餐*/
	int setnum=0;
	cout << endl;
	cout << "【优惠信息】" << endl;
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

	/*规则*/
	cout << endl;
	cout << "【输入规则说明】" << endl;
	cout << "ANU=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;

	/*点单*/
	price *order;
	order = new price[total];
	for (int i = 0; i < total; i++)
	{
		order[i].num = 0;
		order[i].disc = 0;
	}
	cout << endl;
	cout << "请点单：";
	char choice[5];
	for (int i = 1;; i++)
	{
		if (!cin.get(choice, 5))
			break;
		else
		{
			if (i == 1 && choice[0] == '0'&&choice[1] == '\0')
			{
				cout << endl << "已退出" << endl;
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
	cout <<endl<< "您的点单：" << endl;
	for (int i = 0; i < total; i++)
	{
		if (order[i].num > 0)
		{
			cout << list[i].name << '*' << order[i].num;
			cout << endl;
		}
	}
	cout << "共计：";
	cout << endl << endl;
	/*for (int i = 0; i < setnum; i++)
	{
		cout << i+1<<"、  ";
		for (int j = 0; j < total; j++)
		{
			if (set[i][j].num>0)
				cout << list[j].no << '*' << set[i][j].num << '+';
		}
		cout << endl;
	}*/



	/*计价*/
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
	cout << "￥"<<pay << endl;
	cout << endl << "请付款" << endl;
	delete order;
	for (int i = 0; i < setnum; i++)
		delete set[i];
	delete[]set;

	return 0;
}