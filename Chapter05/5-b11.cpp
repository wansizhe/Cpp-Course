#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	char name[50][9], num[50][10], one[9];
	int n;
	cout << "��������������";
	cin >> n;
	
	/*����ѧ����Ϣ*/
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "��ѧ����������ѧ�ţ�";
		cin >> name[i] >> num[i];
	}
	cout << endl;

	/*����ѧ��*/
	cout << "��������Ҫ���ҵ�ѧ��������";
	cin >> one;
	int k = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(one, name[i]) == 0)
		{
			k++;
			break;
		}
	}
	cout << endl;

	/*������ҽ��*/
	if (k == 0)
		cout << "���޴��ˣ�";
	else
		cout <<"������"<< setw(9) << setiosflags(ios::left) << name[i] << "ѧ�ţ�" << setw(10) << setiosflags(ios::left) << num[i];

	cout << endl;
	cout << endl;
	return 0;
}