#include"7-b17.h"

int main()
{
	FILE* fp;
	int c;
	fp=fopen("�����ļ�.txt","r+");
	if (fp == NULL)
	{
		cout << "�����ļ���ʧ��" << endl;
		return 0;
	}
	double v = 8.24, v0 = 24.8;
	int u = 824;
	int p = -1;
	char v1[10] = "20years", u1[10];
	char v2 = '#', u2;
	
		/*check 1*/
	c = group_add(fp, "test");
	cout << "1��/*test����ӳɹ�*/   " << endl;
	if (c == 1)
		cout << "     test����ӳɹ�" << endl;
	else if (c == 0)
		cout << "     test���Ѵ���" << endl;
	cout << endl;
	getchar();

	c = group_add(fp, "check");
	cout << "2��/*check����ӳɹ�*/   " << endl;
	if (c == 1)
		cout << "     check����ӳɹ�" << endl;
	else if (c == 0)
		cout << "     check���Ѵ���" << endl;
	cout << endl;
	getchar();
		
	c = group_add(fp, "temp");
	cout << "3��/*temp����ӳɹ�*/   " << endl;
	if (c == 1)
		cout << "     temp����ӳɹ�" << endl;
	else if (c == 0)
		cout << "     temp���Ѵ���" << endl;
	cout << endl;
	getchar();

	c = group_add(fp, "test");
	cout << "4��/*test���Ѵ���*/   " << endl;
	if (c == 1)
		cout << "     test����ӳɹ�" << endl;
	else if (c == 0)
		cout << "     test���Ѵ���" << endl;
	cout << endl;
	getchar();

		/*check 2*/
	c = group_del(fp, "check");
	cout << "5��/*check��ɾ���ɹ�*/   " << endl;
	if (c == 1)
		cout << "     check��ɾ���ɹ�" << endl;
	else if (c == 0)
		cout << "     check�鲻����" << endl;
	cout << endl;
	getchar();

	c = group_del(fp, "null");
	cout << "6��/*null�鲻����*/   " << endl;
	if (c == 1)
		cout << "     null��ɾ���ɹ�" << endl;
	else if (c == 0)
		cout << "     null�鲻����" << endl;
	cout << endl;
	getchar();
		
		/*check 3*/
	c = item_add(fp, "test", "KB", &v, TYPE_DOUBLE);
	cout << "7��/*KB����test����ӳɹ�*/   " << endl;
	if (c == 1)
		cout << "     KB����test����ӳɹ�" << endl;
	else if (c == 0)
		cout << "     test�鲻���ڻ�test���Ѵ���KB��" << endl;
	cout << endl;
	getchar();

	c = item_add(fp, "test", "KB", &v, TYPE_DOUBLE);
	cout << "8��/*test�鲻���ڻ�test���Ѵ���KB��*/   " << endl;
	if (c == 1)
		cout << "     KB����test����ӳɹ�" << endl;
	else if (c == 0)
		cout << "     test�鲻���ڻ�test���Ѵ���KB��" << endl;
	cout << endl;
	getchar();
		
	c = item_add(fp, "check", "KB", &v, TYPE_DOUBLE);
	cout << "9��/*check�鲻���ڻ�check���Ѵ���KB��*/   " << endl;
	if (c == 1)
		cout << "     KB����check����ӳɹ�" << endl;
	else if (c == 0)
		cout << "     check�鲻���ڻ�check���Ѵ���KB��" << endl;
	cout << endl;
	getchar();

	c = item_add(fp, "temp", "KB", v1, TYPE_STRING);
	cout << "10��/*KB����temp����ӳɹ�*/   " << endl;
	if (c == 1)
		cout << "      KB����temp����ӳɹ�" << endl;
	else if (c == 0)
		cout << "      temp�鲻���ڻ�temp���Ѵ���KB��" << endl;
	cout << endl;
	getchar();

	c = item_add(fp, "test", "K&B", &v2, TYPE_CHARACTER);
	cout << "11��/*K&B����test����ӳɹ�*/   " << endl;
	if (c == 1)
		cout << "      K&B����test����ӳɹ�" << endl;
	else if (c == 0)
		cout << "      test�鲻���ڻ�test���Ѵ���K&B��" << endl;
	cout << endl;
	getchar();

		/*check 4*/
	c = item_del(fp, "test","K&B");
	cout << "12��/*K&B����test��ɾ���ɹ�*/   " << endl;
	if (c == 1)
		cout << "      K&B����test��ɾ���ɹ�" << endl;
	else if (c == 0)
		cout << "      test�鲻���ڻ�test�鲻����K&B��" << endl;
	cout << endl;
	getchar();
		
	c = item_del(fp, "null", "K&B");
	cout << "13��/*null�鲻���ڻ�null�鲻����K&B��*/   " << endl;
	if (c == 1)
		cout << "      K&B����null��ɾ���ɹ�" << endl;
	else if (c == 0)
		cout << "      null�鲻���ڻ�null�鲻����K&B��" << endl;
	cout << endl;
	getchar();

	c = item_del(fp, "test", "null");
	cout << "14��/*test�鲻���ڻ�test�鲻����null��*/   " << endl;
	if (c == 1)
		cout << "      null����test��ɾ���ɹ�" << endl;
	else if (c == 0)
		cout << "      test�鲻���ڻ�test�鲻����null��" << endl;
	cout << endl;
	getchar();

		/*check 5*/
	c = item_update(fp, "test", "KB",&u,TYPE_INT);
	cout << "15��/*test��KB��ֵ���³ɹ�*/" << endl;
	if (c == 1)
		cout << "      test��KB��ֵ���³ɹ�" << endl;
	else if (c == 0)
		cout << "      test�鲻����" << endl;
	cout << endl;
	getchar();

	

	c = item_update(fp, "test", "K&B", &v0, TYPE_DOUBLE);
	cout << "16��/*test��K&B��ֵ���³ɹ�*/" << endl;
	if (c == 1)
		cout << "      test��K&B��ֵ���³ɹ�" << endl;
	else if (c == 0)
		cout << "      test�鲻����" << endl;
	cout << endl;
	getchar();

	c = item_update(fp, "null", "KB", &u, TYPE_INT);
	cout << "17��/*null�鲻����*/"<<endl;
	if (c == 1)
		cout << "      null��KB��ֵ���³ɹ�" << endl;
	else if (c == 0)
		cout << "      null�鲻����" << endl;
	cout << endl;
	getchar();

		/*check 6*/
	c = item_get_value(fp, "test", "KB", &p, TYPE_INT);
	cout << "18��/*test��KB��ֵ��ȡ�ɹ�  824*/" << endl;
	if (c == 1)
		cout << "      test��KB��ֵ��ȡ�ɹ�  "  << p << endl;
	else if (c == 0)
		cout << "      test�鲻���ڻ�test�鲻����KB��" << endl;
	cout << endl;
	getchar();

	c = item_get_value(fp, "temp", "KB", u1, TYPE_STRING);
	cout << "19��/*temp��KB��ֵ��ȡ�ɹ�  20years*/" << endl;
	if (c == 1)
		cout << "      test��KB��ֵ��ȡ�ɹ�  " <<u1 << endl;
	else if (c == 0)
		cout << "      test�鲻���ڻ�test�鲻����KB��" << endl;
	cout << endl;
	getchar();

	double x;
	c = item_get_value(fp, "null", "KB", &x, TYPE_DOUBLE);
	cout << "20��/*null�鲻���ڻ�null�鲻����KB��*/" << endl;
	if (c == 1)
		cout << "      null��KB��ֵ��ȡ�ɹ�  "<< x << endl;
	else if (c == 0)
		cout << "      null�鲻���ڻ�null�鲻����KB��" << endl;
	cout << endl;
	getchar();

	c = item_get_value(fp, "temp", "null", &u2, TYPE_CHARACTER);
	cout << "21��/*test�鲻���ڻ�test�鲻����null��*/" << endl;
	if (c == 1)
		cout << "      test��null��ֵ��ȡ�ɹ�  " << endl << u2 << endl;
	else if (c == 0)
		cout << "      test�鲻���ڻ�test�鲻����null��" << endl;
	cout << endl;
	getchar();
		
	fclose(fp);
	cout << endl;
	return 0;
}