#include<iostream>
using namespace std;

int main()
{
	char ch[50];
	cout << "ÇëÊäÈë£º" << endl;
	gets_s (ch);
	
	if (ch[0] >= 97 && ch[0] <= 122)
		ch[0] -= 32;
	for (int i = 0; i <= 48; i++)
	{
		if (ch[i] == 32 && ch[i + 1] >= 97 && ch[i + 1] <= 122)
			ch[i + 1] -= 32;
		else if (ch[i] != 32 && ch[i + 1] >= 65 && ch[i + 1] <= 90)
			ch[i + 1] += 32;
	}
	cout << ch;
	cout << endl;
	return 0;
}