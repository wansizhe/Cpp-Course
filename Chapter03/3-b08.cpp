#include<iostream>
using namespace std;

int main()
{
	int a, b, c, x;
	cout << "�����������ꡢ�¡��գ�" << endl;
	cin >> a >> b >> c;
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
	{
		switch (b)
		{
		    case 1:
			    if (c >= 1 && c <= 31)
				    cout << "��һ������һ��ĵ� " << (x = c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
			case 2:
				if (c >= 1 && c <= 29)
					cout << "��һ������һ��ĵ� " << (x = 31 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 3:
				if (c >= 1 && c <= 31)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 4:
				if (c >= 1 && c <= 30)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 5:
				if (c >= 1 && c <= 31)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + 30 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 6:
				if (c >= 1 && c <= 30)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + 30 + 31 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 7:
				if (c >= 1 && c <= 31)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + 30 + 31 + 30 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 8:
				if (c >= 1 && c <= 31)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + 30 + 31 + 30 + 31 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 9:
				if (c >= 1 && c <= 30)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 10:
				if (c >= 1 && c <= 31)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 11:
				if (c >= 1 && c <= 30)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			case 12:
				if (c >= 1 && c <= 31)
					cout << "��һ������һ��ĵ� " << (x = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c) << " ��" << endl;
				else
					cout << "�������" << endl;
				break;
			default:
				cout << "�������" << endl;
				break;
		}
	}
	else
	{
		switch (b)
		{
		    case 1:
			    if (c >= 1 && c <= 31)
				    cout << "��һ������һ��ĵ� " << (x = c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 2:
			    if (c >= 1 && c <= 28)
				    cout << "��һ������һ��ĵ� " << (x = 31 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 3:
			    if (c >= 1 && c <= 31)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 4:
			    if (c >= 1 && c <= 30)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 5:
			    if (c >= 1 && c <= 31)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + 30 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 6:
			    if (c >= 1 && c <= 30)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + 30 + 31 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 7:
			    if (c >= 1 && c <= 31)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + 30 + 31 + 30 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 8:
			    if (c >= 1 && c <= 31)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + 30 + 31 + 30 + 31 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 9:
			    if (c >= 1 && c <= 30)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 10:
			    if (c >= 1 && c <= 31)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 11:
			    if (c >= 1 && c <= 30)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    case 12:
			    if (c >= 1 && c <= 31)
				    cout << "��һ������һ��ĵ� " << (x = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c) << " ��" << endl;
			    else
				    cout << "�������" << endl;
			    break;
		    default:
			    cout << "�������" << endl;
			    break;
		}
	}
	return 0;
}