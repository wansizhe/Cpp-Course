#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
private:
	int value[2][3];
public:
	matrix operator+(matrix &b);
	/* ----������Ҫ���������Ա�����Ķ���---- */
	friend istream& operator>>(istream&in, matrix&b);
	friend ostream& operator<<(ostream&out, matrix&b);
};

/* ----�������Ա����������ʵ��---- */
matrix matrix::operator+(matrix &b)
{
	matrix c;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c.value[i][j] = value[i][j] + b.value[i][j];
	return c;
}
istream& operator>>(istream&in, matrix&b)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			in >>  b.value[i][j];
	return in;
}
ostream& operator<<(ostream&out, matrix&b)
{
	out << "| ";
	for (int i = 0; i < 3; i++)
		out << setw(2) << b.value[0][i] << ' ';
	out << '|' << endl;
	out << "| ";
	for (int i = 0; i < 3; i++)
		out << setw(2) << b.value[1][i] << ' ';
	out << '|' << endl;
	return out;
}

/* ----main������׼��---- */
int main()
{
	matrix m1, m2, m3;

	cout << "���������m1��ֵ(��2��3�У������к��е�˳������)" << endl;
	cin >> m1;
	cout << "���������m2��ֵ(��2��3�У������к��е�˳������)" << endl;
	cin >> m2;

	cout << "��ʼ����m1��ֵ��" << endl;
	cout << m1 << endl;
	cout << "��ʼ����m2��ֵ��" << endl;
	cout << m2 << endl;
	cout << "��Ӻ����m3��ֵ��" << endl;
	cout << (m3 = m1 + m2) << endl;

	return 0;
}
