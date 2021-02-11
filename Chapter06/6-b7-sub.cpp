#include <iostream>
using namespace std;

/* 函数的原型定义不准变 */
int   tj_strlen(const char *str);
char *tj_strcat(char *s1, const char *s2);
char *tj_strcpy(char *s1, const char *s2);
char *tj_strncpy(char *s1, const char *s2, const int len);
int   tj_strcmp(const char *s1, const char *s2);
int   tj_strcasecmp(const char *s1, const char *s2);
int   tj_strncmp(const char *s1, const char *s2, const int len);
int   tj_strcasencmp(const char *s1, const char *s2, const int len);
char *tj_strupr(char *str);
char *tj_strlwr(char *str);
int   tj_strchr(const char *str, const char ch);
int   tj_strstr(const char *str, const char *substr);
int   tj_strrchr(const char *str, const char ch);
int   tj_strrstr(const char *str, const char *substr);
char *tj_strrev(char *str);

/* ----- 不允许定义任何形式的全局数组!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
int tj_strlen(const char *str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	const char *p;
	p = str;
	if (p == NULL)
		return 0;
	else
	{
		int i;
		for (i = 0; *p != 0;p++)
			i++;
		return i;
	}
}

char *tj_strcat(char *s1, const char *s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	const char *p1 = s1,*p2=s2;
	char *p = s1;
	if (p1 == NULL)
		return NULL;
	else if (p2 == NULL)
		return s1;
	else
	{
		int l=tj_strlen(p1);
		p = p + l;
		for (; *p2 != 0; p++, p2++)
			*p = *p2;
		*p = 0;
		return s1;
	}
}

char *tj_strcpy(char *s1, const char *s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL)
		return NULL;
	else if (s2 == NULL)
	{
		*s1 = 0;
		return s1;
	}
	else
	{
		char *p1 = s1;
		const char *p2 = s2;
		for (; *p2 != 0; p1++, p2++)
			*p1 = *p2;
		*p1 = 0;
		return s1;
	}
}

char *tj_strncpy(char *s1, const char *s2, const int len)
{
	if (s1 == NULL)
		return NULL;
	else if (s2 == NULL)
		return s1;
	else
	{
		char *p1 = s1;
		const char *p2 = s2;
		for (; *p2 != 0&&(p2-s1<len); p1++, p2++)
			*p1 = *p2;
		return s1;
	}
}

int tj_strcmp(const char *s1, const char *s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL&&s2 == NULL)
		return NULL;
	else if (s1 == NULL&&s2 != NULL)
		return -1;
	else if (s1 != NULL&&s2 == NULL)
		return 1;
	else
	{
		const char *p1 = s1, *p2 = s2;
		for (; ; p1++, p2++)
			if ((*p1 != *p2) || (*p1 == 0 && *p2 == 0))
				break;
		return int(*p1 - *p2);
	}
}

int tj_strcasecmp(const char *s1, const char *s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL&&s2 == NULL)
		return NULL;
	else if (s1 == NULL&&s2 != NULL)
		return -1;
	else if (s1 != NULL&&s2 == NULL)
		return 1;
	else
	{
		const char *p1 = s1, *p2 = s2;
		for (; ; p1++, p2++)
		{
			char a=*p1, b=*p2;
			if (((a >= 'A'&&a <= 'Z') || (a >= 'a'&&a <= 'z')) && ((b >= 'A'&&b <= 'Z') || (b >= 'a'&&b <= 'z')))
			{
				if (a >= 'a'&&a <= 'z')
					a -= 32;
				if (b >= 'a'&&b <= 'z')
					b -= 32;
			}
			if ((a != b) || (a == 0 && b == 0))
			    return int(a - b);
		}
	}
}

int tj_strncmp(const char *s1, const char *s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL&&s2 == NULL)
		return NULL;
	else if (s1 == NULL&&s2 != NULL)
		return -1;
	else if (s1 != NULL&&s2 == NULL)
		return 1;
	else
	{
		const char *p1 = s1, *p2 = s2;
		for (; (p1 - s1 != len-1 ); p1++, p2++)
			if ((*p1 != *p2) || (*p1 == 0 && *p2 == 0))
				break;
		return int(*p1 - *p2);
	}
}

int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL&&s2 == NULL)
		return NULL;
	else if (s1 == NULL&&s2 != NULL)
		return -1;
	else if (s1 != NULL&&s2 == NULL)
		return 1;
	else
	{
		char a, b;
		const char *p1 = s1, *p2 = s2;
		for (; (p1 - s1 != len ); p1++, p2++)
		{
			a = *p1;
			b = *p2;
			if (((a >= 'A'&&a <= 'Z') || (a >= 'a'&&a <= 'z')) && ((b >= 'A'&&b <= 'Z') || (b >= 'a'&&b <= 'z')))
			{
				if (a >= 'a'&&a <= 'z')
					a -= 32;
				if (b >= 'a'&&b <= 'z')
					b -= 32;
			}
			if ((a != b) || (a == 0 && b == 0))
				break;
		}
		return int(a - b);
	}
}

char *tj_strupr(char *str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return NULL;
	else
	{
		char *p = str;
		for (; *p++ != 0;)
			if (*p >= 'a'&&*p <= 'z')
				*p -= 32;
		return str;
	}
}

char *tj_strlwr(char *str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return NULL;
	else
	{
		char *p = str;
		for (; *p++ != 0;)
			if (*p >= 'A'&&*p <= 'Z')
				*p += 32;
		return str;
	}
}

int tj_strchr(const char *str, const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return NULL;
	else
	{
		bool found = false;
		const char *p = str;
		for (;p<=str+(tj_strlen(str)-1); p++)
		{
			if (*p == ch)
				found = true;
			if (found)
				break;
		}
		return found?int(p - str) + 1:0;
	}
}

int tj_strstr(const char *str, const char *substr)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	bool found = false;
	if (str == NULL || substr == NULL)
		return NULL;
	else
	{
		bool found = false;
		const char *p = str, *sp = substr;
		for (;p<=str+(tj_strlen(str)-1); p++)
		{
			if (*p == *sp)
			{
				found = true;
				const char *pp = p, *spp = sp;
				for (;spp<=sp+(tj_strlen(sp)-1);pp++,spp++)
					if (*pp != *spp)
					{
						found = false;
						break;
					}
			}
			if (found)
				break;
		}
		return found ? int(p - str) + 1 : 0;
	}
}

int tj_strrchr(const char *str, const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return NULL;
	else
	{
		bool found = false;
		const char *p = str+(tj_strlen(str)-1);
		for (; p >= str; p--)
		{
			if (*p == ch)
				found = true;
			if (found)
				break;
		}
		return found?int(p - str) + 1:0;
	}
}

int tj_strrstr(const char *str, const char *substr)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	bool found = false;
	if (str == NULL||substr==NULL)
		return NULL;
	else
	{
		bool found = false;
		const char *p = str+(tj_strlen(str)-1), *sp = substr;
		for (;p>=str; p--)
		{
			if (*p == *sp)
			{
				found = true;
				const char *pp = p, *spp = sp;
				for (; spp <= sp + (tj_strlen(sp) - 1); pp++, spp++)
					if (*pp != *spp)
					{
						found = false;
						break;
					}
			}
			if (found)
				break;
		}
		return found ? int(p - str) + 1 : 0;
	}
}

char *tj_strrev(char *str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return NULL;
	else if (tj_strlen(str)==0)
		return str;
	else
	{
		char temp;
		char *ph = str, *pt = str + (tj_strlen(str) - 1);
		for (; ; ph++, pt--)
		{
			if (pt - ph == 1 || pt == ph)
				break;
			temp = *ph;
			*ph = *pt;
			*pt = temp;
		}
		return str;
	}
}