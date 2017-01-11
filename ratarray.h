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

struct s_charray;

typedef struct s_charray t_charray;

struct s_charray
{
    char **charray;

    int size;
};

char *my_strpaste(char *str, int mode);