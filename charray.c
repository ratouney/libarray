/*
** header for stringlib in /home/ratouney/libarray
**
** Made by ratouney ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Thu Oct  6 13:49:57 2016 ratouney ratouney
** Last update Thu Mar 23 21:09:15 2017 
*/

#include "calib.h"

char	**charray(int size)
{
  char	**new;

  if ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  new[size] = NULL;
  return (new);
}
