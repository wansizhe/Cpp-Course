#include<iostream>
#include<cstring>
using namespace std;

short two(char l)
{
	short n,r=1;
	switch (l)
	{
	case 'A':
	case 'a':
		n = 1;
		break;
	case 'B':
	case 'b':
		n = 2;
		break;
	case 'C':
	case 'c':
		n = 3;
		break;
	case 'D':
	case 'd':
		n = 4;
	case 'E':
	case 'e':
		n = 5;
		break;
	case 'F':
	case 'f':
		n = 6;
		break;
	case 'G':
	case 'g':
		n = 7;
		break;
	case 'h':
	case 'H':
		n = 8;
		break;
	case 'I':
	case 'i':
		n = 9;
		break;
	case 'J':
	case 'j':
		n = 10;
		break;
	default:
		break;
	}
	for (int i = 1; i <= n-1; i++)
		r *= 2;
	return r;
}

int main()
{
	short light = 0, t;
	char name[4], turn[4];
	while (1)
	{
		t = light; 
		for (int i = 1; i <= 10; i++)
		{
			cout << char(i + 64);
			if ((t & 1) == 1)
				cout << "on  ";
			else
				cout << "off  ";
			t >>= 1;
		}
		cout << endl;
		cin >> name;
		if (strcmp(name, "end") == 0 || strcmp(name, "END") == 0)
			break;
		cin >> turn;
		if (!((name[0] >= 'A'&&name[0] <= 'J') || (name[0] >= 'a'&&name[0] <= 'j')))
			continue;
		if (!(strcmp(turn,"ON")==0 || strcmp(turn, "OFF") == 0 || strcmp(turn, "on") == 0 || strcmp(turn, "off") == 0))
			continue;
		if (strcmp(turn, "on") == 0 ||strcmp(turn, "ON") == 0)
			light =light| two(name[0]);
		else if (strcmp(turn, "off") == 0 ||strcmp(turn, "OFF") == 0)
			light =( light&(-1 - two(name[0])));
	}
	return 0;
}
