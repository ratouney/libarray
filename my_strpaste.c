/*
** header for stringlib in /home/ratouney/cmod
**
** Made by ratouney ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Thu Oct  6 13:49:57 2016 ratouney ratouney
** Last update Thu Mar 23 21:11:04 2017 
*/

#include "ratarray.h"

char	*stp(char *str, int mode)
{
  int	count;
  char	*new;

  if (str == NULL)
    return (NULL);
  if ((new = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  count = -1;
  while (str[++count] != '\0')
    new[count] = str[count];
  new[count] = '\0';
  if (mode == 1)
    free(str);
  return (new);
}
