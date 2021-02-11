#include<iostream>
using namespace std;

void decode(char word[])
{
	int i;
	for (i = 0; i <=20 ; i++)
	{
		if (word[i] >= 65 && word[i] <= 90)
			word[i] = 64 + 26 - (word[i] - 64) + 1;
		else if (word[i] >= 97 && word[i] <= 122)
			word[i] = 96 + 26 - (word[i] - 96) + 1;
		else
			continue;
	}
	cout << word << endl;
}

int main()
{
	char word[] = "Wrermv Hdliw !!!";
	
	cout << "ÃÜÎÄ£º";
	cout << word << endl;
	cout << "ÒëÎÄ£º";
	decode(word);

	return 0;
}