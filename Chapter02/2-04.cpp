#include<iostream>
using namespace std;

int main()
{
	char c1 = 'C', c2 = '+', c3 = '+';
	cout << "I say:\"" << c1 << c2 << c3 << '\"';
	cout << "\t\t" << "He says:\"C++ is very interesting!\"" << '\n';
	return 0;//输出：I say:"C++",水平制表，He says:"C++ is very interesting!",换行
}