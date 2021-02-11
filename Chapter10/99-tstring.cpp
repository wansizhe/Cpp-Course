#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

/* �ڴ˴�������Ķ��弰ʵ�� */
struct ch
{
	char c;
	ch* next;
};
class TString {
private:
	char *content;
	int   len;

	/* ������Ҫ��������ĳ�Ա��������Ԫ������ */
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

/* ���� TString ������г�Ա����������ʵ�� */
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

/* �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� */
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

/* main ����������Ķ� */
int main()
{
	const int MAX_BYTES = 100 * 1024 * 1024;
	TString s1;

	int     total, len, i;
	char    temp[65536];
	long    t_start, t_end;
	char   *crc_str;

	cout << "�ڴ��ۼ��������ܲ��ԣ����ڴ�ľ���������100MB�ֽ�Ϊ�������������������ʼ" << endl;
	_getch();

	crc_str = new char[MAX_BYTES + 65536]; //���루100MB+64KB���ռ�
	if (crc_str == NULL) {
		cout << "�޷�����" << MAX_BYTES + 65536 << "�ֽڵ�У��ռ䣬������ֹ��������ٴ�����" << endl;
		goto END;
	}
	*crc_str = 0; //��Ϊ�մ�

	t_start = GetTickCount(); //ȡ��ǰϵͳʱ�䣬��λ����
	srand((unsigned int)time(0));
	total = 0;
	while (1) {
		len = 32768 + rand() % 32768;

		cout << "s1���г��ȣ�" << s1.length() / (1024.0 * 1024) << " MB�ֽڣ��������� " << len << " �ֽ�" << endl;
		for (i = 0; i<len; i++)
			temp[i] = ' ' + rand() % 95;	//����������ַ����
		temp[len] = 0;
		total += len;
		s1 += temp;
		strcat(crc_str, temp);
		if (s1.length() == 0 || s1.length() > MAX_BYTES)	//��100MB���ڴ�ľ������
			break;

		/* ���������²�Ҫ����ʲô������ */
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
	t_end = GetTickCount();   //ȡ��ǰϵͳʱ��

	cout << "time=" << (t_end - t_start) / 1000.0 << endl;
	if (s1.length() == 0)
		cout << "�ڴ���䵽�� " << total / (1024.0 * 1024) << " MB�ֽں��ڴ�ľ�" << endl;
	else
		cout << "�ڴ���䵽����100MB�����Խ���" << endl;

	if (s1 != crc_str)
		cout << "s1�ۼ���֤������������ʵ�ֲ���" << endl;
	else
		cout << "    ���β��Ժ�ʱ " << (t_end - t_start) / 1000.0 << "��" << endl;

	delete crc_str;

	cout << endl;

END:
	cout << "���������������۲챾�����ʱ���ڴ�ռ�����" << endl << endl;
	system("pause");

	return 0;
}
