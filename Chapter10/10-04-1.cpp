#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
private:
	int value[2][3];
public:
	matrix(int(*p)[3]);  //���캯�����������ʼ������
	void display();       //����þ���
	matrix operator+(matrix &b);
	/* ----������Ҫ���������Ա�����Ķ���---- */
	matrix();
};

/* ----�������Ա����������ʵ��---- */
matrix::matrix()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			value[i][j] = 0;
}
matrix::matrix(int(*p)[3])
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			value[i][j] = p[i][j];
}
void matrix::display()
{
	cout << "| ";
	for (int i = 0; i < 3; i++)
		cout << setw(2) << value[0][i] << ' ';
	cout << '|' << endl;
	cout << "| ";
	for (int i = 0; i < 3; i++)
		cout << setw(2) << value[1][i] << ' ';
	cout << '|' << endl;
}
matrix matrix::operator+(matrix &b)
{
	matrix c;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c.value[i][j] = value[i][j] + b.value[i][j];
	return c;
}

/* ----main������׼��---- */
int main()
{
	int a[2][3] = { { 1,2,3 },{ 4,5,6 } };
	int b[2][3] = { { 1,2,3 },{ 4,5,6 } };
	matrix m1(a), m2(b), m3;

	cout << "��ʼ����m1��ֵ��" << endl;
	m1.display();
	cout << "��ʼ����m2��ֵ��" << endl;
	m2.display();
	m3 = m1 + m2;
	cout << "��Ӻ����m3��ֵ��" << endl;
	m3.display();

	return 0;
}
