#include <iostream>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
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
};

/* 如果有其它全局函数需要声明，写于此处 */
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

/* 如果有需要的宏定义、只读全局变量等，写于此处 */
struct ch
{
	char c;
	ch* next;
};

