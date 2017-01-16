/*
** header for stringlib in /home/ratouney/libarray
**
** Made by ratouney ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Thu Oct  6 13:49:57 2016 ratouney ratouney
** Last update Wed Nov 30 18:19:49 2016 ratouney
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LA_SN 0
#define LA_SF 1
#define LA_BN 10
#define LA_BF 11

struct s_charray;

typedef struct s_charray t_charray;

struct s_charray
{
    char **data;
    char *fill;
    int size;
};

char *my_strpaste(char *,int);

struct s_string;

typedef struct s_string t_string;

struct s_string
{
    char *string;

    int (*len)(t_string *);
    int (*exist)(t_string *, char );
    int (*cmp)(t_string *, char *, int);
    char *(*copy)(t_string *, int);
    char *(*fuse)(t_string *, char *, int);
    char *(*sl)(t_string *, int, int);
    void (*show)(t_string *, int);
};