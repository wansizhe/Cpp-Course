#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

/* 在此处给出你的定义及实现 */
struct ch
{
	char c;
	ch* next;
};
class TString {
private:
	char *content;
	int   len;

	/* 根据需要定义所需的成员函数、友元函数等 */
public:
	TString();
	TString(const char* c);
	TString(const TString &s);
	~TString();
	TString& operator=(const TString& s);
	TString& operator=(const char* c);
	TString operator+(const TString & s);
	TString operator+(const char* c);
	bool operator>(const TString & s);
	bool operator>(const char* c);
	bool operator<(const TString & s);
	bool operator<(const char* c);
	bool operator>=(const TString & s);
	bool operator>=(const char* c);
	bool operator<=(const TString & s);
	bool operator<=(const char* c);
	bool operator==(const TString & s);
	bool operator==(const char* c);
	bool operator!=(const TString & s);
	bool operator!=(const char* c);
	char& operator[](const int n);
	int length();
	friend istream& operator>>(istream&, TString& s);
	friend ostream& operator<<(ostream&, TString& s);
	friend TString operator+(const char* c, const TString &s);
	friend bool operator>(const char* c, const TString &s);
	friend bool operator<(const char* c, const TString &s);
	friend bool operator>=(const char*c, const TString &s);
	friend bool operator<=(const char* c, const TString &s);
	friend bool operator==(const char* c, const TString &s);
	friend bool operator!=(const char* c, const TString &s);
	friend int TStringLen(TString &s);
	TString& TString::operator+=(const char* c);
};

/* 给出 TString 类的所有成员函数的体外实现 */
TString::TString()
{
	content = NULL;
	len = 0;
}
TString::TString(const char* c)
{
	if (c == NULL || c[0] == '\0')
	{
		len = 0;
		content = NULL;
	}
	else
	{
		len = strlen(c);
		content = new char[len + 1];
		strcpy(content, c);
	}
}
TString::TString(const TString &s)
{
	if (s.content == NULL || s.content[0] == '\0')
	{
		len = 0;
		content = NULL;
	}
	else
	{
		len = s.len;
		content = new char[len + 1];
		strcpy(content, s.content);
	}
}
TString::~TString()
{
	if (content != NULL)
		delete content;
	len = 0;
}
TString& TString::operator=(const TString& s)
{
	if (content != NULL)
		delete content;
	if (s.content == NULL || s.content[0] == '\0')
	{
		len = 0;
		content = NULL;
	}
	else
	{
		len = s.len;
		content = new char[len + 1];
		strcpy(content, s.content);
	}
	return *this;
}
TString& TString::operator=(const char* c)
{
	if (content != NULL)
		delete content;
	if (c == NULL || c[0] == '\0')
	{
		len = 0;
		content = NULL;
	}
	else
	{
		len = strlen(c);
		content = new char[len + 1];
		strcpy(content, c);
	}
	return *this;
}
TString TString::operator+(const TString & s)
{
	TString ss;
	if ((content == NULL || content[0] == '\0') && (s.content == NULL || s.content[0] == '\0'))
	{
		ss.len = 0;
		ss.content = NULL;
	}
	else
	{
		if (s.content != NULL&&s.content[0] != '\0'&&content != NULL&&content[0] != '\0')
		{
			ss.len = len + s.len;
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, content);
			strcat(ss.content, s.content);
		}
		else if (content != NULL&&content[0] != '\0' && (s.content == NULL || s.content[0] == '\0'))
		{
			ss.len = len;
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, content);
		}
		else if (s.content != NULL&&s.content[0] != '\0' && (content == NULL || content[0] == '\0'))
		{
			ss.len = s.len;
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, s.content);
		}
	}
	return ss;
}
TString TString::operator+(const char* c)
{
	TString ss;
	if ((content == NULL || content[0] == '\0') && (c == NULL || c[0] == '\0'))
	{
		ss.content = NULL;
		ss.len = 0;
	}
	else
	{
		if (c != NULL&&c[0] != '\0'&&content != NULL&&content[0] != '\0')
		{
			ss.len = len + strlen(c);
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, content);
			strcat(ss.content, c);
		}
		else if (content != NULL&&content[0] != '\0' && (c == NULL || c[0] == '\0'))
		{
			ss.len = len;
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, content);
		}
		else if (c != NULL&&c[0] != '\0' && (content == NULL || content[0] == '\0'))
		{
			ss.len = strlen(c);
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, c);
		}
	}
	return ss;
}
bool TString::operator>(const TString & s)
{
	if (content == NULL || content[0] == '\0')
		return 0;
	else if (s.content == NULL || s.content[0] == '\0')
	{
		if (content != NULL&&content[0] != '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(content, s.content) <= 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator>(const char* c)
{
	if (content == NULL || content[0] == '\0')
		return 0;
	else if (c == NULL || c[0] == '\0')
	{
		if (content != NULL&&content[0] != '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(content, c) <= 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator<(const TString & s)
{
	if (s.content == NULL || s.content[0] == '\0')
		return 0;
	else if (content == NULL || content[0] == '\0')
	{
		if (s.content != NULL&&s.content[0] != '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(content, s.content) >= 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator<(const char* c)
{
	if (c == NULL || c[0] == '\0')
		return 0;
	else if (content == NULL || content[0] == '\0')
	{
		if (c != NULL&&c[0] != '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(content, c) >= 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator>=(const TString & s)
{
	if (content == NULL || content[0] == '\0')
	{
		if (s.content == NULL || s.content[0] == '\0')
			return 1;
		else
			return 0;
	}
	else if (s.content == NULL || s.content[0] == '\0')
	{
		return 1;
	}
	else
	{
		if (strcmp(content, s.content)< 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator>=(const char* c)
{
	if (content == NULL || content[0] == '\0')
	{
		if (c == NULL || c[0] == '\0')
			return 1;
		else
			return 0;
	}
	else if (c == NULL || c[0] == '\0')
	{
		return 1;
	}
	else
	{
		if (strcmp(content, c)< 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator<=(const TString & s)
{
	if (content == NULL || content[0] == '\0')
	{
		return 1;
	}
	else if (s.content == NULL || s.content[0] == '\0')
	{
		if (content == NULL || content[0] == '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(content, s.content)> 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator<=(const char* c)
{
	if (content == NULL || content[0] == '\0')
	{
		return 1;
	}
	else if (c == NULL || c[0] == '\0')
	{
		if (content == NULL || content[0] == '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(content, c)> 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator==(const TString & s)
{
	if (content == NULL || content[0] == '\0')
	{
		if (s.content == NULL || s.content[0] == '\0')
			return 1;
		else
			return 0;
	}
	else if (s.content == NULL || s.content[0] == '\0')
	{
		if (content == NULL || content[0] == '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(content, s.content) != 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator==(const char* c)
{
	if (content == NULL || content[0] == '\0')
	{
		if (c == NULL || c[0] == '\0')
			return 1;
		else
			return 0;
	}
	else if (c == NULL || c[0] == '\0')
	{
		if (content == NULL || content[0] == '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(content, c) != 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator!=(const TString & s)
{
	if (content == NULL || content[0] == '\0')
	{
		if (s.content == NULL || s.content[0] == '\0')
			return 0;
		else
			return 1;
	}
	else if (s.content == NULL || s.content[0] == '\0')
	{
		if (content == NULL || content[0] == '\0')
			return 0;
		else
			return 1;
	}
	else
	{
		if (strcmp(content, s.content) != 0)
			return 1;
		else
			return 0;
	}
}
bool TString::operator!=(const char* c)
{
	if (content == NULL || content[0] == '\0')
	{
		if (c == NULL || c[0] == '\0')
			return 0;
		else
			return 1;
	}
	else if (c == NULL || c[0] == '\0')
	{
		if (content == NULL || content[0] == '\0')
			return 0;
		else
			return 1;
	}
	else
	{
		if (strcmp(content, c) != 0)
			return 1;
		else
			return 0;
	}
}
char& TString::operator[](const int n)
{
	return content[n];
}
int TString::length()
{
	return len;
}
TString& TString::operator+=(const char* c)
{
	if (c != NULL&&c[0] != '\0'&&content != NULL&&content[0] != '\0')
	{
		int lc = strlen(c);
		//len += strlen(c);
		char *t = new char[(len+=lc)+1];
		strcpy(t, content);
		/*int i,j;
		for (i = 0; content[i] != '\0'; i++)
			t[i] = content[i];*/
		delete content;
		strcpy(t+len-lc, c);
		/*for (j=0; c[j] != '\0'; i++, j++)
			t[i] = c[j];
		t[i] = '\0';*/
		//strcat(t, c);
		content= t;
	}
	else if (c != NULL&&c[0] != '\0' && (content == NULL || content[0] == '\0'))
	{
		len = strlen(c);
		content = new char[len + 1];
		strcpy(content, c);
	}
	return *this;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
istream& operator>>(istream&in, TString& s)
{
	ch *head = NULL, *p = NULL;
	char c;
	int l = 0;
	while (in.get(c))
	{

		if (c == ' ' || c == '\n')
			break;
		else
		{
			if (l == 0)
			{
				p = new ch;
				head = p;
				p->next = NULL;
				p->c = c;
			}
			else
			{
				p->next = new ch;
				p = p->next;
				p->next = NULL;
				p->c = c;
			}
			l++;
		}
	}
	s.content = new char[l + 1];
	p = head;
	s.content[l] = '\0';
	for (int i = 0; i < l; i++)
	{
		s.content[i] = p->c;
		s.content[i + 1] = '\0';
		p = p->next;
	}
	p = head;
	while (p != NULL)
	{
		ch *t = p->next;
		delete p;
		p = t;
	}
	return in;
}
ostream& operator<<(ostream&out, TString& s)
{
	if (s.content == NULL)
		out << "<NULL>";
	else
		out << s.content;
	return out;
}
TString operator+(const char* c, const TString &s)
{
	TString ss;
	if ((c == NULL || c[0] == '\0') && (s.content == NULL || s.content[0] == '\0'))
	{
		ss.len = 0;
		ss.content = NULL;
	}
	else
	{
		if (s.content != NULL&&s.content[0] != '\0'&&c != NULL&&c[0] != '\0')
		{
			ss.len = s.len + strlen(c);
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, c);
			strcat(ss.content, s.content);
		}
		else if (c != NULL&&c[0] != '\0' && (s.content == NULL || s.content[0] == '\0'))
		{
			ss.len = strlen(c);
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, c);
		}
		else if (s.content != NULL&&s.content[0] != '\0' && (c == NULL || c[0] == '\0'))
		{
			ss.len = s.len;
			ss.content = new char[ss.len + 1];
			strcpy(ss.content, s.content);
		}
	}
	return ss;
}
bool operator>(const char* c, const TString &s)
{
	if (c == NULL || c[0] == '\0')
		return 0;
	else if (s.content == NULL || s.content[0] == '\0')
	{
		if (c != NULL&&c[0] != '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(c, s.content) <= 0)
			return 0;
		else
			return 1;
	}
}
bool operator<(const char* c, const TString &s)
{
	if (s.content == NULL || s.content[0] == '\0')
		return 0;
	else if (c == NULL || c[0] == '\0')
	{
		if (s.content != NULL&&s.content[0] != '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(c, s.content) >= 0)
			return 0;
		else
			return 1;
	}
}
bool operator>=(const char* c, const TString &s)
{
	if (c == NULL || c[0] == '\0')
	{
		if (s.content == NULL || s.content[0] == '\0')
			return 1;
		else
			return 0;
	}
	else if (s.content == NULL || s.content[0] == '\0')
	{
		return 1;
	}
	else
	{
		if (strcmp(c, s.content)< 0)
			return 0;
		else
			return 1;
	}
}
bool operator<=(const char* c, const TString &s)
{
	if (c == NULL || c[0] == '\0')
	{
		return 1;
	}
	else if (s.content == NULL || s.content[0] == '\0')
	{
		if (c == NULL || c[0] == '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(c, s.content)> 0)
			return 0;
		else
			return 1;
	}
}
bool operator==(const char* c, const TString &s)
{
	if (c == NULL || c[0] == '\0')
	{
		if (s.content == NULL || s.content[0] == '\0')
			return 1;
		else
			return 0;
	}
	else if (s.content == NULL || s.content[0] == '\0')
	{
		if (c == NULL || c[0] == '\0')
			return 1;
		else
			return 0;
	}
	else
	{
		if (strcmp(c, s.content) != 0)
			return 0;
		else
			return 1;
	}
}
bool operator!=(const char* c, const TString &s)
{
	if (c == NULL || c[0] == '\0')
	{
		if (s.content == NULL || s.content[0] == '\0')
			return 0;
		else
			return 1;
	}
	else if (s.content == NULL || s.content[0] == '\0')
	{
		if (c == NULL || c[0] == '\0')
			return 0;
		else
			return 1;
	}
	else
	{
		if (strcmp(c, s.content) != 0)
			return 1;
		else
			return 0;
	}
}
int TStringLen(TString &s)
{
	return s.len;
}

/* main 函数不允许改动 */
int main()
{
	const int MAX_BYTES = 100 * 1024 * 1024;
	TString s1;

	int     total, len, i;
	char    temp[65536];
	long    t_start, t_end;
	char   *crc_str;

	cout << "内存累加申请性能测试，以内存耗尽或申请满100MB字节为结束条件，按任意键开始" << endl;
	_getch();

	crc_str = new char[MAX_BYTES + 65536]; //申请（100MB+64KB）空间
	if (crc_str == NULL) {
		cout << "无法申请" << MAX_BYTES + 65536 << "字节的校验空间，程序终止，请检查后再次运行" << endl;
		goto END;
	}
	*crc_str = 0; //置为空串

	t_start = GetTickCount(); //取当前系统时间，单位毫秒
	srand((unsigned int)time(0));
	total = 0;
	while (1) {
		len = 32768 + rand() % 32768;

		cout << "s1已有长度：" << s1.length() / (1024.0 * 1024) << " MB字节，本次增加 " << len << " 字节" << endl;
		for (i = 0; i<len; i++)
			temp[i] = ' ' + rand() % 95;	//数组用随机字符填充
		temp[len] = 0;
		total += len;
		s1 += temp;
		strcat(crc_str, temp);
		if (s1.length() == 0 || s1.length() > MAX_BYTES)	//满100MB或内存耗尽则结束
			break;

		/* 下面做的事不要问问什么，任性 */
		if (1) {
			char d1[64], d2[16];
			int  d1_len, d2_len;
			d1_len = 16 + rand() % 16;
			d2_len = 8 + rand() % 8;
			for (i = 0; i < d1_len; i++)
				d1[i] = ' ' + rand() % 95;
			d1[d1_len] = 0;
			for (i = 0; i < d2_len; i++)
				d2[i] = ' ' + rand() % 95;
			d2[d2_len] = 0;
			strcat(d1, d2);
		}
	}
	t_end = GetTickCount();   //取当前系统时间

	cout << "time=" << (t_end - t_start) / 1000.0 << endl;
	if (s1.length() == 0)
		cout << "内存分配到达 " << total / (1024.0 * 1024) << " MB字节后，内存耗尽" << endl;
	else
		cout << "内存分配到达满100MB，测试结束" << endl;

	if (s1 != crc_str)
		cout << "s1累加验证出错，请检查程序的实现部分" << endl;
	else
		cout << "    本次测试耗时 " << (t_end - t_start) / 1000.0 << "秒" << endl;

	delete crc_str;

	cout << endl;

END:
	cout << "请打开任务管理器，观察本程序此时的内存占用情况" << endl << endl;
	system("pause");

	return 0;
}
