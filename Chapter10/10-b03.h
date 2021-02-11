#include <iostream>
using namespace std;

/* ��ȫTString��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
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
};

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
istream& operator>>(istream&, TString& s);
ostream& operator<<(ostream&, TString& s);
TString operator+(const char* c,const TString &s);
bool operator>(const char* c, const TString &s);
bool operator<(const char* c, const TString &s);
bool operator>=(const char* c, const TString &s);
bool operator<=(const char* c, const TString &s);
bool operator==(const char* c, const TString &s);
bool operator!=(const char* c, const TString &s);
int TStringLen(TString &s);

/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
struct ch
{
	char c;
	ch* next;
};

