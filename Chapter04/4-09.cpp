#include<iostream>
using namespace std;

void move(int n, char a, char c, char b)
{
	if (n == 1)
	{
		cout << "把 " << a << " 上的一个放到 " << c << " 上；" << endl << "然后，";
	}
	else
	{
		move(n-1, a, b, c);
		cout << "把 " << a << " 上的一个放到 " << c << " 上；" << endl << "然后，";
		move(n - 1, b, c, a);
	}
	return;
}

int main()
{
	system("cls");
	system("mode con cols=100 lines=30"); // cols 为列 即宽 lines 为行 即高
	

	int n;
	char qidian, zhongdian, fuzhu;
	cout << "请输入A中盘子个数：" << endl;
	cout << "n=";
	cin >> n;
	qidian = 'A';
	zhongdian = 'C';
	fuzhu = 'B';
	move(n, qidian, zhongdian, fuzhu);
	cout << "就没有然后了，已经弄完了。" << endl;
	return 0;
}

