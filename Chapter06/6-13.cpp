#include<iostream>
#include<cmath>
using namespace std;

double fun_sin(double low, double high)
{
	double h, s = 0;
	h = high - low;
	h /= 10000;
	for (int i = 0; i < 10000; i++)
		s += h * sin(low + i * h + h / 2);
	return s;
}

double fun_cos(double low, double high)
{
	double h, s = 0;
	h = high - low;
	h /= 10000;
	for (int i = 0; i < 10000; i++)
		s += h * cos(low + i * h + h / 2);
	return s;
}

double fun_exp(double low, double high)
{
	double h, s = 0;
	h = high - low;
	h /= 10000;
	for (int i = 0; i < 10000; i++)
		s += h * exp(low + i * h + h / 2);
	return s;
}

double definite_integration(double (*p)(double, double), double low, double high)
{
	return p(low, high);
}


int main()
{
	double low, high, value;
	
	cout << "�������sinx���ֵ��ϡ����ޣ�" << endl;
	cin >> low >> high;
	value = definite_integration(fun_sin, low, high);
	cout << " ��sinxdx=" << value << endl << endl;

	cout << "�������cosx���ֵ��ϡ����ޣ�" << endl;
	cin >> low >> high;
	value = definite_integration(fun_cos, low, high);
	cout << " ��cosxdx=" << value << endl << endl;

	cout << "�������e^x���ֵ��ϡ����ޣ�" << endl;
	cin >> low >> high;
	value = definite_integration(fun_exp, low, high);
	cout << " ��e^xdx=" << value << endl << endl;

	return 0;
}

