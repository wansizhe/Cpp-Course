#include <iostream>
using namespace std;

class student {
private:
	int num;
	float score;
public:
	void display();  //���ѧ�źͳɼ�
	void get(void);  //��������ѧ�źͳɼ�
					 //���в�����������κ����ݳ�Ա�ͳ�Ա����
};

/* �ڴ˸������Ա����������ʵ�� */
void student::display()
{
	cout << num << "  " << score << endl;
}

void student::get(void)
{
	cin >> num >> score;
}

int main()
{
	/* ��ע�⣺�������в������ٶ����κ����͵ı���(����ȫ�ֱ���) */
	student *p, s[5];

	/* ��������5���˵�ѧ�ż��ɼ�
	��Ҫ�󣺡����������ȷ��������ʾ�����硰�������**����ѧ�źͳɼ��� */
	for (int i = 1; i <= 5; i++)
	{
		cout << "�������" << i << "����ѧ�źͳɼ�" << endl;
		s[i - 1].get();
	}
	cout << endl;

	/* �����1��3��5���˵���Ϣ */
	p = s;
	p->display();
	(p + 2)->display();
	(p + 4)->display();

	return 0;
}