#include"7-b17.h"

int main()
{
	FILE* fp;
	int c;
	fp=fopen("配置文件.txt","r+");
	if (fp == NULL)
	{
		cout << "配置文件打开失败" << endl;
		return 0;
	}
	double v = 8.24, v0 = 24.8;
	int u = 824;
	int p = -1;
	char v1[10] = "20years", u1[10];
	char v2 = '#', u2;
	
		/*check 1*/
	c = group_add(fp, "test");
	cout << "1、/*test组添加成功*/   " << endl;
	if (c == 1)
		cout << "     test组添加成功" << endl;
	else if (c == 0)
		cout << "     test组已存在" << endl;
	cout << endl;
	getchar();

	c = group_add(fp, "check");
	cout << "2、/*check组添加成功*/   " << endl;
	if (c == 1)
		cout << "     check组添加成功" << endl;
	else if (c == 0)
		cout << "     check组已存在" << endl;
	cout << endl;
	getchar();
		
	c = group_add(fp, "temp");
	cout << "3、/*temp组添加成功*/   " << endl;
	if (c == 1)
		cout << "     temp组添加成功" << endl;
	else if (c == 0)
		cout << "     temp组已存在" << endl;
	cout << endl;
	getchar();

	c = group_add(fp, "test");
	cout << "4、/*test组已存在*/   " << endl;
	if (c == 1)
		cout << "     test组添加成功" << endl;
	else if (c == 0)
		cout << "     test组已存在" << endl;
	cout << endl;
	getchar();

		/*check 2*/
	c = group_del(fp, "check");
	cout << "5、/*check组删除成功*/   " << endl;
	if (c == 1)
		cout << "     check组删除成功" << endl;
	else if (c == 0)
		cout << "     check组不存在" << endl;
	cout << endl;
	getchar();

	c = group_del(fp, "null");
	cout << "6、/*null组不存在*/   " << endl;
	if (c == 1)
		cout << "     null组删除成功" << endl;
	else if (c == 0)
		cout << "     null组不存在" << endl;
	cout << endl;
	getchar();
		
		/*check 3*/
	c = item_add(fp, "test", "KB", &v, TYPE_DOUBLE);
	cout << "7、/*KB项在test组添加成功*/   " << endl;
	if (c == 1)
		cout << "     KB项在test组添加成功" << endl;
	else if (c == 0)
		cout << "     test组不存在或test组已存在KB项" << endl;
	cout << endl;
	getchar();

	c = item_add(fp, "test", "KB", &v, TYPE_DOUBLE);
	cout << "8、/*test组不存在或test组已存在KB项*/   " << endl;
	if (c == 1)
		cout << "     KB项在test组添加成功" << endl;
	else if (c == 0)
		cout << "     test组不存在或test组已存在KB项" << endl;
	cout << endl;
	getchar();
		
	c = item_add(fp, "check", "KB", &v, TYPE_DOUBLE);
	cout << "9、/*check组不存在或check组已存在KB项*/   " << endl;
	if (c == 1)
		cout << "     KB项在check组添加成功" << endl;
	else if (c == 0)
		cout << "     check组不存在或check组已存在KB项" << endl;
	cout << endl;
	getchar();

	c = item_add(fp, "temp", "KB", v1, TYPE_STRING);
	cout << "10、/*KB项在temp组添加成功*/   " << endl;
	if (c == 1)
		cout << "      KB项在temp组添加成功" << endl;
	else if (c == 0)
		cout << "      temp组不存在或temp组已存在KB项" << endl;
	cout << endl;
	getchar();

	c = item_add(fp, "test", "K&B", &v2, TYPE_CHARACTER);
	cout << "11、/*K&B项在test组添加成功*/   " << endl;
	if (c == 1)
		cout << "      K&B项在test组添加成功" << endl;
	else if (c == 0)
		cout << "      test组不存在或test组已存在K&B项" << endl;
	cout << endl;
	getchar();

		/*check 4*/
	c = item_del(fp, "test","K&B");
	cout << "12、/*K&B项在test组删除成功*/   " << endl;
	if (c == 1)
		cout << "      K&B项在test组删除成功" << endl;
	else if (c == 0)
		cout << "      test组不存在或test组不存在K&B项" << endl;
	cout << endl;
	getchar();
		
	c = item_del(fp, "null", "K&B");
	cout << "13、/*null组不存在或null组不存在K&B项*/   " << endl;
	if (c == 1)
		cout << "      K&B项在null组删除成功" << endl;
	else if (c == 0)
		cout << "      null组不存在或null组不存在K&B项" << endl;
	cout << endl;
	getchar();

	c = item_del(fp, "test", "null");
	cout << "14、/*test组不存在或test组不存在null项*/   " << endl;
	if (c == 1)
		cout << "      null项在test组删除成功" << endl;
	else if (c == 0)
		cout << "      test组不存在或test组不存在null项" << endl;
	cout << endl;
	getchar();

		/*check 5*/
	c = item_update(fp, "test", "KB",&u,TYPE_INT);
	cout << "15、/*test组KB项值更新成功*/" << endl;
	if (c == 1)
		cout << "      test组KB项值更新成功" << endl;
	else if (c == 0)
		cout << "      test组不存在" << endl;
	cout << endl;
	getchar();

	

	c = item_update(fp, "test", "K&B", &v0, TYPE_DOUBLE);
	cout << "16、/*test组K&B项值更新成功*/" << endl;
	if (c == 1)
		cout << "      test组K&B项值更新成功" << endl;
	else if (c == 0)
		cout << "      test组不存在" << endl;
	cout << endl;
	getchar();

	c = item_update(fp, "null", "KB", &u, TYPE_INT);
	cout << "17、/*null组不存在*/"<<endl;
	if (c == 1)
		cout << "      null组KB项值更新成功" << endl;
	else if (c == 0)
		cout << "      null组不存在" << endl;
	cout << endl;
	getchar();

		/*check 6*/
	c = item_get_value(fp, "test", "KB", &p, TYPE_INT);
	cout << "18、/*test组KB项值获取成功  824*/" << endl;
	if (c == 1)
		cout << "      test组KB项值获取成功  "  << p << endl;
	else if (c == 0)
		cout << "      test组不存在或test组不存在KB项" << endl;
	cout << endl;
	getchar();

	c = item_get_value(fp, "temp", "KB", u1, TYPE_STRING);
	cout << "19、/*temp组KB项值获取成功  20years*/" << endl;
	if (c == 1)
		cout << "      test组KB项值获取成功  " <<u1 << endl;
	else if (c == 0)
		cout << "      test组不存在或test组不存在KB项" << endl;
	cout << endl;
	getchar();

	double x;
	c = item_get_value(fp, "null", "KB", &x, TYPE_DOUBLE);
	cout << "20、/*null组不存在或null组不存在KB项*/" << endl;
	if (c == 1)
		cout << "      null组KB项值获取成功  "<< x << endl;
	else if (c == 0)
		cout << "      null组不存在或null组不存在KB项" << endl;
	cout << endl;
	getchar();

	c = item_get_value(fp, "temp", "null", &u2, TYPE_CHARACTER);
	cout << "21、/*test组不存在或test组不存在null项*/" << endl;
	if (c == 1)
		cout << "      test组null项值获取成功  " << endl << u2 << endl;
	else if (c == 0)
		cout << "      test组不存在或test组不存在null项" << endl;
	cout << endl;
	getchar();
		
	fclose(fp);
	cout << endl;
	return 0;
}