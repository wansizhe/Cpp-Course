#include"97-b5.h"

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int version;
	version = 3;
	qrcode c(version);
	string s = "Kobe Bryant #24";
	string cod = "\0";
	switch (model(s))
	{
	case 0:
		break;
	case 1:
		cod = numcod(s);
		break;
	case 2:
		cod = letnumcod(s);
		break;
	case 3:
		cod = hanzicod(s);
		break;
	}


	c.fill(cod);
	c.mask();
	c.show(hout);

	getchar();
	setcolor(hout, 0, 15);
	cout << endl << endl;
	return 0;
}