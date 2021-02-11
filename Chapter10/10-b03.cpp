#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "10-b3.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
TString::TString()
{
	content = NULL;
	len = 0;
}
TString::TString(const char* c)
{
	if (c == NULL||c[0]=='\0')
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
	if(content!=NULL)
	    delete content;
	len = 0;
}
TString& TString::operator=(const TString& s)
{
	if(content!=NULL)
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
	if (c == NULL||c[0]=='\0')
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
	else if (c == NULL ||c[0] == '\0')
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
	if (s.content == NULL ||s. content[0] == '\0')
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
	if (c == NULL ||c[0] == '\0')
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
		if (strcmp(content,c) >= 0)
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
		if (strcmp(content, s.content)!= 0)
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
		if (strcmp(content,c) != 0)
			return 0;
		else
			return 1;
	}
}
bool TString::operator!=(const TString & s)
{
	if (content == NULL || content[0] == '\0')
	{
		if (s.content == NULL ||s. content[0] == '\0')
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
		if (strcmp(content,c) != 0)
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

/* 如果有需要的其它全局函数的实现，可以写于此处 */
istream& operator>>(istream&in, TString& s)
{
	ch *head=NULL, *p=NULL;
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
	if (c == NULL ||c[0] == '\0')
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
	if (c == NULL ||c[0] == '\0')
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
	if (c == NULL ||c[0] == '\0')
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

