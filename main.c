/*
** header for stringlib in /home/ratouney/libarray
**
** Made by ratouney ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Thu Oct  6 13:49:57 2016 ratouney ratouney
** Last update Wed Nov 30 18:19:49 2016 ratouney
*/

#include <stdio.h>
#include <ratarray.h>

int alib_strlenv(char *str)
{
    int count;

    count = 0;
    while (str[count] != '\0')
        count++;
    return (count);
}

int alib_strlen(t_charray *data, int line)
{
    int count;

    count = 0;
    while (data->charray[line] != '\0')
        count++;
    return (count);
}

char **charray(int size, int mode)
{
    char **array;
    int count;

    count = 0;
    while (count < size)
    {
        array[count] = malloc(sizeof(char *) *(mode + 1));
        count++;
    }
}

t_charray *newcharray(int size, int mode)
{
    t_charray *data;

    data->charray = charray(size, mode);
    data->size = size;
}

void alib_writetochar(t_charray *data, int line, char *text, int mode)
{
    if (mode == 0)
        data->charray[line] = my_strpaste(text, 0);
    else if (mode == 1)
        data->charray[line] = my_strpaste(text, 1);
}

int main(int argc, char **argv)
{
    char *line = my_strpaste(argv[1], 0);

    t_charray *charray = newcharray(5);
    //printf("Line : [%s]\n", charray->charray[0]);
}