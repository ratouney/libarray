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

t_charray *calib_add_inter(t_charray *data, char **new, char *nf)
{
    t_charray *newdata;

    newdata = malloc(sizeof(t_charray));
    newdata->data = new;
    newdata->fill = nf;
    newdata->size = data->size + 1;
    destroy_charray(data);
    return (newdata);
}

t_charray *calib_add(t_charray *data, char *str, int pos, int mode)
{
    char **new = charray(data->size + 1);
    char *nf = fillgen(data->size + 1);
    int i;
    int mod;

    i = -1;
    mod = 0;
    while (++i + mod < data->size + mod)
    {
        if (mod == 0 && i == pos && (mod = 1))
        {
            new[i] = stp(str, 0);
            nf[i] = '1';
            if (data->fill[i] == '1')
                new[i + mod] = stp(data->data[i], 0) + (nf[i + mod] = '1') * 0;
            else
                new[i + mod] = NULL + (nf[i + mod] = '0') * 0;
        }
        else if (data->fill[i] == '1')
            new[i + mod] = stp(data->data[i], 0) + (nf[i + mod] = '1') * 0;
        else
            new[i + mod] = NULL + (nf[i + mod] = '0') * 0;
    }
    return (calib_add_inter(data, new, nf));
}