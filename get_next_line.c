/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:39:22 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/25 11:04:43 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(char *arr, int fd)
{
    char    *str;
    int     sub; 
  
    sub = 1;
    str = malloc(BUFFER_SIZE + 1);
    if (!str)
      return (NULL);
    while (sub && !ft_strchr(arr, '\n'))
    {
      sub = read(fd, str, BUFFER_SIZE);
	    if (sub == -1)
		  {
		  	free(arr);
		  	free(str);
		  	return (NULL);
		  }
      str[sub] = '\0';
      arr = ft_strjoin(arr, str);
      if (!arr)
        return (NULL);
  }
    free(str);
    return (arr);
}

size_t ft_count(char *arr)
{
  size_t i;

  i = 0; 
  while (arr  && arr[i] && arr[i] != '\n')
      i++;
  return (i);
}

char *ft_line(char *arr)
{
  char *str; 
  size_t i;

  i = 0;
  if (!arr)
    return ((void *)0);
  if (*arr == '\0')
    return (NULL);
  str = malloc(ft_count(arr) + 2);
  if (!str)
    return(NULL);
  while (arr && arr[i] && i < ft_count(arr) + 1)
  {
    str[i] = arr[i];
    i++;
  }
  str[i] = '\0';
      // printf("%p \n", str);
  return (str);
}

char *ft_backup(char *arr)
{
  char *reserve;
  
  if (!arr)
    return (NULL);
  if (ft_count(arr) == ft_strlen(arr))
  {
    free(arr);
    return(NULL);
  }
  reserve = ft_strdup(arr + (ft_count(arr) + 1));
  free(arr);
  return (reserve);
}

char  *get_next_line(int fd)
{
  static char *arr;
  char *one;

  if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647 || fd > 1025)
		return (NULL);
  arr = ft_read(arr, fd);
  one = ft_line(arr);
  arr = ft_backup(arr);
  if (one && *one == '\0')
    return (NULL);
  return (one);
}
