/*
** header for stringlib in /home/ratouney/libarray
**
** Made by ratouney ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Thu Oct  6 13:49:57 2016 ratouney ratouney
** Last update Thu Mar 23 21:10:36 2017 
*/

#include <stdio.h>
#include "calib.h"

char	*fillgen(int size)
{
  char	*new;
  int	i;

  i = 0;
  if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (i < size)
    {
      new[i] = '0';
      i++;
    }
  new[i] = '\0';
  return (new);
}
