#include<iostream>
using namespace std;

void move(int n, char a, char c, char b)
{
	if (n == 1)
	{
		cout << "�� " << a << " �ϵ�һ���ŵ� " << c << " �ϣ�" << endl << "Ȼ��";
	}
	else
	{
		move(n-1, a, b, c);
		cout << "�� " << a << " �ϵ�һ���ŵ� " << c << " �ϣ�" << endl << "Ȼ��";
		move(n - 1, b, c, a);
	}
	return;
}

int main()
{
	system("cls");
	system("mode con cols=100 lines=30"); // cols Ϊ�� ���� lines Ϊ�� ����
	

	int n;
	char qidian, zhongdian, fuzhu;
	cout << "������A�����Ӹ�����" << endl;
	cout << "n=";
	cin >> n;
	qidian = 'A';
	zhongdian = 'C';
	fuzhu = 'B';
	move(n, qidian, zhongdian, fuzhu);
	cout << "��û��Ȼ���ˣ��Ѿ�Ū���ˡ�" << endl;
	return 0;
}

