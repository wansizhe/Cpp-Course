#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _UNISTD_H
#include<iostream>
#include <process.h>
#include <io.h>
#include <direct.h>
#include <Windows.h>
#include<string>
#include<cstring>
#define srandom srand
#define random rand
#define R_OK 4
#define W_OK 2
#define X_OK 1
#define F_OK 0
#define access _access
#define dup2 _dup2
#define execve _execve
#define ftruncate _chsize
#define fileno _fileno
using namespace std;
enum ITEM_TYPE
{
	TYPE_INT,
	TYPE_DOUBLE,
	TYPE_STRING,
	TYPE_CHARACTER,
	TYPE_NULL
};
struct line
{
	char ch[100];
	line* next;
};
extern int group_add(FILE *fp, const char *group_name);
extern int group_del(FILE *fp, const char *group_name);
extern int item_add(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
extern int item_del(FILE *fp, const char *group_name, const char *item_name);
extern int item_update(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
extern int item_get_value(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);