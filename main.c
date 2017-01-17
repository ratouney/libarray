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

int main(int argc, char **argv, char **env)
{
    t_charray *newenv = calib_import(env, -1);
    exit(42);

    t_charray *data = newcharray(5);
    t_charray *other;

    calib_write(data, "Yolo", 0, LA_SN);
    calib_write(data, "Zip", 2, LA_SN);
    calib_write(data, "Texte", 3, LA_SN);
    calib_write(data, "Macro", 4, LA_SN);
    printf("\n");
    calib_show(data);
    printf("\n");
    la_copy(data, other);
    printf("\n");
    calib_show(data);
    printf("\n");
    destroy_charray(data);
    destroy_charray(other);
}