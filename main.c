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
#include "ratarray.h"

char **charray(int size)
{
    char **new;

    new = malloc(sizeof(char *) * (size + 1));
    new[size] = NULL;
    return (new);
}

void write_to_char(char **data, char *new, int pos, int size)
{
    int count;

    if (pos < 0 || pos >= size)
        return;
    if (data[pos] == NULL)
    {
        data[pos] = my_strpaste(new, 0);
    }
    else
    {
        free(data[pos]);
        data[pos] = my_strpaste(new, 0);
    }
}

char *fillgen(int size)
{
    char *new;
    int count;

    count = 0;
    new = malloc(sizeof(char) * (size + 1));
    while (count < size)
    {
        new[count] = '0';
        count++;
    }
    new[count] = '\0';
    return (new);
}

t_charray *newcharray(int size)
{
    t_charray *new;

    new = malloc(sizeof(t_charray));
    new->data = charray(size);
    new->fill = fillgen(size);
    new->size = size;
    return (new);
}

void destroy_charray(t_charray *data)
{
    int count;

    count = 0;
    while (count < data->size)
    {
        if (data->fill[count] == '1' && data->data[count] != NULL)
            free(data->data[count]);
        count++;
    }
    free(data->data);
    free(data->fill);
    free(data);
}

void calib_write(t_charray *array, char *str, int spot, int mode)
{
    if (spot >= array->size || spot < 0)
        write(1, "Out of reach\n", 13);
    else
    {
        if ((mode - (mode % 10)) < 10)
        {
            if (array->fill[spot] == '0')
            {
                array->data[spot] = my_strpaste(str, mode % 10);
                array->fill[spot] = '1';
            }
            else
            {
                write(1, "Line is already occupied\n", 25);
                write(1, "To overwrite, use the appropriate macro\n", 40);
            }
        }
        else
        {
            if (array->fill[spot] == '1')
                free(array->data[spot]);
            array->data[spot] = my_strpaste(str, mode % 10);
        }
    }
}

void calib_show(t_charray *data)
{
    int count;

    count = 0;
    printf("[Content of Charray]\n");
    printf("Status : [%s]\n\n", data->fill);
    while (count < data->size)
    {
        if (data->fill[count] == '1')
            printf("\t[%d] = [%s]\n", count, data->data[count]);
        else
            printf("\t[%d] = Undefined\n", count);
        count++;
    }
    printf("[End of Array]\n");
}

t_charray *calib_add(t_charray *data, char *str, int pos, int mode)
{
    t_charray *newdata;
    char **new = charray(data->size + 1);
    char *newfill = fillgen(data->size + 1);
    int count;
    int mod;

    count = 0;
    mod = 0;
    while (count + mod < data->size + mod)
    {
        if (mod == 0 && count == pos)
        {
            mod = 1;
            new[count] = my_strpaste(str, 0);
            newfill[count] = '1';
            if (data->fill[count] == '1')
            {
                new[count + mod] = my_strpaste(data->data[count], 0);
                newfill[count + mod] = '1';
            }
            else
            {
                new[count + mod] = NULL;
                newfill[count + mod] = '0';
            }
        }
        else
        {
            if (data->fill[count] == '1')
            {
                new[count + mod] = my_strpaste(data->data[count], 0);
                newfill[count + mod] = '1';
            }
            else
            {
                new[count + mod] = NULL;
                newfill[count + mod] = '0';
            }
        }
        count++;
    }
    newdata = malloc(sizeof(t_charray));
    newdata->data = new;
    newdata->fill = newfill;
    newdata->size = data->size + 1;
    destroy_charray(data);
    return (newdata);
}

int main(int argc, char **argv)
{
    t_charray *data = newcharray(5);

    calib_write(data, "Yolo", 0, LA_SN);
    calib_write(data, "Bordel", 1, LA_SN);
    //calib_write(data, "Zip", 2, LA_SN);
    calib_write(data, "Texte", 3, LA_SN);
    calib_write(data, "Macro", 4, LA_SN);
    printf("\n");
    calib_show(data);
    printf("\n");
    data = calib_add(data, "JABAJABAAA\0", 3, 0);
    printf("\n");
    calib_show(data);
    printf("\n");
    destroy_charray(data);
}