/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */
int tj_strlen(const char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int l=0;
	for (int i = 0; ; i++)
	{
		if (str[i] != 0)
			l++;
		else
			break;
	}
	return l; //return值可根据需要修改
}

int tj_strcat(char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = tj_strlen(s1);
	int j = 0;
	while (s2[j] != 0)
	{	
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = 0;
	return 0; //return值可根据需要修改
}

int tj_strcpy(char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	for (int i = 0; i <= tj_strlen(s2); i++)
	{
		s1[i] = s2[i];
	}
	
	return 0; //return值可根据需要修改
}

int tj_strncpy(char s1[], const char s2[], int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	for (int i = 0; i <= len; i++)
	{
		if (s2[i] == 0)
			break;
		else
			s1[i] = s2[i];
	}
	return 0; //return值可根据需要修改
}

int tj_strcmp(const char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i;
	for (i = 0; ; i++)
	{
		if ((s2[i] != s1[i]) || (s1[i] == 0 && s2[i] == 0))
			break;
	}
	return (s1[i] - s2[i]);    //return值可根据需要修改
}

int tj_strcasecmp(const char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i;
	char a, b;
	for (i = 0; ; i++)
	{
		a = s1[i];
		b = s2[i];
		if (((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')) && ((b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z')))
		{
			if (a >= 'a' && a <= 'z')
				a -= 32;
			if (b >= 'a' && b <= 'z')
				b -= 32;
		}
		if ((b != a) || (a == 0 && b == 0))
			break;
	}
	return (a - b); //return值可根据需要修改
}

int tj_strncmp(const char s1[], const char s2[], int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i;
	for (i = 0; i <= len - 1; i++)
	{
		if ((s2[i] != s1[i]) || (s1[i] == 0 && s2[i] == 0) || i == len - 1)
			break;
	}
	return (s1[i] - s2[i]); //return值可根据需要修改
}

int tj_strcasencmp(const char s1[], const char s2[], int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i;
	char a, b;
	for (i = 0; i <= len - 1; i++)
	{
		a = s1[i];
		b = s2[i];
		if (((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')) && ((b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z')))
		{
			if (a >= 'a' && a <= 'z')
				a -= 32;
			if (b >= 'a' && b <= 'z')
				b -= 32;
		}
		if ((b != a) || (a == 0 && b == 0)||i == len - 1)
			break;
	}
	return (a - b);  //return值可根据需要修改
}

int tj_strupr(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	for (int i = 0; ; i++)
	{
		if (str[i] == 0)
			break;
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return 0; //return值可根据需要修改
}

int tj_strlwr(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	for (int i = 0; ; i++)
	{
		if (str[i] == 0)
			break;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return 0; //return值可根据需要修改
}

int tj_strchr(const char str[], char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i;
	bool found = false;
	for (i = 0; i <= tj_strlen(str); i++)
	{
		if (str[i] == ch)
			found = true;
		if (found)
			break;
	}
	return (found ? i + 1 : 0); //return值可根据需要修改
}

int tj_strstr(const char str[], const char substr[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i, n;
	bool get = false;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == substr[0])
		{
			n = i;
			get = true;
			for (int j = 0; substr[j] != 0; j++)
			{
				if (str[i] != substr[j])
				{
					get = false;
					break;
				}
				i++;
			}
			i = n;
			if (get)
				break;
		}
	}
	return get ? n + 1 : 0; //return值可根据需要修改
}

int tj_strrchr(const char str[], const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i;
	bool found;
	i = tj_strlen(str);
	int n = i;
	for (i = n; i >= 0; i--)
	{
		if (str[i] == ch)
			found = true;
		else if (str[i] == 0)
			found = false;
		if (found)
			break;
	}
	return (found ? i + 1 : 0);
	return 0; //return值可根据需要修改
}

int tj_strrstr(const char str[], const char substr[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i, n, j;
	bool get = false;
	for (i = 0; ; i++)
		if (str[i] == 0)
			break;
	for (; i >= 0; i--)
	{
		if (str[i] == substr[0])
		{
			n = i;
			get = true;
			for (j = 0; substr[j] != 0; j++)
			{
				if (str[i] != substr[j])
				{
					get = false;
					break;
				}
				i++;
			}
			i = n;
			if (get)
				break;
		}
	}
	return get ? n + 1 : 0; //return值可根据需要修改
}

int tj_strrev(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i;
	char temp;
	int n = tj_strlen(str) - 1;
	if (n % 2 == 0)
		for (i = 0; i < n / 2; i++)
		{
			temp = str[n - i];
			str[n - i] = str[i];
			str[i] = temp;
		}
	else
		for (i = 0; i <= (n - 1) / 2; i++)
		{
			temp = str[n - i];
			str[n - i] = str[i];
			str[i] = temp;
		}
	return 0; //return值可根据需要修改
}