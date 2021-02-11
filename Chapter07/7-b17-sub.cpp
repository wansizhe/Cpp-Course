#include"7-b17.h"

int group_add(FILE *fp, const char *group_name)
{
	char *to_add = new char[strlen(group_name) + 3];
	to_add[0] = '[';
	to_add[1] = '\0';
	strcat(to_add, group_name);
	strcat(to_add, "]");
	rewind(fp);
	while (!feof(fp))
	{
		char cur[100];
		fgets(cur,99,fp);
		if (/*strstr(cur, to_add) != NULL*/strncmp(cur,to_add,strlen(to_add))==0)
		{
			delete to_add;
			return 0;
		}
	}
	fputs(to_add,fp);
	fputc('\n', fp);
	delete to_add;
	return 1;
}

int group_del(FILE *fp, const char *group_name)
{
	int i = 0;
	char *to_del = new char[strlen(group_name) + 3];
	to_del[0] = '[';
	to_del[1] = '\0';
	strcat(to_del, group_name);
	strcat(to_del, "]");
	rewind(fp);
	while (!feof(fp))
	{
		char cur[100];
		fgets(cur, 99, fp);
		if (/*strstr(cur, to_del) != NULL*/strncmp(cur,to_del,strlen(to_del))==0)
			i++;
	}
	if (i == 0)
	{
		delete to_del;
		return 0;
	}
	rewind(fp);
	line *fhead=new line [1];
	line *curline=fhead;
	while (!feof(fp))
	{
		char cur[100];
		fgets(cur, 99, fp);
		if (/*strstr(cur, to_del) != NULL*/strncmp(cur, to_del, strlen(to_del)) == 0)
			break;
		else
		{
			strcpy(curline->ch, cur);
			curline->next = new line [1];
			curline = curline->next;
			curline->ch[0] = '\0';
			curline->next = NULL;
		}
	}
	while (!feof(fp))
	{
		char tch;
		tch = fgetc(fp);
		if (tch == '[')
		{
			fseek(fp, -1, SEEK_CUR);
			break;
		}
	}
	while (!feof(fp))
	{
		char cur[100];
		fgets(cur, 99, fp);
		strcpy(curline->ch, cur);
		curline->next = new line[1];
		curline = curline->next;
		curline->ch[0] = '\0';
		curline->next = NULL;
		cur[0] = 0;
	}
	rewind(fp);
	ftruncate(_fileno(fp), 0);
	curline = fhead;
	while (curline != NULL)
	{
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	fputc('\n', fp);
	curline = fhead;
	while (curline != NULL)
	{
		line *t = curline->next;
		delete curline;
		curline = t;
	}
	delete to_del;
	return 1;
}

int item_add(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{
	char cur[100];
	char *in_group = new char [strlen(group_name) + 3];
	char *to_add = new char[strlen(item_name) + 2];
	strcpy(in_group, "[");
	strcat(in_group, group_name);
	strcat(in_group, "]");
	strcpy(to_add, item_name);
	strcat(to_add, "=");
	rewind(fp);
	int get = 0;
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, in_group) != NULL&&*/strncmp(cur,in_group,strlen(in_group))==0)
			get++;
	}
	if (get == 0)
	{
		delete in_group;
		delete to_add;
		return 0;
	}
	get = 0;
	rewind(fp);
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, in_group) != NULL*/strncmp(cur, in_group, strlen(in_group))==0)
			break;
	}
	cur[0] = '\0';
	while (!feof(fp)&&cur[0]!='[')
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, to_add) != NULL*/strncmp(cur,to_add,strlen(to_add))==0)
			get++;
	}
	if (get != 0)
	{
		delete in_group;
		delete to_add;
		return 0;
	}
	rewind(fp);
	line *fhead = new line[1];
	line *curline = fhead;
	while (!feof(fp))
	{
		char cur[100];
		fgets(cur, 99, fp);
		strcpy(curline->ch, cur);
		curline->next = new line[1];
		curline = curline->next;
		curline->ch[0] = '\0';
		curline->next = NULL;
		cur[0] = 0;
	}
	get = 0;
	rewind(fp);
	curline = fhead;
	while (curline != NULL)
	{
		if (get != 0)
			break;
		if (/*strstr(curline->ch, in_group) != NULL*/strncmp(curline->ch,in_group,strlen(in_group))==0)
			get++;
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	while (curline != NULL&&curline->ch[0] != '[')
	{
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	fputs(to_add, fp);
	switch (item_type)
	{
	case TYPE_INT:
		fprintf(fp, "%d", *(int *)item_value);
		break;
	case TYPE_DOUBLE:
		fprintf(fp, "%lf", *(double *)item_value);
		break;
	case TYPE_STRING:
		fprintf(fp, "%s", (char *)item_value);
		break;
	case TYPE_CHARACTER:
		fprintf(fp, "%c", *(char *)item_value);
		break;
	case TYPE_NULL:
		break;
	default:
		break;
	}
	fputc('\n', fp);
	while (curline != NULL)
	{
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	fputc('\n', fp);
	curline = fhead;
	while (curline != NULL)
	{
		line *t = curline->next;
		delete curline;
		curline = t;
	}
	delete in_group;
	delete to_add;
	return 1;
}

int item_del(FILE *fp, const char *group_name, const char *item_name)
{
	char cur[100];
	char *in_group = new char[strlen(group_name) + 3];
	char *to_del = new char[strlen(item_name) + 2];
	strcpy(in_group, "[");
	strcat(in_group, group_name);
	strcat(in_group, "]");
	strcpy(to_del, item_name);
	strcat(to_del, "=");
	rewind(fp);
	int get = 0;
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, in_group) != NULL*/strncmp(cur, in_group, strlen(in_group)) == 0)
			get++;
	}
	if (get == 0)
	{
		delete in_group;
		delete to_del;
		return 0;
	}
	get = 0;
	rewind(fp);
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, in_group) != NULL*/strncmp(cur, in_group, strlen(in_group)) == 0)
			break;
	}
	cur[0] = '\0';
	while (!feof(fp)&&cur[0] != '[')
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, to_del) != NULL*/strncmp(cur, to_del, strlen(to_del)) == 0)
			get++;
	}
	if (get == 0)
	{
		delete in_group;
		delete to_del;
		return 0;
	}
	rewind(fp);
	line *fhead = new line[1];
	line *curline = fhead;
	while (!feof(fp))
	{
		char cur[100];
		fgets(cur, 99, fp);
		strcpy(curline->ch, cur);
		curline->next = new line[1];
		curline = curline->next;
		curline->ch[0] = '\0';
		curline->next = NULL;
		cur[0] = 0;
	}
	get = 0;
	rewind(fp);
	ftruncate(_fileno(fp), 0);
	curline = fhead;
	while (curline != NULL)
	{
		if (get != 0)
			break;
		if (/*strstr(curline->ch, in_group) != NULL*/strncmp(curline->ch, in_group, strlen(in_group)) == 0)
			get++;
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	while (curline != NULL)
	{
		if (curline->ch[0] == '[')
			break;
		if (/*strstr(curline->ch, to_del) != NULL*/strncmp(curline->ch, to_del, strlen(to_del)) == 0)
		{
			curline = curline->next;
			break;
		}
		else
		{
			fputs(curline->ch, fp);
			curline = curline->next;
		}
	}
	while (curline->next != NULL)
	{
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	fputc('\n', fp);
	ftruncate(_fileno(fp), ftell(fp));
	curline = fhead;
	while (curline!= NULL)
	{
		line *t = curline->next;
		delete curline;
		curline = t;
	}
	delete in_group;
	delete to_del;
	return 1;
}

int item_update(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{
	char cur[100];
	char *in_group = new char[strlen(group_name) + 3];
	char *to_up = new char[strlen(item_name) + 2];
	strcpy(in_group, "[");
	strcat(in_group, group_name);
	strcat(in_group, "]");
	strcpy(to_up, item_name);
	strcat(to_up, "=");
	int get = 0;
	rewind(fp);
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, in_group) != NULL*/strncmp(cur, in_group, strlen(in_group)) == 0)
			get++;
	}
	if (get == 0)
	{
		delete in_group;
		delete to_up;
		return 0;
	}
	rewind(fp);
	line *fhead = new line[1];
	line *curline = fhead;
	while (!feof(fp))
	{
		char curl[100];
		fgets(curl, 99, fp);
		//cout << ftell(fp) << "  " << cur;
		strcpy(curline->ch, curl);
		//cout << ftell(fp) << "  " << curline->ch;
		curline->next = new line[1];
		curline = curline->next;
	    curline->ch[0] = '\0';
		curline->next = NULL;
		curl[0] = 0;
	}
	get = 0;
	rewind(fp);
	curline = fhead;
	while (curline != NULL)
	{
		if (get != 0)
			break;
		if (/*strstr(curline->ch, in_group) != NULL*/strncmp(curline->ch, in_group, strlen(in_group)) == 0)
			get++;
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	get=0;
	ftruncate(_fileno(fp), ftell(fp));
	while (curline != NULL)
	{
		if (curline->ch[0] == '[')
			break;
		if (/*strstr(curline->ch, to_del) != NULL*/strncmp(curline->ch, to_up, strlen(to_up)) == 0)
		{
			get++;
			fputs(to_up, fp);
			switch (item_type)
			{
			case TYPE_INT:
				fprintf(fp, "%d", *(int *)item_value);
				break;
			case TYPE_DOUBLE:
				fprintf(fp, "%lf", *(double *)item_value);
				break;
			case TYPE_STRING:
				fprintf(fp, "%s", (char *)item_value);
				break;
			case TYPE_CHARACTER:
				fprintf(fp, "%c", *(char *)item_value);
				break;
			case TYPE_NULL:
				break;
			default:
				break;
			}
			fputc('\n', fp);
			curline = curline->next;
			break;
		}
		else
		{
			fputs(curline->ch, fp);
			curline = curline->next;
		}
	}
	if (get == 0)
	{
		fputs(to_up, fp);
		switch (item_type)
		{
		case TYPE_INT:
			fprintf(fp, "%d", *(int *)item_value);
			break;
		case TYPE_DOUBLE:
			fprintf(fp, "%lf", *(double *)item_value);
			break;
		case TYPE_STRING:
			fprintf(fp, "%s", (char *)item_value);
			break;
		case TYPE_CHARACTER:
			fprintf(fp, "%c", *(char *)item_value);
			break;
		case TYPE_NULL:
			break;
		default:
			break;
		}
		fputc('\n', fp);
	}
	
	while (curline!= NULL)
	{
		fputs(curline->ch, fp);
		curline = curline->next;
	}
	fputc('\n', fp);
	curline = fhead;
	while (curline != NULL)
	{
		line *t = curline->next;
		delete curline;
		curline = t;
	}
	delete in_group;
	delete to_up;
	return 1;
}

int item_get_value(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{
	char cur[100];
	char *in_group = new char[strlen(group_name) + 3];
	char *to_get = new char[strlen(item_name) + 2];
	strcpy(in_group, "[");
	strcat(in_group, group_name);
	strcat(in_group, "]");
	strcpy(to_get, item_name);
	strcat(to_get, "=");
	rewind(fp);
	int get = 0;
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, in_group) != NULL*/strncmp(cur, in_group, strlen(in_group)) == 0)
			get++;
	}
	if (get == 0)
	{
		delete in_group;
		delete to_get;
		return 0;
	}
	get = 0;
	rewind(fp);
	while (!feof(fp))
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, in_group) != NULL*/strncmp(cur, in_group, strlen(in_group)) == 0)
			break;
	}
	cur[0] = '\0';
	while (!feof(fp) && cur[0] != '[')
	{
		fgets(cur, 99, fp);
		if (/*strstr(cur, to_del) != NULL*/strncmp(cur, to_get, strlen(to_get)) == 0)
			get++;
	}
	if (get == 0)
	{
		delete in_group;
		delete to_get;
		return 0;
	}
	rewind(fp);
	while (!feof(fp))
	{
		char cur[100];
		fgets(cur, 99, fp);
		if (strncmp(cur, in_group, strlen(in_group)) == 0)
			break;
	}
	char t[100];
	get = 0;
	while (!feof(fp))
	{
		fgets(t, 99, fp);
		if (t[0] == '[')
			break;
		if (strncmp(t, to_get, strlen(to_get)) == 0)
		{
			get++;
			break;
		}
	}
	if (get == 0)
		return 0;
	fseek(fp, 0-(strlen(t)-strlen(to_get)+1), SEEK_CUR);
	switch (item_type)
	{
	case TYPE_INT:
		fscanf(fp, "%d", (int *)item_value);
		break;
	case TYPE_DOUBLE:
		fscanf(fp, "%lf", (double *)item_value);
		break;
	case TYPE_STRING:
		fscanf(fp, "%s", (char *)item_value);
		break;
	case TYPE_CHARACTER:
		fscanf(fp, "%c", (char *)item_value);
		break;
	case TYPE_NULL:
		break;
	default:
		break;
	}
	return 1;
}